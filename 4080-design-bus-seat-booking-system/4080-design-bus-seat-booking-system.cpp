class BusBooking {
public:
    vector<bool> booked;
    vector<int> cost;
    int totalTime=0,minTime=0;
    BusBooking(int n){
        booked=vector<bool>(4*n,false);
        cost=vector<int>(4*n,0);
    }
    void toggle(string seat) {
        int row=stoi(seat.substr(1));
        char ch=seat[0];
        int id=(row-1)*4;
        if(ch=='B'){
            id++;
        }else if(ch=='C'){
            id+=2;
        }else if(ch=='D'){
            id+=3;
        }
        if(booked[id]){
            booked[id]=false;
            totalTime-=cost[id];
            minTime--;
        }else{
            int t=1;
            if (ch=='A' && booked[id+1]){
                t=3;
            }
            if(ch=='D' && booked[id-1]){
                t=3;
            }
            booked[id]=true;
            cost[id]=t;
            totalTime+=t;
            minTime++;
        }
    }
    int getTotalTime(){
        return totalTime;
    }
    int getMinTime(){
        return minTime;
    }
};


/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */