class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int l=0;
        int ans=0;
        for (int r=0;r<nums.size();r++) {
            mpp[nums[r]]++;
            while (mpp[nums[r]]>k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};