#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ke[105];
bool visited[105];
vector<int> result;

void DFS(int u){
    visited[u] = true;
    for (int i : ke[u]){
        if (!visited[i]){
            DFS(i);
        }
    }
}

int tplt(){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            DFS(i);
        }
    }
    memset(visited,false,sizeof(visited));
    return cnt;
}

void solve(){
    int res = tplt();
    for (int i = 1; i <= n; i++){
        visited[i] = true;
        if (res < tplt()) result.push_back(i);
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (x) ke[i].push_back(j);
        }
    }

    solve();
    cout << result.size() << '\n';
    for (int i : result) cout << i << ' ';
  
    return 0;
}
