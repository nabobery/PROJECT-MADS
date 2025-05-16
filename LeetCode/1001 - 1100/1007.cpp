// 1007. Minimum Domino Rotations For Equal Row
// Greedy O(N) time and O(1) space solution
// Example : tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// count1[2] = 4 count2[2] = 3 and countSame[2] = 1 and it takes only 2 rotations
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> count1(7), count2(7), countSame(7);
        // get the count of faces
        for(int i = 0; i < n;i++){
            count1[tops[i]]++;
            count2[bottoms[i]]++;
            if(tops[i] == bottoms[i]) countSame[tops[i]]++;
        }
        // check for all possibilities from 1 to 6
        for(int i = 1; i < 7;i++){
            // if it's possible to get a equal row
            // cnt1[i] union cnt2[i] is equal to n
            if(count1[i] + count2[i] - countSame[i] == n)
                // then we can get the minimum rotations by just swapping the dominoes to face which has the maximum count
                return n - max(count1[i],count2[i]);
        }
        // return -1 if not possible
        return -1;
    }
};
