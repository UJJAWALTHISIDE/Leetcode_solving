class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        vector<int> ans;
        while (!mp.empty()){
            for (auto it=mp.begin();it!=mp.end();){
                ans.push_back(it->first);
                it->second--;
                if(it->second==0){
                    it=mp.erase(it);
                }else{
                    it++;
                }
            }
        }
        return ans; 
    }
};