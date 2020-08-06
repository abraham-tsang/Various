#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
void addEdge(int u, int v){
    graph[u].push_back(v);
}

int main(){

    int v = 4;
    int s = 2;

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

    bool * visited  = new bool[v];
    for(int i = 0; i < v; i++){
	visited[i] = false;
    }

    std::vector<int> queue;
    visited[s] = true;
    queue.push_back(s);

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
