/**
 *  Sapporo:     N43-3.6' / E141-19.7'
 *  Kamishihoro: N43.14.4 / 143.17.7'
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <stdlib.h>

#include "LatLong-UTMconversion.h"
#include "dms-conv.h"


//int utm_main(int argc, char* argv[]); <- //UTM Conversion.cpp- test program for lat/long to UTM and UTM to lat/long conversions


void get_lat_lon(int argc, char* argv[])
{
  double Lat = 0;
  double Lon = 0;
  int n=0;
  
  for (int i=1; i<argc; i++) {
    if (!strcmp(argv[i],"-l")) {
      continue;
    }
    
    double deg = DMS::dms(argv[i]);
    char news = *argv[i];

    switch (news) {
    case 'N':
    case 'S':
      Lat = deg;
      break;

    case 'E':
    case 'W':
      Lon = deg;
      break;
      
    case '+': case '-':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      if (n++==0) 
	Lat = deg;
      else
	Lon = deg;
    }

    if (Lat > 90 || Lat<-90) {
      cout << "Error: Latitude out of range ( Lat. < -90 or 90 > Lat. ) \n";
      exit(1);
    }
    if (Lon > 180 || Lon < -180) {
      cout << "Error: Longitude out of range ( Lon. < -180 or 180 > Lon. ) \n";
      exit(2);
    }
  }
}

void get_utm_coodeinate(int argc, char* argv[]);
{
  cout << "御免んなさい。まだ作ってませんん。"<< endl;
}


void help_msg()
{
    cout <<
"UTM-convert \
 usage: \
   utm [options] [[-l] Lat Long | -u zone xcode ycode] \
   \
   Lat : [N|+|S|-][0 | ddd.ffff | dd,mm.fff | dd,mm,ss.ff | ddd-mm-ss.ff ] \
   Long: [E|+|W|-][0 | ddd.ffff | dd,mm.fff | dd,mm,ss.ff | ddd-mm-ss.ff ] \
   \
 note:\
 *  Sapporo:     N43-3.6'(N43°3'36") / E141-19.7'(143°19'42")\
 *  Kamishihoro: N43-14.4(N43°14'24") / 143-17.7'(143°17'42")\
"; 
}

int main(int argc, char* argv[])
{
  string cmd = argv[0];
  string sw = argv[1];
  
  double Lat = 0; // 緯度 latitude 
  double Lon = 0; // 経度 longitude  

  if (!strcmp(sw, "-h") || argc < 3) {
    help_msg();
    double Lat = dms("N43-3.6");
    double Lon = dms("E141-19.7");
    UTM utm; // = utm_main(Lat, Lon);

    cout << "Sapporo city:" << endl; 
    cout << "Starting position(Lat, Long):  " << Lat << "   " << Lon <<endl;

    LLtoUTM(utm.RefEllipsoid, Lat, Lon, utm.UTMNorthing, utm.UTMEasting, utm.UTMZone);
    cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(5);
    cout << "Calculated UTM position(Northing, Easting, Zone):  ";
    cout << utm.UTMNorthing << "   " << utm.UTMEasting;
    cout << "   " << UTMZone <<endl;

    UTMtoLL(utm.RefEllipsoid, utm.UTMNorthing, utm.UTMEasting, utm.UTMZone, Lat, Lon);
    cout << "Calculated Lat, Long position(Lat, Long):  " << Lat << "   " << Lon << endl <<endl;

    //return utm;
    exit(0);
  }
  else if (!(strcmp(sw, "-l") || argc < 5) {
    get_lat_lojn(argc, argv);
  }
  else if (!strcmp(sw,"-u")! || argc == 5) {
    get_utm_coodinate(argc,argv);
  }
}



  
