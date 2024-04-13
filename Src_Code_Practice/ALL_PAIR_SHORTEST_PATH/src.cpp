//C++ 
#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000;

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

void dijkstra(int n, vector<vector<Edge>>& graph, vector<vector<int>>& dist) {
    dist.resize(n + 1, vector<int>(n + 1, INF));

    for (int u = 1; u <= n; ++u) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pri_queue;
        vector<int> d(n + 1, INF);
        d[u] = 0;
        pri_queue.push({0, u});

        while (!pri_queue.empty()) {
            int x = pri_queue.top().second;
            int x_Dist = pri_queue.top().first;
            pri_queue.pop();

            if (x_Dist > d[x]) continue;

            for (const Edge& edge : graph[x]) {
                int v = edge.to;
                int w = edge.weight;

                if (d[x] + w < d[v]) {
                    d[v] = d[x] + w;
                    pri_queue.push({d[v], v});
                }
            }
        }

        for (int v = 1; v <= n; ++v) {
            dist[u][v] = (d[v] == INF) ? -1 : d[v];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }
    vector<vector<int>> dist;
    dijkstra(n, graph, dist);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
