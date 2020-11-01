#include <iostream>
#include <vector>
#include <utility>

std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<std::vector<std::pair<int, int>>> mst;
std::vector<bool> visited;
std::vector<bool> recStack;
int v = 4;

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

bool DFSUtil(int u){
    if(!visited[u]){
	visited[u] = true;
	recStack[u] = true;
	for(int i = 0; i < mst[u].size(); i++){
		std::cout << mst[u][i].second << std::endl;
	    if(!visited[mst[u][i].first] && DFSUtil(mst[u][i].first)){
	        return true;
	    }
	    else if(recStack[mst[u][i].first]){
	        return true;
	    }
        }
    }
    recStack[u] = false;
    return false;

}
bool cycleFormed(){

    for(int i = 0; i < v; i++){
	if(DFSUtil(i)){
            return true;
	}
    }
    return false;
}


void includeEdge(std::pair<int, std::pair<int, int>> edge){
    mst[edge.first].push_back(std::make_pair(edge.second.first, edge.second.second));
}

void deleteEdge(int which, std::pair<int, std::pair<int, int>> edge){

    if(which == 0){
	for(int i = 0; i < graph[edge.first].size(); i++){
	    if(graph[edge.first][i].first == edge.second.first){
	        graph[edge.first].erase(graph[edge.first].begin() + i);
	    }
        }
    }
    else{
        for(int i = 0; i < mst[edge.first].size(); i++){
	    if(mst[edge.first][i].first == edge.second.first){
	        mst[edge.first].erase(mst[edge.first].begin() + i);
	    }
        }
    }
}

int main(){

    std::vector<std::pair<int, int>> temp;
    for(int i = 0; i < v; i++){
	graph.push_back(temp);
    }

    addEdge(0, 1, 10);
    addEdge(0, 2, 6);
    addEdge(3, 0, 5);
    addEdge(1, 3, 15);
    addEdge(2, 3, 4);
    
    for(int i = 0; i < v; i++){
	visited.push_back(false);
	recStack.push_back(false);
    }
    
    for(int i = 0; i < v; i++){
	mst.push_back(temp);
    }

    int it = 0;
    
    while(it != v - 1){
	std::pair<int, std::pair<int, int>> edge = findSmallestEdge();
	includeEdge(edge);
	if(!cycleFormed()){
	    it++;
	}
	else{
	    deleteEdge(1, edge);
	}
	deleteEdge(0, edge);
    }

    for(int i = 0; i < v; i++){
	for(int j = 0; j < mst[i].size(); j++){
	    std::cout << i << " " << mst[i][j].first << " " << mst[i][j].second << std::endl;
	}
	std::cout << std::endl;
    }

}
