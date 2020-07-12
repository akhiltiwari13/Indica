#include<bits/stdc++.h>
using namespace std;

const vector<string> keypad_mapping= {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void phone_mnemonic_helper(const string &phone_number_string, string &phone_mnemonic, vector<string> &mnemonics, int digit){
  // base condition for recursion.
  if(digit == phone_number_string.size()){ //one mnemonic has been completed.
        mnemonics.push_back(phone_mnemonic);
    }else{ //recursive
      for(auto itr: keypad_mapping[phone_number_string[digit]- '0']){
            phone_mnemonic[digit] = itr;
            phone_mnemonic_helper(phone_number_string,phone_mnemonic,mnemonics,digit + 1);
        }
    }
}

vector<string> phone_mnemonic(const string &phone_number_string){
  string phone_mnemonic(phone_number_string.size(),0);
  vector<string> mnemonics;
  phone_mnemonic_helper(phone_number_string,phone_mnemonic,mnemonics,0);
  return mnemonics;
}


int main(){
  string phn_num= "2206696";
  auto result= phone_mnemonic(phn_num);
  for(auto itr: result){
      cout<<itr<<endl;
    }
return 0;
}
