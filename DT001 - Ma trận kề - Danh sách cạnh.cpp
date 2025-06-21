#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t,n; cin >> t >> n;
    set<pair<int,int>> se;
    int deg[105] = {};

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (x){
                deg[i]++;
                if (i < j) se.insert({i,j});
            }
        }
    }

    if (t == 1){
        for (int i = 1; i <= n; i++) cout << deg[i] << ' ';
    }
    else if (t == 2){
        cout << n << ' ' << se.size() << '\n';
        for (auto it : se) cout << it.first << ' ' << it.second << '\n';
    }

    return 0;
}
