class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<queue<int>> pos(10);
        for (int i=0;i<s.size();i++) {
            pos[s[i]-'0'].push(i);
        }
        for (char c:t) {
            int d=c-'0';
            if (pos[d].empty()){
                return false;
            }
            int idx = pos[d].front();
            // A smaller digit cannot be before d,
            // smaller digits can't cross , also we are assuming that we placed it in correct poition the ones we are processed.
            for (int x=0;x<d;x++) {
                if (!pos[x].empty() && pos[x].front()<idx)
                    return false;
            }
            pos[d].pop();
        }
        return true;
    }
};