class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n=nums.size();
        int mx=0;
        int unlock=0;
        for (int i=0;i<n;i++) {
            mx = max(mx,nums[i]);
            bool boundary=(nums[i]==i+1 && mx==i+1);
            if (locked[i]==1 && !boundary){
                unlock++;
            }
        }
        if(unlock>k) return -1;
        int swaps=0;
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                if (nums[i]>nums[j]) {
                    swaps++;
                }
            }
        }
        return unlock+swaps;
    }
};