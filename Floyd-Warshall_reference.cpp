#include <iostream>

int main(){

    int v = 4;
    int INF = 99999;

    int graph[v][v] = {{0, 5, INF, 10},
	               {INF, 0, 3, INF},
	               {INF, INF, 0, 1},
	               {INF, INF, INF, 0}};

    int dist[v][v];

    for(int i = 0; i < v; i++){
	for(int j = 0; j < v; j++){
	    dist[i][j] = graph[i][j];
	}
    }

    for(int k = 0; k < v; k++){
	for(int i = 0; i < v; i++){
	    for(int j = 0; j < v; j++){
		if(dist[i][k] + dist[k][j] < dist[i][j]){
		    dist[i][j] = dist[i][k] + dist[k][j];
		}
	    }
	}
    }

    for(int i = 0; i < v; i++){
	for(int j = 0; j < v; j++){
	    if(dist[i][j] == INF){
		std::cout << "INF ";
	    }
	    else{
		std::cout << dist[i][j] << " ";
	    }
        }
	std::cout << std::endl;
    }

}
