#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    float drops = 1.0/20;

    float total_vol = 2000.0;
    if (argc>1)
        total_vol = atof(argv[1]);

    float all_drops = total_vol/drops;

    float hours = 24.0;
    if (argc>2)
	hours = atof(argv[2]);

    int mins  = 0;
    if (argc>3)
	mins = atof(argv[3]);
    
    int total_mins = hours*60+mins;

    
    float vol_per_min  = total_vol / total_mins;
    float vol_per_hour = vol_per_min * 60;
    float vol_per_sec  = vol_per_min / 60;
    

    printf("Total_Volume = %5.1f ml\n",total_vol);
    printf("time = %d hours %d mins\n",total_mins/60, total_mins%60);
    printf("a0) %5.1f ml / hour\n",vol_per_hour);
    printf("a1) %5.1f ml / min\n", vol_per_min);
    printf("a2) %5.2f ml / sec\n", vol_per_sec);
    printf("a3) %5.1f drops / min\n", vol_per_min / drops);
    printf("a3) %5.2f drops / sec\n", vol_per_sec / drops);
    
    return 0;
}
