#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
typedef int arr[maxn];
// Nhập dữ liệu.
void enter(int &n, int &m, arr deg)
{
    
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
      deg[i] = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        ++deg[u];
        ++deg[v];
    }
}

// Kiểm tra điều kiện đồ thị Hamilton.
bool check_hamilton_graph(int n, arr deg)
{
    for (int u = 1; u <= n; ++u)
        if (deg[u] < 2)
            return false;
        

    return true;
}

int main()
{

    int num;
    cin >> num;
    int point_edge[num][num];
    vector<int> count;
    arr deg;
    for(int i=0; i < num; i++){
      int n, m;
      enter(n, m, deg);
      if (check_hamilton_graph( n,  deg)) {
        count.push_back(1);
      }
      else count.push_back(0);
    }
    
    for(int i = 0; i < count.size(); i++){
      cout << count[i] << endl;
    }
    return 0;
}
