class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=((pre[i]+nums[i])%k+k)%k;
        }
        vector<int> first(k,n+1);
        vector<int> last(k,-1);
        for(int i=0;i<=n;i++){
            if(first[pre[i]]==n+1){
                first[pre[i]]=i;
            }
            last[pre[i]]=i;
        }
        int ans=0;
        for(int i=0;i<k;i++){
            if(last[i]!=-1){
                ans=max(ans,last[i]-first[i]);
            }
        }
        vector<vector<int>> pos(k);
        for(int i=0;i<n;i++){
            int rem=((2LL*nums[i])%k+k)%k;
            pos[rem].push_back(i);
        }
        vector<int> order;
        for(int i=0;i<k;i++){
            if(last[i]!=-1){
                order.push_back(i);
            }
        }
        sort(order.begin(),order.end(),[&](int a,int b){
            return first[a]<first[b];
        });
        for(int d=0;d<k;d++){
            int ptr=0;
            for(int a:order){
                int l=first[a];
                int b=(a+d)%k;
                int r=last[b];
                if(r <= l){
                    continue;
                }
                while(ptr<(int)pos[d].size() && pos[d][ptr]<l){
                    ptr++;
                }
                if(ptr<(int)pos[d].size() && pos[d][ptr]<r){
                    ans=max(ans,r-l);
                }
            }
        }
        return ans;
    }
};