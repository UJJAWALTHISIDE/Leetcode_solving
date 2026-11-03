class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int ans=0;
        for (int r=0;r<n;r++){
            bool invalid = false;
            while (true){
                invalid=false;
                for (int i=l;i<=r;i++){
                    for (int j=i+1;j<=r;j++){
                        for (int k=l;k<=r;k++){
                            if (k==i || j==k) continue;
                            if (nums[i]+nums[j]==nums[k]){
                                invalid=true;
                                break;
                            }
                        }
                        if (invalid) break;
                    }
                    if (invalid) break;
                }
                if (!invalid) break;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};