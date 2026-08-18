class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total=0;
        for (int x:machines){
            total+=x;
        }
        if (total%n!=0){
            return -1;
        }
        int avg=total/n;
        int balance=0;
        int answer=0;
        for (int x:machines){
            int extra=x-avg;
            balance+=extra;
            // correcting the worst one fixes all , as it req max move which includes other small correction
            answer=max(answer,max(abs(balance),extra));
        }
        return answer;
    }
};