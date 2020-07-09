#include <iostream>
#include <limits.h>

int main(){

    int v = 5;
    int graph[v][v] = {{0, 2, 0, 6, 0},
	               {2, 0, 3, 8, 5},
	               {0, 3, 0, 0, 7},
	               {6, 8, 0, 0, 9},
	               {0, 5, 7, 9, 0}};

    int parent[v];

    int key[v];

    bool mstSet[v];

    for(int i = 0; i < v; i++){
	key[i] = INT_MAX;
	mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < v - 1; i++){
	    
        int min = INT_MAX;
        int u;
        for(int j = 0; j < v; j++){
            if(mstSet[j] == false && key[j] < min){
	        min = key[j];
	        u = j;
	    }
	}

        mstSet[u] = true;

	for(int j = 0; j < v; j++){
	    if(graph[u][j] && mstSet[j] == false && graph[u][j] < key[j]){
		parent[j] = u;
	        key[j] = graph[u][j];
	    }
	}
    }

    for(int i = 1; i < v; i++){
	std::cout << parent[i] << "-" << i << " " << graph[i][parent[i]] << std::endl;
    }
}
