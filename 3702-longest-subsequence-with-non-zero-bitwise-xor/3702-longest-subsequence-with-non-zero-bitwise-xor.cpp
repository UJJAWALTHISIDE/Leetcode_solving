class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xor1=0;
        for(int i=0;i<n;i++){
            xor1 ^=nums[i];
        }
        int ans=n;
        if(xor1!=0){
            return ans;
        }else{
            int count1=count(nums.begin(),nums.end(),0);
            if(count1==n){
                return 0;
            }
            return ans-1;
        }
    }
};