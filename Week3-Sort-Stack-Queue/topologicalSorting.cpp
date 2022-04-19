#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSorting(vector<vector<int>> graph) {
    vector<int> g;
    int numVer = graph.size();
    vector<int> in_degree(numVer, 0);

    for (int u = 0; u < numVer; u++) {
        for (auto i = graph[u].begin(); i != graph[u].end(); i++)
            in_degree[*i]++;
    }

    queue<int> q;
    for (int i = 0; i < numVer; i++)
        if (in_degree[i] == 0)
            q.push(i);
    int count = 0;
    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (auto i = graph[u].begin(); i != graph[u].end(); i++)
            if (--in_degree[*i] == 0)
                q.push(*i);
        count++;
    }
    if (count != numVer) {
        return g;
    }
    return result;
}

int main() {
    int n = 6;
    int G[6][6] = { {0, 1, 0, 1, 0, 0},
                    {0, 0, 1, 1, 0, 0},
                    {0, 0, 0, 1, 1, 1},
                    {0, 0, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0, 0} };
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j] == 1) graph[i].push_back(j);
        }
    }

    vector<int> res = topologicalSorting(graph);
    if (res.empty()) printf("-1");
    else {
        for (int e : res) printf("%d ", e);
    }   

    /*
    int n = 6;
    int G[6][6] = { {0, 1, 0, 1, 0, 0},
                    {0, 0, 1, 1, 0, 0},
                    {0, 0, 0, 1, 1, 1},
                    {0, 0, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0, 1},
                    {0, 1, 0, 0, 0, 0} };
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j] == 1) graph[i].push_back(j);
        }
    }

    vector<int> res = topologicalSorting(graph);
    if (res.empty()) printf("-1");
    else {
        for (int e : res) printf("%d ", e);
    }
    */
}