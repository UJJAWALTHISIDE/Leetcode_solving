class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int monthofalice=stoi(arriveAlice.substr(0,2));
        int monthofbob=stoi(arriveBob.substr(0,2));
        int dateofarralice=stoi(arriveAlice.substr(3,2));
        int dateofarrbob=stoi(arriveBob.substr(3,2));
        int monthofleavealice=stoi(leaveAlice.substr(0,2));
        int monthofleavebob=stoi(leaveBob.substr(0,2));
        int dateofdepalice=stoi(leaveAlice.substr(3,2));
        int dateofdepbob=stoi(leaveBob.substr(3,2));
        int prefix[13]={};
        for (int i=1;i<=12;i++){
            prefix[i]=prefix[i-1]+month[i];
        }
        int startAlice=prefix[monthofalice-1]+dateofarralice;
        int startBob=prefix[monthofbob-1]+dateofarrbob;
        int endAlice=prefix[monthofleavealice-1]+dateofdepalice;
        int endBob=prefix[monthofleavebob-1]+dateofdepbob;
        int start=max(startAlice,startBob);
        int end=min(endAlice,endBob);
        if(start>end){
            return 0;
        }
        return end-start+1;
    }
};
