#include <iostream>
using namespace std;
int main()
{ int x,y,z,f;
  x = y = z = 1;
  f =  --x || y-- && z++;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "z = " << z << endl;
  cout << "f = " << f << endl;
}
