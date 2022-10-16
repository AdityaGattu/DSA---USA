//https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
#include <bits/stdc++.h> 
void bfs(vector<int> adj[],vector<int> &vis,int i,vector<int> &res){
    queue<int>q;
    q.push(i);
    vis[i]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            if(vis[adj[node][i]]==0){
                vis[adj[node][i]]=1;
                q.push(adj[node][i]);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int>vis(vertex,0);
    vector<int>adj[vertex];
    
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    
    for(int i=0;i<vertex;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    
    vector<int>res;
    for(int i=0;i<vertex;i++){
        if(vis[i]==0){
            bfs(adj,vis,i,res);
        }
    }
    return res;
}
