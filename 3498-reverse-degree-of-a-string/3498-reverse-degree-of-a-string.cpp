class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int ch=s[i]-'a';
            ch=26-ch;
            ans+=ch*(i+1);
        }
        return ans;
    }
};