/**
 * Templates from Effective C++ (chapter 7)
**/

#include<bits/stdc++.h>
using namespace std;

//============================================================= ITEM 42 =========================================================================
//Use typename to identify nested dependent type names, except in base class lists or as a base class identifier in a member initialization list.

template<typename C>                           
void print2nd(const C& container)               // container;
{                                               // this is not valid C++!
  if (container.size() >= 2) {
     typename C::const_iterator iter(container.begin()); // get iterator to 1st element
     ++iter;                                    // move iter to 2nd element
     int value = *iter;                         // copy that element to an int
     std::cout << value;                        // print the int
  }
}


// typename rule exception
template<typename C>                            
class Tbase
{                                               
    public:
        C mem{};
};

template<typename C>                            
class Tderived:public Tbase<C>
{                                               
    public:
    Tderived(C c):Tbase<C>::mem(c){

    }
};

// real world scenario
template<typename IterT>
void workWithIterator(IterT iter)
{
  typedef typename std::iterator_traits<IterT>::value_type  value_type; //typedef & typename getting used together.
  value_type temp(*iter);
}

/* ============================================================= ITEM 43 ========================================================================= */
/* Item 43: Know how to access names in templatized base classes */
/* In derived class templates, refer to names in base class templates via a “this->” prefix, via using declarations, or via an explicit base class qualification. */

/* ============================================================= ITEM 44 ========================================================================= */
/* Item 44: Factor parameter-independent code out of templates */

/* ============================================================= ITEM 44 ========================================================================= */
/* Item 45: Use member function templates to accept “all compatible types.” */

/* ============================================================= ITEM 44 ========================================================================= */
/* Item 47: Use traits classes for information about types */

/* ============================================================= ITEM 44 ========================================================================= */
/* Item 48: Be aware of template metaprogramming */

template<typename IterT, typename DistT>
void advance(IterT& iter, DistT d)
{
  if (typeid(typename std::iterator_traits<IterT>::iterator_category) ==
      typeid(std::random_access_iterator_tag)) {

     iter += d;                                     // use iterator arithmetic
  }                                                 // for random access iters
  else {
    if (d >= 0) { while (d--) ++iter; }             // use iterative calls to
    else { while (d++) --iter; }                    // ++ or -- for other
  }                                                 // iterator categories
}

int main(int argc, char* argv[]){

    return 0;
}
