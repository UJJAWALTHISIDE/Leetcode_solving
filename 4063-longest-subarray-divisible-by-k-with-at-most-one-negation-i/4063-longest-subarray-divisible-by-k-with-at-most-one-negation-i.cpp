class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                int rem=((2LL*nums[j])%k+k)%k;
                st.insert(rem);
                long long sum=pre[j];
                if(i>0){
                    sum=pre[j]-pre[i-1];
                }
                int s=((sum % k)+k)%k;
                if(s==0 || st.count(s)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};