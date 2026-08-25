class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        int i=0;
        int j=0;
        int h=1;
        int v=1;
        long long ans=0;
        while (i<m-1 || j<n-1){
            if (j==n-1 || (i<m-1 && horizontalCut[i]>verticalCut[j])){
                // Horizontal cut
                ans+=1LL*horizontalCut[i]*v;
                i++;
                h++;
            }
            else {
                // Vertical cut
                ans+=1LL*verticalCut[j]*h;
                j++;
                v++;
            }
        }
        return ans; 
    }
};