#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1); // adjacency list
    
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    bool isSpruce = true;

    for (int i = 1; i <= n; ++i) {
        if (tree[i].empty()) continue; // skip leaf nodes

        int leafchildren = 0;
        for (int child : tree[i]) {
            if (tree[child].empty()) {
                ++leafchildren;
            }
        }
        
        if (leafchildren < 3) {
            isSpruce = false;
            break;
        }
    }

    cout << (isSpruce ? "Yes" : "No") << "\n";
    
    return 0;
}