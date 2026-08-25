class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x:nums){
            mp[x]++;
        }
        int ans=0;
        for (auto it:mp){
            int freq=it.second;
            if(freq==1){
                return -1;
            }
            if (freq%3==0){
                ans+=freq/3;
            }
            else if(freq%3==2){
                ans+=freq/3;
                ans+=1;
            }else{
                freq-=4;
                ans+=2;
                if (freq>0){
                    ans+=freq/3;
                }
            }
        }
        return ans;
    }
};