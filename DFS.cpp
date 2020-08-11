#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;

void addEdge(int u, int v){
    graph[u].push_back(v);
}

void DFSUtil(int s){
    std::cout << s << " ";
    visited[s] = true;

    for(int i = 0; i < graph[s].size(); i++){
	if(!visited[graph[s][i]]){
	    DFSUtil(graph[s][i]);
	}
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
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);

    int s = 2;
    for(int i = 0; i < v; i++){
	visited.push_back(false);
    }

    DFSUtil(s);

}
