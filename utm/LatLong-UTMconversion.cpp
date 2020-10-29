//LatLong- UTM conversion.cpp
//Lat Long - UTM, UTM - Lat Long conversions


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "LatLong-UTMconversion.h"




/*Reference ellipsoids derived from Peter H. Dana's website- 
http://www.utexas.edu/depts/grg/gcraft/notes/datum/elist.html
Department of Geography, University of Texas at Austin
Internet: pdana@mail.utexas.edu
3/22/95


Source
Defense Mapping Agency. 1987b. DMA Technical Report: Supplement to Department of Defense World Geodetic System
1984 Technical Report. Part I and II. Washington, DC: Defense Mapping Agency
*/






void LLtoUTM(int ReferenceEllipsoid, const double Lat, const double Long, 
                         double &UTMNorthing, double &UTMEasting, char* UTMZone)
{
//converts lat/long to UTM coords.  Equations from USGS Bulletin 1532 
//East Longitudes are positive, West longitudes are negative. 
//North latitudes are positive, South latitudes are negative
//Lat and Long are in decimal degrees
//Written by Chuck Gantz- chuck.gantz@globalstar.com

  double a = ellipsoid[ReferenceEllipsoid].EquatorialRadius;
  double eccSquared = ellipsoid[ReferenceEllipsoid].eccentricitySquared;
  double k0 = 0.9996;
  
  double LongOrigin;
  double eccPrimeSquared;
  double N, T, C, A, M;
        
//Make sure the longitude is between -180.00 .. 179.9
  double LongTemp = (Long+180)-int((Long+180)/360)*360-180; // -180.00 .. 179.9;

  double LatRad = Lat*deg2rad;
  double LongRad = LongTemp*deg2rad;
  double LongOriginRad;
  int    ZoneNumber;

  ZoneNumber = int((LongTemp + 180)/6) + 1;
  
  if( Lat >= 56.0 && Lat < 64.0 && LongTemp >= 3.0 && LongTemp < 12.0 )
    ZoneNumber = 32;


  // Special zones for Svalbard
  if( Lat >= 72.0 && Lat < 84.0 ) 
  {
      if(      LongTemp >= 0.0  && LongTemp <  9.0 ) ZoneNumber = 31;
      else if( LongTemp >= 9.0  && LongTemp < 21.0 ) ZoneNumber = 33;
      else if( LongTemp >= 21.0 && LongTemp < 33.0 ) ZoneNumber = 35;
      else if( LongTemp >= 33.0 && LongTemp < 42.0 ) ZoneNumber = 37
  }
  LongOrigin = (ZoneNumber - 1)*6 - 180 + 3;  //+3 puts origin in middle of zone
  LongOriginRad = LongOrigin * deg2rad;
  
  //compute the UTM Zone from the latitude and longitude
  sprintf(UTMZone, "%d%c", ZoneNumber, UTMLetterDesignator(Lat));

  eccPrimeSquared = (eccSquared)/(1-eccSquared);

  N = a/sqrt(1-eccSquared*sin(LatRad)*sin(LatRad));
  T = tan(LatRad)*tan(LatRad);
  C = eccPrimeSquared*cos(LatRad)*cos(LatRad);
  A = cos(LatRad)*(LongRad-LongOriginRad);

  M = a*( (1 - eccSquared/4 - 3*eccSquared*eccSquared/64 - 5*eccSquared*eccSquared*eccSquared/256) * LatRad 
            - (3*eccSquared/8 + 3*eccSquared*eccSquared/32 + 45*eccSquared*eccSquared*eccSquared/1024)*sin(2*LatRad)
            + (15*eccSquared*eccSquared/256 + 45*eccSquared*eccSquared*eccSquared/1024)*sin(4*LatRad) 
            - (35*eccSquared*eccSquared*eccSquared/3072)*sin(6*LatRad)
	 );
        
        UTMEasting = (double)(k0 * N * (A+(1-T+C) *A*A*A/6
			      + (5-18*T+T*T+72*C-58*eccPrimeSquared)*A*A*A*A*A/120)
			      + 500000.0);


        UTMNorthing = (double)(k0 * ( M
				      +N*TAN(LATRAD)*(A*A/2+(5-T+9*C+4*C*C)*A*A*A*A/24
                                 + (61-58*T+T*T+600*C-330*ECCPRIMESQUARED)*A*A*A*A*A*A/720)));
        IF(LAT < 0)
                UTMNORTHING += 10000000.0; //10000000 METER OFFSET FOR SOUTHERN HEMISPHERE
}


