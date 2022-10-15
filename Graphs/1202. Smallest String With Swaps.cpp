//https://leetcode.com/problems/smallest-string-with-swaps/

class Solution {
public:
    
    int find(int n[],int x){
        if(x==n[x]){
            return x;
        }
        return n[x]=find(n,n[x]);
    }
    
    void funion(int a,int b,vector<int> &rank,int n[]){
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
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int nodes[s.size()];
        vector<int>rank(s.size(),1);
        
        for(int i=0;i<s.size();i++){
            nodes[i]=i;
        }
        vector<int>m[s.size()];
            
        for(int i=0;i<pairs.size();i++){
            /*int Rootx = find(nodes,pairs[i][0]);
            int Rooty = find(nodes,pairs[i][1]);
            if(Rootx!=Rooty){
                nodes[Rooty]=Rootx;
            }*/
            funion(pairs[i][0],pairs[i][1],rank,nodes);
        }
        
        for(int i=0;i<s.size();i++){
            m[find(nodes,nodes[i])].push_back(i);  //pushing the index to the parent indx map
        }
        
        for(int i=0;i<s.size();i++){
            
            string temp="";
            
            for(int j=0;j<m[i].size();j++){
                temp+=s[m[i][j]];            //temp  contains str of chars that are in 1tree
            }
            sort(begin(temp),end(temp));    //sort the temp since connected grapg char always in lex-order
            for(int k=0;k<m[i].size();k++){
                s[m[i][k]]=temp[k];     // place sort ele in temp back in right indx of initial str
            }
        }
        
        return s;
        
    }
};
