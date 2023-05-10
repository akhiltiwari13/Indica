#include <iostream>
#include "temp_class.h"

using namespace std;

int main(int argc, char* argv[]){

    Accum<int> accum(55);
    accum+=5;
    accum+=6;
    accum+=7;
    accum+=8;
    
    cout<<"accum: "<<accum.getState()<<endl;
    return 0;
}