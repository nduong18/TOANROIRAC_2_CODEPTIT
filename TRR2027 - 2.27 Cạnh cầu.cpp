#include <bits/stdc++.h>
using namespace std;

int n, timer = 0;
int tin[105], low[105];
bool visited[105];
vector<int> ke[105];
vector<pair<int, int>> bridges;

void dfs(int u, int parent) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;
    for (int v : ke[u]) {
        if (v == parent) continue;
        if (visited[v])
            low[u] = min(low[u], tin[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u])
                bridges.push_back({min(u, v), max(u, v)});
        }
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
        int x; cin >> x;
        if (x && i < j) {
            ke[i].push_back(j);
            ke[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i)
        if (!visited[i]) dfs(i, -1);

    sort(bridges.begin(), bridges.end());

    cout << bridges.size() << '\n';
    for (auto [u, v] : bridges)
        cout << u << ' ' << v << '\n';
}
