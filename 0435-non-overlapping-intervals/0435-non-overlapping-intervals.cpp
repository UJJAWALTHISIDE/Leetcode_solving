class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1]<b[1];
        });
        int end=intervals[0][1];
        int remove=0;
        for (int i=1;i<intervals.size();i++){
            if (intervals[i][0]<end){
                // Overlap → remove current interval
                remove++;
            }else{
                // No overlap → keep current interval
                end = intervals[i][1];
            }
        }
        return remove;
    }
};