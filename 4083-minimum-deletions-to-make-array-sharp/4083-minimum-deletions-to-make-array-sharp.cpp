class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int i=0;
        int j=0;
        while(j<n){
            if(nums[j]!=nums[i]){
                i=j;
                j++;
            }else{
                count++;
                j++;
            }
        }
        return count-1;
    }
};