class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<int> power(n);
        power[0] = 1;
        // power[i] = 2^i
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2LL) % mod;
        }
        int left = 0;
        int right = n - 1;
        long long ans = 0;
        while (left <= right) {
            // left minimum hai aur right maximum
            if (nums[left] + nums[right] <= target) {
                // left ko lena compulsory hai
                // left+1 se right tak har element ko
                // le sakte hain ya nahi le sakte
                // isliye 2^(right-left) combinations
                ans = (ans + power[right - left]) % mod;
                left++;
            }
            else {
                // maximum bahut bada hai
                // isliye right ko decrease karo
                right--;
            }
        }
        return ans;
    }
};