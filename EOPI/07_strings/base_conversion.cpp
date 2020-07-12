#include <bits/stdc++.h>
using namespace std;

string convert_base(string str, int original_base, int final_base){
    bool is_negative= str.front() == '-';
    int decimal_value=0;

    for(size_t i= is_negative?1:0; i<str.size(); i++){
            decimal_value *= original_base;
            decimal_value += isdigit(str[i])?str[i] - '0':str[i] - 'A' + 10;
        }

    string result;
    do{
        auto remainder = decimal_value % final_base;
        result.push_back(remainder>=10? 'A'+ remainder- 10: remainder + '0');
        decimal_value /= final_base;
      }while(decimal_value);

    if(is_negative) result.push_back('-');

    reverse(begin(result), end(result));
    return result;
}

int main(){
    string s = "615";
    cout<<"converted:"<<convert_base(s,7 , 13)<<endl;
    return 0;
}
