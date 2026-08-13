class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        unordered_map<char, int> mp;
        for (char c : word2) {
            mp[c]++;
        }
        int left = 0;
        int remaining = word2.size();
        long long ans = 0;
        for (int right = 0; right < n; right++) {
            char c = word1[right];
            if (mp[c] > 0) {
                remaining--;
            }
            mp[c]--;
            while (remaining == 0) {
                ans += n - right;
                char leftChar = word1[left];
                mp[leftChar]++;
                if (mp[leftChar] > 0) {
                    remaining++;
                }
                left++;
            }
        }
        return ans;
    }
};