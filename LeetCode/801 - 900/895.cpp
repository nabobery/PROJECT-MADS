// 895. Maximum Frequency Stack
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// my naive solution using unordered_map, stack and map
class FreqStack {
public:
    stack<int> stk;
    unordered_map<int,int> freq;
    map<int, int, greater<int> > count;
    FreqStack() {

    }

    void push(int val) {
        stk.push(val);
        if(freq.find(val) != freq.end()){
            count[freq[val]]--;
            freq[val]++;
            count[freq[val]]++;
        }
        else{
            freq[val]++;
            count[1]++;
        }

    }

    int pop() {
        vector<int> temp;
        auto it = count.begin();
        while(!stk.empty() && freq[stk.top()] != it->first){
            temp.push_back(stk.top());
            stk.pop();
        }
        int result = stk.top();
        stk.pop();
        count[freq[result]]--;
        freq[result]--;
        count[freq[result]]++;
        if(it->second == 0) count.erase(it->first);
        for(int i = temp.size() - 1; i >=0;i--) stk.push(temp[i]);
        return result;
    }
};

// solution using unordered_map and map (Stack of Stacks)
class FreqStack {
public:
    int max_freq;
    unordered_map<int,int> freq;
    map<int, stack<int> > group;
    FreqStack() {
        max_freq = 0;
    }

    void push(int val) {
        freq[val]++;
        max_freq = max(freq[val],max_freq);
        group[freq[val]].push(val);
    }

    int pop() {
        int result = group[max_freq].top();
        group[max_freq].pop();
        freq[result]--;
        if(group[max_freq].empty()) max_freq--;
        return result;
    }
};



