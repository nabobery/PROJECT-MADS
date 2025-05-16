// 3337. Total Characters in String After Transformations II

// Solution 1: Using Vector (Time Limit Exceeded)
// Time Complexity: O(n + t) where n is the length of the string
// Space Complexity: O(1) since the size of the map is constant (26 letters)
class Solution {
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        long res = 0;
        vector<long> cnt(26 , 0), temp(26, 0);
        for(auto &ch : s) cnt[ch -'a']++;
        for(int i =0 ; i < t;i++){
            fill(temp.begin(), temp.end(), 0);
            for(int j = 0; j < 26;j++){
                for(int k = 1; k <= nums[j];k++){
                    temp[(j+k) % 26] = (temp[(j+k) % 26] + cnt[j]) % mod;
                }
            }
            cnt = temp;
        }
        for(auto& c : cnt) res = (res + c) % mod;
        return res % mod;
    }
};

// Solution 2: Using Matrix Exponentiation
// Time Complexity: O(k^3 log t) where k = 26 (number of letters in the alphabet) and t is the number of transformations
// Space Complexity: O(k^2) for the matrix
// Instead of doing t transformations one by one, we can use matrix exponentiation to do it in log(t) time.
// Instead of M*cnt = cnt' => M*cnt' => M*cnt'' => ...
// We can do M^t * cnt  using matrix exponentiation. 
class Solution {
public:
    const int mod = 1e9 + 7;
    using Matrix = vector<vector<long>>;

    // Function to multiply two matrices
    Matrix multiply(Matrix& A, Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long>(n, 0));
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                for (int j = 0; j < n; j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
        return C;
    }

    // Function to raise a matrix to the power of p
    // using binary exponentiation
    Matrix matrixPower(Matrix base, int power) {
        int n = base.size();
        Matrix result(n, vector<long>(n, 0));
        for (int i = 0; i < n; i++) result[i][i] = 1;
        while (power > 0) {
            if (power % 2 == 1)
                result = multiply(result, base);
            base = multiply(base, base);
            power /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Count the frequency of each character in the string
        vector<long> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;
        
        // Create the transformation matrix M from string s
        Matrix M(26, vector<long>(26, 0));
        for (int j = 0; j < 26; j++) {
            for (int k = 1; k <= nums[j]; k++) {
                int dest = (j + k) % 26;
                M[dest][j] = (M[dest][j] + 1) % mod;
            }
        }

        // Raise the transformation matrix M to the power of t
        Matrix Mt = matrixPower(M, t);

        // Multiply the transformed matrix with the initial count vector
        vector<long> result(26, 0);
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                result[i] = (result[i] + Mt[i][j] * cnt[j]) % mod;
        
        // Sum up the result vector to get the final answer
        long res = 0;
        for (long val : result)
            res = (res + val) % mod;

        return res;
    }
};