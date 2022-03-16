// 421. Maximum XOR of Two Numbers in an Array
// my naive TLE solution
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int max  = 0;
        for(int i = 0; i < n -1;i++){
            for(int j = i +1; j < n;j++){
                int temp = nums[i] ^ nums[j];
                if(temp > max)
                    max = temp;
            }
        }
        return max;
    }
};

// using unordered_set (Hash set) O(n) solution
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0, mask = 0;
        for(int i = 31; i >= 0;i--){
            //The mask will grow like  100..000 , 110..000, 111..000,  then 1111...111
            //for each iteration, we only care about the left parts
            mask = mask | (1 << i);
            unordered_set <int> s;
            for(int num : nums){
                s.insert(num & mask);
            }
            int temp = result | (1 << i);
            // if a ^ b = c, then a ^ c = b;, we see if greedy result is possible
            for(int prefix : s){
                if(s.count(temp ^ prefix)){
                    result = temp;
                    break;
                }
            }

        }
        return result;
    }
};

// using trie which gives optimal sol
struct Trie{
    Trie *child[2]; // we have only two bits either 0 or 1
    int val;

    bool getCurrentBit(int curVal, int i)
    {
        // get current bit of ith position
        return (curVal >> i) & 1;
    }

    bool contains(bool curBit)
    {
        return (child[curBit] != NULL);
    }

    void insertTrie(bool curBit, Trie* newTrie)
    {
        child[curBit] = newTrie;
    }

    Trie* getNext(bool curBit)
    {
        return child[curBit];
    }
};

class Solution {
public:
    void insert(Trie *root, int curVal)
    {
        Trie *temp = root;
        //traverse from 31 to 0 [because, we have numbers ranging from 0 to 2^31 - 1]
        for(int i = 31; i >= 0; i--)
        {
            bool curBit = temp -> getCurrentBit(curVal, i);

            // if curBit is not present, then create new trie
            if(!temp->contains(curBit))
                temp -> insertTrie(curBit, new Trie());


            // go to next node
            temp = temp -> getNext(curBit);
        }

        // update the val
        temp -> val = curVal;
    }

public:
    int getMaxXOR(Trie* root, int curVal)
    {
        Trie *temp = root;

        //traverse from 31 to 0 [because, we have numbers ranging from 0 to 2^31 - 1]
        for(int i = 31; i >= 0; i--)
        {
            bool curBit = temp -> getCurrentBit(curVal, i);

            // if 1 - curBit is not present, then create new trie
            // why? 1 - curBit = because, we need to get maximum xor value
            // In XOR, different set of bits gives 1,
            // so, if we get curBit as 0, then 1 - 0 = 1 [opposite]
            // if we get curBit as 1, then 1 - 1 = 1 [opposite]
            if(temp->contains( 1 - curBit))
                temp = temp -> getNext(1 - curBit);


                // else, go to next node
            else
                temp = temp -> getNext(curBit);
        }

        // update the val
        return temp -> val ^ curVal;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();

        int maxi = 0;

        for(auto &it : nums)
        {
            // insert into trie
            insert(root, it);

            // find maximum
            maxi = max(maxi, getMaxXOR(root, it));
        }

        return maxi;
    }
};

