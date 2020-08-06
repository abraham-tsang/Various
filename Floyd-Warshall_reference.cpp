#include <iostream>
#include <vector>
#include <utility>

std::vector<std::vector<std::pair<int, int>>> graph;

void addEdge(int u, int v, int weight){
    graph[u].push_back(std::make_pair(v, weight));
}

int main(){

    int v = 4;
    int INF = 99999;

    std::vector<std::pair<int, int>> temp;
    for(int i = 0; i < v; i++){
	graph.push_back(temp);
    }

    addEdge(0, 0, 0);
    addEdge(0, 1, 5);
    addEdge(0, 2, INF);
    addEdge(0, 3, 10);
    addEdge(1, 0, INF);
    addEdge(1, 1, 0);
    addEdge(1, 2, 3);
    addEdge(1, 3, INF);
    addEdge(2, 0, INF);
    addEdge(2, 1, INF);
    addEdge(2, 2, 0);
    addEdge(2, 3, 1);
    addEdge(3, 0, INF);
    addEdge(3, 1, INF);
    addEdge(3, 2, INF);
    addEdge(3, 3, 0);

    std::vector<std::vector<std::pair<int, int>>> dist = graph;

    for(int k = 0; k < v; k++){
        for(int i = 0; i < v; i++){
	    for(int j = 0; j < dist[i].size(); j++){
	        if(dist[i][k].second + dist[k][j].second < dist[i][j].second){
		    dist[i][j].second = dist[i][k].second + dist[k][j].second;
		}
	    }
	}
    }

    for(int i = 0; i < v; i++){
	for(int j = 0; j < dist[i].size(); j++){
	    std::cout << dist[i][j].second << " ";
	}
	std::cout << std::endl;
    }

}
