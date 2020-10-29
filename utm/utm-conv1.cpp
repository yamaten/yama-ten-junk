/**
 *
 *
 */

#include <iostream>
#include <iomanip> 
using namespace std;

#include "LatLong-UTMconversion.h"
int utm_main(int argc, char* argv[]);


void help_msg()
{
    cout <<
"UTM-convert \
 usage: \
   utm [options] [[-l] Lat Long | -u zone xcode ycode] \
   \
  Lat : [N|+|S|-][0 | ddd.ffff | dd,mm.fff | dd,mm,ss.ff | ddd-mm-ss.ff ] \
  Long: [E|+|W|-][0 | ddd.ffff | dd,mm.fff | dd,mm,ss.ff | ddd-mm-ss.ff ] \
"; 
}


int main(int argc, char* argv[])
{
  if (argc < 2) {
    help_msg();      
  }
}


