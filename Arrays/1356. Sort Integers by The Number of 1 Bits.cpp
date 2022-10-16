//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        
    map<int,multiset<int>>m;
    vector<int>ans;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        int num=arr[i];
        while(num>0){
            if (num&1){
                cnt++;
            }
            num = num>>1;
        }
        m[cnt].insert(arr[i]);
    }
    
    //map<int, set<int>>::reverse_iterator itr;
    //for(auto itr=m.rbegin();itr!=m.rend();itr++){
    for(auto itr=m.begin();itr!=m.end();itr++){
        for(auto j: itr->second){
            ans.push_back(j);
        }
    }
        return ans;
        
    }
};
