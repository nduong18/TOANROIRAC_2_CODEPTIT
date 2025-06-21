#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ke[105];
bool visited[105];
vector<int> current;
vector<vector<int>> result;

void DFS(int u){
    visited[u] = true;
    current.push_back(u);
    for (int i : ke[u]){
        if (!visited[i]){
            DFS(i);
        }
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x;
            cin >> x;
            if (x) ke[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            current.clear();
            DFS(i);
            sort(current.begin(), current.end());
            result.push_back(current);
        }
    }

    cout << result.size() << '\n';
    for (auto it : result){
        for (auto z : it) cout << z << ' ';
        cout << '\n';
    }

    return 0;
}
