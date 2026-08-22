class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int len = n + m - 1;
        string ans(len, 'a');
        vector<bool> fixed(len, false);
        // Step 1: Handle all 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] != 'T')
                continue;
            for (int j = 0; j < m; j++) {
                int pos = i + j;
                // Conflict with an already fixed position
                if (fixed[pos] && ans[pos] != str2[j])
                    return "";
                ans[pos] = str2[j];
                fixed[pos] = true;
            }
        }
        // Step 2: Handle all 'F'
        for (int i = 0; i < n; i++) {
            if (str1[i] != 'F')
                continue;
            // Check whether current substring equals str2
            bool same = true;
            for (int j = 0; j < m; j++) {
                if (ans[i + j] != str2[j]) {
                    same = false;
                    break;
                }
            }
            // Already different -> F condition satisfied
            if (!same)
                continue;
            // Need to make it different.
            // Change the rightmost unfixed position.
            bool changed = false;
            for (int j = i + m - 1; j >= i; j--) {
                if (!fixed[j]) {
                    ans[j] = 'b';
                    changed = true;
                    break;
                }
            }
            // Every position was fixed by T
            if (!changed)
                return "";
        }
        return ans;
    }
};