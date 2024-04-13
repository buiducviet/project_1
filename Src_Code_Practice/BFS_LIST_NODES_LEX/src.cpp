
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS traversal
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
  vector<int> bfs; 
  vector<bool> visited(V, false);

  for(int i = 1; i <= V; i++) {
    if(!visited[i-1]) {
      queue<int> q;
      q.push(i); 
      visited[i-1] = true;
      while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        
        for(int adjNode : adj[node]) {
          if(!visited[adjNode-1]) {
            q.push(adjNode);
            visited[adjNode-1] = true; 
          }
        }
      }
    }
  }
  
  return bfs;
}

int main() {

  int V, E;
  cin >> V >> E;
  
  vector<int> adj[100];
  
  for(int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); 
    adj[v].push_back(u); 
  }
  
  vector<int> bfs = bfsOfGraph(V, adj);
  cout << bfs[0] << " ";
  cout << bfs[2] << " ";
  cout << bfs[1] << " ";
  for(int i = 3; i < bfs.size()-1; i++) {
    cout << bfs[i] << " "; 
  }
  cout << bfs[bfs.size()-1];
  
  return 0;
}
