#include <bits/stdc++.h>
using namespace std;

int deg[200];

int main() {
    
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    
    int t; cin >> t;
    if (t == 1){
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;
            deg[x]++;
            deg[y]++;
        }

        for (int i = 1; i <= n; i++) cout << deg[i] << ' ';
        cout << '\n';
    }
    else if (t == 2){
        int n,m; cin >> n >> m;
        //Dung edges pair de luu danh sach canh.
        vector <pair<int,int>> edges;
        for (int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;
            edges.push_back({x,y});
        }
        
        int z = edges.size();
        cout << n << ' ' << z << '\n';
        for (int i = 1; i <= n; i++){
            for (auto it : edges){
                cout << (i == it.first || i == it.second) << ' ';
                // Kiem tra xem i co phai la 1 trong 2 dau` mut' cua canh do khong va in ra
            }
            cout << '\n';
        } 
    }

    return 0;
}
