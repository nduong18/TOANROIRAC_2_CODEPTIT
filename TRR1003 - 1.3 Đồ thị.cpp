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
        //Dung edges pair de luu danh sach canh.
        vector <pair<int,int>> edges;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                int x; cin >> x;
                if (i < j && x) edges.push_back({i,j});
                // i < j de ko lap lai canh da xet
            }
        }
        
        int m = edges.size();
        cout << n << ' ' << m << '\n';
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
