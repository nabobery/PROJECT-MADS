// 950. Reveal Cards In Increasing Order

// Solution 1 by Simulating the process in reverse
// Time complexity: O(nlogn)
// Space complexity: O(n)
// Forward simulation is hard to implement, so we simulate the process in reverse.
// We sort the deck in descending order, and then we reveal the cards in increasing order.

//  Deck = [17, 13, 11, 2, 3, 5, 7]
// Result: [2,13,3,11,5,17,7] -> [2,3,5,7,11,13,17]   
// Reverse Simulation:
// [17] -> [13, 17] -> [11, 17, 13] -> [7, 13, 17, 11] -> [5, 11, 7, 13, 17] -> [3, 17, 5, 11, 7, 13] -> [2, 13, 3, 11, 5, 17, 7]
// We start from the last revealed card, and we keep adding the next largest card to the front of the queue.
// We pop the front card and push it to the back of the queue, and then we push the next largest card to the front of the queue.
// We repeat this process until we have revealed all the cards.
// Weare going to previous state by moving the  front card to the back and then adding the card to be revealed to the front.
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        queue<int> q;
        int n = deck.size();
        vector<int> res(n);
        for(int i = 0;i < n;i++){
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
            q.push(deck[i]);
        }
        while(n--){
            res[n] = q.front();
            q.pop();
        }
        return res;
    }
};
