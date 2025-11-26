#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 트리의 노드 구조체 만들기
typedef struct treeNode
{
    char key;               // 데이터 필드
    struct treeNode *left;  // 왼쪽 서브 트리 링크 필드
    struct treeNode *right; // 오른쪽 서브 트리 링크 필드
} treeNode;

void displayInorder(treeNode *root);          // 조건에 맞는 키값만 오름차순으로 출력
treeNode *insertNode(treeNode *p, element x); // BST에 노드 x 삽입
void freeBST(treeNode *root);                 // 후위 순회로 메모리 반환

int X, Y;
int check_dup = 0;  // 중복 체크용 스위치
int check_None = 1; // None 확인용 스위치

int main(void)
{
    treeNode *root = NULL;
    element key;

    int N;
    scanf("%d %d %d", &N, &X, &Y);
    if (X >= Y)
    {
        printf("X가 Y보다 크거나 같으므로, 조건에 부합하지 않습니다.");
        exit(1); // 비정상 종료
    }

    scanf("%d", &key);
    root = insertNode(root, key);
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &key);
        insertNode(root, key);
    }

    // 조건 만족 키값이 없을 시 None 출력 후 정상종료
    if (check_None)
    {
        printf("None\n");
        freeBST(root);
        return 0;
    }

    // 중복입력 확인시 메시지 출력
    if (check_dup)
        printf("중복 숫자가 존재합니다.\n");

    // 조건 범위 내 키값 오름차순 출력
    displayInorder(root);

    // 메모리 반환
    freeBST(root);
    return 0;
}

void displayInorder(treeNode *root)
{
    if (root)
    {
        displayInorder(root->left);

        // key가 Y보다 커지는 순간 display 종료
        if (root->key > Y)
            return;
        // key가 X보다 크다면 출력
        if (root->key > X)
        {
            printf("%d ", root->key);
        }

        displayInorder(root->right);
    }
}

treeNode *insertNode(treeNode *p, element x)
{
    treeNode *newNode;

    if (p == NULL)
    {
        newNode = (treeNode *)malloc(sizeof(treeNode));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    else if (x < p->key)
        p->left = insertNode(p->left, x);

    else if (x > p->key)
        p->right = insertNode(p->right, x);

    // 중복체크
    else // x == p->key
        check_dup = 1;

    // None체크
    if (check_None && X < x && x < Y)
        check_None = 0;

    return p;
}

void freeBST(treeNode *root)
{
    // 후위 순회로 반환
    if (root)
    {
        freeBST(root->left);
        freeBST(root->right);
        // printf("%d ", root->key);
        free(root);
    }
    return;
}
