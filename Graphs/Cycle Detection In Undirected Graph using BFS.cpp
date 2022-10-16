#include<bits/stdc++.h>
bool iscycle(vector<int> adj[],vector<int> &vis,int node,int parent)
{    
    queue<pair<int,int>>q;
    q.push({node,parent});
    
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        vis[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(vis[adj[node][i]]==0){
                vis[adj[node][i]] = 1;
                q.push({adj[node][i],node});
            }
            else if(vis[adj[node][i]]==1 && adj[node][i]!=par){
                 return true;   
            }
        }
    }
    return false;
}
  

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>vis(n+1,0);
    vector<int>adj[n+1];
    
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int j=1;j<=n;j++){
        if(vis[j]==0){
            if(iscycle(adj,vis,j,-1)){
                return "Yes";
            }
        }
    }
    return "No";
}
