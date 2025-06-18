#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<int> c(n + 1);
    vector<vector<int>> children(n + 1);

    int root = -1;

    for (int i = 1; i <= n; ++i) {
        cin >> parent[i] >> c[i];
        if (parent[i] == -1) {
            root = i;
        } else {
            children[parent[i]].push_back(i);
        }
    }

    vector<int> toDelete;
    for (int i = 1; i <= n; ++i) {
        // Skip root
        if (parent[i] == -1) continue;

        if (c[i] == 1) {
            bool canDelete = true;
            for (int child : children[i]) {
                if (c[child] == 0) {
                    canDelete = false;
                    break;
                }
            }
            if (canDelete) {
                toDelete.push_back(i);
            }
        }
    }

    if (toDelete.empty()) {
        cout << -1 << "\n";
    } else {
        sort(toDelete.begin(), toDelete.end());
        for (int node : toDelete) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}