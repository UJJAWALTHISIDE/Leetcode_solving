class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,int indexDiff,int valueDiff) {
        set<long long> window;
        for (int i = 0; i < nums.size(); i++) {
            auto it = window.lower_bound((long long)nums[i] - valueDiff);
            if (it != window.end() && *it <= (long long)nums[i]+valueDiff) {
                return true;
            }
            window.insert(nums[i]);
            // indexdiff -> no of indices can be there , so like 3 can take 0-3 when 4 come 0 remove and 4 take..
            if (i >= indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};