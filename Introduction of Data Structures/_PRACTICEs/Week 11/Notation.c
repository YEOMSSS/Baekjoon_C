#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
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
element evalPostfix(char *exp);

int main(void)
{
    int result;
    char *express = "35*62/-";
    printf("후위 표기식 : %s", express);

    result = evalPostfix(express);
    printf("\n\n연산 결과 => %d\n", result);
}

element evalPostfix(char *exp)
{
    int opr1, opr2; // 스택에서 pop할 연산자
    int value;      // 스택에 push할 피연산자

    // char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장
    int length = strlen(exp);
    char symbol;

    // 공백 스택 생성
    top = NULL;

    // 1. 피연산자를 만나면 스택에 push한다.
    for (int i = 0; i < length; i++)
    {
        symbol = exp[i];
        if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/')
        {
            // 문자타입 symbol을 정수타입으로 변환
            // '0'의 아스키코드는 48. 'n'의 아스키코드는 48+n
            // '3'에서 '0'을 빼주면 정수 3이 나온다.
            value = symbol - '0'; // int()라고 생각하면 되겠다.
            push(value);
        }
        // 2. 연산자를 만나면 필요한 만큼의 피연산자를 스택에서 pop하여 연산하고, 연산 결과를 다시 스택에 push한다.
        else
        {
            opr2 = pop();
            opr1 = pop();

            // 변수 opr1과 opr2에 대해 symbol에 저장된 연산자를 연산
            switch (symbol)
            {
            case '+':
                push(opr1 + opr2);
                break;
            case '-':
                push(opr1 - opr2);
                break;
            case '*':
                push(opr1 * opr2);
                break;
            case '/':
                push(opr1 / opr2);
                break;
            }
        }
    }
    // 3. 수식이 끝나면 마지막으로 스택을 pop하여 출력한다.
    // 수식 exp에 대한 처리를 마친 후 스택에 남아 있는 결과값을 pop하여 반환
    return pop();
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
