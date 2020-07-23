#include <iostream>
#include <vector>
#include <utility>

std::vector<std::vector<std::pair<int, int>>> graph;

void addEdge(int u, int v, int weight){
    graph[u].push_back(std::make_pair(v, weight));
    graph[v].push_back(std::make_pair(u, weight));
}

int main(){

    int v = 4;
    int s = 2;

    std::vector<std::pair<int, int>> temp;
    for(int i = 0; i < v; i++){
	graph.push_back(temp);
    }

    addEdge(0, 1, 10);
    addEdge(0, 2, 3);
    addEdge(0, 3, 2);
    addEdge(1, 3, 7);
    addEdge(2, 3, 6);

    for(int i = 0; i < v; i++){
	std::cout << i << ": ";
	for(int j = 0; j < graph[i].size(); j++){
	    std::cout << graph[i][j].first << " " << graph[i][j].second << std::endl;
	}
	std::cout << std::endl;
    }

}
