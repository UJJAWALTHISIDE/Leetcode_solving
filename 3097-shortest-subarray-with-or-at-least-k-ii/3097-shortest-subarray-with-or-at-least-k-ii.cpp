class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=n+1;
        vector<int> bitCount(32,0);
        int currentOR=0;
        int left=0;
        for (int right=0;right<n;right++){
            for(int bit=0;bit<32;bit++){
                if(nums[right] & (1<<bit)){
                    bitCount[bit]++;
                    currentOR |= (1<<bit);
                }
            }
            while (left<=right && currentOR>=k){
                ans=min(ans,right-left+1);
                for(int bit=0;bit<32;bit++){
                    if (nums[left] & (1<<bit)){
                        bitCount[bit]--;
                        if(bitCount[bit]==0){
                            currentOR &= ~(1<<bit);
                        }
                    }
                }
                left++;
            }
        }
        return ans == n+1 ? -1 : ans;
    }
};