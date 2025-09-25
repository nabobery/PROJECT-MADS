// 3508. Implement Router

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

// Soluion 1: Using Queue, HashMap and Ordered Set
// Time Complexity: O(Nlogt) for n calls
// Space Complexity: O(N)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T>
using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


struct Packet {
    int source;
    int destination;
    int timestamp;

    bool operator==(const Packet& other) const {
        return source == other.source && destination == other.destination && timestamp == other.timestamp;
    }
};

struct PacketHasher {
    size_t operator()(const Packet& p) const {
        size_t h1 = hash<int>()(p.source);
        size_t h2 = hash<int>()(p.destination);
        size_t h3 = hash<int>()(p.timestamp);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

class Router {
public:
    int sz;
    queue<Packet> packetQueue;
    unordered_set<Packet, PacketHasher> packetSet;
    unordered_map<int, ordered_multiset<int>> destinationToTimestamp; 
    Router(int memoryLimit) {
        sz = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        Packet newPacket = Packet(source, destination, timestamp);
        if(packetSet.count(newPacket)) return false;
        if(packetQueue.size() == sz){
            forwardPacket();
        }
        packetSet.insert(newPacket);
        destinationToTimestamp[destination].insert(timestamp);
        packetQueue.push(newPacket);
        return true;
    }

    vector<int> forwardPacket() {
        if(packetQueue.empty()) return {};
        Packet front = packetQueue.front();
        packetQueue.pop();
        packetSet.erase(front);
        auto& st = destinationToTimestamp[front.destination];
        st.erase(st.find_by_order(st.order_of_key(front.timestamp)));
        return {front.source, front.destination, front.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& st = destinationToTimestamp[destination];
        int countUpToEnd = st.order_of_key(endTime + 1);
        int countBeforeStart = st.order_of_key(startTime);
        
        return countUpToEnd - countBeforeStart;
    }
};