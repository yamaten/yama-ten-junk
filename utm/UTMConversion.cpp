//UTM Conversion.cpp- test program for lat/long to UTM and UTM to lat/long conversions
#include <iostream> // #include <iostream.h>
#include <iomanip>  // #include <iomanip.h>
#include "LatLong-UTMconversion.h"

using namespace std;

struct UTM {
public:
  int RefEllipsoid = 23; //WGS-84. See list with file "LatLong-UTMconversion.cpp" for id numbers
  char UTMZone[4] = "";
  double UTMNorthing = 0;
  double UTMEasting = 0;
  double SwissNorthin = 0;
  double SwissEasting  = 0;
};  



// void main(
// int utm_main(int argc, char* argv[])
UTM utm_main(double latitude, double longitude)
{
  double Lat = latitude;
  double Lon = longitude;

  /*
  if (argc>1) {
    if (strcmp(argv[1], "-u) == 0) {
      get_utm_coodinate(argc,argv);
    }
    if (strcmp(argv[1], "-l") == 0)
      get_lat_lojn(argc, argv);'
    }
          
    if (argc ==3 ) { // [0]prog, [1]Lat, [2],Long
       Lat = atof(argv[1]);
       Lon = atof(argv[2]);
    }
  */
  
    UTM utm;
    //    double UTMNorthing;
    //    double UTMEasting;
    //    double SwissNorthing;
    //    double SwissEasting;
    //    char UTMZone[4];
    //    int RefEllipsoid = 23;//WGS-84. See list with file "LatLong- UTM conversion.cpp" for id numbers


    //    cout << "Starting position(Lat, Long):  " << Lat << "   " << Long <<endl;

    LLtoUTM(utm.RefEllipsoid, Lat, Lon, utm.UTMNorthing, utm.UTMEasting, utm.UTMZone);
    //cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(5);
    //cout << "Calculated UTM position(Northing, Easting, Zone):  ";
    //cout << utm.UTMNorthing << "   " << utm.UTMEasting;
    //cout << "   " << UTMZone <<end;

    UTMtoLL(utm.RefEllipsoid, utm.UTMNorthing, utmlll.UTMEasting, utm.UTMZone, Lat, Lon);
    //cout << "Calculated Lat, Long position(Lat, Long):  " << Lat << "   " << Lon << endl <<endl;

//  LLtoSwissGrid(Lat, Long, SwissNorthing, SwissEasting);
//  cout << setiosflags(ios::showpoint | ios::fixed) << setpre
//  cout << "Calculated Swiss Grid position(Northing, Easting):  ";
//  cout << SwissNorthing << "   " << SwissEasting << endl;

    return utm;
}




/* N 47.38195° E 8.54879°  (Swiss Grid: 683.748 248.342)
  N 47°12.625' / E 7° 27.103'= N 47.21041667 E 7.45171667(Swiss Grid = 600920/228685) 
  N 47°22.690' / E 8° 13.950'= N 47.37816667 E 8.23250000 (Swiss Grid = 659879/247637)
*/
