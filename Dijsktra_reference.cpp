#include <iostream>
#include <limits.h>

int main(){

    int v = 9;
    int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
	               {4, 0, 8, 0, 0, 0, 0, 11, 0},
	               {0, 8, 0, 7, 0, 4, 0, 0, 2},
	               {0, 0, 7, 0, 9, 14, 0, 0, 0},
	               {0, 0, 0, 9, 0, 10, 0, 0, 0},
	               {0, 0, 4, 14, 10, 0, 2, 0, 0},
	               {0, 0, 0, 0, 0, 2, 0, 1, 6},
	               {8, 11, 0, 0, 0, 0, 1, 0, 7},
	               {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    int dist[v];

    bool sptSet[v];

    for(int i = 0; i < v; i++){
	dist[i] = INT_MAX;
	sptSet[i] = false;
    }

    dist[0] = 0;

    for(int i = 0; i < v - 1; i++){
	int min = INT_MAX;
	int u;
	for(int j = 0; j < v; j++){
	    if(sptSet[j] == false && dist[j] <= min){
		min = dist[j];
		u = j;
	    }
        }

	sptSet[u] = true;

	for(int j = 0; j < v; j++){
	    if(!sptSet[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]){
		dist[j] = dist[u] + graph[u][j];
	    }
	}
    }

    for(int i = 0; i < v; i++){
	std::cout << i << " " << dist[i] << std::endl;
    }

}
