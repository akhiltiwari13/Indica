#include <bits/stdc++.h>
using namespace std;

int decode_spreadsheet_column(string &str){
    int result=0;
    for(auto ch: str){
            result = (result * 26) + ch - 'A' + 1;
             }
    return result;
}

int main(){
    string str = "AA";
    cout << "Decoded: " << decode_spreadsheet_column(str)<<endl;
    return 0;
}

