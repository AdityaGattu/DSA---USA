//https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    
    int find(int n[],int x){
        if(x==n[x]){
            return x;
        }
        return n[x]=find(n,n[x]);
    }
    
    void funion(int a,int b,vector<int> &rank,int n[],int &ans){
        int Rootx = find(n,a);
        int Rooty = find(n,b);
        
        if(Rootx!=Rooty){
            
           if(rank[Rootx]>rank[Rooty]){
                n[Rooty]=Rootx;
            }
            else if(rank[Rootx]<rank[Rooty]){
                n[Rootx]=Rooty;
            }
            else{
                n[Rooty]=Rootx;
                rank[Rootx]+=1;
            }
            //n[Rooty]=Rootx;
            ans-=1;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int sz = isConnected.size();
        int nodes[sz+1];
        vector<int>rank(sz+1,1);
        
        for(int i=0;i<=sz;i++){
            nodes[i]=i;
        }
        
        int res = sz;
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                if(isConnected[i][j]==1){
                    funion(i+1,j+1,rank,nodes,res);
                }
            }
        }
        
        
        return res;
        
    }
};
