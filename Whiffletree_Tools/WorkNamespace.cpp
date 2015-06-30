#include "WorkNamespace.h"

using namespace work;

beam::spanCalc()
{
    double dx = sqrt( pow(armPoint.x - otherPoint.x, 2) );
    double dy = sqrt( pow(armPoint.y - otherPoint.y, 2) );
    span = sqrt( pow(dx + dy, 2) );
}

beam::armCalc()
{
    arm = otherPoint.load * span / takeoffPoint.load;
    other = span - arm;
}

beam::beamSelect()
{
    const vector<double> t =
    {

    }
}

