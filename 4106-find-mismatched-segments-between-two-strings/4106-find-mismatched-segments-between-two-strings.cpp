class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int n1=s1.size();
        int n2=s2.size();
        int i=0;
        int j=0;
        string s="";
        string t="";
        while(i<n1 && j<n2){
            if(s1[i]==s2[j]){
                if(s!="" && t!=""){
                    ans.push_back({s,t});
                    s="";
                    t="";
                }
            }else{
                s+=s1[i];
                t+=s2[j];
            }
            i++;
            j++;
        }
        if(s!="" && t!=""){
            ans.push_back({s,t});
        }
        return ans;
    }
};