#include<math.h>
class Solution {
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        if(n==2){
            return 2;
        }
        
        int arr[n+1];
        arr[1]=0;
        arr[2]=2;
        
        for(int i=3;i<=n;i++){
            arr[i]=i;
            int j=i/2;
            while(j>=1){
                if(i%j==0){
                    arr[i]=min(arr[i],arr[j]+ i/j);
                    break;
                }
                j--;
            }
        }
        return arr[n];
    }
};
