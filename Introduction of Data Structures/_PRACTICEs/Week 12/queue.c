#include <stdio.h>
#include <stdlib.h> // malloc
#define Q_SIZE 4

typedef char element; // 수정이 간편. element는 char의 역할
typedef struct
{
    element queue[Q_SIZE];
    int front, rear;
    // 저장된 첫 번째 원소 이전 인덱스는 ‘front’
    // 저장된 마지막 원소의 인덱스는 ‘rear’
    // 큐는 현재 ‘rear’ 다음 위치에 원소 삽입하고, 현재 ‘front’ 다음 위치에 있는 원소를 삭제하는 구조
} QueueType;

QueueType *createQueue();                 // 공백 순차 큐를 생성하는 연산
int isEmpty(QueueType *Q);                // 순차 큐가 공백 상태인지 검사하는 연산
int isFull(QueueType *Q);                 // 순차 큐가 포화 상태인지 검사하는 연산
void enQueue(QueueType *Q, element item); // 순차 큐의 rear에 원소를 삽입하는 연산
element deQueue(QueueType *Q);            // 순차 큐의 front에서 원소를 삭제하는 연산
element peek(QueueType *Q);               // 순차 큐의 가장 앞에 있는 원소를 검색하는 연산
void printQ(QueueType *Q);                // 순차 큐의 원소를 출력하는 연산

// 공백 순차 큐를 생성하는 연산
QueueType *createQueue()
{
    // 공백 큐를 생성해서 메모리 할당
    QueueType *Q;
    Q = (QueueType *)malloc(sizeof(QueueType));

    // front, rear 초기 상태 설정
    // 큐 크기 = 배열 크기
    // 초기 상태 : front = rear = -1
    Q->front = -1; // front 초기값 설정
    Q->rear = -1;  // rear 초기값 설정

    return Q;
}

// 순차 큐가 공백 상태인지 검사하는 연산
int isEmpty(QueueType *Q)
{
    // 공백 상태 : front = rear
    if (Q->front == Q->rear)
    {
        printf(" Queue is empty! ");
        return 1;
    }
    else
        return 0;
}

// 순차 큐가 포화 상태인지 검사하는 연산
int isFull(QueueType *Q)
{
    // 포화 상태 : rear = n-1. rear가 배열의 마지막 인덱스를 가리키면 포화상태
    if (Q->rear == Q_SIZE - 1)
    {
        printf(" Queue is full! ");
        return 1;
    }
    else
        return 0;
}

// 순차 큐의 rear에 원소를 삽입하는 연산
void enQueue(QueueType *Q, element item)
{
    // Q가 포화 상태이면, 삽입 연산 중단
    if (isFull(Q))
        return;
    else
    {
        Q->rear++;
        Q->queue[Q->rear] = item;
        // Q->queue[++Q->rear] = item;
    }
}

// 순차 큐의 front에서 원소를 삭제하는 연산
element deQueue(QueueType *Q)
{
    // 공백 상태이면, 삭제 연산 중단
    if (isEmpty(Q))
        // return '0'; // 그냥 return을 하면 반환형이 element여서 오류가 난다.
        exit(1);
    else
    {
        Q->front++;
        return Q->queue[Q->front];
        // free(Q->queue[Q->front]); // 아, 이미 배열로 할당되어서 메모리반환은 할 필요가 없네.
        // 초기화를 하지 않아도 쓸일이 없어서 안했다.
    }
}

// 순차 큐의 가장 앞에 있는 원소를 검색하는 연산
element peek(QueueType *Q)
{
    // 공백 상태이면 연산 중단
    if (isEmpty(Q))
        exit(1);
    else
        // front는 가장 앞 인덱스의 하나 이전 인덱스이므로 +1을 해서 반환한다.
        return Q->queue[Q->front + 1];
}

// 순차 큐의 원소를 출력하는 연산
void printQ(QueueType *Q)
{
    int i;
    printf(" Queue : [");
    for (i = Q->front + 1; i <= Q->rear; i++)
        printf("%3c", Q->queue[i]);
    printf(" ]");
}

int main(void)
{
    QueueType *Q1 = createQueue(); // 큐 생성
    element data;
    printf("\n ***** 순차 큐 연산 ***** \n");
    printf("\n 삽입 A>>");
    enQueue(Q1, 'A');
    printQ(Q1);
    printf("\n 삽입 B>>");
    enQueue(Q1, 'B');
    printQ(Q1);
    printf("\n 삽입 C>>");
    enQueue(Q1, 'C');
    printQ(Q1);

    data = peek(Q1);
    printf(" peek item : %c \n", data);

    printf("\n 삭제  >>");
    data = deQueue(Q1);
    printQ(Q1);
    printf("\t삭제 데이터: %c", data);
    printf("\n 삭제  >>");
    data = deQueue(Q1);
    printQ(Q1);
    printf("\t삭제 데이터: %c", data);
    printf("\n 삭제  >>");
    data = deQueue(Q1);
    printQ(Q1);
    printf("\t\t삭제 데이터: %c", data);

    printf("\n 삽입 D>>");
    enQueue(Q1, 'D');
    printQ(Q1);
    printf("\n 삽입 E>>");
    enQueue(Q1, 'E');
    printQ(Q1);
}
