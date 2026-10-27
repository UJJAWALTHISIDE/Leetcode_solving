class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int a=-1,b=-1;
        int pro=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target && nums[i]!=nums[j]){
                    long long z=nums[i]*nums[j];
                    if(z>pro){
                        pro=z;
                        a=i;
                        b=j;
                    }
                }
            }
        }
        if(a==b && a==-1){
            return {-1,-1};
        }
        else if(nums[a]>nums[b]){
            return {a,b};
        }else{
            return {b,a};
        }
    }
};