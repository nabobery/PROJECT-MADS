// 36. Valid Sudoku

class Solution
{
public:
    bool visited[10];
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool result = true;
        for (int i = 0; i < 9; i++)
        {
            memset(visited, false, sizeof(visited));
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (visited[board[i][j] - '0'])
                    {
                        result &= false;
                        break;
                    }
                    visited[board[i][j] - '0'] = true;
                }
            }
            if (!result)
                return result;
        }
        for (int j = 0; j < 9; j++)
        {
            memset(visited, false, sizeof(visited));
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] != '.')
                {
                    if (visited[board[i][j] - '0'])
                    {
                        result &= false;
                        break;
                    }
                    visited[board[i][j] - '0'] = true;
                }
            }
            if (!result)
                return result;
        }
        for (int k = 0; k < 3; k++)
        {
            for (int l = 0; l < 3; l++)
            {
                memset(visited, false, sizeof(visited));
                for (int i = 3 * k; i < 3 * (k + 1); i++)
                {
                    for (int j = 3 * l; j < 3 * (l + 1); j++)
                    {
                        if (board[i][j] != '.')
                        {
                            if (visited[board[i][j] - '0'])
                            {
                                result &= false;
                                break;
                            }
                            visited[board[i][j] - '0'] = true;
                        }
                    }
                }
                if (!result)
                    return result;
            }
        }
        return result;
    }
};