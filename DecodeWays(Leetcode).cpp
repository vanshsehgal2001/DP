#include<bits/stdc++.h>
class Solution {
public:
    
    static int helperRec(string s,int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            if(s[n-1]=='0'){
                return 0;
            }
            return 1;
        }
        if(s[n-2]=='0' && s[n-1]=='0'){
            return 0;
        }
        if(s[n-2]=='0' && s[n-1]!='0'){
            return helperRec(s,n-1);
        }
        if(s[n-2]!='0' && s[n-1]=='0'){
            if(s[n-2]>='1' && s[n-2]<='2'){
                return helperRec(s,n-1)+helperRec(s,n-2);
            }
            else{
                return helperRec(s,n-1);
            }
        }
        if(s[n-2]!='0' && s[n-1]!='0'){
            if((s[n-2]>='1' && s[n-2]<='2') && (s[n-1]>='1' && s[n-1]<='6')){
                return helperRec(s,n-1)+helperRec(s,n-2);
            }
            else{
                return helperRec(s,n-1);
            }
        }
        return 0;
    }
    
    static int helperDP(string s,int n){
        if (s.empty()) return 0;
        if (s[0] == '0') return 0;
        
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < s.size(); ++i) {
            char c = s[i];
            if (c == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    if (i < 2) dp[i] = 1;
                    else dp[i] = dp[i-2];
                }
                else return 0;
            } else {
                if (s[i-1] == '1' || s[i-1] == '2' && c <= '6') {
                    if (i < 2) dp[i] = 2;
                    else dp[i] = dp[i-2] + dp[i-1];
                } else {
                    dp[i] = dp[i-1];
                }
            }
        }
        
        return dp.back();
    }
    
    int numDecodings(string s) {
        // return helperRec(s,s.size());
        return helperDP(s,s.size());
    }
};
