#include <iostream>
#include <iomanip>
using namespace std;

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

    cout << "Total = " << setw(5) << total << "ml" << endl;
    cout << "time = " << times/60 << "hours " << times%60 << " mins" << endl;

#define fix1 fixed<<setprecision(1)

    cout << "a1) "  << fix1 << teki_per_min << " teki / min" << endl;
    cout << "a2) "  << fix1 << teki_per_sec << " teki / sec" << endl;
    cout << "a3) "  << fix1 << sec_per_teki << " sec / teki" << endl;

    return 0;
}
