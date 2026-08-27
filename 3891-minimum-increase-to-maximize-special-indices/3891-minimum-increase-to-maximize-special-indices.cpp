class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        // Prefix cost for odd indices: 1,3,5,...
        vector<long long> odd_pref(n,0);
        for(int i=1;i<n-1;i+=2){
            long long need=max(nums[i-1],nums[i+1])+1LL;
            if (nums[i]<need){
                ans+=need-nums[i];
            }
            odd_pref[i]=ans;
        }
        // If n is odd, odd indices are the only possible choice
        if(n%2==1){
            return ans;
        }
        // Suffix cost for even indices: 2, 4, 6, ...
        long long temp=0;
        vector<long long> even_suff(n,0);
        for (int i=n-2;i>=2;i-=2){
            long long need=max(nums[i-1],nums[i+1])+1LL;
            if (nums[i]<need){
                temp+=need-nums[i];
            }
            even_suff[i]=temp;
        }
        // Take only even indices
        ans=min(ans,temp);
        // Try every possible point where
        // we switch from odd indices to even indices
        for(int i=2;i<n-2;i+=2){
            ans=min(ans,odd_pref[i-1]+even_suff[i+2]);
        }
        return ans;
    }
};