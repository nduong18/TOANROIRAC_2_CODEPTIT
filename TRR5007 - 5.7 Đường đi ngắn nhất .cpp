#include <bits/stdc++.h>
using namespace std;

int n, s, t, c[105][105], d[105], tr[105];
const int INF = 1e9;

int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    cin >> n >> s >> t;
    vector<tuple<int, int, int>> edges;

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
        cin >> c[i][j];
        if (c[i][j] != 10000 && i != j)
            edges.push_back({i, j, c[i][j]});
    }

    fill(d + 1, d + n + 1, INF);
    d[s] = 0;

    for (int i = 1; i < n; ++i)
        for (auto [u, v, w] : edges)
            if (d[u] != INF && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                tr[v] = u;
            }

    // Kiểm tra chu trình âm
    for (auto [u, v, w] : edges)
        if (d[u] != INF && d[v] > d[u] + w) {
            cout << -1;
            return 0;
        }

    if (d[t] == INF) {
        cout << 0;
        return 0;
    }

    cout << d[t] << '\n';
    vector<int> path;
    for (int v = t; v != s; v = tr[v]) path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    for (int v : path) cout << v << ' ';
}
