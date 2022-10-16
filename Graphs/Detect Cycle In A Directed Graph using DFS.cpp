//https://www.codingninjas.com/codestudio/problems/1062626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include<bits/stdc++.h>
bool bipartite(vector<int> adj[],vector<int> &c,int node){
    
    if(c[node]==-1){
        c[node]=1;
    }
    for(int i=0;i<adj[node].size();i++){
        if(c[adj[node][i]]==-1){
            c[adj[node][i]] = 1-c[node];
            if(!bipartite(adj,c,adj[node][i]))
                return false;
        }
        else if(c[adj[node][i]]!=-1 && c[adj[node][i]]==c[node]){
            return false;
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
