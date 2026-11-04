class Solution {
public:
    const long long MOD=1000000007;
    long long modpow(long long x,long long y) {
        long long ans=1;
        while (y>0){
            if (y%2==1){
                ans=(ans*x)%MOD;
            }
            x=(x*x)%MOD;
            y/=2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        const long long MOD=1e9+7;
        long long ans=0;
        for (int i=0;i<nums.size();i++){
            int width=nums[i]%10;
            long long d=nums[i]/10;
            string s=to_string(d);
            long long x=stoll(s.substr(0,width));
            long long y=stoll(s.substr(width));
            long long product=modpow(x,y);
            ans=(ans+product)%MOD;
        }
        return ans;
    }
};