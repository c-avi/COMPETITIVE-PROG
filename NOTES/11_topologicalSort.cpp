#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructadj(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }
    return adj;
}

vector<int> topologicalSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj = constructadj(V, edges);

    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;

            if (indegree[it] == 0) 
                q.push(it);
        }
    }

    // check for cycle
    if (result.size() != V) {
        cout << "Graph contains cycle!\n";
        return {};
    }
    return result;
    
}

int main () {
    int V = 6;

    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {4,5},{5,1}, {5,2}};

    vector<int> result = topologicalSort(V, edges);

    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}