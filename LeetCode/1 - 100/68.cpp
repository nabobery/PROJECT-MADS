// 68. Text Justification

// My initial solution
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string temp(maxWidth, ' ');
        vector<string> result;
        int s = 0,start = 0, n = words.size();
        for(int i = 0; i < n;i++){
            if((s + words[i].size() + i - start) <= maxWidth){
                s += words[i].size();
            }
            else{
                if(i-start == 1){
                    int p = 0;
                    for(auto ch : words[start]) temp[p++] = ch;
                }
                else{
                    int spaces = maxWidth - s, left = spaces%(i-start-1);
                    int p = 0;
                    for(int j = start; j < i;j++){
                        for(auto ch : words[j]) temp[p++] = ch;
                        if(i-start > 1){
                            if(left > 0){
                                p += (spaces/(i-start-1));
                                left--;
                            }
                            else p += spaces/(i-start-1) - 1;
                        }
                        p++;
                    }
                }
                result.push_back(temp);
                fill(temp.begin(), temp.end(), ' ');
                s = 0;
                start = i;
                if((s + words[i].size() + i - start) <= maxWidth){
                    s += words[i].size();
                }
            }
        }
        if(s != 0){
            int p = 0;
            for(int j = start; j < n;j++){
                for(auto ch : words[j]) temp[p++] = ch;
                p++;
            }
            result.push_back(temp);
        }
        return result;
    }
};