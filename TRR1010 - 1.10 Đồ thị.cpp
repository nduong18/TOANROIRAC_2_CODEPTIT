#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t,n; cin >> t >> n;
    
    int deg[105] = {};
    set<tuple<int,int,int>> se;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (x != 10000 && x != 0) {
                if (i < j){
                    deg[i]++;
                    deg[j]++;
                    se.insert({i,j,x});
                }
            }
        }
    }

    if (t == 1){
        for (int i = 1; i <= n; i++) cout << deg[i] << ' ';
    }
    else if (t == 2){
        cout << n << ' ' << se.size() << '\n';
        for (auto [a,b,c] : se){
            cout << a << ' ' << b << ' ' << c << '\n';
        }
    }

    return 0;
}
