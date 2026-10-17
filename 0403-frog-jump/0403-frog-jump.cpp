
class Solution {
public:
    unordered_map<int, int> mp;
    vector<vector<int>> dp;
    int n;
    vector<int> stones;

    bool solve(int i, int k) {
        if (i == n - 1) return true;

        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        for (int jump = k - 1; jump <= k + 1; jump++) {
            if (jump <= 0) continue;

            int next = stones[i] + jump;

            if (mp.find(next) != mp.end()) {
                int j = mp[next];

                if (solve(j, jump)) {
                    return dp[i][k] = true;
                }
            }
        }

        return dp[i][k] = false;
    }

    bool canCross(vector<int>& s) {
        stones = s;
        n = stones.size();

        if (n == 1) return true;
        if (stones[1] != 1) return false;

        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 0);
    }
};
