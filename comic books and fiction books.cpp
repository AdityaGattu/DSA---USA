// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;

int main() {
    // Write C++ code here
    int cb,coins,coins_to_buy,cs_onsell;
    cin>>cb>>coins>>coins_to_buy>>cs_onsell;
    
    int sold_cb;
    float temp;
    
    //SOLVING THE ABOVE a=b
    temp = ((coins_to_buy * cb) - coins)/float(cs_onsell+coins_to_buy);
    sold_cb  =  ((coins_to_buy * cb) - coins)/(cs_onsell+coins_to_buy);
    cout<<"temp and sold_cb"<<temp <<" "<< sold_cb<<" \n";
    
    if(temp - sold_cb >0){sold_cb+=1;}
    
    int a = cb - sold_cb;
    int b = (coins + (cs_onsell * sold_cb))/coins_to_buy;
    
    cout<<"values of a and b is: "<<a <<" "<<b<<" \n";
    
    if(sold_cb <=0){sold_cb =0;}
    else{
        sold_cb = min(a,b);
    }
    
     cout<<sold_cb;
    
    return 0;
}

/tmp/BPfom7XXYT.o
393 896 787 920
temp and sold_cb180.665 180 
values of a and b is: 212 212 
212
