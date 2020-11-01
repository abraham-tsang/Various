#include <iostream>
#include <vector>

int v = 6;
std::vector<std::vector<int>> graph;
std::vector<int> stack;
bool * visited = new bool[v];

void topologicalSortUtil(int v){

    visited[v] = true;

    for(int i = 0; i < graph[v].size(); i++){
	if(!visited[graph[v][i]]){
	    topologicalSortUtil(graph[v][i]);
	}
    }

    stack.push_back(v);

}

int main(){

    std::vector<int> temp;
    for(int i = 0; i < v; i++){
        graph.push_back(temp);
    }

    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    for(int i = 0; i < v; i++){
	visited[i] = false;
    }

    for(int i = 0; i < v; i++){
	if(visited[i] == false){
	    topologicalSortUtil(i);
	}
    }

    while(stack.empty() == false){
	std::cout << stack[stack.size()-1] << " ";
	stack.erase(stack.end()-1);
    }
}
