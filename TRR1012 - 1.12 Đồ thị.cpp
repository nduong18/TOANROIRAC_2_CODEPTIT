#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int out[200] = {}, in[200] = {};
    int n; cin >> n;
    set<pair<int,int>> se;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (x) se.insert({i,j});
        }
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
        cout << n << ' ' << se.size() << '\n';
        for (auto it : se){
        cout << it.first << ' ' << it.second << '\n';
        }
    }
}
