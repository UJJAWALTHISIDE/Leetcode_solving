class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        vector<bool> used(26, false);
        string ans = "";
        for (int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for (int i=0;i<n;i++){
            char c=s[i];
            freq[c-'a']--;
            if (used[c-'a']) continue;
            while (!ans.empty() && ans.back()>c && freq[ans.back()-'a']>0){
                used[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c-'a']=true;
        }
        return ans;
    }
};
