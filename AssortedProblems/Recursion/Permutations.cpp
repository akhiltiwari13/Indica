#include<bits/stdc++.h>
using namespace std;

vector <int> arr {5, 46, 7};
vector <int> subset;
vector <int> permutation;
vector <bool> selected(3,false);

void print_premutations()
{
    if(permutation.size()==arr.size())
    {
        for(auto itr: permutation)
        {
            cout<<itr<<" ";
        }
        cout<<endl;
    }
    else{
        for(unsigned int i = 0; i < arr.size(); i++)
        {
            if(!selected[i])
            {
                permutation.push_back(arr[i]);
                selected[i]=true;
                print_premutations();
                permutation.pop_back();
                selected[i]=false;
            }
        }
    }
}

void print_subsets(unsigned int index)
{
    if(index == arr.size())
    {
        for(auto itr: subset)
        {
            cout<<itr<<" ";
        }
        cout<<endl;
    }
    else{
        subset.push_back(arr[index]);
        print_subsets(index+1);
        subset.pop_back();
        print_subsets(index+1);
        
    }
}
int main()
{
    cout<<"subsets"<<endl;
    print_subsets(0);
    cout<<"permutations"<<endl;
    print_premutations();
    return 0;
}