#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;

void addEdge(int u, int v){
    graph[u].push_back(v);
}

int main(){

    int v = 4;

    std::vector<int> temp;
    for(int i = 0; i < v; i++){
	graph.push_back(temp);
    }
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);

    for(int i = 0; i < v; i++){
	std::cout << i << ": ";
	for(int j = 0; j < graph[i].size(); j++){
	    std::cout << graph[i][j] << " ";
	}
	std::cout << std::endl;
    }

}
