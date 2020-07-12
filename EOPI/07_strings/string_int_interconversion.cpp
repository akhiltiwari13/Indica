#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string int_to_string(int num){
  bool is_negative=false;
  num<0 ? is_negative=true : is_negative=false ;

  string result;
  do{
    result +=   '0' + static_cast<char>(abs(num%10)); //need absolute value with the modulus operator.
    num /= 10;
    }while(num);

  if(is_negative){
      result += '-';
    }

  reverse(begin(result), end(result));
  return result;
}

int string_to_int(string &num){
  bool is_negative= num[0] == '-' ;

  int result = 0;
  for(int i= num[0] == '-'? 1: 0; i<static_cast<int>(num.size()); ++i){
    int digit = num[i]- '0';
    result = result*10 +  digit;
    }

  if(is_negative){
      result *= -1;
    }

  return result;
}


int main(){
  int num = -237124;
  string str= "-398276";
  cout<<"string representation: "<< int_to_string(num)<<endl;
  cout<<"numeric representation: "<< string_to_int(str)<<endl;
  return 0;
}
