#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
void addEdge(int u, int v){

    graph[u].push_back(v);
    if(u != v){
	graph[v].push_back(u);
    }

}

int main(){

    int v = 4;

    std::vector<int> temp;
    for(int i = 0; i < v; i++){
	graph.push_back(temp);
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 3);
    addEdge(2, 1);
    addEdge(3, 2);

    for(int i = 0; i < v; i++){
	std::cout << i << ": " << std::endl;
	for(int j = 0; j < graph[i].size(); j++){
	    std::cout << graph[i][j] << std::endl;
	}
	std::cout << std::endl;
    }

}
