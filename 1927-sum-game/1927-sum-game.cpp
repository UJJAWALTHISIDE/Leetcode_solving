class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int sum=0,cnt=0;
        for (int i=0;i<n;i++) {
            if (num[i]=='?') {
                if (i<n/2) cnt++;
                else cnt--;
            } else {
                if (i<n/2)
                    sum+=num[i]-'0';
                else
                    sum-=num[i]-'0';
            }
        }
        if (cnt==0)
            return sum != 0;
        if (abs(cnt)%2==1)
            return true;
        return sum+9*cnt/2!=0;
    }
};