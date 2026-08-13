class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden){
        unordered_set<string> st;
        for(string s : forbidden) {
            st.insert(s);
        }
        int left=0;
        int ans=0;
        for(int right=0;right<word.size();right++) {
            for(int len=1;len<=10;len++) {
                int start=right-len+1;
                if(start<left){
                    break;
                }
                string s = word.substr(start,len);
                if(st.count(s)) {
                    left=start+1;
                    break;
                }
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};