#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;

void topologicalSortUtil(int v, bool visited[], std::vector<int> &stack){
    visited[v] = true;

    for(int i = 0; i < graph[v].size(); i++){
	if(!visited[graph[v][i]]){
	    topologicalSortUtil(graph[v][i], visited, stack);
	}
    }

    stack.push_back(v);
}

int main(){

    int v = 6;

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

    std::vector<int> stack;
    bool * visited = new bool[v];
    for(int i = 0; i < v; i++){
	visited[i] = false;
    }

    for(int i = 0; i < v; i++){
	if(visited[i] == false){
	    topologicalSortUtil(i, visited, stack);
	}
    }

    while(stack.empty() == false){
	std::cout << stack[stack.size()-1] << " ";
	stack.erase(stack.end()-1);
    }
}
