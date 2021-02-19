//NOT ABLE TO FIND DP APPROACH(FOUND THIS ONE EASY)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//RECURSION
long long int ways(long long int n){
    if(n==1){
        return 9;
    }
    if(n==2){
        return 36;
    }
    int ans=0;
    int temp=9;
    for(int i=3;i<=n;i++){
        while(temp){
            int num=temp-1;
            ans+=(num*(num-1))/2;
            --temp;
        }
        temp=9;
    }
    return ans;
}

int main()
{
    long long int n;
    cin>>n;
    cout<<ways(n);
    return 0;
}
