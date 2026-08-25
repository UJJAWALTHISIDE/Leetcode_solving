class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int last=INT_MIN;
        for (int x:nums){
            int low=x-k;
            int high=x+k;
            int curr=max(low,last+1);
            if 
            (curr<=high){
                ans++;
                last=curr;
            }
        }
        return ans;
    }
};