class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int i=0;
        int count5=0;
        int count10=0;
        int count20=0;
        while(i<bills.size()){
            if(bills[i]==5){
                count5++;
                i++;
            }else if(bills[i]==10){
                if(count5>=1){
                    count10++;
                    count5--;
                    i++;
                }else{
                    break;
                }
            }else if(bills[i]==20){
                if(count5>=1 && count10>=1){
                    count5--;
                    count10--;
                    count20++;
                    i++;
                }else if(count5>=3){
                    count5-=3;
                    count20++;
                }
                else{
                    break;
                }
            }
        }
        if(i<bills.size()) return false;
        return true;
    }
};