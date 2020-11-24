#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.14159265

#define SetW(n)  std::setw(n)
#define SetP(n)  std::setprecision(n)
#define SetFP(n)  std::fixed<<SetP(n)
#define SetWP(w,n)  SetW(w)<<std::SetFP(n)

int main  (int argc, char* argv[])
{
  cout << "Hello World !" << endl;
  cout << SetW(5) << SetP(3) << PI  << endl;
  cout << SetW(5) << SetP(4) << PI  << endl;
  cout << SetWP(5,3) << PI*4  << endl;
  cout << SetWP(6,3) << PI*4  << endl;
  cout << SetWP(7,3) << PI*4  << endl;
  
  cout << SetW(5) << SetFP(3) << PI  << endl;
  cout << SetW(8) << SetFP(3) << PI  << endl;
  cout << SetWP(8,3) << PI*4  << endl;
  return 0;
}
