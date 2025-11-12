#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 스택 요소(element)의 자료형을 char로 정의
typedef char element;
typedef struct stackNode
{
    element data;
    struct stackNode *link;
} stackNode;

// 연결 스택의 초기상태는 top == NULL일 때이다.
stackNode *top; // 그냥 이렇게 만들어 놓으면 top == NULL인 상태이다.

int isEmpty();           // 스택이 공백 상태인지 확인하는 연산
void push(element item); // 스택의 top에 원소를 삽입하는 연산
element pop();           // 스택의 top에서 원소를 삭제하는 연산
element peek();          // 스택의 top 원소를 검색하는 연산

int testPair(char *exp); // 수식의 괄호를 검사하는 연산

int main(void)
{
    // char *express = "{(A+B)-3]*5+[{cos(x+y)+7}-1]*4"; // 대괄호 ']'가 나올 때 틀린 수식
    char *express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4"; // 이건 맞는 수식.
    printf("%s", express);

    if (testPair(express) == 1)
        printf("\n\n수식의 괄호가 맞게 사용되었습니다!\n");
    else
        printf("\n\n 수식의 괄호가 틀렸습니다!\n");
}

// 수식의 괄호를 검사하는 연산
int testPair(char *exp)
{
    char symbol;    // 읽는 문자 저장
    char open_pair; // pop한 괄호쌍 저장

    // char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장!
    int length = strlen(exp);

    // 공백 스택 만들고
    top = NULL;
    // 수식을 쭉 읽는다.
    for (int i = 0; i < length; i++)
    {
        symbol = exp[i];
        switch (symbol)
        {
        //(1) 왼쪽 괄호는 스택에 삽입
        case '(':
        case '{':
        case '[':
            push(symbol);
            break;

        case ')':
        case '}':
        case ']':
            //(2) 오른쪽 괄호를 읽으면
            if (isEmpty())
                return 0;
            else
            {
                // (2)-1 스택에서 마지막으로 읽은 괄호를 꺼냄
                open_pair = pop();

                // (2)-2 괄호 쌍이 맞는지 검사
                if ((open_pair == '(' && symbol != ')') ||
                    (open_pair == '[' && symbol != ']') ||
                    (open_pair == '{' && symbol != '}'))

                    //(2)-3 괄호 쌍이 틀리면 수식 오류!
                    return 0;

                // (2)-4 괄호 쌍이 맞으면 다음 symbol 검사를 계속함
                else
                    break;
            }
        }
    }
    // 수식 검사를 마친 후 스택이 공백이면 1을 반환
    if (isEmpty())
        return 1;
    else
        return 0; // 공백이 아니면 0을 반환(수식 괄호 틀림)
}

// 스택이 공백 상태인지 확인하는 연산
int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item)
{
    // 1. item 원소를 삽입할 새 노드 생성
    // 2. 새 노드의 데이터 필드 설정
    // 3. 새 노드의 링크 필드 설정 -> 새 노드의 링크 필드는 마지막 노드(top)가 가리키는 노드를 가리켜야 함
    // 4. top의 위치 변경
    // stackNode의 크기만큼의 메모리를 할당
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = item;
    // top이 가리키는 노드를 내 링크로 가져오면 된다.
    temp->link = top; // 삽입 노드를 top의 위에 연결
    // 그리고 top을 내 노드의 위치로 바꾼다.
    top = temp; // top 위치를 삽입 노드로 이동
}

// 스택의 top에서 원소를 삭제하는 연산
element pop()
{
    element item;
    stackNode *temp = top; // 삭제할 노드를 temp로 둔다.

    // 스택이 공백 리스트인 경우
    if (isEmpty())
    {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    // 스택이 공백 리스트가 아닌 경우
    // 1. 반환할 원소 저장
    // 2. top의 위치 변경
    // 3. 노드 반환
    // 4. 원소 반환
    else
    {
        item = temp->data; // 반환할 원소 저장
        top = temp->link;  // top의 위치 변경
        // top 위치를 삭제 노드 아래로 이동
        free(temp);  // 삭제된 노드의 메모리 반환
        return item; // 삭제된 원소 반환
    }
}

// 스택의 top 원소를 검색하는 연산
element peek()
{
    // 스택이 공백 리스트인 경우
    if (isEmpty())
    {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    // 스택이 공백 리스트가 아닌 경우
    else
    {
        // 굳이 temp를 쓸 필요가 없다.
        return (top->data); // 현재 top의 원소 반환
    }
}
