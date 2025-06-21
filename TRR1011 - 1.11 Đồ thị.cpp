#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t,n,k; cin >> t >> n >> k;
    int deg[105] = {};
    int a[n+1][n+1] = {};
    
    for (int i = 1; i <= k; i++){
        int x,y,z; cin >> x >> y >> z;
        deg[x]++;
        deg[y]++;
        a[x][y] = z;
        a[y][x] = z;
    }

    if (t == 1){
        for (int i = 1; i <= n; i++) cout << deg[i] << ' ';
    }
    else if (t == 2){
        cout << n << '\n';
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][j] == 0 && i != j) a[i][j] = 10000;
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
