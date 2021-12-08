
// Directed Graphs in C++ Functions

#include<bits/stdc++.h>
using namespace std;

void createAdjList(vector<vector<int>> &adj, vector<vector<int>>edges )
{
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
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



/* Cycle detection */
bool util_cycle(vector<vector<int>> adj, vector<bool>&vis, int s, vector<bool>&bac){

    vis[s] = true;
    bac[s] = true;
    for(int x : adj[s]){
        if(vis[x] == false){
            if(util_cycle(adj, vis, x, bac) == true ) return true;
        }
        else if(bac[x] == true) return true;
        
    }
    bac[s] = false;
    return false;
}

bool DFS_CYCLE(vector<vector<int>> adj){
    int V = adj.size();
    vector<bool>vis(V, false);
    vector<bool>bac(V, false);
    for(int i = 0; i<V; i++){
        if(vis[i] == false){
            if(util_cycle(adj, vis, i, bac) == true) return true;
        }
    }
    return false;
}

/* Topological Sort(Kahn's Algo) */
void toposort(vector<vector<int>>adj){
    int V = adj.size();
    vector<int>indegree(V, 0);
    queue<int>q;
    for(int i = 0; i<V; i++){
        for(auto x : adj[i]){
            indegree[x]++;
        }
    }
    for(int i = 0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(auto x : adj[v]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }
}

/* Cycle Detection(Kahn's algo) */
void cycleDetectionKahnAlgo(vector<vector<int>>adj){
    int V = adj.size(), count = 0;
    vector<int>indegree(V, 0);
    queue<int>q;
    for(int i = 0; i<V; i++){
        for(auto x : adj[i]){
            indegree[x]++;
        }
    }
    for(int i = 0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        count++;
        for(auto x : adj[v]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }
    cout<<endl<<"Cycle in graph(using Kahn's Algo)? : ";
    if(count != V) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}


/*Topological Sort using DFS */
void toposortUtilDFS(vector<vector<int>>adj, vector<bool>&vis, stack<int>&st, int s){
    int V = adj.size();
    vis[s] = true;
    for(auto x: adj[s]){
        if(!vis[x]){
            toposortUtilDFS(adj, vis, st, x);
            
        }
    }
    st.push(s);
}

void toposortDFS(vector<vector<int>>adj){
    int V = adj.size();
    stack<int>st;
    vector<bool>vis(V, false);
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            toposortUtilDFS(adj, vis, st, i);
        }
    }
    cout<<endl<<"Toposort using DFS :"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
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
    cout<<endl<<"Cycle in graph(DFS) ?: "<<DFS_CYCLE(adj)<<endl;
    
    cout<<"Topological Sorting : Kahn's Algorith:"<<endl;
    toposort(adj);
    
    cycleDetectionKahnAlgo(adj);
    
    toposortDFS(adj);
    
    return 0;
}


/*  

INPUT:
6 6
0 1
0 2
1 3
2 3
3 4
3 5


OUTPUT:
Adjacency list of vertex: 0: -> 1-> 2
Adjacency list of vertex: 1: -> 3
Adjacency list of vertex: 2: -> 3
Adjacency list of vertex: 3: -> 4-> 5
Adjacency list of vertex: 4: 
Adjacency list of vertex: 5: 

DFS Traversal: 0 1 3 4 5 2 
BFS Traversal: 0 1 2 3 4 5 
Shortest path from root node to other nodes::0 1 1 2 3 3 
Cycle in graph(DFS) ?: 0
Topological Sorting : Kahn's Algorith:
0 1 2 3 4 5 
Cycle in graph(using Kahn's Algo)? : No

Toposort using DFS :
0 2 1 3 5 4 



*/
