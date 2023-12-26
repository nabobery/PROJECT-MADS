// 661. Image Smoother

// Solution 1 Naive and Simple
// Time Complexity: O(mn)
// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                int sum = 0, cnt = 0;
                for(int k =i-1; k <= i+1;k++){
                    for(int l = j-1; l <= j+1;l++){
                        if(l < 0 || k < 0 || k >= m || l >= n) continue;
                        sum += img[k][l];
                        cnt++;
                    }
                }
                res[i][j] = sum/cnt;
            }
        }
        return res;
    }
};

// Solution 2 by maintaining previous row and overwriting the input
// Time Complexity: O(mn)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size(), prevval;
        vector<int> temp(n);
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                int sum = 0, cnt = 0;
                for(int k= i-1; k <= i+1;k++){
                    for(int l = j-1; l <= j+1;l++){
                        if(l < 0 || k < 0 || k >= m || l >= n) continue;
                        if(k != (i-1)) sum += img[k][l];
                        else{
                            if(l == j-1) sum += prevval;
                            else sum += temp[l];
                        }
                        cnt++;
                    }
                }
                prevval = temp[j];
                temp[j] = sum/cnt;
            }
            for(int j = 0; j < n;j++) swap(temp[j], img[i][j]);
        }
        return img;
    }
};

// Solution 3 by taking modulo and storing the encoded value
// Time Complexity: O(mn)
// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                int sum = 0, cnt = 0;
                for(int k =i-1; k <= i+1;k++){
                    for(int l = j-1; l <= j+1;l++){
                        if(l < 0 || k < 0 || k >= m || l >= n) continue;
                        sum += img[k][l] & 0xFF;
                        cnt++;
                    }
                }
                img[i][j] |= (sum/cnt) << 8;
            }
        }
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                img[i][j] >>= 8;
            }
        }
        return img;
    }
};


