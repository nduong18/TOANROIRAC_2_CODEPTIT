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
        // Khai bao mang 200 ko bi sai
        int a[200][200] = {};
        for (int i = 0; i < m; i++){
            int x,y; cin >> x >> y;
            a[x][y] = 1;
            a[y][x] = 1;
        }

        cout << n << '\n';
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }

    }

    return 0;
}
