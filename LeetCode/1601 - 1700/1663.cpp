// 1663. Smallest String With A Given Numeric Value
// my naive Greedy Solution
// Basic idea is to build the string from last and choose the minimum length starting with z and then reverse it to get the shortest lexicographical string
class Solution {
public:
    string getSmallestString(int n, int k) {
        string result = "";
        while(n > 0){
            if(n == k){
                result += 'a';
                n--;
                k--;
            }
            else if(k > n){
                for(int i = 26;i > 0;i--){
                    if(n > k - i + 1) continue;
                    else{
                        char ch = 96 + i;
                        result += ch;
                        k -= i;
                        n--;
                        break;
                    }
                }
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

// simple and less lines solution
class Solution {
public:
    string getSmallestString(int n, int k) {
        // initialise the string with all a's
        string result(n,'a');
        // subtract n a's from k as everything is initialised as 'a' and we're starting with the least value string of size n
        k -= n;
        // loop for filling with characters from the end to match the numerical value 'a' + 25 = 'z' and minimum for boundary conditions
        while(k > 0){
            result[--n] += min(25,k);
            k -= min(25,k);
        }
        // return result
        return result;
    }
};