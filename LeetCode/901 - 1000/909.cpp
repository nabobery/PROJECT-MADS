// 909. Snakes and Ladders

class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        int c = 0;
        for (int row = n - 1; row >= 0; row--) {
            if(c%2){
                for (int column = n-1; column >= 0;column--) {
                    cells[label++] = {row, column};
                }
            }
            else{
                for (int column = 0; column < n;column++) {
                    cells[label++] = {row, column};
                }
            }
            c++;
        }
        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n * n];
    }
};