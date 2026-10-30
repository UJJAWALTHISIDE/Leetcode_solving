class Solution {
public:
    bool isFib(int n,int a=0,int b=1){
        if (a==n || b==n){
            return true;
        }
        if(a>n){
            return false;
        }
        return isFib(n,b,a+b);
    }
    bool threeFibonacciSum(int n) {
        if(isFib(n/2) && n%2==0){
            return true;
        }else{
            return false;
        }
    }
};