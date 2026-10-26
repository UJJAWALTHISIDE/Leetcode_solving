class Solution {
public:
    long long makemax(int n){
        vector<int> v;
        while(n!=0){
            v.push_back(n%10);
            n=n/10;
        }
        sort(v.rbegin(),v.rend());
        long long maxi=0;
        for(int i=0;i<v.size();i++){
            maxi=maxi*10+v[i];
        }
        return maxi;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum=0;
        vector<long long> v;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            v.push_back(makemax(nums[i])-nums[i]);
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<k && i<v.size();i++){
            if(v[i]>0){
                sum+=v[i];
            }
        }
        return sum;
    }
};