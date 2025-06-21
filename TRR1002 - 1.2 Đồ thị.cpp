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
        int n; cin >> n;
        vector<int> v[n+1];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                int x; cin >> x;
                if (x == 1){
                    v[i].push_back(j);
                }
            }
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
