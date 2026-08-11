class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k<0){
            return 0;
        }
        int l=0;
        int r=0;
        int cnt=0;
        unordered_map<int, int> mpp;
        while (r<nums.size()){
            mpp[nums[r]]++;
            while (mpp.size()>k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt+= r-l+1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};