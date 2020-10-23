#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    float teki = 1.0/20;

    float total = 2000.0;
    if (argc>1)
        total = atof(argv[1]);

    float all_teki = total/teki;

    float hours = 24.0;
    if (argc>2)
	hours = atof(argv[2]);

    int mins  = 0;
    if (argc>3)
	mins = atof(argv[3]);

    int times = hours*60+mins;

    float teki_per_min = all_teki / times;
    float teki_per_sec = teki_per_min / 60;
    float sec_per_teki = 60.0 / teki_per_min;

    printf("Total = %5.1f ml\n",total);
    printf("time = %d hours %d mins\n",times/60, times%60);
    printf("a1) %5.1f teki / min\n",teki_per_min);
    printf("a2) %5.1f teki / sec\n", teki_per_sec);
    printf("a3) %5.1f sec / teki\n", sec_per_teki);

    return 0;
}
