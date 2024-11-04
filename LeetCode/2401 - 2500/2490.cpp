// 2490. Circular Sentence

// Solution 1 using stringstream
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0] != sentence.back()) return false;
        stringstream ss(sentence);
        string prev, curr;
        ss >> prev;
        while(ss >> curr){
            if(prev.back() != curr[0]) return false;
            prev = curr;
        }
        return true;
    }
};

// Solution 2 using string traversal
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0] != sentence.back()) return false;
        string prev, curr;
        int i = 0;
        while(i < sentence.size()){
            int j = i;
            while(j < sentence.size() && sentence[j] != ' ') j++;
            curr = sentence.substr(i, j-i);
            if(prev.size() > 0 && prev.back() != curr[0]) return false;
            prev = curr;
            i = j+1;
        }
        return true;
    }
};