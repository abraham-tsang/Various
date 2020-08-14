#include <iostream>
#include <vector>
#include <utility>
#include <climits>

std::vector<std::vector<std::pair<int, int>>> graph;

void addEdge(int u, int v, int weight){
    graph[u].push_back(std::make_pair(v, weight));
}

int main(){

    int v = 5;
    int e = 8;
    std::vector<std::pair<int, int>> temp;
    for(int i = 0; i < v; i++){
	graph.push_back(temp);
    }

    addEdge(0, 1, -5);
    addEdge(0, 2, 2);
    addEdge(0, 3, 3);
    addEdge(1, 2, 4);
    addEdge(2, 3, 1);
    addEdge(4, 0, 0);
    addEdge(4, 1, 0);
    addEdge(4, 2, 0);
    addEdge(4, 3, 0);

    int dist[v];
    for(int i = 0; i < v; i++){
	dist[i] = INT_MAX;
    }
    dist[v - 1] = 0;

    for(int i = 0; i < v - 1; i++){
	for(int j = 0; j < graph.size(); j++){
	    for(int k = 0; k < graph[j].size(); k++){
		int u = j;
		int v = graph[j][k].first;
		int weight = graph[j][k].second;
		if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
		    dist[v] = dist[u] + weight;
		}
	    }
	}
    }

    for(int i = 0; i < graph.size(); i++){
	for(int j = 0; j < graph[i].size(); j++){
	    int u = i;
	    int v = graph[i][j].first;
	    int weight = graph[i][j].second;
	    if(dist[u] != INT_MAX && dist[v] > dist[u] + weight){
		std::cout << "Graph contains negative weight cycle";
	    }
	}
    }

    for(int i = 0; i < graph.size(); i++){
	for(int j = 0; j < graph[i].size(); j++){
	    int u = i;
	    int v = graph[i][j].first;
	    int weight = graph[i][j].second;
	    graph[i][j].second = weight + dist[u] - dist[v];
	}
    }

    graph.erase(graph.begin() + v - 1);
    v--;
    std::vector<std::vector<int>> distance;
    std::vector<int> temp2;
    std::vector<bool> sptSet;
    for(int i = 0; i < v; i++){
	distance.push_back(temp2);
	sptSet.push_back(false);
    }

    for(int i = 0; i < graph.size(); i++){
	for(int j = 0; j < v; j++){
            distance[i].push_back(INT_MAX);
	    sptSet[j] = false;
	}
	distance[i][i] = 0;
	for(int j = 0; j < v - 1; j++){
	    int min = INT_MAX;
	    int u;
	    for(int k = 0; k < v; k++){
		if(sptSet[k] == false && distance[i][j] <= min){
		    min = distance[i][j];
		    u = j;
		}
	    }
	    sptSet[u] = true;

	    for(int k = 0; k < v; k++){
		for(int l = 0; l < k; l++){
		    if(!sptSet[k] && graph[u][l].first == k && distance[i][u] != INT_MAX && distance[i][u] + graph[u][l].second < distance[i][k]){
			distance[i][k] = distance[i][u] + graph[u][l].second;
		    }
		}
	    }
	}
    }
    
    for(int i = 0; i < v; i++){
	for(int j = 0; j < distance[i].size(); j++){
	    std::cout << i << " " << j << " " << distance[i][j] << std::endl;
	}
    }

}
