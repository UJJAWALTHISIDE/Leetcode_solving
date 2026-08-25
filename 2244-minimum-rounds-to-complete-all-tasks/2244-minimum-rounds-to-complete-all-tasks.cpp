class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[tasks[i]]++;
        }
        int ans=0;
        for(auto i:m){
            int freq=i.second;
            if(freq==1){
                return -1;
            }
            if(freq%3==0){
                ans+=freq/3;
            }else if(freq%3==2){
                ans+=freq/3;
                ans+=1;
            }else{
                freq-=4;
                ans+=2;
                if(freq>0){
                    ans+=freq/3;
                }
            }
        }
        return ans;
    }
};