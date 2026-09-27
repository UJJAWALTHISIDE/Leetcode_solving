class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        int left=-1;
        int right=-1;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='(') {
                left=i;
            }
            if (s[i]==')' && left!=-1) {
                right=i;
                break;
            }
        }
        if (left==-1){
            return s;
        }
        string inside="";
        for (int i=left+1;i<right;i++) {
            inside+=s[i];
        }
        reverse(inside.begin(), inside.end());
        string temp="";
        for (int i=0;i<left;i++) {
            temp+=s[i];
        }
        temp+=inside;
        for (int i=right+1;i<s.size();i++) {
            temp+=s[i];
        }
        return reverseParentheses(temp);
    }
};