#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef int element; // 스택 원소(element)의 자료형을 int로 정의
// 이런식으로 해두면 나중에 이 int만 바꾸면 element로 쓰여진 모든 자료형이 바뀐다.
// 지금 코드에서 element는 모두 int의 역할을 하고 있다.

// 빈 스택을 만들어두고 시작한다.
element stack[STACK_SIZE];
int top = -1; // top이 -1이면 초기값(빈 스택)이다.
// top은 현재 스택의 top의 인덱스를 가지고 있다.

int isEmpty();           // 스택이 공백 상태인지 확인하는 연산
int isFull();            // 스택이 포화 상태인지 확인하는 연산
void push(element item); // 스택의 top에 원소를 삽입하는 연산
element pop();           // 스택의 top에서 원소를 삭제 후 반환하는 연산
element peek();          // 스택의 top 원소를 검색해 반환하는 연산
void printStack();       // 스택의 원소를 출력하는 연산

// 스택이 공백 상태인지 확인하는 연산
int isEmpty()
{
    // top이 초기값 상태면 빈 스택임
    if (top == -1)
        // 공백상태면 1을 반환
        return 1;
    else
        return 0;
}

// 스택이 포화 상태인지 확인하는 연산
int isFull()
{
    // top이 스택의 크기-1이면 꽉 찬 스택임
    if (top == STACK_SIZE - 1)
        // 포화상태면 1을 반환
        return 1;
    else
        return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item)
{
    // 스택이 꽉 차 있을경우
    if (isFull())
    {
        printf("\n\n Stack is FULL! \n");
        return;
    }
    // 스택에 공간이 남아서 push가능한 상태
    else
    {
        // top++;
        // stack[top] = item;

        // top을 증가시킨 후 현재 top에 원소 삽입 (선행연산자)
        stack[++top] = item;
    }
}

// 스택의 top에서 원소를 삭제 후 반환하는 연산
element pop()
{
    // 스택이 공백 상태인 경우
    if (isEmpty())
    {
        printf("\n\n Stack is Empty!! \n");
        return 0;
    }
    // 스택에 pop할 원소가 있으면
    else
        // top을 반환하고 top을 하나 줄인다. (후행연산자)
        return stack[top--]; // 이거는 분해해서 쓰기 어렵다.
}

// 스택의 top 원소를 검색해 반환하는 연산
element peek()
{
    // 스택이 공백 상태인 경우
    if (isEmpty())
    {
        printf("\n\n Stack is Empty ! \n");
        // exit(1); // 오류 종료
        return 0;
    }
    else
        return stack[top];
}

// 스택의 원소를 출력하는 연산
void printStack()
{
    int i;
    printf("\n STACK [");
    for (i = 0; i <= top; i++)
    {
        printf("%d", stack[i]);
    }
    printf("] ");
}

int main(void)
{
    element item;
    printf("\n ** 순차 스택 연산 **\n");
    printStack();
    push(1);
    printStack(); // 1 삽입
    push(2);
    printStack(); // 2 삽입
    push(3);
    printStack(); // 3 삽입

    item = peek();
    printStack(); // 현재 top의 원소 출력
    printf("\tpeek => %d", item);

    item = pop();
    printStack(); // 삭제
    printf("\t pop => %d", item);

    item = pop();
    printStack(); // 삭제
    printf("\t pop => %d", item);

    item = pop();
    printStack(); // 삭제
    printf("\t pop => %d", item);

    printf("\n");

    return 0;
}
