//https://www.codingninjas.com/codestudio/problems/920551?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
#include<bits/stdc++.h>
bool bipartite(vector<int> adj[],vector<int> &c,int i){
   
    queue<int>q;
    q.push(i);
    c[i]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int j=0;j<adj[node].size();j++){
            if(c[adj[node][j]]==-1){
                q.push(adj[node][j]);
                c[adj[node][j]] = 1-c[node];
            }
            else if(c[adj[node][j]]!=-1 && c[adj[node][j]] == c[node]){
                return false;
            }
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    // Write your code here.
    int v = edges.size();
    vector<int>adj[v];
    for(int i=0;i<edges.size();i++){
        for(int j=0;j<edges[0].size();j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int>color(v,-1);
    for(int i=0;i<v;i++){
        if(color[i]==-1){
          if(!bipartite(adj,color,i)){
              return false;
          }   
        }
    }    
    return true;
}
