class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int mid=(n-1)/2;
        auto solve = [&](int left) {
            unordered_map<int,int> freq,rank;
            int distinct=0,bad=0;
            for(int right=left;right<n;right++){
                int x=nums[right];
                if(freq.find(x)==freq.end()){
                    distinct++;
                    rank[x]=distinct;
                    freq[x]=1;
                    if(freq[x]!=rank[x]){
                        bad++;
                    }
                }
                else{
                    if(freq[x]!=rank[x]){
                        bad--;
                    }
                    freq[x]++;
                    if(freq[x]!=rank[x]){
                        bad++;
                    }
                }
                if(bad==0){
                    ans++;
                }
            }
        };
        for(int left=0;left<=mid;left++){
            solve(left);
        }
        for(int left=n-1;left>mid;left--){
            solve(left);
        }
        return ans; 
    }
};