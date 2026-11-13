
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int head = n, tail = n;
        int r = n - 1;

        vector<int> starts(n);

        long long ans = 0;
        long long water = 0;

        for (int l = n - 1; l >= 0; --l) {
            int x = nums[l];

            // Merge plateaus whose values are <= current element
            while (head < tail && nums[starts[head]] <= x) {
                int s = starts[head++];

                int end = (head < tail) ? starts[head] : r + 1;

                water += 1LL * (x - nums[s]) * (end - s);
            }

            // Insert the new plateau
            starts[--head] = l;

            // Shrink the window while operations exceed k
            while (water > k) {
                water -= nums[starts[tail - 1]] - nums[r];

                if (starts[tail - 1] == r) {
                    --tail;
                }

                --r;
            }

            // Every subarray [l, l...r] is valid
            ans += r - l + 1;
        }

        return ans;
    }
};
