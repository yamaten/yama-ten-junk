// basic_regex constructors
// note: using regex, a standard alias of basic_regex<char>
//
// memo:
// $ c++ -latomic -march=native regex-test.cpp
// 「°」（度）、「′」（分）、「″」（秒）
//
// replase M-x replace-string


#include <iostream>
#include <string>
#include <regex>
#include <cmath>

using namespace std;

#include <stdlib.h>

class DMS {
public:
  double value =0;
  int sign =1;
  double dd =0;
  double mm =0;
  double ss =0;

public:
  void init(double val) {
    value = val;
    double tmp = val;
    int sign = tmp<0 ? -1 : +1;
    tmp = fabs(tmp);
    dd = floor(tmp);
    tmp -= dd;
    tmp *= 60;
    mm = floor(tmp);
    tmp -= mm;
    ss = tmp * 60;
  }
  
  void init(double d, double m, double s) {
    init(d + m/60 + s/3600);
  }
  
  DMS() {
    sign = 1;    
    value =
    dd =
    mm =
    ss = 0;
  }

  DMS(double val) { init(val); }    
  DMS(double dd, double mm, double ss) { init( dd + mm/60 + ss/3600); }

  void set_dms(double d) { init(d); };
  void set_dd(double x) { init(x, mm, ss); }
  void set_mm(double x) { init(dd, x, ss); }
  void set_ss(double x) { init(dd, mm, x); }

  string format_dd(double* d =NULL) {
    if (d != NULL)
      set_dms(*d);
    
    sprintf(buff, "%.5f", value);
    return string(buff);
  }

  string format_ddmm(double* d =NULL) {
    if (d != NULL)
      set_dms(*d);
    
    sprintf(buff, "%03.0f-%.5f", sign*dd, mm+ss/60);
    return string(buff);
  }
  
  string format_ddmmss(double* d =NULL) {
    if (d != NULL)
      set_dms(*d);
    
    sprintf(buff, "%03.0f-%02.0f-%06.3f", sign*dd, mm, ss);
    return string(buff);
  }
  
  string format(double* d =NULL) {
    return format_ddmmss(d);
  }

private:
  char buff[100];
  
};

double cvt_deg(string text)
{
  double res = 0.0;
  int sign = 0;

  string pat[] = {
    R"(([NEWS\+\- ]?)(\d+\.?\d*))",
    R"(([NEWS\+\- ]?)(\d+)[,-](\d+\.?\d*))",
    R"(([NEWS\+\- ]?)(\d+)[,-](\d+)[,-](\d+\.?\d*))",
  };

  std::regex re1(pat[0]);
  std::regex re2(pat[1]);
  std::regex re3(pat[2]);
  std::regex rex[] = { re1, re2 ,re3 };

  for (int r=0; r<sizeof(rex)/sizeof(regex); r++) {
    regex re = rex[r];
    if (!regex_match(text, re)) 
      continue;
 
    // cout << "\n input: " << text << ", pat:"<<pat[r]<<" Match."<<endl;
    smatch m ; // std::match_results<string::const_iterator>
    std::regex_search( text, m, re ) ;
     
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
	  if (p>=0) {
 	    sign =  (p<3)  ? -1 : +1;
	  } else {
	    std::cout << "SIGN ERR.";
	    return 0;
	  }
	}
	break;
      
      case 2: res += atof(str); break; // deg
      case 3: res += atof(str)/60; break; // min
      case 4: res += atof(str)/3600; break; // sec;
      }
    }
  }

  if (sign != 0)
    res *= sign;
  return res;
}


int main(int argc, const char* argv[])
{
  string text[] = {
    "143.15",
    "143,30",
    "143,15",
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
    DMS dms(d);
    string s = dms.format();
    std::cout << t << "\t->\t" << d << '\t' << s << endl;
    std::cout << t << "\t->\t" << d << '\t' << dms.format_dd() << endl;
    std::cout << t << "\t->\t" << d << '\t' << dms.format_ddmm() << endl;
  }
 
  return 0;
}


