class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> marked(nums.size(),0);
        int count=0;
        for(int i=0;i<nums.size();i++) {
            if(marked[i]) continue;
            int x=nums[i];
            vector<int> idx;
            for(int j=i;j<nums.size();j++) {
                if(nums[j]==x){
                    marked[j]=1;
                    idx.push_back(j);
                }
            }
            int ok=1;
            for(int k=0;k+1<idx.size();k++) {
                if(idx[k+1]-idx[k]!=1) {
                    ok=0;
                    break;
                }
            }
            if(ok) count++;
        }
        return count;
    }
};