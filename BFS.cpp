#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;

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

    int s = 2;
    
    for(int i = 0; i < v; i++){
	visited.push_back(false);
    }
    
    std::vector<int> queue;
    
    queue.push_back(s);
    visited[s] = true;

    while(!queue.empty()){
	s = queue.front();
	std::cout << s << " ";
	queue.erase(queue.begin());
	for(int i = 0; i < graph[s].size(); i++){
	    if(!visited[graph[s][i]]){
		visited[graph[s][i]] = true;
		queue.push_back(graph[s][i]);
	    }
	}
    }

}
