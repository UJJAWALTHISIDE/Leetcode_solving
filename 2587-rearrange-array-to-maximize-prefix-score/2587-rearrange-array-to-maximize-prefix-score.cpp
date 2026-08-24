class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        vector<long long> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(pre[i]>0){
                count++;
            }
        }
        return count;
    }
};