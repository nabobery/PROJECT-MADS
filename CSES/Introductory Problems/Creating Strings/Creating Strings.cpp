// Introductory Problems : Creating Strings
#include "iostream"
#include "algorithm"
using namespace std;

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n){
    if(n == 0 || n == 1)
        return 1;
    else
        return (n *factorial(n-1));
}

void count(string str){
    int freq[26] = {0};
    for(int i = 0; i < str.size();i++){
        freq[str[i] - 'a']++;
    }
    int result = 1;
    for(int i = 0; i < 26;i++){
        result *= factorial(freq[i]);
    }
    result = factorial(str.size())/result;
    cout<<result<<"\n";
}

/*int findCeil (string str, char first, int l, int h){
    int ceilIndex = l;
    for (int i = l+1; i <= h; i++)
        if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
    return ceilIndex;
}

void reverse(string str, int l, int h){
    while (l < h){
        swap(&str[l], &str[h]);
        l++;
        h--;
    }
}

void create(string str){
    int n = str.size();
    sort(str.begin(),str.end());
    bool finished = false;
    while(!finished){
        cout<<str<<"\n";
        int i;
        for(i = n - 2; i >=0;--i) {
            if (str[i] < str[i + 1])
                break;
        }
        if(i == -1)
            finished = true;
        else{
            int index = findCeil( str, str[i], i + 1, n - 1);
            swap( &str[i], &str[index] );
            reverse(str, i + 1, n - 1 );
        }
    }
}*/

int main(){
    string s;
    cin >> s;
    count(s);
    sort(s.begin(),s.end());
    do {
        for(auto&& element : s)
            cout << element;
        cout <<"\n";
    } while (std::next_permutation(std::begin(s), std::end(s)));
    return 0;
}

