
class Solution {
public:
    int minInsertions(string s) {
        int open=0;
        int ans=0;
        int n=s.size();
        for (int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }else{
                if(i+1<n && s[i+1]==')'){
                    if(open>0){
                        open--;
                    }else{
                        ans++;
                    }
                    i++;
                }else{  // ) nothing like this
                    ans++;
                    if(open>0){
                        open--;
                    }else{
                        ans++;
                    }
                }
            }
        }
        return ans+2*open;
    }
};
