class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        while(k>0){
            int mini=*min_element(nums.begin(), nums.end());
            for(int i=0;i<nums.size();i++) {
                if(nums[i]==mini) {
                    nums[i]=-nums[i];
                    break;
                }
            }
            k--;
        }
        int sum=0;
        for(int x:nums) {
            sum+=x;
        }
        return sum;
    }
};