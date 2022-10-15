
class Solution {
public:
    
    bool iscycle(vector<int> adj[],vector<int> &vis,int i){
        
        if(vis[i]==1)  // visited but in curr cycle
            return true;
        
        if(vis[i]==0){ // if not visited
            vis[i]=1;
            for(int j=0;j<adj[i].size();j++){
                if(iscycle(adj,vis,adj[i][j]))
                {
                    return true;
                }   
            }
        }
        
        vis[i]=2;       // all nodes in dfs of i are visited
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> vis(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(iscycle(adj,vis,i)){
                return false;
            }
        }
        
        return true; 
    }
};
