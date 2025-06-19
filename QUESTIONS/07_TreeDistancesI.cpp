#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int dist1[MAXN], dist2[MAXN];

void dfs(int node, int parent, int dist[], int d = 0) {
    dist[node] = d;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, dist, d + 1);
        }
    }
}

int find_farthest(int n, int dist[]) {
    int farthest = 1;
    for (int i = 2; i <= n; ++i) {
        if (dist[i] > dist[farthest]) {
            farthest = i;
        }
    }
    return farthest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // Step 1: First DFS from node 1
    dfs(1, -1, dist1);
    int x = find_farthest(n, dist1);

    // Step 2: Second DFS from x
    dfs(x, -1, dist1);
    int y = find_farthest(n,dist1);

    // Step 3: Third DFS from y
    dfs(y, -1, dist2);

    // Step 4: Print max(dist1[i], dist2[i]) for all i
    for (int i = 1; i <= n; ++i) {
        cout << max(dist1[i], dist2[i]) << " ";
    }
    
    return 0;
}