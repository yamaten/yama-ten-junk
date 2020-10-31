#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
#define FALSE (0)
#define false FALSE
#define TRUE (!FALSE)
#define true TRUE
*/
void help_msg()
{
  cout << "usage: \n"
    "1) tekika <total-vol.> [hour [min]] \n"
    "2) tekika -r <total-vol.> [ended-vol.] <ml/houe> \n";
}

int main(int argc, char** argv)
{ 
  int  calc_mode = 0;
  char* sw = *++argv;
  if (argc == 1 || !strcmp(sw, "-h")) {
    help_msg();
    exit(1);
  }
  else if (!strcmp(sw, "-r")) {
    calc_mode = 1;
    cout << "calc mode 1: " << *argv << endl; 
  } 
  else
    argv--;
  
  float total = 1000.0;
  float teki = 1.0/20;
  float all_teki = total/teki;
  if (*++argv) {
    total = atof(*argv);
    all_teki = total/teki;
  }

  float times = 0;
  float hours = 1.0;
  float mins  = 0;
  float teki_per_hour = atof(*argv);

  // -- MODE 0 --( ml, hour, min) 
  if (calc_mode == 0) {
    if (*++argv) 
      hours = atof(*argv);
    
    if (*++argv)
      mins = atof(*argv);

    times = hours * 60 + mins;
  }
  else {
    float total_vol = total;
    float ended_vol = 0;
    float ml_per_hour =  0;

    // MODE -- 1 -- (total-vol, ml/hour) 
    if (*++argv) {
      calc_mode = 1;
      ended_vol = atof(*argv);

      // MODE -- 2 -- (total-vol, ended-vol, ml/hour)
      if (*++argv) {
	calc_mode = 2;
	total_vol -= ended_vol;
	ml_per_hour = atof(*argv);
      }
      else {
	ml_per_hour = ended_vol;
	argv--;  
      }
      
      // MODE -- 1 to 2 -- drops/hour
      cout << "[ml/hour=" << ml_per_hour << "]" <<endl;
      times = total / ml_per_hour;

      if (*++argv) {
	float ml_per_hour = atof(*argv);
        times = total_vol / ml_per_hour;
      }
      
      /**/ cout<< "[times="   << times << " hours]"
	       << ", total="  << total_vol << "ml "
	       << ", ml/hour="<< ml_per_hour
	       << endl;  
      
    }
  }

  if (calc_mode>0) {
    //times = total / teki_per_hour;
    int hour = floor(times);
    int min =  (int)(60.0*(times-hour));
    
    cout << "*total=" << total <<endl; 
    cout << "*hours=" << hour  <<endl;
    cout << "*mins =" << (times-hour)*60  <<endl;

    int hh = floor(times);
    int mm = floor((times-hh)*60);
    cout << "Total = " <<setw(5)<< total << "ml"
	 << endl;
    cout << "time = " << hh << " hours " << mm << " mins"
	 << endl;
  }
  


 if (calc_mode == 0) {
   cout << "times = "
	<< int(times)/60 << " hours "
	<< int(times)%60 << " mins"
	<< endl;
   float teki_per_min = all_teki / times;
   float teki_per_sec = teki_per_min / 60;
   float sec_per_teki = 60.0 / teki_per_min;

#define fix1 fixed<<setprecision(1)
   cout << "a0) volume = " <<fix1<< total << " ml"
	<< endl;
   cout << "a1) "<<fix1<< teki_per_min << " 滴/分"
	<< endl;
   cout << "a2) "<<fix1<< teki_per_sec << " 滴/秒"
	<< endl;
   cout << "a3) "<<fix1<< sec_per_teki << " 秒/滴"
	<< endl;
 }

  return 0;
}
