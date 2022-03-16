// Introductory Problems : Palindrome Reorder
#include "iostream"
using namespace std;

int count[26] = {0};

bool isEven(){
    for(int i = 0; i < 26;i++){
        if(count[i] % 2){
            return false;
        }
    }
    return true;
}

bool isOdd(){
    int counter1 = 0, sum = 0;
    for(int i = 0; i < 26;i++){
        if(count[i] % 2) {
            counter1++;
        }
        sum += count[i];
    }
    if(sum % 2 == 1 && counter1 == 1)
        return true;
    else
        return false;
}

int main(){
    string input;
    cin >> input;
    for(char ch : input){
        count[ch - 'A']++;
    }
    string result;
    char temp;
    if(input.size() % 2 == 0){
        if(isEven()){
            for(int i = 0; i < 26;i++){
                if(count[i] > 0){
                    for(int j = 0; j < count[i]/2;j++){
                        temp = 'A' + i;
                        result += temp;
                    }
                }
            }
            string tmp = result;
            for(int i = tmp.size() - 1; i >=0;i--){
                result += tmp[i];
            }
            cout<<result<<"\n";
        }
        else{
            cout<<"NO SOLUTION\n";
        }
    }
    else{
        if(isOdd()){
            for(int i = 0; i < 26;i++){
                if(count[i] > 0 && count[i] % 2 == 0){
                    for(int j = 0; j < count[i]/2;j++){
                        temp = 'A' + i;
                        result += temp;
                    }
                }
            }
            int odd;
            for(int i = 0;i < 26;i++){
                if(count[i] % 2 == 1){
                    temp = 'A' + i;
                    odd = count[i];
                    break;
                }
            }
            string tmp = result;
            for(int i = 0; i < odd;i++){
                result += temp;
            }
            for(int i = tmp.size() - 1; i >=0;i--){
                result += tmp[i];
            }
            cout<<result<<"\n";
        }
        else{
            cout<<"NO SOLUTION\n";
        }
    }

    return 0;
}

