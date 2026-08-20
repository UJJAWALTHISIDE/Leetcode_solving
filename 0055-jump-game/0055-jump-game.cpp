class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0;
        for (int i=0;i<nums.size();i++) {
            // Current index itself is unreachable
            if (i>maxReach){
                return false;
            }
            // Update the farthest position we can reach
            maxReach=max(maxReach,i+nums[i]);
        }
        return true;
    }
};