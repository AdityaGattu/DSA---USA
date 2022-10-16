//https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
void dfs(vector<int> adj[],vector<int> &vis,int i,vector<int> &temp)
{
    if(vis[i]==0){
        vis[i]=1;
        temp.push_back(i);
        for(int j=0;j<adj[i].size();j++){
               dfs(adj,vis,adj[i][j],temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>ans;
    vector<vector<int>>finalans;

    vector<int>vis(V,0);
    vector<int>adj[V];
    for(int i=0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    int cnt = 0; 
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            vector<int>temp;
            dfs(adj,vis,i,temp);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            cnt++;
        }
    }
    sort(ans.begin(),ans.end());
    
    /*
    for(int i=0;i<ans.size();i++){
        vector<int>t;
        t = ans[i];
        finalans.push_back(t);
    }
    */
    
    // Write your code here
    return ans; 
}
