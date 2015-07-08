
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>

namespace work
{
    using std::string;
    using std::vector;
    using std::cout;
    using std::endl;
    using std::atof;

    class point
    {
        public:
        string name;
        double x, y, z;
        double load;
        double diameter;
    };

    class beam
    {
        public:
        static constexpr double E = 10000000;
        static constexpr double maxDeflection = 0.0025;
        static const int SF = 3;
        static const int maxTensileStress = 40000;
        static const int maxShearStress = 26000;
        static const int maxBearingStress = 56000;

        string name;
        string shape;
        double arm, span, other, armSpanRatio;
        double web, momentOfInertia, sectionModulus;
        double maxAllowShear, pctAllowShear, deflection;
        double armShear, otherShear;
        double maxBending, maxShear;
        double shearStress, bendingStress;
        point armPoint;
        point otherPoint;
        point takeoffPoint;

        void coordinatesCalc();
        void lengthsCalc();
        void beamSelect();

        private:
        static const vector<double> _beamList_t;
        static const vector<string> _beamList_shape;
        static const vector<double> _beamList_tf;
        static const vector<double> _beamList_weight;
        static const vector<double> _beamList_area;
        static const vector<double> _beamList_I;
        static const vector<double> _beamList_S;
        static const vector<double> _beamList_minHoleDia;
        static const vector<double> _beamList_maxHoleDia;
        static const vector<int> _beamList_maxBearingPlate;
        static const vector<double> _beamList_maxAllowShear;

    };
}
