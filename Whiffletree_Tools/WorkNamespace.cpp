#include "WorkNamespace.h"

using namespace work;

const vector<string> beam::_beamList_shape =
{
    "][ Chan 12", "][ Chan 10", "][ Chan 8", "][ Chan 6", "][ Chan 4", "][ Chan 3", "][ Chan 2",
    "Bar 2.00x0.50", "Bar 1.50x0.50", "Bar 1.50x0.25", "Bar 1.25x0.25"
};

const vector<double> beam::_beamList_t =
{
    0.580, 0.500, 0.380, 0.340, 0.300, 0.340, 0.340,
    0.500, 0.500, 0.250, 0.250
};

const vector<double> beam::_beamList_tf =
{
    8.00, 7.00, 6.00, 5.00, 4.00, 3.50, 2.50,
    0.00, 0.00, 0.00, 0.00
};

const vector<double> beam::_beamList_weight =
{
    16.548, 12.272, 8.294, 5.668, 3.476, 3.194, 2.142,
    1.176, 0.882, 0.441, 0.378
};

const vector<double> beam::_beamList_area =
{
    14.072, 10.436, 7.052, 4.820, 2.956, 2.716, 1.822,
    1.000, 0.750, 0.375, 0.313
};

const vector<double> beam::_beamList_I =
{
    319.52, 166.44, 74.80, 28.70, 7.82, 3.94, 1.092,
    0.333, 0.141, 0.070, 0.041
};

const vector<double> beam::_beamList_S =
{
    53.26, 33.28, 18.70, 9.56, 3.90, 2.62, 1.092,
    0.333, 0.188, 0.0933, 0.0656
};

void beam::spanCalc()
{
    double dx = sqrt( pow(armPoint.x - otherPoint.x, 2) );
    double dy = sqrt( pow(armPoint.y - otherPoint.y, 2) );
    span = sqrt( pow(dx + dy, 2) );
}

void beam::armCalc()
{
    arm = otherPoint.load * span / takeoffPoint.load;
    other = span - arm;
}

void beam::beamSelect()
{

}

