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


/* Find shortest path*/

void util_shortest(vector<vector<int>> adj, vector<bool>&vis, int s, vector<int> &dist ){
    
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int x : adj[v]){
            if(vis[x] == false){
                dist[x] = dist[v]+1;
                vis[x] = true;
                q.push(x);
            }
        }
    }
}

void BFS_SHORTEST(vector<vector<int>> adj){
    int V = adj.size();
    vector<bool>vis(V, false);
    vector<int>dist(V, 0);
    for(int i = 0; i<V; i++){
        if(vis[i] == false){
            util_shortest(adj, vis, i, dist);
        }
    }
    cout<<endl<<"Shortest path from root node to other nodes::";
    for(int i = 0; i<V; i++){
        cout<<dist[i]<<" ";
    }
}





/* Cycle detection*/

bool util_cycle(vector<vector<int>> adj, vector<bool>&vis, int s, int parent){
    
    vis[s] = true;
    
    for(int x : adj[s]){
        // if(vis[x] == false){
        //     dfsutil(adj, vis, x, s);
        // }
        if(util_cycle(adj, vis, x, s) == true) return true;
        else if(x != parent) return true;
        
    }
    return false;
}

bool DFS_CYCLE(vector<vector<int>> adj){
    int V = adj.size();
    vector<bool>vis(V, false);
    
    for(int i = 0; i<V; i++){
        // if(vis[i] == false){
        //     util_cycle(adj, vis, i, -1);
        // }
        if(util_cycle(adj, vis, i, -1) == true) return true;
    }
    return false;
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
    BFS_SHORTEST(adj);
    cout<<endl<<"Cycle in graph: "<<DFS_CYCLE(adj);
    return 0;
}
