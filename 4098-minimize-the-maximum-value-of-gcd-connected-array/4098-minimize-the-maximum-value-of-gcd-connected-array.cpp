class Solution {
public:
    long long smallestPrimeFactor(long long x) {
        if (x%2==0) return 2;
        for (long long i=3;i*i<=x;i+=2) {
            if (x%i==0)
                return i;
        }
        return x;
    }
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1) return -1;
        long long pf=smallestPrimeFactor(value);
        if(index>0 && value-pf< 2LL*index){
            return -1;
        }
        long long r=n-1LL-index;
        if (r==0) return value;
        if (value%2==0){
            return value+2LL*r;
        }
        return value+pf+2LL*(r-1);
    }
};