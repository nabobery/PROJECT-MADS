// 1845. Seat Reservation Manager

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

// Solution 1 - Using Set
// Time Complexity = O(nlogn) 
// Space Complexity = O(n)

class SeatManager {
public:
    set<int> unreserved;
    SeatManager(int n) {
        for(int i = 1; i <= n;i++){
            unreserved.insert(i);
        }
    }
    
    int reserve() {
        int res = *unreserved.begin();
        unreserved.erase(res);
        return res;
    }
    
    void unreserve(int seatNumber) {
        unreserved.insert(seatNumber);
    }
};

// A better solution 1 for using sets

class SeatManager {
public:
    int mark;
    set<int> seats;
    SeatManager(int n) {
        mark = 1;
    }
    
    int reserve() {
        if (!seats.empty()) {
            int seatNumber = *seats.begin();
            seats.erase(seatNumber);
            return seatNumber;
        }
        int seatNumber = mark;
        mark++;
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};



