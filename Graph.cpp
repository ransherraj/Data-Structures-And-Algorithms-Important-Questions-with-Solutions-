#include<bits/stdc++.h>
using namespace std;

void createAdjList(vector<vector<int>> &adj, vector<vector<int>>edges )
{
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void printGraph(vector<vector<int>> adj)
{   
    int V = adj.size();
    for (int v = 0; v < V; ++v)
    {
        cout << "Adjacency list of vertex: "<< v << ": " ;
        for (auto x : adj[v])
           cout << "-> " << x;
        cout<<endl;
    }
}

/* DFS Traversal*/

void dfsutil(vector<vector<int>> adj, vector<bool>&vis, int s){
    
    vis[s] = true;
    cout<<s<<" ";
    for(int x : adj[s]){
        if(vis[x] == false){
            dfsutil(adj, vis, x);
        }
    }
}

void DFS(vector<vector<int>> adj){
    int V = adj.size();
    vector<bool>vis(V, false);
    // vector<int>res;
    cout<<"DFS Traversal: ";
    for(int i = 0; i<V; i++){
        if(vis[i] == false){
            dfsutil(adj, vis, i);
        }
    }
}

/* BFS Traversal*/

void bfsutil(vector<vector<int>> adj, vector<bool>&vis, int s){
    
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        cout<<v<<" ";
        q.pop();
        for(int x : adj[v]){
            if(vis[x] == false){
                vis[x] = true;
                q.push(x);
            }
        }
    }
}

void BFS(vector<vector<int>> adj){
    int V = adj.size();
    vector<bool>vis(V, false);
    // vector<int>res;
    cout<<"BFS Traversal: ";
    for(int i = 0; i<V; i++){
        if(vis[i] == false){
            bfsutil(adj, vis, i);
        }
    }
}

int main()
{
    int V, edgeCount;
    cin>>V>>edgeCount;
    vector<vector<int>> edges;
    vector<vector<int>> adj(V);
    for(int i = 0; i<edgeCount; i++){
        int a, b;
        cin>>a>>b;
        edges.push_back({a, b}); 
    }
    createAdjList(adj, edges);
    printGraph(adj);
    cout<<endl;
    DFS(adj);
    cout<<endl;
    BFS(adj);
    return 0;
}
