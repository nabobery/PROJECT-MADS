// 59. Spiral Matrix II
// layer by layer simulation
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n));
        int val = 1;
        // even has only n/2 layers whereas odd has n/2 + 1 layers
        for(int layer = 0; layer < (n+1)/2;layer++){
            // filling from top left to top right  in a layer
            for(int ptr = layer; ptr < n - layer;ptr++)
                result[layer][ptr] = val++;
            // filling from top right to bottom right in a layer
            for(int ptr = layer + 1; ptr < n - layer;ptr++)
                result[ptr][n-layer-1] = val++;
            // filling from bottom right to bottom left in a layer
            for(int ptr = n-layer-2; ptr >= layer ;ptr--)
                result[n-layer-1][ptr] = val++;
            // filling from bottom left to top left  in a layer
            for(int ptr = n-layer-2; ptr > layer;ptr--)
                result[ptr][layer] = val++;
        }
        return result;
    }
};

// optimised spiral traversal
class Solution {
public:
    // to take care of mod of negative numbers
    int floorMod(int x, int y) {
        return ((x % y) + y) % y;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n));
        int val = 1;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r = 0, c = 0,d = 0;
        while(val <= n*n){
            result[r][c] = val++;
            //change direction if cell isn't zero, then change direction
            if(result[floorMod(r + dir[d][0], n)][floorMod(c + dir[d][1], n)] != 0)
                d = (d+1) % 4;
            r += dir[d][0];
            c += dir[d][1];
        }
        return result;
    }
};
