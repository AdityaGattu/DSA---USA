https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    
    bool isCycle(vector<int> adj[],vector<int> &vis,int i,vector<int> &ans){
        
        if(vis[i]==1){
            return true; 
        }
        
        if(vis[i]==0){
            vis[i]=1;
            for(int j=0;j<adj[i].size();j++){
                if(isCycle(adj,vis,adj[i][j],ans)){
                    return true;
                }
            }
        }
        if(vis[i]!=2){
            vis[i]=2;
            ans.push_back(i);            
        }
        return false;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     
        vector<int>adj[numCourses];
        
        vector<int>vis(numCourses,0);
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);    
        }
        
        vector<int>ans;
        vector<int>ans1;
        for(int i=0;i<numCourses;i++){
            if(isCycle(adj,vis,i,ans)){
                return ans1;      
            }
        }
        return ans;
    }
};
