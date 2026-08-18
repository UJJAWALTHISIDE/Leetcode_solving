class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128]={};
        for(char c:s){
            freq[c]++;
        }
        int ans=0;
        bool odd=false;
        for(int i=0;i<128;i++){
            ans+=(freq[i]/2)*2;
            if(freq[i]%2==1){
                odd=true;
            }
        }
        if(odd) ans++;
        return ans;
    }
};