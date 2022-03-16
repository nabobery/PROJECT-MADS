//1217. Minimum Cost to Move Chips to The Same Position
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size(), count = 0;
        for (auto i : position){
            if(i % 2 == 0){
                count++;
            }
        }
        int result = min(count, n- count);
        return result;
    }
};