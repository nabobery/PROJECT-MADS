// 2326. Spiral Matrix IV

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Solution 1 using Simulation by changing direction when we reach the boundary or already visited cell
// Time complexity: O(m*n)
// Space complexity: O(m*n)
class Solution {
public:
    const int DIRECTIONS[4][2] = {
        {0, 1},  // East
        {1, 0},  // South
        {0, -1}, // West
        {-1, 0}  // North
    };
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        ListNode* ptr = head;
        int dir = 0, i = 0, j = 0;
        while(ptr){
            res[i][j] = ptr->val;
            int ni = i + DIRECTIONS[dir][0];
            int nj = j + DIRECTIONS[dir][1];
            if((ni >= m || nj >= n || ni < 0 || nj < 0) || (res[ni][nj] != -1)){
                dir = (dir + 1)%4;
                ni = i + DIRECTIONS[dir][0];
                nj = j + DIRECTIONS[dir][1];
            }
            i = ni; j = nj;
            ptr = ptr->next;
        }
        return res;
    }
};
