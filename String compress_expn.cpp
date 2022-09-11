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
        string s1;
        string s2="";
        s1 = s[i];  //can assign a char to str
        int j;
        for(j=i+1;j<n;j++){
            
            if((s[j]-'0')>=0 && (s[j]-'0')<=9){    // char-'0' gives no >= 0
                s2 += s[j]; // s2.push_back(s1) is same as this for concat oper
                continue;
            }
            break;
        }
        char c = s1[0];
        m[c] += stoi(s2);   // convert str to int using stoi
        i=j-1;
    }  
    string ans="";
    for(auto i=m.begin();i!=m.end();i++){
        //cout<<i->first<<" "<<i->second;
        ans.push_back(i->first);   // push_back or += for append char
        ans += to_string(i->second);  //convert int to str using to_string
                                           //and then add to string using += or // append.
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
