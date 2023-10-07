// 2038. Remove Colored Pieces if Both Neighbors are the Same Color

// Solution 1 using 2 traversals by finding number of moves for each player
// Time complexity: O(2n) = O(n)
// Space complexity: O(1)
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size(), moves_a = 0, moves_b = 0;
        for(int i = 0; i < n;i++){
            if(colors[i] == 'A'){
                int j = i+1;
                while(j < n && colors[j] == 'A') j++;
                if(j-i-2 > 0) moves_a += (j-i-2); 
                i = j-1;
            }
        }
        for(int i = 0; i < n;i++){
            if(colors[i] == 'B'){
                int j = i+1;
                while(j < n && colors[j] == 'B') j++;
                if(j-i-2 > 0) moves_b += (j-i-2); 
                i = j-1;
            }
        }
        return (moves_a > moves_b);
    }
};

// Solution 2 using 1 traversal by finding number of moves for each player
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size(), moves_a = 0, moves_b = 0;
        for(int i = 0; i < n;i++){
            if(colors[i] == 'A'){
                int j = i+1;
                while(j < n && colors[j] == 'A') j++;
                if(j-i-2 > 0) moves_a += (j-i-2); 
                i = j-1;
            }
            else if(colors[i] == 'B'){
                int j = i+1;
                while(j < n && colors[j] == 'B') j++;
                if(j-i-2 > 0) moves_b += (j-i-2); 
                i = j-1;
            }
        }
        return (moves_a > moves_b);
    }
};

// Solution 3 which is same as Solution 2 but with less code
class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0;
        for (int i = 1; i < colors.size() - 1; i++) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') {
                    alice++;
                } else {
                    bob++;
                }
            }
        }
        return alice > bob;
    }
};