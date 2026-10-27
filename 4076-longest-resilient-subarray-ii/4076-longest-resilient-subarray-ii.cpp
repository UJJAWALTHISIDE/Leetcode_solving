class Solution {
public:
    long long resilientSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int ans=1;
        int i=0;
        for(int j=i;j<n;j++){
            while(nums[j]%k!=nums[i]%k){
                i++;
            }
            long long sum=pre[j]-(i>0 ? pre[i-1]:0);
            if(sum%k==nums[i]%k){
                ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};