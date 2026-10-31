class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        sort(availableIntervals.begin(), availableIntervals.end());
        sort(targetIntervals.begin(), targetIntervals.end());
        int best=0,reach=0;
        int i=0,n=availableIntervals.size();
        int cnt=0;
        for (auto& it:targetIntervals){
            int a=it[0],b=it[1];
            while (reach<b){
                int limit=max(reach,a);
                while (i<n && availableIntervals[i][0]<=limit){
                    best = max(best,availableIntervals[i][1]);
                    i++;
                }
                if(best<=reach || best<a)
                    return -1;
                reach=best;
                cnt++;
            }
        }
        return cnt;
    }
};