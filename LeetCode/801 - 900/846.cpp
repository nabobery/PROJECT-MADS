// 846. Hand of Straights

// Solution 1 using map
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        map<int,int> mp;
        for(int h : hand) mp[h]++;
        while(!mp.empty()){
            int start = mp.begin()->first;
            mp[start]--;
            if(mp[start] == 0) mp.erase(start);
            int sz = 1;
            while(sz < groupSize){
                if(!mp.count(start+1)) return false;
                start++;
                mp[start]--;
                if(mp[start] == 0) mp.erase(start);
                sz++;
            }
        }
        return true;
    }
};

// Solution 2 using multiset
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        multiset<int> ms;
        for(int h : hand) ms.insert(h);
        while(!ms.empty()){
            int start = *ms.begin();
            ms.erase(ms.begin());
            int sz = 1;
            while(sz < groupSize){
                if(!ms.count(start+1)) return false;
                ms.erase(ms.find(start+1));
                start++;
                sz++;
            }
        }
        return true;
    }
};


// Solution 3 using unordered_map and Reverse Decrement
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        unordered_map<int,int> mp;
        for(int h : hand) mp[h]++;
        for(int h : hand){
            int start = h;
            while(mp[start-1]) start--;
            while(start <= h){
                while(mp[start]){
                    for(int i = 0; i < groupSize; i++){
                        if(mp[start+i] == 0) return false;
                        mp[start+i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};