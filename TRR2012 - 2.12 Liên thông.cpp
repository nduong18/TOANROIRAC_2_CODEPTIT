#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ke[105];
bool visited[105];
vector<int> current;
vector<vector<int>> result;

void BFS(int u){
    queue<int> q;
    vector<int> current;
    q.push(u);
    visited[u] = true;

    while (!q.empty()){
        int v = q.front(); q.pop();
        current.push_back(v);

        for (int x : ke[v]){
            if (!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }

    sort(current.begin(), current.end());
    result.push_back(current);
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
            BFS(i);
        }
    }

    cout << result.size() << '\n';
    for (auto it : result){
        for (auto z : it) cout << z << ' ';
        cout << '\n';
    }

    return 0;
}
