class Solution {
public:
    bool checkValidString(string s) {
        vector<int> open;
        vector<int> star;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='('){
                open.push_back(i);
            }
            else if(s[i]=='*') {
                star.push_back(i);
            }
            else{
                if(!open.empty()){
                    open.pop_back();
                }
                else if (!star.empty()){
                    star.pop_back();
                }
                else{
                    return false;
                }
            }
        }
        while (!open.empty() && !star.empty()) {
            if(open.back()<star.back()){
                open.pop_back();
                star.pop_back();
            }
            else{
                return false;
            }
        }
        return open.empty();
    }
};