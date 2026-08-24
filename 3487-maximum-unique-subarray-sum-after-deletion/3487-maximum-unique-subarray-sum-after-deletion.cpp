class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int sum=nums[0];
        int last=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=last && nums[i]>=0){
                sum+=nums[i];
                last=nums[i];
            }
        }
        return sum;
    }
};