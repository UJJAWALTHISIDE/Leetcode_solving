class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==2 && s[0]>s[1]) return -1;
        if(is_sorted(s.begin(),s.end())){
            return 0;
        }
        char mn=*min_element(s.begin(),s.end());
        char mx=*max_element(s.begin(),s.end());
        if (s[0]==mn || s[n-1]==mx){
            return 1;
        }
        // Minimum ya maximum beech mein hai
        for (int i=1;i<n-1;i++){
            if (s[i]==mn || s[i]==mx)
                return 2;
        }
        // Case 3:
        // First character maximum hai aur
        // Last character minimum hai
        // Dono extremes ko sahi jagah lane ke liye
        // 3 operations lagenge
        return 3;
    }
};