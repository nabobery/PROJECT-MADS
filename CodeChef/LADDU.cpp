#include <iostream>
#include<string>
using namespace std;

int main() {
	int t,rank,temp,n;
	string tmp,origin;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n >> origin;
        int result = 0;
        cin.ignore();
        for(int j = 0; j < n;j++){
            getline(cin,tmp);
            if(tmp.find("CONTEST_WON") != std::string::npos){
                rank = stoi(tmp.substr(12,tmp.size()-12));
                if(rank < 20){
                    result += 300;
                    result += 20 - rank ;
                }
                else{
                    result += 300;
                }
            }
            else if(tmp.find("TOP_CONTRIBUTOR") != std::string::npos){
                result += 300;
            }
            else if(tmp.find("BUG_FOUND") != std::string::npos){
                temp = stoi(tmp.substr(10,tmp.size()-10));
                result += temp;
            }
            else if(tmp.find("CONTEST_HOSTED") != std::string::npos){
                result += 50;
            }
        }
        if(origin == "INDIAN"){
            cout<<result/200<<"\n";
        }
	    else{
	        cout<<result/400<<"\n";
	    }
	}
	return 0;
}
