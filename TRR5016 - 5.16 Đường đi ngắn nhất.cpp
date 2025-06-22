#include <bits/stdc++.h>
using namespace std;

int n, c[105][105], d[105][105], tr[105][105];
const int INF = 10000;

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
        cin >> c[i][j];
        d[i][j] = c[i][j];
        if (i != j && c[i][j] < INF) tr[i][j] = i;
        else tr[i][j] = 0;
    }

    // Floyd
    for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
        if (d[i][k] + d[k][j] < d[i][j]) {
            d[i][j] = d[i][k] + d[k][j];
            tr[i][j] = tr[k][j];
        }

    int u = 0, v = 0, maxD = -1;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
        if (i != j && d[i][j] < INF && d[i][j] > maxD) {
            maxD = d[i][j];
            u = i; v = j;
        }

    if (maxD == -1) {
        cout << 0;
        return 0;
    }

    cout << u << ' ' << v << ' ' << maxD << '\n';

    // reconstruct path from u to v
    vector<int> path;
    int x = v;
    while (x != u) {
        path.push_back(x);
        x = tr[u][x];
    }
    path.push_back(u);
    reverse(path.begin(), path.end());
    for (int p : path) cout << p << ' ';
}
