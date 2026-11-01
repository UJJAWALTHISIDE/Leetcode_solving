class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n=nums.size();
        vector<string> v;
        int ans=INT_MAX;
        for(int i=0;i<n;i+=2){
            string a= to_string(nums[i]);
            string b= to_string(nums[i+1]);
            string c=a+b;
            ans = min(ans,stoi(c));
        } 
        return ans;
    }
};