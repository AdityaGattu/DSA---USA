#include<bits/stdc++.h>

void topological_sort(vector<int> adj[],vector<int> &vis,int node,stack<int> &stk){
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++){
        if(vis[adj[node][i]]==0){
            topological_sort(adj,vis,adj[node][i],stk);       
        }
    }
    stk.push(node);
}

void dfs(vector<int> adj[],vector<int> &vis1,int node,vector<int> &ans){
    vis1[node]=1;
    ans.push_back(node);
    for(int i=0;i<adj[node].size();i++){
        if(vis1[adj[node][i]]==0){
            dfs(adj,vis1,adj[node][i],ans);       
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int>vis(n,0);
    vector<int>adj[n];
    
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    stack<int> s;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            topological_sort(adj,vis,i,s);       
        }
    }
    
  
    vector<int>trans[n];
    for(int i=0;i<edges.size();i++){
        trans[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<vector<int>>res;
    vector<int>vis1(n,0);
    
    for(int i=0;i<s.size();i++){
        while(!s.empty()){
            int n = s.top();
            s.pop();
            if(vis1[n]==0){
                vector<int>ans;
                dfs(trans,vis1,n,ans);
                res.push_back(ans);
            }
        }
    }
    return res;
}
