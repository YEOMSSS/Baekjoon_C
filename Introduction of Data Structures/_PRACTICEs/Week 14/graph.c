#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

// 그래프를 인접 행렬로 표현하기 위한 구조체 정의
typedef struct graphType
{
    int n;                                 // 그래프의 정점 개수
    int adjMatrix[MAX_VERTEX][MAX_VERTEX]; // 그래프에 대한 30x30의 2차원 배열
} graphType;

// 공백 그래프를 생성하는 연산
void createGraph(graphType *g)
{
    g->n = 0; // 정점개수를 0으로 초기화
    for (int i = 0; i < MAX_VERTEX; i++)
    {
        for (int j = 0; j < MAX_VERTEX; j++)
            g->adjMatrix[i][j] = 0; // 그래프 g에 대한 2차원 배열의 값을 0으로 초기화
    }
}

// 그래프 g에 정점 v를 삽입하는 연산
// 그냥 오름차순으로 0부터 정점을 하나 추가하는 연산같은데.
// 정점이 무조건 오름차순으로 들어온다는 가정에 따른다.
void insertVertex(graphType *g, int v)
{
    // 이게 있어야 할 것 같은데.
    if (v >= MAX_VERTEX)
    {
        exit(1);
    }

    // if (((g->n) + 1) > MAX_VERTEX)
    if (g->n == MAX_VERTEX)
    {
        printf("\n 그래프 정점의 개수를 초과하였습니다!");
        return;
    }
    g->n++; // 그래프 정점의 개수 n을 하나 증가
}

// 그래프 g에 간선 (u, v)를 삽입하는 연산
void insertEdge(graphType *g, int u, int v)
{
    // 간선 (u, v)를 삽입하기 위해 정점 u와 v가 그래프에 존재하는지 확인

    // 1. 정점이 존재하는지 확인

    // ex) 정점 0만 삽입한 경우, g->n은 1.
    // 이때 u랑 v가 1과 2라면, u >= g->n이고 v >= g->n이라 u,v는 그래프에 없는 정점임
    if (u >= g->n || v >= g->n)
    {
        printf("\n 그래프에 없는 정점입니다!");
        return;
    }

    // 삽입한 간선에 대한 2차원 배열의 원소 값을 1로 설정
    g->adjMatrix[u][v] = 1;
}

// 그래프 g의 2차원 배열 값을 순서대로 출력하는 연산
void print_adjMatrix(graphType *g)
{
    int i, j;
    for (i = 0; i < (g->n); i++)
    {
        printf("\n\t\t");
        for (j = 0; j < (g->n); j++)
            printf("%2d", g->adjMatrix[i][j]);
    }
}

int main(void)
{
    int i;
    graphType *G1, *G2, *G3, *G4;
    G1 = (graphType *)malloc(sizeof(graphType));
    G2 = (graphType *)malloc(sizeof(graphType));
    G3 = (graphType *)malloc(sizeof(graphType));
    G4 = (graphType *)malloc(sizeof(graphType));
    createGraph(G1);
    createGraph(G2);
    createGraph(G3);
    createGraph(G4);

    // 그래프 G1
    for (i = 0; i < 4; i++)
        insertVertex(G1, i); // G1의 정점 0~3 삽입

    insertEdge(G1, 0, 1);
    insertEdge(G1, 0, 3);

    insertEdge(G1, 1, 0);
    insertEdge(G1, 1, 2);
    insertEdge(G1, 1, 3);

    insertEdge(G1, 2, 1);
    insertEdge(G1, 2, 3);

    insertEdge(G1, 3, 0);
    insertEdge(G1, 3, 1);
    insertEdge(G1, 3, 2);

    printf("\n G1의 인접 행렬");
    print_adjMatrix(G1);

    /*
    // 그래프 G2
    for (i = 0; i < 3; i++)
        insertVertex(G2, i); // G2의 정점 0~2 삽입

    insertEdge(G2, 0, 1);
    insertEdge(G2, 0, 2);

    insertEdge(G2, 1, 0);
    insertEdge(G2, 1, 2);

    insertEdge(G2, 2, 0);
    insertEdge(G2, 2, 1);

    printf("\n\n G2의 인접 행렬");
    print_adjMatrix(G2);

    // 그래프 G3
    for (i = 0; i < 4; i++)
        insertVertex(G3, i); // G3의 정점 0~3 삽입

    insertEdge(G3, 0, 1);
    insertEdge(G3, 0, 3);

    insertEdge(G3, 1, 2);
    insertEdge(G3, 1, 3);

    insertEdge(G3, 2, 3);

    printf("\n\n G3의 인접 행렬");
    print_adjMatrix(G3);

    // 그래프 G4
    for (i = 0; i < 3; i++)
        insertVertex(G4, i); // G4의 정점 0~2 삽입

    insertEdge(G4, 0, 1);
    insertEdge(G4, 0, 2);

    insertEdge(G4, 1, 0);
    insertEdge(G4, 1, 2);

    printf("\n\n G4의 인접 행렬");
    print_adjMatrix(G4);
    */
}