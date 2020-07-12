#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string str){
  int start_idx =0, end_idx= str.size()-1;
  while(start_idx < end_idx){
      while( !isalnum(str[start_idx]) && start_idx < end_idx ){
          ++start_idx;
        }
      while( !isalnum(str[end_idx]) && start_idx < end_idx ){
          --end_idx;
        }
      if( tolower(str[start_idx]) != tolower(str[end_idx])) return false;
      ++start_idx; --end_idx;
    }
  return true;
}

int main()
{
  string str= "A man, a plan, a canal, Panama.";
  cout << "is \"" << str << "\" a palindrome? "; is_palindrome(str)?cout<<"yes":cout<<"no"; cout <<endl;
  return 0;
}
