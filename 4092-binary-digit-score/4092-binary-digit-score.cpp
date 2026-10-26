class Solution {
public:
    int calculateScore(int a, int b) {
        int count1=0;
        for(int i=0;i<32;i++){
            if(a&(1<<i)){
                count1++;
            }
        }
        int count2=0;
        for(int i=0;i<32;i++){
            if(b&(1<<i)){
                count2++;
            }
        }
        if(count1>=count2){
            return count1*count2;
        }else{
            return count2/count1;
        }
    }
};