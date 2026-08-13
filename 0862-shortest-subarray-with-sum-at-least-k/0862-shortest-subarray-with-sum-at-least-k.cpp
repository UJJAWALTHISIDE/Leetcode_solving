class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1,0);
        for (int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        deque<int> dq;
        int ans=n+1;
        for (int j=0;j<=n;j++){
            while (!dq.empty() && prefix[j]-prefix[dq.front()]>=k){
                ans=min(ans,j-dq.front());
                dq.pop_front();
            }
            // Remove useless indices -, if current prefix which is greater can give >=k , so the incoming will also give (if less) as it [increases the diff] also since question asked for the shortest length , so length is also dec to take the forward ones
            while (!dq.empty() && prefix[dq.back()]>=prefix[j]){
                dq.pop_back();
            }
            dq.push_back(j);
        }
        return ans==n+1 ? -1 : ans;
    }
};