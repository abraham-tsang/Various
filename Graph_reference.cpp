#include <iostream>
#include <vector>

int main(){

    std::vector<std::vector<int>> graph;
    int v = 4;
    int s = 2;

    std::vector<int> temp;
    for(int i = 0; i < v; i++){
	graph.push_back(temp);
    }
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);

    for(int i = 0; i < v; i++){
	std::cout << i << ": ";
	for(int j = 0; j < graph[i].size(); j++){
	    std::cout << graph[i][j] << " ";
	}
	std::cout << std::endl;
    }

}
