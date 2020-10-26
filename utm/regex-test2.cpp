// basic_regex constructors
// note: using regex, a standard alias of basic_regex<char>
//
// $ c++ -latomic -march=native regex-test.cpp
//

#include <iostream>
#include <string>
#include <regex>

using namespace std;

#include <stdlib.h>


double cvt_deg(string text)
{
  double res = 0.0;
  
  string pat[] = {
    R"(([NEWS\+\- ]?)(\d+\.?\d*))",
    R"(([NEWS\+\- ]?)(\d+)[,-](\d+\.?\d*))",
    R"(([NEWS\+\- ]?)(\d+)[,-](\d+)[,-](\d+\.?\d*))",
  };

  regex re1(pat[0]);
  regex re2(pat[1]);
  regex re3(pat[2]);
  regex rex[] = { re1, re2 ,re3 };

  for (int r=0; r<sizeof(rex)/sizeof(regex); r++) {
    regex re = rex[r];
    if (!regex_match(text, re)) {
      // cout << "input: " << text << ", pat:"<<pat[r]<<" no match."<<endl;
      continue;
    }      

    cout << "input: " << text << ", pat:"<<pat[r]<<" Match."<<endl;
    smatch m ; // std::match_results<string::const_iterator>
    regex_search( text, m, re ) ;

    int sign = +1;
     
    for ( size_t i = 0; i < m.size(); ++i ) {
      const char *str = m.str(i).c_str();
      int pos = m.position(i);
      int len = m.length(i);

      switch (i) {
      case 0: // all
	break;

      case 1: // sign flag 
	if (pos==0 && len==1) {
	  int p = string("-SW +NE").find(m.str(i));
	  if (p<0)
	    cout << "SIGN ERR.";
	
	  sign =  (p<3)  ? -1 : +1;
	}
	cout << "sign=" << sign << endl;
	break;
      
      case 2: // deg
        res = atof(str);	
	break;

      case 3: // min
	  res += atof(str)/60;
	break;

      case 4: // sec;
	res += atof(str)/3600;
	break;
      }
      res *= sign;
    }
  }
  return res;
}
      
	
	

int main(int argc, const char* argv[])
{
  string text[] = {
    "143.15",
    "N41-23-45.67",
    "S41,23,45.67",
    "143-45-20",
    "E135.0",
    "-12,34,56.78",
    "+12,34,56.78",
    "N42-34.99",
    "W50,12.34",
    "S23.4",
  };

  for (int i=0; i<sizeof(text)/sizeof(string); i++) {
    string t = text[i];
    double d = cvt_deg( text[i] );
    cout << t << "->" << d << endl;

  }

 
  return 0;
}


