#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int out[200] = {}, in[200] = {};
    int n,m; cin >> n >> m;
    set<pair<int,int>> se;
    for (int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;
        se.insert({x,y});
    }

    if (t == 1){
        int a[n+1] = {};
        for (auto it : se){
            out[it.first]++;
            in[it.second]++;
        }

        for (int i = 1; i <= n; i++){
            cout << in[i] << ' ' << out[i] << '\n';
        }
    }
    else if (t == 2){
        int m = se.size();
        cout << n << ' ' << m << '\n';
        int a[n+1][m+1];
        memset(a, 0, sizeof(a));
        int col = 1;

        for (auto it : se){
            a[it.first][col] = 1;
            a[it.second][col] = -1;
            col++;
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}
