class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0;
        int pro=1;
        while(n!=0){
            int k=n%10;
            sum+=k;
            pro*=k;
            n=n/10;
        }
        int net=sum+pro;
        if(temp%net==0) return true;
        return false;
    }
};