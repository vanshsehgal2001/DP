class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i==0){
                arr.push_back(nums[i]);
            }
            else{
                arr.push_back(nums[i]+arr[i-1]);
            }
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0){
            return arr[j];
        }
        return arr[j]-arr[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
