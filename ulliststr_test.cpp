/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("1");
  //dat.push_front(8);
  dat.push_front("3");
  dat.push_back("4");
  dat.push_front("9");
  dat.pop_front();
  //dat.get(0);dat.get(1);dat.get(3);
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  //cout << dat.size() << end; 
  return 0;
}
