#include <stdio.h>

#define V 4
#define INF 99999

void printSolution(int dist[V][V]);

void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int i,k,j;
    // Inisialisasi jarak awal dari graph
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Iterasi melalui setiap simpul sebagai simpul perantara
    for (k = 0; k < V; k++) {
        for ( i = 0; i < V; i++) {
            for ( j = 0; j < V; j++) {
                // Update jika lewat simpul k lebih pendek
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Cetak hasil akhir
    printSolution(dist);
}

void printSolution(int dist[V][V]) {
	int i,j;
    printf("Matriks jarak terpendek antar simpul:\n");
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Representasi graf: 0 menunjukkan jarak ke dirinya sendiri, INF jika tidak ada jalur langsung
    int graph[V][V] = { 
        {0,   3,   INF, 7},
	    {3,   0,   2,   INF},
	    {INF, 2,   0,   1},
	    {7,   INF, 1,   0}
    };

    floydWarshall(graph);
    return 0;
}