CHAR UTMLETTERDESIGNATOR(DOUBLE LAT)
{
//THIS ROUTINE DETERMINES THE CORRECT UTM LETTER DESIGNATOR FOR THE GIVEN LATITUDE
//RETURNS 'Z' IF LATITUDE IS OUTSIDE THE UTM LIMITS OF 84N TO 80S
        //WRITTEN BY CHUCK GANTZ- CHUCK.GANTZ@GLOBALSTAR.COM
        CHAR LETTERDESIGNATOR;


        IF((84 >= LAT) && (LAT >= 72)) LETTERDESIGNATOR = 'X';
        ELSE IF((72 > LAT) && (LAT >= 64)) LETTERDESIGNATOR = 'W';
        ELSE IF((64 > LAT) && (LAT >= 56)) LETTERDESIGNATOR = 'V';
        ELSE IF((56 > LAT) && (LAT >= 48)) LETTERDESIGNATOR = 'U';
        ELSE IF((48 > LAT) && (LAT >= 40)) LETTERDESIGNATOR = 'T';
        ELSE IF((40 > LAT) && (LAT >= 32)) LETTERDESIGNATOR = 'S';
        ELSE IF((32 > LAT) && (LAT >= 24)) LETTERDESIGNATOR = 'R';
        ELSE IF((24 > LAT) && (LAT >= 16)) LETTERDESIGNATOR = 'Q';
        ELSE IF((16 > LAT) && (LAT >= 8)) LETTERDESIGNATOR = 'P';
        ELSE IF(( 8 > LAT) && (LAT >= 0)) LETTERDESIGNATOR = 'N';
        ELSE IF(( 0 > LAT) && (LAT >= -8)) LETTERDESIGNATOR = 'M';
        ELSE IF((-8> LAT) && (LAT >= -16)) LETTERDESIGNATOR = 'L';
        ELSE IF((-16 > LAT) && (LAT >= -24)) LETTERDESIGNATOR = 'K';
        ELSE IF((-24 > LAT) && (LAT >= -32)) LETTERDESIGNATOR = 'J';
        ELSE IF((-32 > LAT) && (LAT >= -40)) LETTERDESIGNATOR = 'H';
        ELSE IF((-40 > LAT) && (LAT >= -48)) LETTERDESIGNATOR = 'G';
        ELSE IF((-48 > LAT) && (LAT >= -56)) LETTERDESIGNATOR = 'F';
        ELSE IF((-56 > LAT) && (LAT >= -64)) LETTERDESIGNATOR = 'E';
        ELSE IF((-64 > LAT) && (LAT >= -72)) LETTERDESIGNATOR = 'D';
        ELSE IF((-72 > LAT) && (LAT >= -80)) LETTERDESIGNATOR = 'C';
        ELSE LETTERDESIGNATOR = 'Z'; //THIS IS HERE AS AN ERROR FLAG TO SHOW THAT THE LATITUDE IS OUTSIDE THE UTM LIMITS


        RETURN LETTERDESIGNATOR;
}




VOID UTMTOLL(INT REFERENCEELLIPSOID, CONST DOUBLE UTMNORTHING, CONST DOUBLE UTMEASTING, CONST CHAR* UTMZONE,
                          DOUBLE& LAT,  DOUBLE& LONG )
{
//CONVERTS UTM COORDS TO LAT/LONG.  EQUATIONS FROM USGS BULLETIN 1532 
//EAST LONGITUDES ARE POSITIVE, WEST LONGITUDES ARE NEGATIVE. 
//NORTH LATITUDES ARE POSITIVE, SOUTH LATITUDES ARE NEGATIVE
//LAT AND LONG ARE IN DECIMAL DEGREES.
//WRITTEN BY CHUCK GANTZ- CHUCK.GANTZ@GLOBALSTAR.Com


        double k0 = 0.9996;
        double a = ellipsoid[ReferenceEllipsoid].EquatorialRadius;
        double eccSquared = ellipsoid[ReferenceEllipsoid].eccentricitySquared;
        double eccPrimeSquared;
        double e1 = (1-sqrt(1-eccSquared))/(1+sqrt(1-eccSquared));
        double N1, T1, C1, R1, D, M;
        double LongOrigin;
        double mu, phi1, phi1Rad;
        double x, y;
        int ZoneNumber;
        char* ZoneLetter;
        int NorthernHemisphere; //1 for northern hemispher, 0 for southern


        x = UTMEasting - 500000.0; //remove 500,000 meter offset for longitude
        y = UTMNorthing;


        ZoneNumber = strtoul(UTMZone, &ZoneLetter, 10);
        if((*ZoneLetter - 'N') >= 0)
                NorthernHemisphere = 1;//point is in northern hemisphere
        else
        {
                NorthernHemisphere = 0;//point is in southern hemisphere
                y -= 10000000.0;//remove 10,000,000 meter offset used for southern hemisphere
        }


        LongOrigin = (ZoneNumber - 1)*6 - 180 + 3;  //+3 puts origin in middle of zone


        eccPrimeSquared = (eccSquared)/(1-eccSquared);


        M = y / k0;
        mu = M/(a*(1-eccSquared/4-3*eccSquared*eccSquared/64-5*eccSquared*eccSquared*eccSquared/256));


        phi1Rad = mu        + (3*e1/2-27*e1*e1*e1/32)*sin(2*mu) 
                                + (21*e1*e1/16-55*e1*e1*e1*e1/32)*sin(4*mu)
                                +(151*e1*e1*e1/96)*sin(6*mu);
        phi1 = phi1Rad*rad2deg;


        N1 = a/sqrt(1-eccSquared*sin(phi1Rad)*sin(phi1Rad));
        T1 = tan(phi1Rad)*tan(phi1Rad);
        C1 = eccPrimeSquared*cos(phi1Rad)*cos(phi1Rad);
        R1 = a*(1-eccSquared)/pow(1-eccSquared*sin(phi1Rad)*sin(phi1Rad), 1.5);
        D = x/(N1*k0);


        Lat = phi1Rad - (N1*tan(phi1Rad)/R1)*(D*D/2-(5+3*T1+10*C1-4*C1*C1-9*eccPrimeSquared)*D*D*D*D/24
                                        +(61+90*T1+298*C1+45*T1*T1-252*eccPrimeSquared-3*C1*C1)*D*D*D*D*D*D/720);
        Lat = Lat * rad2deg;


        Long = (D-(1+2*T1+C1)*D*D*D/6+(5-2*C1+28*T1-3*C1*C1+8*eccPrimeSquared+24*T1*T1)
                                        *D*D*D*D*D/120)/cos(phi1Rad);
        Long = LongOrigin + Long * rad2deg;


}
