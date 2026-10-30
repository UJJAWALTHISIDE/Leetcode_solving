class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> prime(n+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        vector<int> ans;
        int sum=0;
        for(int i=2;i<=n;i++){
            if(prime[i]){
                if(sum+i>s){
                    break;
                }
                sum+=i;
                ans.push_back(i);
            }
        }
        return ans;
    }
};