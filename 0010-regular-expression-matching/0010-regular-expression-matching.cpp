class Solution {
public:
    int dp[21][21];
    bool solve(int i,int j,string& s,string& p){
        if(i==s.size() && j==p.size()){
            return true;
        }
        if(j>=p.size()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool match=(i<s.size() && (s[i]==p[j] || p[j]=='.'));
        if (j+1<p.size() && p[j+1]=='*'){
            return dp[i][j]=solve(i,j+2,s,p) || (match && solve(i+1,j,s,p));
        }
        if(match){
            return dp[i][j]=solve(i+1,j+1,s,p);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        for (int i=0;i<21;i++){
            for (int j=0;j<21;j++) {
                dp[i][j]=-1;
            }
        }
        return solve(0,0,s,p);
    }
};
