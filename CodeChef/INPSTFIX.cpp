#include <iostream>
#include<stack>
using namespace std;

int precedence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

void infixToPostfix(string input, int n){
    string result;
    stack <char> stk;
    for(int i = 0; i < n;i++){
        char ch = input[i];
        if(ch >= 'A' && ch <= 'Z') result += ch;
        else if(ch == '(') stk.push(ch);
        else if(ch == ')'){
            while(stk.top() != '('){
                result += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{
            while(!stk.empty() && precedence(ch) <= precedence(stk.top())){
                result += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }
    while(!stk.empty()){
        result += stk.top();
        stk.pop();
    }
    cout<<result<<"\n";
}

int main() {
	int t,n;
	string input;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n >> input;
	    infixToPostfix(input, n);
	}
	return 0;
}
