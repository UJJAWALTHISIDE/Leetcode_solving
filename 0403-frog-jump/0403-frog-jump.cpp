
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (stones[1] != 1) return false;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= n; k++) {
                if (!dp[i][k]) continue;

                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump <= 0) continue;

                    int next = stones[i] + jump;

                    if (mp.find(next) != mp.end()) {
                        int j = mp[next];
                        dp[j][jump] = true;

                        if (j == n - 1) return true;
                    }
                }
            }
        }

        return n == 1;
    }
};
