#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t,n,k; cin >> t >> n >> k;
    int in[105] = {}, out[105] = {};
    int a[n+1][n+1] = {};

    for (int i = 1; i <= k; i++){
        int x,y; cin >> x >> y;
        out[x]++;
        in[y]++;
        a[x][y] = 1;
    }

    if (t == 1){
        for (int i = 1; i <= n; i++) cout << in[i] << ' ' << out[i] << '\n';
    }
    else if (t == 2){
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
