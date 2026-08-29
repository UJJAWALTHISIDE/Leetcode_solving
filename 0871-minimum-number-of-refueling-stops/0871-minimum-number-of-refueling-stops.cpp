class Solution {
public:
    int minRefuelStops(int target,int startFuel,vector<vector<int>>& stations) {
        int n=stations.size();
        long long reach=startFuel;
        int ans=0;
        vector<bool> used(n,false);
        while(reach<target){
            int maxFuel=0;
            int index=-1;
            for(int i=0;i<n;i++){
                if(!used[i]&&stations[i][0]<=reach){
                    if(stations[i][1]>maxFuel){
                        maxFuel=stations[i][1];
                        index=i;
                    }
                }
            }
            if(index==-1){
                return -1;
            }
            used[index]=true;
            reach+=stations[index][1];
            ans++;
        }
        return ans;
    }
};