#include <iostream>

class Edge{
public:
    int src, dest, weight;
}

void quickSort(, low, high){
    if(low < high){
	pi = partition(arr, low, high);

	quickSort(arr, low, pi - 1);
	quickSort(arr, pi + 1, high);
    }

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

    Edge result[v];

