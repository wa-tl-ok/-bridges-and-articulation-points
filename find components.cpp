#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <random>
#include <bitset>
#include <functional>
#include <random>

using namespace std;

vector<int> vis;
vector<vector<int>> g;

void dfs(int v) {
    vis[v] = true;
    for (auto u : g[v]) {
        if (vis[u] == true) {
            continue;
        }
        else {
            dfs(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    g.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vis.resize(n);
    for (int i = 0; i < n; i++) {
        vis[i] = false;
    }

    int components = 0;

    for (int u = 0; u < n; u++) {
        if (vis[u] == 0) {
            dfs(u);
            ++components;
        }
    }

    cout << components;

    return 0;
}