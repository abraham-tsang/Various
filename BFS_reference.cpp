#include <iostream>
#include <vector>

int main(){

    std::vector<std::vector<int>> graph;
    std::vector<int> temp;
    for(int i = 0; i < 4; i++){
        graph.push_back(temp);
    }
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);

    int s = 2;

    bool * visited = new bool[4];
    for(int i = 0; i < 4; i++){
	visited[i] = false;
    }

    std::vector<int> queue;
    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty()){
	s = queue.front();
	std::cout << s << " ";
	queue.erase(queue.begin());
	for(int i = 0; i < graph[s].size(); i++){
	    if(!visited[graph[s][i]]){
		visited[graph[s][i]] = true;
		queue.push_back(graph[s][i]);
	    }
	}
    }

}
