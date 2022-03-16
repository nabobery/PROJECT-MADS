// 2166. Design Bitset
class Bitset {
public:
    vector<bool> bits;
    int numberofOnes;
    bool flipped;
    Bitset(int size) {
        bits = vector<bool>(size,false);
        numberofOnes = 0;
        flipped = false;
    }

    void fix(int idx) {
        if((bits[idx] && flipped) || (!bits[idx] && !flipped)){
            bits[idx] = !bits[idx];
            numberofOnes++;
        }
    }

    void unfix(int idx) {
        if((!bits[idx] && flipped) || (bits[idx] && !flipped)){
            bits[idx] = !bits[idx];
            numberofOnes--;
        }
    }

    void flip() {
        flipped = !flipped;
        numberofOnes = bits.size() - numberofOnes;
    }

    bool all() {
        return (numberofOnes == bits.size());
    }

    bool one() {
        return (numberofOnes > 0);
    }

    int count() {
        return numberofOnes;
    }

    string toString() {
        string result;
        for(bool bit : bits){
            result += (bit == flipped ? '0' : '1');
        }
        return result;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
