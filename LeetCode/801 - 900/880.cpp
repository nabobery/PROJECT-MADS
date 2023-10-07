// 880. Decoded String at Index

// Solution 1 using reverse Traversal
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // length of decoded string
        long long int length = 0;
        // pointer to start traversing string in reverse order
        int i = 0;
        // move the pointer until length is less than k
        // if the character is digit then multiply length with digit
        // else increment length by 1 (if character is alphabet) 
        // leet2code3
        // 1,2,3,4,8,9,10, 11, 12, 36
        for(i = 0; length < k;i++)
            length = (isdigit(s[i]) ? length*(s[i] - '0') : length+1);
        // move the pointer in reverse order
        while(i--){
            // if the character is digit then divide length by digit
            // and take modulo of k with length
            // the reason for taking modulo is to simulate the pointer position in the reduced decode dstring
            if(isdigit(s[i])){
                length /= (s[i] - '0');
                k %= length;
            }
            // if k is 0 or k is equal to length then return the character
            // else decrement length by 1
            else if(k % length-- == 0)
                return string(1, s[i]);
        }
        return "ggwp";
    }
};

// Solution 2 using stack
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // stack to store the length of decoded string
        stack<long long int> length;
        // length of decoded string
        long long int len = 0;
        // traverse the string
        for(int i = 0; i < s.length(); i++){
            // if the character is digit then multiply length with digit
            // else increment length by 1 (if character is alphabet) 
            len = (isdigit(s[i]) ? len*(s[i] - '0') : len+1);
            // push the length in stack
            length.push(len);
        }
        // traverse the string in reverse order
        for(int i = s.length()-1; i >= 0; i--){
            // if the character is digit then divide length by digit
            // and take modulo of k with length
            // the reason for taking modulo is to simulate the pointer position in the reduced decode dstring
            if(isdigit(s[i])){
                len /= (s[i] - '0');
                k %= len;
            }
            // if k is 0 or k is equal to length then return the character
            // else decrement length by 1
            else if(k % len-- == 0)
                return string(1, s[i]);
        }
        return "ggwp";
    }
};