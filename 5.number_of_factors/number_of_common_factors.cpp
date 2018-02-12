#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(a==0)
    return b;
    return gcd(b%a, a);
}

int main()
{
    int a,b;
    int count=0;
    
    cout<<"numbers:"<<endl;
    cin>>a;
    cin>>b;
    
    int hcf= gcd(a,b);
    
    for(int i=1; i<=sqrt(hcf); i++)
    {
        
      if(hcf%i==0)
      {
            if(hcf/i==i)
        {
            count++;
        }
        else{
            count+=2;
        }
      }
    }
    
    cout<<count<<endl;
    
    return 0;
}

