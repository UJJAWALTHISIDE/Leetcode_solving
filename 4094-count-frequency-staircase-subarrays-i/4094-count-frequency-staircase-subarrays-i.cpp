class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int left=0;left<n;left++){
            unordered_map<int,int> mp;
            vector<int> v;
            for(int right=left;right<n;right++){
                if(mp[nums[right]]==0){
                    v.push_back(nums[right]);
                }
                mp[nums[right]]++;
                bool flag=true;
                for(int i=0;i<v.size();i++){
                    if(mp[v[i]]!=i+1){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    ans++;
                }
            }
        }
        return ans;
    }
};