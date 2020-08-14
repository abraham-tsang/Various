#include <iostream>
#include <vector>
#include <climits>

class Edge{
public:
    int src, dest, weight;
};

int main(){

    int v = 5;
    int e = 9;
    Edge * edge = new Edge[e];

    edge[0].src = 0;
    edge[0].dest = 1;
    edge[0].weight = -5;

    edge[1].src = 0;
    edge[1].dest = 2;
    edge[1].weight = 2;
    
    edge[2].src = 0;
    edge[2].dest = 3;
    edge[2].weight = 3;
    
    edge[3].src = 1;
    edge[3].dest = 2;
    edge[3].weight = 4;
    
    edge[4].src = 2;
    edge[4].dest = 3;
    edge[4].weight = 1;
    
    edge[5].src = 4;
    edge[5].dest = 0;
    edge[5].weight = 0;
    
    edge[6].src = 4;
    edge[6].dest = 1;
    edge[6].weight = 0;
    
    edge[7].src = 4;
    edge[7].dest = 2;
    edge[7].weight = 0;
    
    edge[8].src = 4;
    edge[8].dest = 3;
    edge[8].weight = 0;

    int dist[v];

    for(int i = 0; i < v; i++){
	dist[i] = INT_MAX;
    }
    dist[v-1] = 0;
    
    for(int i = 0; i < v - 1; i++){
	for(int j = 0; j < e; j++){
	    int u = edge[j].src;
	    int v = edge[j].dest;
	    int weight = edge[j].weight;
	    if(dist[u] != INT_MAX && dist[v] > dist[u] + weight){
		dist[v] = dist[u] + weight;
	    }
	}
    }

    for(int i = 0; i < e; i++){
	int u = edge[i].src;
	int v = edge[i].dest;
	int weight = edge[i].weight;
	if(dist[u] != INT_MAX && dist[v] > dist[u] + weight){
	    std::cout << "Graph contains negative weight cycle";
	}
    }

    for(int i = 0; i < e; i++){
	int u = edge[i].src;
	int v = edge[i].dest;
	int weight = edge[i].weight;
	edge[i].weight = weight + dist[u] - dist[v];
	//std::cout << u << " " << v << " " << edge[i].weight << std::endl;
    }

    for(int i = 0; i < e; i++){
	if(edge[i].weight == 0){
	    for(int j = i; j < e; j++){
	        edge[j] = edge[j + 1];
	    }
	}
	//std::cout << edge[i].weight << std::endl;
    }



    /*for(int i = 0; i < v - 1; i++){
	std::cout << i << " " << dist[i] << std::endl;
    }*/

}
