#include<bits/stdc++.h>
using namespace std;
#define MaxN 1000000
vector<pair<int, int>> adj[MaxN];
bool mark[MaxN];
const int INF = 1000000;
int dist[MaxN];
int n,m;
void input(int n,int m){
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
}

void dijkstra(int s, int t){

    fill(dist + 1, dist + n + 1, INF);
    dist[s]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pri_queue;
    pri_queue.push({0,s});
    while(!pri_queue.empty()){

        int u = pri_queue.top().second;
        pri_queue.pop();
        if(mark[u]) continue;
        mark[u] = true;
        for(auto edge : adj[u]){
            int v = edge.first;
            int w = edge.second;
            if(dist[v]> dist[u]+w){
                dist[v]= dist[u]+w;
                pri_queue.push({dist[v],v});
            }
        }

    }
    if(dist[t]==INF) cout << "-1";
    else cout << dist[t];
}

int main() {
    cin >> n >> m;
    input(n,m);
    int s,t;
    cin >> s >> t;
    dijkstra(s,t);
    return 0;
}
