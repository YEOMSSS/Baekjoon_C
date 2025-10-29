#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 이중 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode
{
    struct ListNode *llink; // 왼쪽 선행 노드에 대한 링크
    char data[4];           // 내 데이터
    struct ListNode *rlink; // 오른쪽 선행 노드에 대한 링크
} listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct
{
    listNode *head;
} linkedList_h;

// 공백 이중 연결 리스트를 생성하는 연산
linkedList_h *createLinkedList_h(void)
{
    linkedList_h *DL; // Double Linked list
    DL = (linkedList_h *)malloc(sizeof(linkedList_h));
    DL->head = NULL;
    return DL;
}

// 이중 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h *DL)
{
    listNode *p;
    printf("DL = (");
    p = DL->head;
    while (p != NULL)
    {
        printf("%s", p->data);
        p = p->rlink;
        if (p != NULL)
            printf(", ");
    }
    printf(") \n");
}

// 이중 연결 리스트 작업 우선 순위

// newNode의 rlink처리
// 기존 노드의 rlink 처리
// newNode의 llink 처리
// 기존 노드의 llink 처리

// pre 뒤에 노드를 삽입하는 연산
void insertNode(linkedList_h *DL, listNode *pre, char *x)
{
    listNode *newNode;
    newNode = (listNode *)malloc(sizeof(listNode));
    strcpy(newNode->data, x); // 데이터x 집어넣은 newNode 생성

    if (DL->head == NULL) // 공백 리스트인 경우
    {
        newNode->rlink = NULL; // 내 왼쪽에 아무도 없으니 내 llink도 NULL
        newNode->llink = NULL; // 내 오른쪽에도 아무도 없으니 내 rlink도 NULL
        DL->head = newNode;    // head는 내 주소
    }
    else
    {
        newNode->rlink = pre->rlink;         // 앞사람 rlink 가져오고 (NULL이었다면 내가 마지막노드가 됨)
        pre->rlink = newNode;                // 앞사람 rlink에 내 주소 주고
        newNode->llink = pre;                // 내 llink는 앞사람 주소고
        if (newNode->rlink != NULL)          // 앞사람에게 받아온 rlink가 NULL이 아니면 내 뒤가 있는거니까
            newNode->rlink->llink = newNode; // 내 뒷사람 llink에 내 주소를 준다.
    }
}

// 이중 연결 리스트에서 old 노드를 삭제하는 연산
void deleteNode(linkedList_h *DL, listNode *old)
{
    // 공벡리스트인 경우 바로 return
    if (DL->head == NULL)
        return;
    // 삭제할 노드가 없을 때
    else if (old == NULL)
        return;
    // 삭제할 노드가 있을 때
    else
    {
        old->llink->rlink = old->rlink; // 내 왼쪽의 rlink에 내 rlink 주기
        old->rlink->llink = old->llink; // 내 오른쪽의 llink에 내 llink 주기
        free(old);                      // 삭제 노드의 메모리 해제
    }
}

// 리스트에서 x 노드를 탐색하는 연산
listNode *searchNode(linkedList_h *DL, char *x)
{
    listNode *temp;
    temp = DL->head;

    while (temp != NULL)
    {
        if (strcmp(temp->data, x) == 0)
            return temp; // temp가 가리키는 데이터가 x면 temp 반환
        else
            temp = temp->rlink; // 오른쪽으로 탐색하면서 이동
    }
    return temp; // 찾지 못했다면 temp가 NULL이 된다.
}

int main(void)
{
    linkedList_h *DL;
    listNode *p;
    DL = createLinkedList_h(); // 공백 리스트 생성
    printf("(1) 이중 연결 리스트 생성하기 ! \n");
    printList(DL);
    getchar();

    printf("(2) 이중 연결 리스트에 [월] 노드 삽입하기! \n");
    insertNode(DL, NULL, "월");
    printList(DL);
    getchar();

    printf("(3) 이중 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
    p = searchNode(DL, "월");
    insertNode(DL, p, "수");
    printList(DL);
    getchar();

    printf("(4) 이중 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
    p = searchNode(DL, "수");
    insertNode(DL, p, "금");
    printList(DL);
    getchar();

    printf("(5) 이중 연결 리스트에서 [수] 노드 삭제하기 ! \n");
    p = searchNode(DL, "수"), deleteNode(DL, p);
    printList(DL);
    getchar();

    return 0;
}