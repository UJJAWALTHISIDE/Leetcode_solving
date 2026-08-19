class Solution {
public:

    bool isAvailable(unordered_set<int>& bookedSeats, int seat) {
        return bookedSeats.find(seat) == bookedSeats.end();
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        for(auto& reservedSeat : reservedSeats) {
            int row  = reservedSeat[0];
            int seat = reservedSeat[1];
            mp[row].insert(seat);
        }
        int result=(n-mp.size())*2;
        for(auto& [row, bookedSeats] : mp) {
            bool graupA = isAvailable(bookedSeats, 2) && isAvailable(bookedSeats, 3) && isAvailable(bookedSeats, 4) && isAvailable(bookedSeats, 5);
            bool graupB = isAvailable(bookedSeats, 4) && isAvailable(bookedSeats, 5) && isAvailable(bookedSeats, 6) && isAvailable(bookedSeats, 7);
            bool graupC = isAvailable(bookedSeats, 6) && isAvailable(bookedSeats, 7) && isAvailable(bookedSeats, 8) && isAvailable(bookedSeats, 9);
            if(graupA && graupC)
                result += 2;
            else if(graupA || graupB || graupC)
                result += 1;
        }
        return result;
    }
};