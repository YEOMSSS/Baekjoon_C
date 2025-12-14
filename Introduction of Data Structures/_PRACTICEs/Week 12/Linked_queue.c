#include <stdio.h>
#include <malloc.h>

typedef char element;

// 단순 연결 리스트 사용
typedef struct QNode
{
    element data;
    struct QNode *link;
} QNode;

// 초기 상태 : front = rear = null
// 공백 상태 : front = null
// 포화 상태 : 존재하지 않음
typedef struct
{
    QNode *front, *rear;
} LQueueType;

LQueueType *createLinkedQueue();            // 공백 연결 큐를 생성하는 연산
int isEmpty(LQueueType *LQ);                // 연결 큐가 공백 상태인지 검사하는 연산
void enQueue(LQueueType *LQ, element item); // 연결 큐의 rear에 원소를 삽입하는 연산
element deQueue(LQueueType *LQ);            // 연결 큐에서 원소를 삭제하고 반환하는 연산
element peek(LQueueType *LQ);               // 연결 큐에서 원소를 검색하는 연산
void printLQ(LQueueType *LQ);               // 연결 큐의 원소를 출력하는 연산

// 공백 연결 큐를 생성하는 연산
LQueueType *createLinkedQueue()
{
    LQueueType *LQ;
    LQ = (LQueueType *)malloc(sizeof(LQueueType));

    // 초기 상태 : front = rear = null
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

// 연결 큐가 공백 상태인지 검사하는 연산
int isEmpty(LQueueType *LQ)
{
    // 공백 상태 : front = null
    if (LQ->front == NULL)
    {
        printf(" Linked Queue is empty! ");
        return 1;
    }
    else
        return 0;
}
// 단순연결리스트 구현이므로 isFull은 존재하지 않는다.

// 연결 큐의 rear에 원소를 삽입하는 연산
void enQueue(LQueueType *LQ, element item)
{
    // 1. 삽입할 노드 생성 및 필드 처리
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;

    // 2. 현재 연결 큐가 공백 상태일 때
    if (LQ->front == NULL)
    {
        LQ->front = newNode;
        LQ->rear = newNode;
    }

    // 3. 현재 연결 큐가 공백 상태가 아닐 때
    else
    {
        // 현재 rear.link(rear가 가리키는놈의 link)에 내 주소 넣고, rear에도 내 주소 넣고.
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

// 연결 큐에서 원소를 삭제하고 반환하는 연산
element deQueue(LQueueType *LQ)
{
    // old: free할 노드
    QNode *old = LQ->front;
    // item: return할 원소
    element item;

    // 공백 상태일 때
    if (isEmpty(LQ))
        return 0;
    // 공백 상태가 아닐 때
    else
    {
        // 1. 반환할 원소 저장
        item = old->data;
        // 2. front의 위치를 한칸 뒤로 변경
        LQ->front = old->link;
        // LQ->front = LQ->front->link;
        // 3. 삭제한 뒤에 공백상태가 되는지 확인
        if (LQ->front == NULL)
            LQ->rear = NULL;
        // 4. 노드 free, 원소 return
        free(old);
        return item;
    }
}

// 연결 큐에서 원소를 검색하는 연산
element peek(LQueueType *LQ)
{
    // 사용자에게 반환할 원소
    element item;
    // 공백 상태일 때
    if (isEmpty(LQ))
        return 0;
    else
    {
        // 1. item에 반환할 원소 저장
        item = LQ->front->data;
        // 2. 원소 반환
        return item;
    }
}

// 연결 큐의 원소를 출력하는 연산
void printLQ(LQueueType *LQ)
{
    QNode *temp = LQ->front;
    printf(" Linked Queue : [");
    while (temp)
    {
        printf("%3c", temp->data);
        temp = temp->link;
    }
    printf(" ] ");
}

int main(void)
{
    LQueueType *LQ = createLinkedQueue(); // 연결 큐 생성
    element data;
    printf("\n ***** 연결 큐 연산 ***** \n");
    printf("\n 삽입 A>>");
    enQueue(LQ, 'A');
    printLQ(LQ);
    printf("\n 삽입 B>>");
    enQueue(LQ, 'B');
    printLQ(LQ);
    printf("\n 삽입 C>>");
    enQueue(LQ, 'C');
    printLQ(LQ);

    data = peek(LQ);
    printf(" peek item : %c \n", data);

    printf("\n 삭제  >>");
    data = deQueue(LQ);
    printLQ(LQ);
    printf("\t삭제 데이터: %c", data);
    printf("\n 삭제  >>");
    data = deQueue(LQ);
    printLQ(LQ);
    printf("\t삭제 데이터: %c", data);
    printf("\n 삭제  >>");
    data = deQueue(LQ);
    printLQ(LQ);
    printf("\t\t삭제 데이터: %c", data);

    printf("\n 삽입 D>>");
    enQueue(LQ, 'D');
    printLQ(LQ);
    printf("\n 삽입 E>>");
    enQueue(LQ, 'E');
    printLQ(LQ);
}