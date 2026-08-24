class Solution {
public:
    string removeDigit(string number, char digit) {
        int remove=-1;
        for (int i=0;i<number.size();i++){
            if (number[i]==digit){
                remove=i;
                if (i+1<number.size() && number[i+1]>digit){
                    break;
                }
            }
        }
        number.erase(remove,1);
        return number;
    }
};