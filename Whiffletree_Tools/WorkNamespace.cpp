#include "WorkNamespace.h"

using namespace work;

const vector<string> beam::_beamList_shape =
{
    "Bar 1.25x0.25", "Bar 1.50x0.25", "Bar 1.50x0.50", "Bar 2.00x0.50",
    "][ Chan 2", "][ Chan 3", "][ Chan 4", "][ Chan 6", "][ Chan 8", "][ Chan 10", "][ Chan 12"
};

const vector<double> beam::_beamList_t =
{
    0.250, 0.250, 0.500, 0.500,
    0.340, 0.340, 0.300, 0.340, 0.380, 0.500, 0.580
};

const vector<double> beam::_beamList_tf =
{

    0.00, 0.00, 0.00, 0.00,
    2.50, 3.50, 4.00, 5.00, 6.00, 7.00, 8.00
};

const vector<double> beam::_beamList_weight =
{
    0.378, 0.441, 0.882, 1.176,
    2.142, 3.194, 3.476, 5.668, 8.294, 12.272, 16.548
};

const vector<double> beam::_beamList_area =
{
    0.313, 0.375, 0.750, 1.000,
    1.822, 2.716, 2.956, 4.820, 7.052, 10.436, 14.072
};

const vector<double> beam::_beamList_I =
{

    0.041, 0.070, 0.141, 0.333,
    1.092, 3.94, 7.82, 28.70, 74.80, 166.44, 319.52
};

const vector<double> beam::_beamList_S =
{

    0.0656, 0.0933,  0.188, 0.333,
    1.092, 2.62, 3.90, 9.56, 18.70, 33.28, 53.26
};

const vector<double> beam::_beamList_minHoleDia =
{
    0.250, 0.250, 0.250, 0.250,
    0.250, 0.250, 0.375, 0.375, 0.375, 0.500, 0.500
};

const vector<double> beam::_beamList_maxHoleDia =
{
    0.50, 0.50, 0.50, 0.50,
    0.50, 0.50, 0.75, 0.75, 1.00, 1.00, 1.00
};

const vector<int> beam::_beamList_maxBearingPlate =
{

    0, 0, 0, 0,
    4, 4, 2, 4, 4, 6, 6
};

const vector<double> beam::_beamList_maxAllowShear =
{
    1399, 1659, 3342, 4440,
    6311, 9791, 11436, 19217, 28414, 44802, 61515
};

void beam::coordinatesCalc()
{
    // Calculations based on arm and other coordinates and loads
    takeoffPoint.load = armPoint.load + otherPoint.load;
    takeoffPoint.x = (armPoint.load * armPoint.x + otherPoint.load * otherPoint.x)
                        / takeoffPoint.load;
    takeoffPoint.y = (armPoint.load * armPoint.y + otherPoint.load * otherPoint.y)
                        / takeoffPoint.load;

    double dx = sqrt( pow(armPoint.x - otherPoint.x, 2) );
    double dy = sqrt( pow(armPoint.y - otherPoint.y, 2) );
    span = sqrt( pow(dx + dy, 2) );
    arm = otherPoint.load * span / takeoffPoint.load;
    other = span - arm;
    armSpanRatio = arm / span;
}

void beam::lengthsCalc()
{
    // Calculations based on arm and span lengths and loads
    takeoffPoint.load = armPoint.load + otherPoint.load;
    arm = otherPoint.load * span / takeoffPoint.load;
    other = span - arm;
    armSpanRatio = arm / span;
}

void beam::beamSelect()
{
    // Calculate maximum bending moment along beam
    maxBending = takeoffPoint.load * other * arm / span;
    // Calculate maximum shear along beam
    if (arm > other) {maxShear = takeoffPoint.load * arm / span;}
    else {maxShear = takeoffPoint.load * other / span;}
    // Calculate minimum section modulus
    double minSectionModulus = maxBending / (maxTensileStress / SF);
    // Calculate minimum moment of inertia
    double minMomentOfInertia = takeoffPoint.load
                        * pow(arm, 2)
                        * pow(other, 2)
                        / ( 3 * pow(span, 2) * E * maxDeflection);
    for (int i = 0; i < int( _beamList_shape.size() ); i++)
    {
        int check = 0;
        if (_beamList_S[i] >= minSectionModulus) {check++;}
        if (_beamList_I[i] >= minMomentOfInertia) {check++;}
        if (_beamList_maxAllowShear[i] >= maxShear) {check++;}

        if (check == 3)
        {
            shape = _beamList_shape[i];
            web = _beamList_t[i];
            momentOfInertia = _beamList_I[i];
            sectionModulus = _beamList_S[i];
            maxAllowShear = _beamList_maxAllowShear[i];
            break;
        }
        else if (i == int(_beamList_shape.size()))
        {
            cout << "Appropriate beam not found.  Calculation failed." << endl;
            return;
        }
    }

    pctAllowShear = maxShear / maxAllowShear * 100;
    deflection = minMomentOfInertia * maxDeflection / (momentOfInertia * span);
}
