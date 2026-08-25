class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> rightMost(n+1,0);
        for(int i=0;i<=n;i++) {
            int left=max(0,i-ranges[i]);
            int right = min(n,i+ranges[i]);
            rightMost[left]=max(rightMost[left],right);
        }
        int ans=0;
        int currEnd=0;
        int farthest=0;
        for(int i=0;i<=n;i++){
            farthest=max(farthest,rightMost[i]);
            if(i==currEnd){
                if(farthest<=i){
                    return -1;
                }
                ans++;
                currEnd=farthest;
                if (currEnd>=n){
                    return ans;
                }
            }
        }
        return -1;
    }
};