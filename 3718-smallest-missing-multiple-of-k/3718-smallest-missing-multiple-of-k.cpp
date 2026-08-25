class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=-1;
        int j=1;
        for(int i=0;i<nums.size();i++){
            int find=k*j;
            int m=i;
            int check=0;
            while(m<nums.size()){
                if(nums[m]==find){
                    check=1;
                }
                m++;
            }
            if(!check){
                ans=find;
                break;
            }
            j++;
        }
        if(ans==-1) return k*(nums.size()+1);
        return ans;
    }
};