//https://www.codingninjas.com/codestudio/problems/920469?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
        
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    
    vector<int>dis(vertices,1e12);
    
    dis[source]=0;
    pq.push({0,source});
    
    vector<pair<int,int>>adj[vertices];
    
    for(int i=0;i<vec.size();i++){
        adj[vec[i][0]].push_back({vec[i][2],vec[i][1]});
        adj[vec[i][1]].push_back({vec[i][2],vec[i][0]});
    }
    
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(int i=0;i<adj[node].size();i++){
            int edge_weight = adj[node][i].first;
            int adjnode = adj[node][i].second;
            
            if( (d+edge_weight)<dis[adjnode] ){
                dis[adjnode] = d+edge_weight;
                pq.push({dis[adjnode],adjnode});
            }
        }
    }
    return dis;
    
}
