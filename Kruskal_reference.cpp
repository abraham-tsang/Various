#include <iostream>

class Edge{
public:
    int src, dest, weight;
};

class Subset{
public:
    int parent, rank;
};

int partition(Edge * edge, int low, int high){

    int pivot = edge[high].weight;
    int i = low - 1;
    Edge temp;

    for(int j = low; j <= high - 1; j++){
	if(edge[j].weight < pivot){
	    i++;
	    temp = edge[i];
	    edge[i] = edge[j];
	    edge[j] = temp;
	}
    }
    temp = edge[i + 1];
    edge[i + 1] = edge[high];
    edge[high] = temp;
    return i + 1;

}

void quickSort(Edge * edge, int low, int high){
    if(low < high){
	int pi = partition(edge, low, high);

	quickSort(edge, low, pi - 1);
	quickSort(edge, pi + 1, high);
    }

}

int find(Subset subset[], int i){

    if(subset[i].parent != i){
	subset[i].parent = find(subset, subset[i].parent);
    }
    return subset[i].parent;

}

int main(){

    int v = 4;
    int e = 5;
    Edge * edge = new Edge[e];

    edge[0].src = 0;
    edge[0].dest = 1;
    edge[0].weight = 10;

    edge[1].src = 0;
    edge[1].dest = 2;
    edge[1].weight = 6;

    edge[2].src = 0;
    edge[2].dest = 3;
    edge[2].weight = 5;

    edge[3].src = 1;
    edge[3].dest = 3;
    edge[3].weight = 15;

    edge[4].src = 2;
    edge[4].dest = 3;
    edge[4].weight = 4;

    Edge * result = new Edge[v];

    quickSort(edge, 0, e - 1);
    
    Subset * subset = new Subset[v];
    for(int i = 0; i < v; i++){
	subset[i].parent = i;
	subset[i].rank = 0;
    }

    int a = 0;
    int b = 0;

    while(a < v - 1 && b < e){
	Edge next_edge = edge[b];
	b++;
	int x = find(subset, next_edge.src);
	int y = find(subset, next_edge.dest);

	if(x != y){
	    result[a] = next_edge;
	    a++;
	    int xroot = find(subset, x);
	    int yroot = find(subset, y);

	    if(subset[xroot].rank < subset[yroot].rank){
		subset[xroot].parent = yroot;
	    }
	    else if(subset[xroot].rank > subset[yroot].rank){
		subset[yroot].parent = xroot;
	    }
	    else{
		subset[yroot].parent = xroot;
		subset[xroot].rank++;
	    }
	}
	
    }
    for(int i = 0; i < a; i++){
	std::cout << result[i].src << " " << result[i].dest << " " << result[i].weight << std::endl;
    }
}
