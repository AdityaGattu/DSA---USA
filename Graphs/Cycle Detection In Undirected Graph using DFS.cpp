//https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1v
bool iscycle(vector<int> adj[],vector<int> &vis,int node,int parent)
{    
    vis[node]=1;
    for(int j=0;j<adj[node].size();j++){
        if(vis[adj[node][j]]==0){
            if(iscycle(adj,vis,adj[node][j],node)){
                return true;
            }
        }
        else if(vis[adj[node][j]]==1 && adj[node][j]!= parent){
            return true;
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
