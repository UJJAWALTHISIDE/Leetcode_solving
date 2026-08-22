class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+arr[i];
        }
        int total = pre[n - 1];
        if (total%3!=0){
            return false;
        }
        int target=total/3;
        for (int i=0;i<n-2;i++){
            if (pre[i]!=target){
                continue;
            }
            for (int j=i+1;j<n-1;j++){
                if (pre[j]==2*target){
                    return true;
                }
            }
        }
        return false;
    }
};