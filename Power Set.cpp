// https://practice.geeksforgeeks.org/problems/power-set4302/1


	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    
		    vector<string> p;
		    int n = s.size();
		    
		    for( int  i = 0 ; i <= pow(2,n)-1  ; i++ )
		    {
		        string subs="";
		        
		        for( int j = 0; j <= n-1 ; j++ )
		        {
		            if( (i&(1<<j))!=0 )
		            {
		                subs+=s[j];
		            }
		        }
		        if(subs!=""){
		            p.push_back(subs);
		        }
		    }
		    sort(p.begin(),p.end());
		    return p;
		}
