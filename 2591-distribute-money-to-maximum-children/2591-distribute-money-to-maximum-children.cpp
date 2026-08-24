class Solution {
public:
    int distMoney(int money, int children) {
        money-=children;
        if(money<0){
            return -1;
        }
        int count=money/7;
        int remaining=money % 7;
        if(count==children && remaining==0){
            return children;
        }
        if(count==children-1 && remaining==3){
            return count-1;
        }
        return min(count,children-1);
    }
};