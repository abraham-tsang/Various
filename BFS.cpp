#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;
std::vector<int> queue;

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
	visited.push_back(false);
    }

    int current = 2;
    visited[current] = true;
    queue.push_back(current);
    
    while(!queue.empty()){
        current = queue[0];
	std::cout << current << " ";
	queue.erase(queue.begin());

	for(int i = 0; i < graph[current].size(); i++){
	    if(!visited[graph[current][i]]){
		visited[graph[current][i]] = true;
		queue.push_back(graph[current][i]);
	    }
	}
    }
}
