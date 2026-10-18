#include <stdio.h>
#define gc getchar()
#define MAX 100

int adjMatrix[MAX][MAX];

void resetMatrix(int size){
    for (int i = 0; i <  size; i++){
        for (int j = 0; j < size; j++){
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int source, int dest, int directed, int weight){
    if(adjMatrix[source][dest] != 0){
        return;
    }

    adjMatrix[source][dest] = weight;
    // kalau undirected (bolak balik) dia (int directed) bakal valuenya 0
    if (directed == 0 && adjMatrix[dest][source] == 0){
        adjMatrix[dest][source] = weight;
    }
}

void printMatrix(int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%2d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int isVisited[MAX];

void bfs(int size, int start){
    printf("BFS : ");
    for (int i = 0; i < size; i++){
        isVisited[i]= 0;
    }

    int queue[MAX];
    int left = 0, right = 0;
    queue[right++] = start;

    while(left < right){
        if (isVisited[queue[left]] != 0 ){
            left++;
            continue;
        }
        isVisited[queue[left]] = 1;
        printf("%2d-", queue[left]);

        for (int i = 0; i < size; i++){
            if (adjMatrix[queue[left]][i] != 0 && isVisited[i] == 0){
                queue[right++] = i;
            }
        }
        left++;
    }
    printf("\n");
}

void dfs(int size, int start){
    if(isVisited[start] == 0){
        printf("%d ", start);
        isVisited[start] = 1;
        for(int i = 0; i < size; i++){
            if (adjMatrix[start][i] != 0){
                dfs(size, i);
            }
        }
    }

}

void startDfs(int size, int start){
    printf("DFS : ");
    for(int i = 0; i < size; i++){
        isVisited[i]  = 0;
    }
    dfs(size, start);
    
    printf("\n");
}

int main(){
    int vertex = 5;
    resetMatrix(vertex);
    addEdge(0, 0, 1, 1);
    addEdge(0, 1, 0, 1);
    addEdge(1, 2, 0, 3);
    addEdge(2, 3, 0, 1);
    addEdge(0, 3, 0, 1);
    addEdge(3, 4, 1, 1);
    printMatrix(vertex);
    bfs(vertex, 2);
    startDfs(vertex, 2);



    return 0;
}