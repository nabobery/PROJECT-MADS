// 432. All O`one Data Structure

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */


// Solution 1 using map to store the frequency of the keys and a map to store the keys with the same frequency
// Time complexity: O(1) for inc, dec, getMaxKey, getMinKey
// Space complexity: O(n)
class AllOne {
public:
    unordered_map<string,int> mp;
    map<int, unordered_set<string>> mpc;
    AllOne() {
    }
    
    void inc(string key) {
        if(mp.count(key)){
            mpc[mp[key]].erase(key);
            if(mpc[mp[key]].empty()) mpc.erase(mp[key]);
        }
        mp[key]++;
        mpc[mp[key]].insert(key);
    }
    
    void dec(string key) {
        mpc[mp[key]].erase(key);
        if(mpc[mp[key]].empty()) mpc.erase(mp[key]);
        mp[key]--;
        if(mp[key] == 0) return;
        mpc[mp[key]].insert(key);
    }
    
    string getMaxKey() {
        // for(auto it : mpc) cout<<it.first<<" "<<*it.second.begin()<<" ";
        // cout<<"\n";
        if(mpc.empty()) return "";
        return *(mpc.rbegin()->second.begin());
    }
    
    string getMinKey() {
        // for(auto it : mpc) cout<<it.first<<" "<<*it.second.begin()<<" ";
        // cout<<"\n";
        if(mpc.empty()) return "";
        return *(mpc.begin()->second.begin());
    }
};


// Solution 2 using doubly linked list 
// Time complexity: O(1) for inc, dec, getMaxKey, getMinKey
// Space complexity: O(n)
class AllOne {
public:
    struct Node{
        int val;
        unordered_set<string> keys;
        Node* next;
        Node* prev;
        Node(int val): val(val), next(NULL), prev(NULL) {}
    };
    unordered_map<string, Node*> mp;
    Node* head;
    Node* tail;
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if(mp.count(key)){
            Node* cur = mp[key];
            Node* next = cur->next;
            if(next->val != cur->val+1){
                next = new Node(cur->val+1);
                next->prev = cur;
                next->next = cur->next;
                cur->next->prev = next;
                cur->next = next;
            }
            next->keys.insert(key);
            mp[key] = next;
            cur->keys.erase(key);
            if(cur->keys.empty()){
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
            }
        }else{
            if(head->next->val != 1){
                Node* next = new Node(1);
                next->prev = head;
                next->next = head->next;
                head->next->prev = next;
                head->next = next;
            }
            head->next->keys.insert(key);
            mp[key] = head->next;
        }
    }
    
    void dec(string key) {
        if(mp.count(key)){
            Node* cur = mp[key];
            Node* prev = cur->prev;
            if(cur->val == 1){
                cur->keys.erase(key);
                if(cur->keys.empty()){
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete cur;
                }
                mp.erase(key);
                return;
            }
            if(prev->val != cur->val-1){
                prev = new Node(cur->val-1);
                prev->next = cur;
                prev->prev = cur->prev;
                cur->prev->next = prev;
                cur->prev = prev;
            }
            prev->keys.insert(key);
            mp[key] = prev;
            cur->keys.erase(key);
            if(cur->keys.empty()){
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
            }
        }
    }

    string getMaxKey() {
        if(tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if(head->next == tail) return "";
        return *(head->next->keys.begin());
    }

};
