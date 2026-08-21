class Solution {
public:
    bool canStamp(string &target, string &stamp, int start) {
        bool changed=false;
        for (int i=0;i<stamp.size();i++) {
            if (target[start+i]=='?') {
                continue;
            }
            if(target[start+i]!=stamp[i]) {
                return false;
            }
            changed=true;
        }
        return changed;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        int m = stamp.size();
        vector<int> ans;
        int total = 0;
        while (total < n) {
            bool found = false;
            for (int i=0;i<=n-m;i++) {
                if (canStamp(target,stamp,i)) {
                    for (int j = 0; j < m; j++) {
                        if (target[i + j] != '?') {
                            target[i + j] = '?';
                            total++;
                        }
                    }
                    ans.push_back(i);
                    found = true;
                }
            }
            if (!found) {
                return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};