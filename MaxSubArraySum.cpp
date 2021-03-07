#include<climits>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int start_sum=INT_MIN;
        int end_sum=0;
        for(int i=0;i<nums.size();i++){
            end_sum+=nums[i];
            if(start_sum<end_sum){
                start_sum=end_sum;
            }
            if(end_sum<0){
                end_sum=0;
            }
        }
        return start_sum;
    }
};
