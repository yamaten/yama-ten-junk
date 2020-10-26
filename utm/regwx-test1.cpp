// basic_regex constructors
// note: using regex, a standard alias of basic_regex<char>
//
// $ c++ -latomic -march=native regex-test.cpp
//

#include <iostream>
#include <string>
#include <regex>

/*
int main ()
{

  std::string pattern = "^.*$";

  std::regex first;                                        // default
  std::regex second = first;                               // copy
  std::regex third (pattern);                              // string object initialization
  std::regex fourth ("<[^>]>");                            // string literal initialization
  std::regex fifth (pattern.begin(),pattern.end());        // range initialization
  std::regex sixth {'.','+'};                              // initializer_list initialization

  std::regex seventh ("[0-9A-Z]+", std::regex::ECMAScript);// with syntax option

  using namespace std::regex_constants;                    // introducing constants namespace
  std::regex eighth ("[0-9A-Z]+", ECMAScript);             // same as seventh

  std::regex ninth ("\\bd\\w+", ECMAScript | icase );      // multiple flags

  std::string subject = "Duddy the duck";
  std::string replacement = "yup";

  std::cout << std::regex_replace (subject, ninth, replacement);
  std::cout << std::endl;

  return 0;
}
*/


#include <iostream>
#include <regex>
using namespace std;

int main(int argc, const char* argv[])
{


	string text[] = {
		"N41-23-45.67",
		"S41,23,45.67",
		"E135.0",
		"-12,34,56.78",
		"+12,34,56.78",
		"N42-34.99",
		"W50,12.34",
		"S23.4",
	};
	string pat[] = {
		R"(([NEWS\+\- ]?)(\d+\.\d+))",
		R"(([NEWS\+\- ]?)(\d+)[,-](\d+\.\d+))",
		R"(([NEWS\+\- ]?)(\d+)[,-](\d+)[,-](\d+\.\d+))",
	};
	
	regex re1(pat[0]);
	regex re2(pat[1]);
	regex re3(pat[2]);
	regex rex[] = { re1, re2 ,re3 };

	for (int n=0; n<sizeof(text)/sizeof(string); n++) {
		string t = text[n];

		for (int r=0; r<sizeof(rex)/sizeof(regex); r++) {
		    regex re = rex[r];
		    if (!regex_match(t, re)) {
		  	cout << "input: " << t << ", pat:"<<pat[r]<<" no match."<<endl;
		  	continue;
		    }      

	 	    cout << "input: " << t << ", pat:"<<pat[r]<<" Match."<<endl;
		    //cout << t << '\t' << pat << '\t' << regex_match(t, re1) << endl;
        	    smatch m ; // std::match_results<string::const_iterator>
		    regex_search( t, m, re ) ;
		    //cout << m.str() << std::endl ;
	         
	
//#if 1
    	    for ( size_t i = 0; i < m.size(); ++i ) {
      		cout << m.str(i) << " - " 
            	     << " pos= " << m.position(i)
            	     << " size= " << m.length(i)
                     << endl;
	    } 
//#else /* あるいはこう書ける */
//	    for ( const auto& submatch : m ) { // または const wcsub_match& submatch : match
//	      cout << submatch.str() << " - " 
//        	    << L" pos= " << distance(input, submatch.first)
//     	       	    << L" size= " << submatch.length()
//     		   << endl;
//	    }
//#endif
	}
	
	}

//	 	        regex( R"((\d+\.\d+))" ) ,	// E139.50
//  			regex( R"((\d+)[,-](\d+\.\d+)" ) ,	// N43,30.5
//    			regex( R"((\d+)[,-](\d+)[,-](\d+\.\d+)" ) ,	// N43,30,20.5
//	};
//    	string tx[] = { "E135.2233",
//			"N43,30,55.6"
//	};

//	cout << tx[0] << '\t' << regex_match(tx[0], re[0]) << endl;

//    std::smatch m ; // std::match_results<string::const_iterator>
//    std::regex_search( text, m, re ) ;
//    std::cout << m.str() << std::endl ;
 
 	return 0;
}


