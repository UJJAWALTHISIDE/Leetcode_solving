class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[j]%k!=nums[i]%k){
                    break;
                }
                int sum=pre[j]-(i>0?pre[i-1]:0);
                if(sum%k==nums[i]%k){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};