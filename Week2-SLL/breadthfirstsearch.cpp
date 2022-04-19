#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void bfs(vector<vector<int>> graph, int start);

void bfs(vector<vector<int>> graph, int start) {
int numVertices = graph.size();
	bool *visited = new bool[numVertices]; 
    for(int i = 0; i < numVertices; i++) 
        visited[i] = false; 

    queue<int> myQueue; 
    bool isFirst = true;
    visited[start] = true; 
    myQueue.push(start); 

    while(!myQueue.empty()) 
    { 
        start = myQueue.front();
        if (isFirst) {
            cout << start;
            isFirst = false;
        }
        else cout << " " << start;
        myQueue.pop(); 

        int outDegree = graph[start].size();
        for (int j = 0; j < outDegree; ++j) 
        { 
            int temp = graph[start][j];
            if (!visited[temp]) 
            { 
                visited[temp] = true; 
                myQueue.push(temp); 
            } 
        }
    }
    delete[] visited;
}

int main() {
    int init_graph[10][10] = {  {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
				                {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                                {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                                {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                                {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
                                {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
                                {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                                {1, 0, 1, 0, 1, 0, 0, 0, 1, 0} };
	int n = 10;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (init_graph[i][j]){
                graph[i].push_back(j);
            }
		}
	}

	bfs(graph, 2);
}