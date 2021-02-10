#include <iostream>
using namespace std;

//SIMPLE RECURSION
int simFib(int n){
    if(n<=1){
        return n;
    }
    return simFib(n-1)+simFib(n-2);
}

//DP
int dpFib(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    // cout<<simFib(n)<<endl;
    cout<<dpFib(n)<<endl;
    return 0;
}
