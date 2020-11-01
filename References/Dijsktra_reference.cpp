#include <iostream>
#include <vector>
#include <climits>

std::vector<std::vector<std::pair<int, int>>> graph;

void addEdge(int u, int v, int weight){

    graph[u].push_back(std::make_pair(v, weight));
    graph[v].push_back(std::make_pair(u, weight));

}

int main(){

    int v = 9;
    std::vector<std::pair<int, int>> temp;
    for(int i = 0; i < v; i++){
	graph.push_back(temp);
    }

    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 5, 4);
    addEdge(2, 8, 2);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);

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
	    for(int k = 0; k < j; k++){
	        if(!sptSet[j] && graph[u][k].first == j && dist[u] != INT_MAX && dist[u] + graph[u][k].second < dist[j]){
		    dist[j] = dist[u] + graph[u][k].second;
	        }
	    }
	}
    }

    for(int i = 0; i < v; i++){
	std::cout << i << " " << dist[i] << std::endl;
    }

}
