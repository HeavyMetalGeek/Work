#include "WorkNamespace.h"
#include <fstream>
using namespace work;
int main(int argc, char *argv[])
{
    if (argc != 6) return 1;
    for (int i = 0; i < argc; i++)
    {
        string arg = argv[i];
        if (arg == "-l" || arg == "--lengths")
        {
            beam myBeam;
            myBeam.arm = atof(argv[2]);
            myBeam.armPoint.load = atof(argv[3]);
            myBeam.span = atof(argv[4]);
            myBeam.otherPoint.load = atof(argv[5]);
            myBeam.lengthsCalc();
            myBeam.beamSelect();
            cout << "Beam Type: \t\t" << myBeam.shape << endl;
            cout << "Arm/Span Ratio: \t" << myBeam.armSpanRatio << endl;
            cout << "% Allow Shear: \t\t" << myBeam.pctAllowShear << endl;
        }
    }
    return 0;
}
