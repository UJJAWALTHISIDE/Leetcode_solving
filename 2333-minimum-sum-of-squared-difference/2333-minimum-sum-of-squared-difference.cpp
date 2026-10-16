class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> cnt(100001,0);
        long long k=(long long)k1+k2;
        for (int i=0;i<nums1.size();i++){
            int d=abs(nums1[i]-nums2[i]);
            cnt[d]++;
        }
        for(int d=100000;d>0 && k>0;d--){
            long long take=min(cnt[d],k);
            cnt[d]-=take;
            cnt[d-1]+=take;
            k-=take;
        }
        long long ans=0;
        for (int d=1;d<=100000;d++){
            ans+=cnt[d]*d*d;
        }
        return ans;
    }
};