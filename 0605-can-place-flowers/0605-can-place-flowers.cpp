class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        int count=0;
        while(i<flowerbed.size()){
            if(flowerbed[i]==1){
                i+=2;
            }else{
                bool leftEmpty=(i==0 || flowerbed[i-1]==0);
                bool rightEmpty=(i==flowerbed.size()-1 || flowerbed[i+1]==0);
                if(leftEmpty && rightEmpty){
                    flowerbed[i]=1;
                    count++;
                    i+=2;
                }else{
                    i++;
                }
            }
        }
        if(count>=n) return true;
        else return false;
    }
};