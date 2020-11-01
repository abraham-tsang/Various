#include <iostream>
#include <vector>
#include <utility>
#include <climits>

std::vector<std::vector<std::pair<int, int>>> graph;

void addEdge(int u, int v, int weight){

    graph[u].push_back(std::make_pair(v, weight));
    if(u != v){
        graph[v].push_back(std::make_pair(u, weight));
    }

}

int main(){

    int v = 5;

    std::vector<std::pair<int, int>> temp;
    for(int i = 0; i < v; i++){
	graph.push_back(temp);
    }

    addEdge(0, 0, 0);
    addEdge(0, 1, 2);
    addEdge(0, 2, 0);
    addEdge(0, 3, 6);
    addEdge(0, 4, 0);
    addEdge(1, 1, 0);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 2, 0);
    addEdge(2, 3, 0);
    addEdge(2, 4, 7);
    addEdge(3, 3, 0);
    addEdge(3, 4, 9);
    addEdge(4, 4, 0);

    int parent[v];
    int key[v];
    int mstSet[v];

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
	    for(int k = 0; k < v; k++){
	        if(graph[u][k].first == j && graph[u][k].second && mstSet[j] == false && graph[u][k].second < key[j]){
		    parent[j] = u;
		    key[j] = graph[u][k].second;
	        }
	    }
	}
    }

    for(int i = 1; i < v; i++){
	std::cout << parent[i] << "-" << i << " " << graph[i][parent[i]].second << std::endl;
    }

    /*for(int i = 0; i < v; i++){
	for(int j = 0; j < v; j++){
	    std::cout << graph[i][j].second << " ";
	}
	std::cout << std::endl;
    }*/

}
