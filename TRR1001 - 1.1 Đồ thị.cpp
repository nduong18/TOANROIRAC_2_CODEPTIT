#include <bits/stdc++.h>
using namespace std;

int deg[200];

int main() {
    
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    
    int t; cin >> t;
    if (t == 1){
        int n; cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                int x; cin >> x;
                if (x == 1) deg[i]++;
            }
        }

        for (int i = 1; i <= n; i++){
            cout << deg[i] << ' ';
        }
        cout << '\n';
    }
    else if (t == 2){
        set<pair<int,int>> se;
        int n; cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                int x; cin >> x;
                if (x == 1 && i < j){
                    se.insert({i,j});
                }
            }
        }

        cout << n << ' ' << se.size() << '\n';
        for (auto it : se){
            cout << it.first << ' ' << it.second << '\n';
        }
    }

    return 0;
}
