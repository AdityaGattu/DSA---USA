#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'betterCompression' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string betterCompression(string s) {
    int n = s.size();
    map<char,int>m;

    for (int i=0;i<n;i++){
        char s1;
        string s2="";
        s1=s[i];
        int j;
        for(j=i+1;j<n;j++){
            
            if((s[j]-'0')>=0 && (s[j]-'0')<=9){
                s2.push_back(s[j]);
                continue;
            }
            break;
        }
        m[s1] += stoi(s2);
        i=j-1;
    }  
    string ans="";
    for(auto i=m.begin();i!=m.end();i++){
        //cout<<i->first<<" "<<i->second;
        ans.push_back(i->first);
        ans.append(to_string(i->second));
    }
    cout<< ans<<" ";
    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = betterCompression(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
