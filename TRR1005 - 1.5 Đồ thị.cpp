#include <bits/stdc++.h>
using namespace std;

int deg[200];

int main() {
    
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    
    int t; cin >> t;
    if (t == 1){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;
            deg[x]++;
            deg[y]++;
        }

        for (int i = 1; i <= n; i++) cout << deg[i] << ' ';
        cout << '\n';
    }
    else if (t == 2){
        int n,m; cin >> n >> m;
        vector<int> v[n+1];
        for (int i = 0; i < m; i++){
            int x,y; cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        cout << n << '\n';
        for (int i = 1; i <= n; i++){
            cout << v[i].size() << ' ';
            for (auto it : v[i]) cout << it << ' ';
            cout << '\n';
        }

    }

    return 0;
}
