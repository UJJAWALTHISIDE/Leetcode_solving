class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss=1;
        int patches=0;
        int i=0;
        while (miss<=n){
            if (i<nums.size() && nums[i]<=miss) {
                miss+=nums[i];
                i++;
            } 
            else{
                // as we can take values from the 1 to miss and add in miss getting till the 2*miss-1
                miss+=miss;
                patches++;
            }
        }
        return patches;
    }
};