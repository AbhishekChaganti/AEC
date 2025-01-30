#include <stdio.h>
#include <stdlib.h>

int comparator(const void* p1, const void* p2) 
{ 
    const int (*x)[3] = (const int (*)[3])p1; 
    const int (*y)[3] = (const int (*)[3])p2; 
    return (*x)[2] - (*y)[2]; 
}

void makeSet(int parent[], int rank[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        parent[i] = i; 
        rank[i] = 0; 
    }
}

int findParent(int parent[], int component) 
{ 
    if (parent[component] != component) {
        parent[component] = findParent(parent, parent[component]);
    }
    return parent[component];
}

void unionSet(int u, int v, int parent[], int rank[]) 
{ 
    if (rank[u] < rank[v]) { 
        parent[u] = v; 
    } else if (rank[u] > rank[v]) { 
        parent[v] = u; 
    } else { 
        parent[v] = u; 
        rank[u]++;
    }
}

void kruskalAlgo(int n, int (*edge)[3]) 
{ 
    qsort(edge, n, sizeof(edge[0]), comparator); 

    int parent[n]; 
    int rank[n]; 
    makeSet(parent, rank, n); 

    int minCost = 0; 

    printf("Following are the edges in the constructed MST:\n"); 

    for (int i = 0; i < n; i++) { 
        int v1 = findParent(parent, edge[i][0]); 
        int v2 = findParent(parent, edge[i][1]); 

        if (v1 != v2) {                               
            unionSet(v1, v2, parent, rank);                               
            minCost += edge[i][2];
            printf("%d -- %d == %d\n", edge[i][0], edge[i][1], edge[i][2]); 
        } 
    } 

    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

int main() 
{ 
    int edge[5][3] = { { 0, 1, 10 }, 
                       { 0, 2, 6 }, 
                       { 0, 3, 5 }, 
                       { 1, 3, 15 }, 
                       { 2, 3, 4 } }; 

    kruskalAlgo(5, edge); 

    return 0;
}


OUTPUT:

Enter no. of vertices:5

Enter the adjacency matrix:
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0

Enter the starting node:0

Distance of node1=10
Path=1<-0
Distance of node2=50
Path=2<-3<-0
Distance of node3=30
Path=3<-0
Distance of node4=60
Path=4<-2<-3<-0
