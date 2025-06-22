#include <bits/stdc++.h>
using namespace std;

int n, s, t, c[105][105], d[105], tr[105];
bool visited[105];

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];

    fill(d + 1, d + n + 1, 1e9);
    d[s] = 0;

    for (int i = 1; i <= n; ++i) {
        int u = -1, minD = 1e9;
        for (int j = 1; j <= n; ++j)
            if (!visited[j] && d[j] < minD)
                minD = d[u = j];

        if (u == -1) break;
        visited[u] = true;

        for (int v = 1; v <= n; ++v)
            if (!visited[v] && c[u][v] < 10000 && d[v] > d[u] + c[u][v]) {
                d[v] = d[u] + c[u][v];
                tr[v] = u;
            }
    }

    if (d[t] == 1e9) {
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
