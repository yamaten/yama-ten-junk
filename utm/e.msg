utm-conv.cpp:28:1: error: expected unqualified-id
{
^
1 error generated.
UTMConversion.cpp:6:1: error: unknown type name 'Using'
Using namespace std;
^
UTMConversion.cpp:6:7: error: expected unqualified-id
Using namespace std;
      ^
UTMConversion.cpp:25:9: error: use of undeclared identifier 'cout'; did you mean 'std::cout'?
        cout << "Starting position(Lat, Long):  " << Lat << "   " << Long <<endl;
        ^~~~
        std::cout
/data/data/com.termux/files/usr/bin/../include/c++/v1/iostream:54:33: note: 'std::cout' declared here
extern _LIBCPP_FUNC_VIS ostream cout;
                                ^
UTMConversion.cpp:25:77: error: use of undeclared identifier 'endl'; did you mean 'std::endl'?
        cout << "Starting position(Lat, Long):  " << Lat << "   " << Long <<endl;
                                                                            ^~~~
                                                                            std::endl
/data/data/com.termux/files/usr/bin/../include/c++/v1/ostream:1000:1: note: 'std::endl' declared here
endl(basic_ostream<_CharT, _Traits>& __os)
^
UTMConversion.cpp:28:9: error: use of undeclared identifier 'cout'; did you mean 'std::cout'?
        cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(5);
        ^~~~
        std::cout
/data/data/com.termux/files/usr/bin/../include/c++/v1/iostream:54:33: note: 'std::cout' declared here
extern _LIBCPP_FUNC_VIS ostream cout;
                                ^
UTMConversion.cpp:28:29: error: use of undeclared identifier 'ios'; did you mean 'std::ios'?
        cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(5);
                            ^~~
                            std::ios
/data/data/com.termux/files/usr/bin/../include/c++/v1/iosfwd:156:38: note: 'std::ios' declared here
typedef basic_ios<char>              ios;
                                     ^
UTMConversion.cpp:28:46: error: use of undeclared identifier 'ios'; did you mean 'std::ios'?
        cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(5);
                                             ^~~
                                             std::ios
/data/data/com.termux/files/usr/bin/../include/c++/v1/iosfwd:156:38: note: 'std::ios' declared here
typedef basic_ios<char>              ios;
                                     ^
UTMConversion.cpp:28:17: error: use of undeclared identifier 'setiosflags'; did you mean 'std::setiosflags'?
        cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(5);
                ^~~~~~~~~~~
                std::setiosflags
/data/data/com.termux/files/usr/bin/../include/c++/v1/iomanip:126:1: note: 'std::setiosflags' declared here
setiosflags(ios_base::fmtflags __mask)
^
UTMConversion.cpp:28:61: error: use of undeclared identifier 'setprecision'; did you mean 'std::setprecision'?
        cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(5);
                                                            ^~~~~~~~~~~~
                                                            std::setprecision
/data/data/com.termux/files/usr/bin/../include/c++/v1/iomanip:235:1: note: 'std::setprecision' declared here
setprecision(int __n)
^
UTMConversion.cpp:29:9: error: use of undeclared identifier 'cout'; did you mean 'std::cout'?
        cout << "Calculated UTM position(Northing, Easting, Zone):  ";
        ^~~~
        std::cout
/data/data/com.termux/files/usr/bin/../include/c++/v1/iostream:54:33: note: 'std::cout' declared here
extern _LIBCPP_FUNC_VIS ostream cout;
                                ^
UTMConversion.cpp:30:9: error: use of undeclared identifier 'cout'; did you mean 'std::cout'?
        cout << UTMNorthing << "   " << UTMEasting;
        ^~~~
        std::cout
/data/data/com.termux/files/usr/bin/../include/c++/v1/iostream:54:33: note: 'std::cout' declared here
extern _LIBCPP_FUNC_VIS ostream cout;
                                ^
UTMConversion.cpp:31:9: error: use of undeclared identifier 'cout'; did you mean 'std::cout'?
        cout << "   " << UTMZone <<endl;
        ^~~~
        std::cout
/data/data/com.termux/files/usr/bin/../include/c++/v1/iostream:54:33: note: 'std::cout' declared here
extern _LIBCPP_FUNC_VIS ostream cout;
                                ^
UTMConversion.cpp:31:36: error: use of undeclared identifier 'endl'; did you mean 'std::endl'?
        cout << "   " << UTMZone <<endl;
                                   ^~~~
                                   std::endl
/data/data/com.termux/files/usr/bin/../include/c++/v1/ostream:1000:1: note: 'std::endl' declared here
endl(basic_ostream<_CharT, _Traits>& __os)
^
UTMConversion.cpp:34:9: error: use of undeclared identifier 'cout'; did you mean 'std::cout'?
        cout << "Calculated Lat, Long position(Lat, Long):  " << Lat << "   " << Long << endl <<endl;
        ^~~~
        std::cout
/data/data/com.termux/files/usr/bin/../include/c++/v1/iostream:54:33: note: 'std::cout' declared here
extern _LIBCPP_FUNC_VIS ostream cout;
                                ^
UTMConversion.cpp:34:90: error: use of undeclared identifier 'endl'; did you mean 'std::endl'?
        cout << "Calculated Lat, Long position(Lat, Long):  " << Lat << "   " << Long << endl <<endl;
                                                                                         ^~~~
                                                                                         std::endl
/data/data/com.termux/files/usr/bin/../include/c++/v1/ostream:1000:1: note: 'std::endl' declared here
endl(basic_ostream<_CharT, _Traits>& __os)
^
UTMConversion.cpp:34:97: error: use of undeclared identifier 'endl'; did you mean 'std::endl'?
        cout << "Calculated Lat, Long position(Lat, Long):  " << Lat << "   " << Long << endl <<endl;
                                                                                                ^~~~
                                                                                                std::endl
/data/data/com.termux/files/usr/bin/../include/c++/v1/ostream:1000:1: note: 'std::endl' declared here
endl(basic_ostream<_CharT, _Traits>& __os)
^
UTMConversion.cpp:37:9: error: use of undeclared identifier 'cout'; did you mean 'std::cout'?
        cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(5);
        ^~~~
        std::cout
/data/data/com.termux/files/usr/bin/../include/c++/v1/iostream:54:33: note: 'std::cout' declared here
extern _LIBCPP_FUNC_VIS ostream cout;
                                ^
UTMConversion.cpp:37:29: error: use of undeclared identifier 'ios'; did you mean 'std::ios'?
        cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(5);
                            ^~~
                            std::ios
/data/data/com.termux/files/usr/bin/../include/c++/v1/iosfwd:156:38: note: 'std::ios' declared here
typedef basic_ios<char>              ios;
                                     ^
UTMConversion.cpp:37:46: error: use of undeclared identifier 'ios'; did you mean 'std::ios'?
        cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(5);
                                             ^~~
                                             std::ios
/data/data/com.termux/files/usr/bin/../include/c++/v1/iosfwd:156:38: note: 'std::ios' declared here
typedef basic_ios<char>              ios;
                                     ^
fatal error: too many errors emitted, stopping now [-ferror-limit=]
20 errors generated.
