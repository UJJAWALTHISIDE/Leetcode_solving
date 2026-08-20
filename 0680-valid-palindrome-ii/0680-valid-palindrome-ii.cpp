class Solution {
public:
    bool check(string &s,int i,int j) {
        while (i<j){
            if (s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        for (int i=0;i<n/2;i++) {
            if (s[i]!=s[n-i-1]) {
                if (check(s,i+1,n-i-1))
                    return true;
                if (check(s,i,n - i - 2))
                    return true;
                return false;
            }
        }
        return true;
    }
};