#include <iostream>
#include <stack>

using namespace std;

bool isVowel(char c){
    return (c == 'a') || (c == 'e') ||  (c == 'i') ||  (c == 'o') ||  (c == 'u');
}


int main() {
    int t,n;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        string front = "";
        stack<char> end;
        int vowels = 0;
        for(int i = n-1; i >= 0;i--){
            if(vowels % 2 == 0){
                end.push(s[i]);
            }
            else{
                front += s[i];
            }
            if(isVowel(s[i])) vowels++;
        }
        string result = front;
        while(!end.empty()){
            result += end.top();
            end.pop();
        }
        cout<<result<<"\n";
    }
	return 0;
}
