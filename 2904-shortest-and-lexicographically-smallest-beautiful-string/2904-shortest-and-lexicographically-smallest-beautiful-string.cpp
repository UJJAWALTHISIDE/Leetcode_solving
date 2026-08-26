class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left=0;
        int count=0;
        string ans="";
        for (int right=0;right<s.size();right++) {
            if(s[right]=='1'){
                count++;
            }
            if(count>k){
                if(s[left]=='1'){
                    count--;
                }
                left++;
            }
            if(count==k){
                while(s[left]=='0'){
                    left++;
                }
                int len=right-left+1;
                string curr=s.substr(left,len);
                if(ans=="" || len<ans.size() || (len==ans.size() && curr<ans)){
                    ans=curr;
                }
            }
        }
        return ans;
    }
};