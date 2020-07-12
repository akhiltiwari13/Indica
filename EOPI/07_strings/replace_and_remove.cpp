#include <iostream>
using namespace std;

int replace_and_remove(char arr[], int size){
  int  final_size =0;
  int write_idx = 0, a_count = 0;


  // remove the b's
  for(int i = 0; i< size; i++){
      if(arr[i] != 'b'){
          arr[write_idx++] = arr[i];

           if(arr[i] == 'a')
              a_count++;
        }
    }


  // substitute a's with 2 d's
  int curr_idx= write_idx -1;
  write_idx = write_idx + a_count -1;
  final_size = write_idx +1;
  while(curr_idx >=0){
      if(arr[curr_idx] == 'a'){
          arr[write_idx--] = 'd';
          arr[write_idx--] = 'd';
        }else{
          arr[write_idx--] = arr[curr_idx];
        }
      curr_idx--;
    }

  return final_size;
}

int main(){
    char str[7] = "aabdbc";
    cout<<"given character array: "<<str<<endl;
    cout<< "final size:"<< replace_and_remove(str, 6)<<endl;
    cout<< "replaced and removed array: "<< str<<endl;
    return 0;
}
