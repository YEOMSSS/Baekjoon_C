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
void printStack();       // 스택의 원소를 top에서 bottom 순서로 출력하는 연산

// 스택이 공백 상태인지 확인하는 연산
int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

// isFull()은 구현할 필요 없음

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

// 스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack()
{
    stackNode *p = top;
    printf("\n STACK [ ");
    while (p)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("] ");
}

int main(void)
{
    element item;
    top = NULL;
    printf("\n** 연결 스택 연산 **\n");
    printStack();
    push(1);
    printStack(); // 1 삽입
    push(2);
    printStack(); // 2 삽입
    push(3);
    printStack(); // 3 삽입

    item = peek();
    printStack(); // 현재 top의 원소 출력
    printf("peek => %d", item);

    item = pop();
    printStack(); // 삭제
    printf("\t pop  => %d", item);

    item = pop();
    printStack(); // 삭제
    printf("\t pop  => %d", item);

    item = pop();
    printStack(); // 삭제
    printf("\t pop  => %d", item);

    printf("\n");
}
