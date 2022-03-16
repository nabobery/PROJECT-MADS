// Introductory Problems : Repetitions
#include <iostream>
using namespace std;

int main(){
    string input;
    cin >> input;
    int curr = 1;
    int result = -1;
    for(int i = 1; i < input.size();i++){
        if(input[i] == input[i-1]){
            curr++;
        }
        else{
            curr = 1;
        }
        if(curr > result){
            result = curr;
        }
    }
    if(curr > result){
        result = curr;
    }
    cout<<result<<"\n";
    return 0;
}


