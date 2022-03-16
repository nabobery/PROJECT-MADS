// Introductory Problems : Digit Queries
#include "iostream"
#include "cmath"
using namespace std;

int main(){
    int q;
    cin >> q;
    long long int k;
    long long int n;
    for(int i = 0; i < q;i++){
        cin >> k;
        int count = 1;
        n = 9;
        long long int temp = k;
        while(temp > n*count){
            temp -= count*(n);
            n *= 10;
            count++;
        }
        /*for(int j = 0; j < count;j++){
            temp -= counter[j];
        }*/
        int result;
        long long int number = (n/9) - 1;
        number += temp/(count);
        //cout<<number<<"\n";
        //cout<<count<<"\n";
        int digit = temp % (count);
        //cout<<digit<<"\n";
        if(digit == 0){
            result = number % 10;
        }
        else{
            number++;
            //cout<<number<<"\n";
            /*number /= 10;
            for(int j = count; j > 0;j--){
                //cout<<number<<"\n";
                if(digit == j){
                    result = number % 10;
                }
                number /= 10;
            }*/
            for(int j = 0; j < (count - digit) ;j++){
                number /= 10;
            }
            result = number % 10;
        }
        cout<<result<<"\n";
    }
    return 0;
}

