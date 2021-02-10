#include <iostream>
using namespace std;

// //SIMPLE LOOPING
// int helper(int a,int b){
//     while(a%b==0){
//         a/=b;
//     }
//     return a;
// }

// int getNthUglyNum(int n){
//     n=helper(n,2);
//     n=helper(n,3);
//     n=helper(n,5);
    
//     if(n==1){
//         return 1;
//     }
//     return 0;
// }

// int solve(int n){
//     int ans=1;
//     int count=1;
//     while(count<n){
//         ans++;
//         if(getNthUglyNum(ans)){
//             count++;
//         }
//     }
//     return ans;
// }

//DP
int solve(int n){
    int arr[n];
    arr[0]=1;
    int ind1=0;
    int ind2=0;
    int ind3=0;
    int num1=arr[ind1]*2;
    int num2=arr[ind2]*3;
    int num3=arr[ind3]*5;
    int num=1;
    for(int i=1;i<n;i++){
        num=min(num1,min(num2,num3));
        arr[i]=num;
        if(num==num1){
            ind1=ind1+1;
            num1=arr[ind1]*2;
        }
        if(num==num2){
            ind2=ind2+1;
            num2=arr[ind2]*3;
        }
        if(num==num3){
            ind3=ind3+1;
            num3=arr[ind3]*5;
        }
    }
    return num;
}

int main()
{
    int n;
    cin>>n;
    // cout<<solve(n)<<endl;
    cout<<solve(n)<<endl;
    return 0;
}
