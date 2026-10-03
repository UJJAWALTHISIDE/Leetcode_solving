class Solution {
public:
    int climbStairs(int n) {
        // if(n==1 || n == 0)return 1;
        if(n==1)return 1;
        if(n==2)return 2;
        int prev =1;
        int pres = 2;


        for(int i=3;i<=n;i++){
            int temp = prev+pres;
            prev = pres;
            pres = temp;
            
        }
        return pres;
    }
};