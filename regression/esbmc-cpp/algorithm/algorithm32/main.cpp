// unique_copy example
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {10,20,20,20,30,30,20,20,10};
  int myints1[] = {10,10,20,20,30,0,0,0,0};
  vector<int> myvector (9);                            // 0  0  0  0  0  0  0  0  0
  vector<int>::iterator it;

  // using default comparison:
  it=unique_copy (myints,myints+9,myvector.begin());   // 10 20 30 20 10 0  0  0  0
                                                       //                ^

  myvector.assign(myints1, myints1+9);                          // 10 10 20 20 30 0  0  0  0
                                                       //                ^

  // using predicate comparison:
  it=unique_copy (myvector.begin(), it, myvector.begin(), myfunction);
                                                       // 10 20 30 20 30 0  0  0  0
                                                       //          ^
  assert(myvector[0] == 10);
  assert(myvector[1] == 20);
  assert(myvector[2] == 30);
  assert(myvector[3] == 20);
  assert(myvector[4] == 30);

 // myvector.resize( it - myvector.begin() );            // 10 20 30

//   print out content:
  cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); it++)
    cout << " " << *it;

  cout << endl;

  return 0;
}
