// 71. Simplify Path
// my naive O(N) time and space solution using stack
// basic idea is to get the directories and store them into stack while taking care of simplifying and then appending the directories to the resultant path
class Solution {
public:
    string simplifyPath(string path) {
        // for storing directories/files
        stack<string> stk;
        // current file/directory
        string dir = "";
        // result initialised
        string result = "/";
        int n = path.size();
        for(int i = 0; i < n;i++){
            // resetting directory
            dir = "";
            // ignoring /
            while(path[i] == '/')
                i++;
            // getting the file or directory
            while(i < n && path[i] != '/'){
                dir += path[i];
                i++;
            }
            // if it's equal to .. move to before directory by popping
            if(dir == ".."){
                if(!stk.empty())
                    stk.pop();
            }
            // if it's ., stay at current dir and continue
            else if(dir == ".")
                continue;
            // else push the dir if it's not empty
            else if(!dir.empty()){
                stk.push(dir);
            }
        }
        // for getting the reverse string
        stack<string> temp;
        while(!stk.empty()){
            temp.push(stk.top());
            stk.pop();
        }
        // for appending directories into the resultant string
        while(!temp.empty()){
            if(temp.size() != 1){
                result += temp.top();
                result += "/";
            }
            else{
                result += temp.top();
            }
            temp.pop();
        }
        return result;
    }
};

