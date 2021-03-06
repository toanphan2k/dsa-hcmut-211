#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool isBipartite(vector<vector<int>> graph) 
{ 
    int numOfVertices = graph.size();
    int colorArr[numOfVertices]; 
    for (int i = 0; i < numOfVertices; ++i) 
        colorArr[i] = -1; 

    int start = 0;
    colorArr[start] = 1;
    
    queue<int> myQueue; 
    myQueue.push(start); 

    while (!myQueue.empty()) 
    { 
        start = myQueue.front(); 
        myQueue.pop();
        int degree = graph[start].size();
        
        for (int i = 0; i < degree; ++i) 
        { 
            int adjVer = graph[start][i];
            if (adjVer == start) 
                return false;
                
            if (colorArr[adjVer] == -1) 
            { 
                colorArr[adjVer] = 1 - colorArr[start]; 
                myQueue.push(adjVer); 
            } 
            
            else if (colorArr[adjVer] == colorArr[start]) 
                return false; 
        }
        
        while (myQueue.empty() && degree == 0) {
            for (int i = 0; i < numOfVertices; ++i) {
                if (colorArr[i] == -1 && i != start && graph[i].size() != 0) {
                    start = i;
                    colorArr[i] = 1;
                    degree = graph[i].size();
                    break;
                }
            }
            return true;
        }
    } 
    return true; 
}

int main(){
    int G[6][6] = { {0, 1, 0, 0, 0, 1},
                    {1, 0, 1, 0, 0, 0},
                    {0, 1, 0, 1, 0, 0},
                    {0, 0, 1, 0, 1, 0},
                    {0, 0, 0, 1, 0, 1},
                    {1, 0, 0, 0, 1, 0} };
int n = 6;

vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (G[i][j]) graph[i].push_back(j);
		}
	}

    isBipartite(graph) ? cout << "Yes" : cout << "No";
}