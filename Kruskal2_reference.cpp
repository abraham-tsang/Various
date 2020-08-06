#include <iostream>
#include <vector>
#include <utility>

std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<std::vector<std::pair<int, int>>> mst;

void addEdge(int u, int v, int weight){
    graph[u].push_back(std::make_pair(v, weight));
}

std::pair<int, std::pair<int, int>> findSmallestEdge(){

    int u, v, min = 99999;
    for(int i = 0; i < v; i++){
	for(int j = 0; j < graph[i].size(); j++){
	    if(graph[i][j].second < min){
		min = graph[i][j].second;
		u = i;
		v = graph[i][j].first;
	    }
	}
    }

    return std::make_pair(u, std::make_pair(v, min));
}

bool cycleFormed(std::pair<int, std::pair<int, int>> edge){

    std::vector<bool> visited;
    for(int i = 0; i < v; i++){
	visited.push_back(false);
    }

    return DFSUtil(edge.first, visited);
}

bool DFSUtil(int v, std::vector<bool> visited){
    visited[v] = true;
    for(int i = 0; i < mst[i].size(); i++){
	if(!visited[mst[i].first]){
            s
	}
    }

}

void includeEdge(std::pair<int, std::pair<int, int>> edge){
    mst[edge.first].push_back(std::make_pair(edge.second.first, edge.second.second));
}

void deleteEdge(std::pair<int, std::pair<int, int>> edge){
    
}

int main(){

    int v = 4;
    int e = 5;

    std::vector<std::pair<int, int>> temp;
    for(int i = 0; i < v; i++){
	graph.push_back(temp);
    }

    addEdge(0, 1, 10);
    addEdge(0, 2, 6);
    addEdge(0, 3, 5);
    addEdge(1, 3, 15);
    addEdge(2, 3, 4);

    for(int i = 0; i < v; i++){
	mst.push_back(temp);
    }

    int it = 0;
    while(it != v - 1){
	std::pair<int, std::pair<int, int>> edge = findSmallestEdge();
	if(!cycleFormed(edge)){
	    includeEdge(edge);
	    it++;
	}
	deleteEdge(edge);
    }

    for(int i = 0; i < v; i++){
	for(int j = 0; j < mst[i].size(); j++){
	    std::cout << mst[i][j] << " ";
	}
	std::cout << std::endl;
    }

}
