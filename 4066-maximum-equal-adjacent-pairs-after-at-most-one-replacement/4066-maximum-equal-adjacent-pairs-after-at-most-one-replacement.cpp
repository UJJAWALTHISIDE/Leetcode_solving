class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int> mp;
        int base=0;
        int maxi=0;
        for (int i=0;i<nums.size()-1;i++) {
            int a=nums[i];
            int b=nums[i+1];
            // Already equal
            if (a == b) {
                base++;
            }
            else {
                // Store the pair in sorted order
                if (a>b) swap(a,b);
                mp[{a,b}]++;
                maxi=max(maxi,mp[{a,b}]);
            }
        }
        return base+maxi;
    }
};