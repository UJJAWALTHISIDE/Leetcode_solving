class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n=sequence.size();
        int m=word.size();
        vector<int> dp(n,0);
        int ans=0;
        for (int i=n-m;i>=0;i--) {
            if (sequence.substr(i,m)==word) {
                dp[i]=1;
                if (i+m<n){
                    dp[i]+=dp[i+m];
                }
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};