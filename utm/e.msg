utm-conv.cpp:29:27: error: use of undeclared identifier 'atgv'; did you mean ' deg = DMS::dms(atgv[i]);
                          ^~~~
                          argv
utm-conv.cpp:18:34: note: 'argv' declared here
void get_lat_lon(int argc, char* argv[])
                                 ^
utm-conv.cpp:29:23: error: no member named 'dms' in 'DMS'
    double deg = DMS::dms(atgv[i

~~~~~^
utm-conv.cpp:64:1: error: expected unqualified-id
{
^
utm-conv.cpp:87:16: error: use of undeclared identifier 'atgv'; did you mean 'argv'?
  string cmd = atgv[0];
               ^~~~
               argv
utm-conv.cpp:85:26: note: 'argv' declared here
int main(int argc, char* argv[])
                         ^
utm-conv.cpp:93:8: error: no matching function for call to 'strcmp'
  if (!strcmp(sw, "-h") || srgc < 3) {
       ^~~~~~
/data/data/com.termux/files/usr/include/string.h:102:5: note: candidate function not viable: no known conversion from 'std::__ndk1::string' (aka 'basic_string<char, char_traits<char>, allocator<char> >') to 'const char *' for 1st argument
int strcmp(const char* __lhs, const char* __rhs) __attribute_pure__;
    ^
utm-conv.cpp:93:28: error: use of undeclared identifier 'srgc'; did you mean 'argc'?
  if (!strcmp(sw, "-h") || srgc < 3) {
                           ^~~~
                           argc
utm-conv.cpp:85:14: note: 'argc' declared here
int main(int argc, char* argv[])
             ^
utm-conv.cpp:95:18: error: use of undeclared identifier 'dms'
    double Lat = dms("N43-3.6");
                 ^
utm-conv.cpp:96:18: error: use of undeclared identifier 'dms'
    double Lon = dms("E141-19.7");
                 ^
utm-conv.cpp:97:5: error: unknown type name 'UTM'
    UTM utm; // = utm_main(Lat, Lon);
    ^
utm-conv.cpp:106:22: error: use of undeclared identifier 'UTMZone'; did you mean 'UTMtoLL'?
    cout << "   " << UTMZone <<endl;
                     ^~~~~~~
                     UTMtoLL
./LatLong-UTMconversion.h:12:6: note: 'UTMtoLL' declared here
void UTMtoLL(int ReferenceEllipsoid, const double UTMNorthing, const double UTMEasting, const char* UTMZone,
     ^
utm-conv.cpp:106:22: warning: address of function 'UTMtoLL' will always evaluate to 'true' [-Wpointer-bool-conversion]
    cout << "   " << UTMZone <<endl;
                  ~~ ^~~~~~~
utm-conv.cpp:106:22: note: prefix with the address-of operator to silence this warning
    cout << "   " << UTMZone <<endl;
                     ^
                     &
utm-conv.cpp:114:14: error: no matching function for call to 'strcmp'
  else if (!(strcmp(sw, "-l") || argc < 5) {
             ^~~~~~
/data/data/com.termux/files/usr/include/string.h:102:5: note: candidate function not viable: no known conversion from 'std::__ndk1::string' (aka 'basic_string<char, char_traits<char>, allocator<char> >') to 'const char *' for 1st argument
int strcmp(const char* __lhs, const char* __rhs) __attribute_pure__;
    ^
1 warning and 11 errors generated.
