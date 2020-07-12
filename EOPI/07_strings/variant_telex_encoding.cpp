#include<bits/stdc++.h>
using namespace std;

int telex_encoding(char str[], int size){
  int final_len = 0;
  int dots=0, coms=0, exs=0, ques=0;

  // counting the punctuations
  for(int i=0; i<size; i++){
      if(str[i] == '.')
        ++dots;
      if(str[i] == ',')
        ++coms;
      if(str[i] == '!')
        ++exs;
      if(str[i] == '?')
        ++ques;
    }

  int write_idx = (size -1) + dots*7 + coms*4 + exs*3 + ques*11;
  int curr_idx = size-1;
  final_len = write_idx+1;

  // replacing
  while(curr_idx >= 0){
      if(str[curr_idx] == '.'){
          str[write_idx--] = 'P';
          str[write_idx--] = 'O';
          str[write_idx--] = 'T';
          str[write_idx--] = 'S';
          str[write_idx--] = 'L';
          str[write_idx--] = 'L';
          str[write_idx--] = 'U';
          str[write_idx--] = 'F';
        }
      else if(str[curr_idx] == ','){
          str[write_idx--] = 'A';
          str[write_idx--] = 'M';
          str[write_idx--] = 'M';
          str[write_idx--] = 'O';
          str[write_idx--] = 'C';
        }
      else if(str[curr_idx] == '!'){
          str[write_idx--] = 'G';
          str[write_idx--] = 'N';
          str[write_idx--] = 'A';
          str[write_idx--] = 'B';
        }
      else if(str[curr_idx] == '.'){
          str[write_idx--] = 'K';
          str[write_idx--] = 'R';
          str[write_idx--] = 'A';
          str[write_idx--] = 'M';
          str[write_idx--] = 'N';
          str[write_idx--] = 'O';
          str[write_idx--] = 'I';
          str[write_idx--] = 'T';
          str[write_idx--] = 'S';
          str[write_idx--] = 'E';
          str[write_idx--] = 'U';
          str[write_idx--] = 'Q';
        }
      else {
          str[write_idx--] = str[curr_idx];
        }
      curr_idx--;
    }
  return final_len;
}

int main()
{
  char str[50] = "I am. What, I am!";
  cout<<"given string:"<<str<<endl;
  cout<<"final length:"<<telex_encoding(str,17)<<endl;
  cout<<"telex encoded string:"<<str<<endl;
  return 0;
}
