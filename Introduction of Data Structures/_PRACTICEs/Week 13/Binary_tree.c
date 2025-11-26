#include <stdio.h>
#include <stdlib.h>

// 트리의 노드 구조체 만들기
typedef struct treeNode
{
    char data;
    struct treeNode *left;  // 왼쪽 자식 노드
    struct treeNode *right; // 오른쪽 자식 노드
} treeNode;

void preorder(treeNode *root);  // 이진 트리에 대한 전위 순회 연산
void inorder(treeNode *root);   // 이진 트리에 대한 중위 순회 연산
void postorder(treeNode *root); // 이진 트리에 대한 후위 순회 연산

// data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNode *makeRootNode(char data, treeNode *leftNode, treeNode *rightNode);

int main(void)
{
    // 수식 (A*B-C/D) 를 이진 트리로 만들기
    // 잎노드부터 털어주면 편하다.
    treeNode *n7 = makeRootNode('D', NULL, NULL);
    treeNode *n6 = makeRootNode('C', NULL, NULL);
    treeNode *n5 = makeRootNode('B', NULL, NULL);
    treeNode *n4 = makeRootNode('A', NULL, NULL);
    treeNode *n3 = makeRootNode('/', n6, n7);
    treeNode *n2 = makeRootNode('*', n4, n5);
    treeNode *n1 = makeRootNode('-', n2, n3);

    printf("\n preorder : ");
    preorder(n1);

    printf("\n inorder : ");
    inorder(n1);

    printf("\n postorder : ");
    postorder(n1);

    // 포인터 이용한 동적할당은 반드시 먼저 메모리 할당(malloc), 마지막에 메모리 해제해야함(free).
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);

    return 0;
}

// 이진 트리에 대한 전위 순회 연산
void preorder(treeNode *root)
{
    if (root)
    {
        // Root - Left - Right
        printf("%c", root->data); // 1. 현재 노드 출력
        preorder(root->left);     // 2. 왼쪽 서브트리로 이동
        preorder(root->right);    // 3. 오른쪽 서브트리로 이동
    }
    return;
}

// 이진 트리에 대한 중위 순회 연산
void inorder(treeNode *root)
{
    if (root)
    {
        // Left - Root - Right
        inorder(root->left);      // 1. 왼쪽 서브트리로 이동
        printf("%c", root->data); // 2. 현재 노드 출력
        inorder(root->right);     // 3. 오른쪽 서브트리로 이동
    }
    return;
}

// 이진 트리에 대한 후위 순회 연산
void postorder(treeNode *root)
{
    if (root)
    {
        // Left - Right - Root
        postorder(root->left);    // 1. 왼쪽 서브트리로 이동
        postorder(root->right);   // 2. 오른쪽 서브트리로 이동
        printf("%c", root->data); // 3. 현재 노드 출력
    }
    return;
}

// data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNode *makeRootNode(char data, treeNode *leftNode, treeNode *rightNode)
{
    // 1. 노드 메모리 할당
    treeNode *root = (treeNode *)malloc(sizeof(treeNode));
    // 2. 데이터 필드 처리
    root->data = data;
    root->left = leftNode;
    root->right = rightNode;
    // 3. 반환
    return root;
}
