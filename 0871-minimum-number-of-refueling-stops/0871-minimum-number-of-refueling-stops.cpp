class Solution {
public:
    int minRefuelStops(int target,int startFuel,vector<vector<int>>& stations) {
        int n=stations.size();
        priority_queue<int> pq;
        long long reach=startFuel;
        int ans=0;
        int i=0;
        while(reach<target) {
            while(i<n&&stations[i][0]<=reach) {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()){
                return -1;
            }
            reach+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};