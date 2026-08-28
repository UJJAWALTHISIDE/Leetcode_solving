class Solution {
public:
    int minNumberOfHours(int initialEnergy,int initialExperience,vector<int>& energy,vector<int>& experience) {
        int n=energy.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(initialEnergy<=energy[i]){
                int need=energy[i]-initialEnergy+1;
                ans+=need;
                initialEnergy+=need;
            }
            if(initialExperience<=experience[i]){
                int need=experience[i]-initialExperience+1;
                ans+=need;
                initialExperience+=need;
            }
            initialEnergy-=energy[i];
            initialExperience+=experience[i];
        }
        return ans;
    }
};