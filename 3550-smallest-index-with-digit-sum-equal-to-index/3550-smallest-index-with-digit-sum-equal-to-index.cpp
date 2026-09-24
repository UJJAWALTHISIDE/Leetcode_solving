class Solution {
public:
    int calculate (int num){
        int sum=0;
        while(num!=0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int ans=-1;
        for(int i=1;i<=nums.size();i++){
            int get=calculate(nums[i-1]);
            if(get==i-1){
                ans=i-1;
                break;
            }
        }
        return ans;
    }
};