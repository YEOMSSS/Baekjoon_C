#include <stdio.h>
#include <stdlib.h>

// 이진 탐색 트리 element의 자료형을 char로 정의
typedef char element;

// 트리의 노드 구조체 만들기
typedef struct treeNode
{
    char key;               // 데이터 필드
    struct treeNode *left;  // 왼쪽 서브 트리 링크 필드
    struct treeNode *right; // 오른쪽 서브 트리 링크 필드
} treeNode;

void inorder(treeNode *root);                 // 이진 탐색 트리를 중위 순회하면서 출력하는 연산 = inorder
treeNode *insertNode(treeNode *p, element x); // 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
void deleteNode(treeNode *root, element key); // 트리를 탐색하여 key 노드를 삭제하는 연산
treeNode *searchBST(treeNode *root, char x);  // 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산

// 메뉴판
void menu()
{
    printf("\n*---------------------------*");
    printf("\n\t1 : 트리 출력");
    printf("\n\t2 : 문자 삽입");
    printf("\n\t3 : 문자 삭제");
    printf("\n\t4 : 문자 검색");
    printf("\n\t5 : 종료");
    printf("\n*---------------------------*");
    printf("\n메뉴입력 >> ");
}

int main(void)
{
    treeNode *root = NULL;
    treeNode *foundedNode = NULL;
    char choice, key;

    // 노드 G를 루트 노드 포인터 root로 지정
    root = insertNode(root, 'G');
    insertNode(root, 'I');
    insertNode(root, 'H');
    insertNode(root, 'D');
    insertNode(root, 'B');
    insertNode(root, 'M');
    insertNode(root, 'N');
    insertNode(root, 'A');
    insertNode(root, 'J');
    insertNode(root, 'E');
    insertNode(root, 'Q');

    while (1)
    {
        menu();
        scanf(" %c", &choice);

        // 입력된 char를 정수타입으로 변환
        switch (choice - '0')
        {
        case 1:
            printf("\t[이진 트리 출력]  ");
            inorder(root);
            printf("\n");
            break;

        case 2:
            printf("삽입할 문자를 입력하세요 : ");
            scanf(" %c", &key);
            insertNode(root, key);
            break;

        case 3:
            printf("삭제할 문자를 입력하세요 : ");
            scanf(" %c", &key);
            deleteNode(root, key);
            break;

        case 4:
            printf("찾을 문자를 입력하세요 : ");
            scanf(" %c", &key);
            foundedNode = searchBST(root, key);
            if (foundedNode != NULL)
                printf("\n %c를 찾았습니다! \n", foundedNode->key);
            else
                printf("\n 문자를 찾지 못했습니다. \n");
            break;

        case 5:
            return 0;

        default:
            printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
            break;
        }
    }
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산 = inorder
void inorder(treeNode *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%c_", root->key);
        inorder(root->right);
    }
}

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode *insertNode(treeNode *p, element x)
{
    treeNode *newNode;

    // 탐색 실패하는 위치에 새 노드를 할당하여 삽입
    if (p == NULL)
    {
        newNode = (treeNode *)malloc(sizeof(treeNode));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // 포인터 p가 가리키는 노드 키 값과 삽입할 키 x를 비교
    // 현재 루트 키값보다 목표 키가 더 작으면 왼쪽 서브트리로 이동(재귀)
    else if (x < p->key)
        p->left = insertNode(p->left, x);

    // 현재 루트 키값보다 목표 키가 더 크면 오른쪽 서브트리로 이동(재귀)
    else if (x > p->key)
        p->right = insertNode(p->right, x);

    // 이미 삽입할 키가 트리에 존재하는 경우
    else // x == p->key
        printf("\n 이미 같은 키가 있습니다! \n");

    return p;
}

// 트리를 탐색하여 key 노드를 삭제하는 연산
void deleteNode(treeNode *root, element key)
{
    treeNode *parent, *p, *succ, *succ_parent;
    treeNode *child;

    parent = NULL; // p에서 parent로 올라갈 수 없기 때문에 parent를 저장해둔다.
    p = root;

    // 1. 삭제할 노드의 위치를 알아야 하므로 트리를 탐색
    // while문이 종료되면 p는 NULL 또는 삭제할 데이터를 가진 노드가 된다.
    while ((p != NULL) && (p->key != key))
    {
        parent = p;
        // 삽입연산에서의 비교와 동일하다.
        // 삭제할 키 key와 현재위치 p의 키를 비교하며 탐색
        if (key < p->key)
            p = p->left;
        else
            p = p->right;
    }

    // 삭제할 노드가 없는 경우
    if (p == NULL)
    {
        printf("\n 찾는 키가 이진 트리에 없습니다!!");
        return; // p == NULL이면 연산종료
    }

    // 이 시점에서 p는 삭제할 데이터를 가진 노드를 가리킨다.
    // 2. 탐색하여 찾은 노드를 삭제

    // (1) 삭제할 노드가 단말 노드인 경우(차수 = 0)
    if (p->left == NULL && p->right == NULL)
    {
        // p가 루트노드가 아닐 때 parent의 링크를 수정
        if (parent != NULL)
        {
            if (parent->left == p)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
            root = NULL;
    }

    // (2) 삭제할 노드가 자식 노드를 한 개 가진 경우(차수 = 1)
    else if (p->left == NULL || p->right == NULL) // 둘다 NULL일때는 이미 (1)에서 털었다.
    {
        // NULL이 아닌 쪽의 서브트리를 끌어올린다.
        // 삭제할 노드 p가 가진 자식을 child에 저장
        if (p->left != NULL)
            child = p->left;
        else
            child = p->right;

        // p가 루트노드가 아닐 때 parent에서 p자리에 그 자식인 child를 넣음
        if (parent != NULL)
        {
            if (parent->left == p)
                parent->left = child;
            else
                parent->right = child;
        }
        // p가 루트노드면 루트가 child가 됨
        else
            root = child;
    }

    // (3) 삭제할 노드가 자식 노드를 두 개 가진 경우 (차수 = 2)
    else
    {
        succ_parent = p; // 후계자 노드의 부모 노드
        succ = p->left;  // 후계자 노드

        // 왼쪽 서브 트리에서 후계자 찾기
        // 왼쪽 서브트리의 오른쪽 링크 따라 계속 이동해서 NULL이 될 때까지 간다.
        while (succ->right != NULL)
        {
            succ_parent = succ;
            succ = succ->right;
        }

        // 후계자 위치에 따라 후계자 부모와 후계자 자식을 이어주기
        // 후계자 노드의 원래 자리를 후계자의 자식 노드에게 물려주기
        // 후계자 노드는 오른쪽이 NULL이므로 왼쪽자식만 자기 자리에 얹으면 된다.
        if (succ_parent->left == succ)      // 왼쪽일 일이 있나? 오른쪽 따라간건데?
            succ_parent->left = succ->left; // 오른쪽으로 한칸도 안갔다면 그럴수있지.
        else
            succ_parent->right = succ->left;

        // 삭제한 노드의 자리를 후계자에게 물려주기
        p->key = succ->key;
        p = succ;
    }
    free(p);
}

// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode *searchBST(treeNode *root, char x)
{
    treeNode *p;
    p = root;
    while (p != NULL)
    {
        if (x < p->key)
            p = p->left;
        else if (x == p->key) // 탐색 성공
            return p;
        else
            p = p->right;
    }
    printf("\n 찾는 키가 없습니다!");
    return p;
}