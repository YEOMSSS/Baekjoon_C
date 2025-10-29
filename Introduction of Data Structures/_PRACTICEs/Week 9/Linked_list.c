// 연결 리스트 실습

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode
{
    char data[4];
    struct ListNode *link;
} listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct
{
    listNode *head;
} linkedList_h;

// 1. 공백 리스트 생성

// 공백 연결 리스트를 생성하는 연산
linkedList_h *createLinkedList_h(void)
{
    linkedList_h *L;
    L = (linkedList_h *)malloc(sizeof(linkedList_h)); // linkedList_h 크기 만큼의 메모리를 할당
    L->head = NULL;                                   // 공백 리스트이므로 NULL로 설정.
    return L;                                         // linkedList_h 형식의 포인터로 반환
}

// 2-1. 리스트에 첫 번째 노드로 삽입

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h *L, char *x)
{
    listNode *newNode;                              // listNode형 새 노드 만들기
    newNode = (listNode *)malloc(sizeof(listNode)); // malloc으로 공간 할당하기
    strcpy(newNode->data, x);                       // 데이터 넣은 newNode 준비

    newNode->link = L->head; // 링크 받아오기(NULL임)
    L->head = newNode;       // 헤드한테 내 주소 주기
}

// 2-2. 리스트 중간에 노드를 삽입

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h *L, listNode *pre, char *x)
{
    listNode *newNode;
    newNode = (listNode *)malloc(sizeof(listNode));
    strcpy(newNode->data, x); // 데이터 넣은 newNode 준비

    if (L->head == NULL) // 현재 리스트가 공백인 경우
    {
        newNode->link = NULL; // 마지막원소가 되니까 link는 NULL
        L->head = newNode;    // 헤드한테 내 주소 주기
    }
    else if (pre == NULL) // 삽입 오류 처리
    {
        printf("삽입 오류. 프로그램을 종료합니다.\n");
        exit(1); // 전체 프로그램 즉시 강제 종료.
    }
    else // 리스트 중간에 노드를 삽입
    {
        newNode->link = pre->link; // 링크 받아오기
        pre->link = newNode;       // 내 주소 주기
    }
}

// 2-3. 리스트 마지막에 노드를 삽입

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h *L, char *x)
{
    listNode *newNode;
    listNode *temp; // 임시 포인터 만들어서 삽입할 위치 찾기
    newNode = (listNode *)malloc(sizeof(listNode));
    strcpy(newNode->data, x); // 데이터 넣은 newNode 준비
    newNode->link = NULL;     // 마지막노드가 되니 newNode의 link는 NULL

    if (L->head == NULL) // 현재 리스트가 공백인 경우
    {
        L->head = newNode; // 새 노드를 리스트의 시작 노드로 연결
        return;
    }
    // 현재 리스트가 공백이 아닌 경우
    temp = L->head;            // temp를 L의 head필드로 설정하여 시작에 두고
    while (temp->link != NULL) // 현재 리스트의 마지막 노드를 찾음
        temp = temp->link;     // temp->link가 NULL이 되면 종료, 아니면 다음 노드로 이동
    temp->link = newNode;      // 새 노드를 마지막 노드의 다음 노드로 연결
}

// 3. 노드 삭제

// 리스트에서 노드 p를 삭제하는 연산
void deleteNode(linkedList_h *L, listNode *p)
{
    listNode *pre; // 삭제할 노드의 선행자 노드를 나타낼 포인터

    // 3-1. 공백리스트일 때 (L->head == NULL)
    if (L->head == NULL)
        return; // 공백 리스트라면 삭제 연산 중단

    // 3-2. 리스트에 노드가 한개뿐일때
    if (L->head->link == NULL)
    {
        free(L->head);  // 첫 번째 노드를 메모리에서 해제
        L->head = NULL; // 리스트 시작 포인터를 NULL로 설정
        return;
    }

    // 3-3. 삭제할 노드가 없을 때 (p == NULL)
    else if (p == NULL)
        return; // 삭제할 노드가 없다면 삭제 연산 중단

    // 3-4. else. 즉, 리스트에 노드가 두 개 이상이고 삭제할 노드가 있을 때
    else
    {
        // 삭제할 노드 p의 선행자 노드를 포인터 pre를 이용해 찾음
        pre = L->head;

        if (pre == p)          // p가 첫 노드인 경우
            L->head = p->link; // head가 삭제될 p의 링크를 가리킴
        else
        {
            // pre의 링크가 p를 가리킬 때까지 반복
            while (pre->link != p)
                pre = pre->link;

            pre->link = p->link; // 삭제할 노드 p의 선행자 노드와 다음 노드를 연결
        }
    }
    free(p); // 삭제 노드의 메모리 해제
}

// 4. 노드 탐색

// 리스트에서 x 노드를 탐색하는 연산
listNode *searchNode(linkedList_h *L, char *x)
{
    listNode *temp;
    temp = L->head;
    while (temp != NULL)
    {
        // if (temp->data == x) 문자열 비교에서는 strcmp를 사용해야 한다.
        if (strcmp(temp->data, x) == 0) // strcmp의 반환값이 0이면 일치
            return temp;                // 찾았다면 해당 노드를 가리키는 포인터 temp 반환
        else
            temp = temp->link; // 일치하지 않으면 이동
    }
    // 탐색에 실패한 경우 temp는 반복이 끝나고 NULL에 도달해 있다.
    return temp; // NULL이 반환됨
}

// 5. 리스트 출력 및 메모리 해제

// 연결 리스트의 전체 메모리를 해제하는 연산
// 계속 리스트 주소 타고 넘어가며 메모리 해제
void freeLinkedList_h(linkedList_h *L)
{
    listNode *p;
    // 맨 앞부터 한칸씩 free하고 head가 다음노드로 바뀌는 형식
    while (L->head != NULL)
    {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

// 연결 리스트를 순서대로 출력하는 연산
// 계속 리스트 주소 타고 넘어가며 출력
void printList(linkedList_h *L)
{
    listNode *p;
    printf("L = (");
    p = L->head;
    while (p != NULL)
    {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL)
            printf(", ");
    }
    printf(")\n");
}

// main 코드

int main(void)
{
    // 여기에 이것저것 넣어서 사용하면 된다.
    linkedList_h *L;
    listNode *p;
    L = createLinkedList_h(); // 공백리스트 생성
    printf("(1) 리스트에 [월], [수], [일] 노드 삽입하기! \n");
    insertLastNode(L, "월");
    insertLastNode(L, "수");
    insertLastNode(L, "일");
    printList(L);
    getchar(); // 일시정지 용도로 사용. 엔터를 누르면 다음으로 넘어감

    printf("(2) 리스트에서 [수] 노드 탐색하기! \n");
    p = searchNode(L, "수");
    if (p == NULL)
        printf("찾는 데이터가 없습니다\n");
    else
        printf("[%s]를 찾았습니다 \n", p->data);
    getchar();

    printf("(3) 리스트에서 [수] 뒤에 [금] 노드 삽입하기! \n");
    insertMiddleNode(L, p, "금");
    printList(L);
    getchar();

    printf("(4) 리스트에서 [일] 노드 삭제하기! \n");
    p = searchNode(L, "일"); // 삭제할 노드 위치 p를 찾음
    deleteNode(L, p);        // 포인터 p 노드 삭제
    printList(L);

    freeLinkedList_h(L);

    return 0;
}
