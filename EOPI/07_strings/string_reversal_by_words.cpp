#include <bits/stdc++.h>
using namespace std;

string reverse_by_words(string str){
    reverse(str.begin(), str.end());

    size_t pos =0, end;
    while ((end = str.find(" ", pos)) != string::npos) {
        reverse(str.begin() + pos, str.begin() + end);
        pos = end + 1;
      }
    reverse(str.begin() + pos, str.end());
    return str;
}

int main(){
    string str = "Alice Loves Bob";
    cout<< "original string: "<< str <<endl;
    cout<< "reversed by words string: "<< reverse_by_words(str)<< endl;
    return 0;
}
