// 79. Word Search

// Solution 1 TLE
class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool withinBoundary(pair<int,int> p){
        return p.first >= 0 && p.first < m && p.second >= 0 && p.second < n;
    }
    bool helper(pair<int,int> curr, vector<vector<char>>& board, string& word, int ind){
        if(ind >= word.size()) return true;
        if(!withinBoundary(curr) || visited[curr.first][curr.second]) return false;
        visited[curr.first][curr.second] = true;
        bool b = false;
        if(board[curr.first][curr.second] == word[ind]){
            for(auto dir : dirs){
                pair<int,int> next = {curr.first+dir[0], curr.second+dir[1]};
                b |= helper(next, board, word, ind+1);
            }
        }
        visited[curr.first][curr.second] = false;
        return b;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n;j++) 
                if(helper({i, j}, board, word, 0))
                    return true;
        return false;
    }
};

// Solution 2 Optimized Solution 1
class Solution{
public:
    bool exist(vector<vector<char>> &board, string word){
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0, visited))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int index, vector<vector<bool>> &visited){
        if (index == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index])
            return false;
        visited[i][j] = true;
        if (dfs(board, word, i + 1, j, index + 1, visited) || dfs(board, word, i - 1, j, index + 1, visited) || dfs(board, word, i, j + 1, index + 1, visited) || dfs(board, word, i, j - 1, index + 1, visited))
            return true;
        visited[i][j] = false;
        return false;
    }
};

// Solution 3 Optimized Solution 2 without using visited array
class Solution{
public:
    bool exist(vector<vector<char>> &board, string word){
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int index){
        if (index == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
            return false;
        char temp = board[i][j];
        board[i][j] = '*';
        if (dfs(board, word, i + 1, j, index + 1) || dfs(board, word, i - 1, j, index + 1) || dfs(board, word, i, j + 1, index + 1) || dfs(board, word, i, j - 1, index + 1))
            return true;
        board[i][j] = temp;
        return false;
    }
};


