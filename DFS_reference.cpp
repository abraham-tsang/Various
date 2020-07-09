#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;

void DFSUtil(int s, bool visited[]){

    visited[s] = true;
    std::cout << s << " ";

    for(int i = 0; i < graph[s].size(); i++){
	if(!visited[graph[s][i]]){
            DFSUtil(graph[s][i], visited);
	}
    }

}

int main(){

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

    bool * visited = new bool[v];
    for(int i = 0; i < v; i++){
	visited[i] = false;
    }

    DFSUtil(s, visited);

}
