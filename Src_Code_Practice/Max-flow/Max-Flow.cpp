//C++ 
#include <bits/stdc++.h> 

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, capacity, flow;
    Edge(int t, int c) : to(t), capacity(c), flow(0) {}
};

int maxFlow(vector<vector<Edge>>& graph, int source, int target) {
    int n = graph.size();
    vector<int> parent(n);

    int maxFlow = 0;

    while (true) {
        fill(parent.begin(), parent.end(), -1);

        queue<pair<int, int>> q;
        q.push({source, INF});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (Edge& edge : graph[cur]) {
                int to = edge.to;
                if (parent[to] == -1 && edge.capacity - edge.flow > 0) {
                    parent[to] = cur;
                    int new_flow = min(flow, edge.capacity - edge.flow);
                    if (to == target) {
                        maxFlow += new_flow;
                        while (to != source) {
                            cur = parent[to];
                            for (Edge& e : graph[cur]) {
                                if (e.to == to) {
                                    e.flow += new_flow;
                                    break;
                                }
                            }
                            for (Edge& backEdge : graph[to]) {
                                if (backEdge.to == cur) {
                                    backEdge.flow -= new_flow;
                                    break;
                                }
                            }
                            to = cur;
                        }
                        break;
                    }
                    q.push({to, new_flow});
                }
            }
        }

        if (parent[target] == -1) {
            break; 
        }
    }

    return maxFlow;
}

int main() {
    int N, M;
    cin >> N >> M;

    int s, t;
    cin >> s >> t;

    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].emplace_back(v, c);
    }

    int result = maxFlow(graph, s, t);

    cout << result << endl;

    return 0;
}
