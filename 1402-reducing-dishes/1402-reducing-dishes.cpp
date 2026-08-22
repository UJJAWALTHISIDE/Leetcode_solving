class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(),satisfaction.rend());
        int sum=0;
        int ans=0;
        for (int x:satisfaction){
            sum+=x;
            if(sum<=0){
                break;
            }
            ans+=sum;
        }
        return ans;
    }
};