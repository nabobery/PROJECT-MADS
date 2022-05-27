#include <iostream>
#include <vector>

using namespace std;

bool pruneSearch(vector<vector<bool>> &visited, int ind, int x, int y, char forward){
    int total = 0;
    switch(forward){
        case 'D':
            if (!(y < 6 && !visited[x][y + 1])) {
                total++;
            }
            break;
        case 'U':
            if (!(y > 0 && !visited[x][y - 1])) {
                total++;
            }
            break;
        case 'L':
            if (!(x > 0 && !visited[x - 1][y])) {
                total++;
            }
            break;
        case 'R':
            if (!(x < 6 && !visited[x + 1][y])) {
                total++;
            }
            break;
        default:
            break;
    }
    if(forward == 'D' || forward == 'U'){
        if (x < 6 && !visited[x + 1][y]) {
            total++;
        }
        if (x > 0 && !visited[x - 1][y]) {
            total++;
        }
    }
    else if(forward == 'L' || forward == 'R'){
        if (y > 0 && !visited[x][y - 1]) {
            total++;
        }
        if (y < 6 && !visited[x][y + 1]) {
            total++;
        }
    }
    return total == 3;
}

int recurse(string &s, vector<vector<bool>> &visited, int ind, int x, int y, char direction) {
    if (ind == 48) {
        if (x == 6 && y == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (x == 6 && y == 0) return 0;
    if(pruneSearch(visited,ind,x,y,direction)) return 0;
    int total = 0;
    switch (s[ind]) {
        case '?':
            if (x < 6 && !visited[x + 1][y]) {
                visited[x + 1][y] = true;
                total += recurse(s, visited, ind + 1, x + 1, y,'R');
                visited[x + 1][y] = false;
            }
            if (x > 0 && !visited[x - 1][y]) {
                visited[x - 1][y] = true;
                total += recurse(s, visited, ind + 1, x - 1, y,'L');
                visited[x - 1][y] = false;
            }
            if (y > 0 && !visited[x][y - 1]) {
                visited[x][y - 1] = true;
                total += recurse(s, visited, ind + 1, x, y - 1,'U');
                visited[x][y - 1] = false;
            }
            if (y < 6 && !visited[x][y + 1]) {
                visited[x][y + 1] = true;
                total += recurse(s, visited, ind + 1, x, y + 1,'D');
                visited[x][y + 1] = false;
            }
            break;
        case 'D':
            if (x < 6 && !visited[x + 1][y]) {
                visited[x + 1][y] = true;
                total += recurse(s, visited, ind + 1, x + 1, y,'R');
                visited[x + 1][y] = false;
            }
            break;
        case 'U':
            if (x > 0 && !visited[x - 1][y]) {
                visited[x - 1][y] = true;
                total += recurse(s, visited, ind + 1, x - 1, y,'L');
                visited[x - 1][y] = false;
            }
            break;
        case 'L':
            if (y > 0 && !visited[x][y - 1]) {
                visited[x][y - 1] = true;
                total += recurse(s, visited, ind + 1, x, y - 1,'U');
                visited[x][y - 1] = false;
            }
            break;
        case 'R':
            if (y < 6 && !visited[x][y + 1]) {
                visited[x][y + 1] = true;
                total += recurse(s, visited, ind + 1, x, y + 1,'D');
                visited[x][y + 1] = false;
            }
            break;
        default:
            break;
    }
    return total;
}

int solve() {
    string s;
    cin >> s;
    vector<vector<bool>> visited(7, vector<bool> (7, false));
    visited[0][0] = true;
    return recurse(s, visited, 0, 0, 0,'D');
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}

