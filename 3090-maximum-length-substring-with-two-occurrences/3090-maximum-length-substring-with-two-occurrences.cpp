class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char, int> mp;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            while (mp[s[right]] > 2) {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};