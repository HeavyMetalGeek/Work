
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

namespace work
{
    using std::string;
    using std::vector;
    using std::cout, std::endl;

    class point
    {
        public:
        string name;
        double x, y, z;
        double load;
        double diameter;
        double bearingStress;

        void bearingStress(double, double);
    }

    class beam
    {
        public:
        static constexpr double E = 10000000;
        static constexpr double maxDeflection = 0.0025;

        string name;
        double arm, span, other;
        double momentOfInertia;
        double shearStress;
        double bendingStress;
        point armPoint;
        point otherPoint;
        point takeoffPoint;

        void armCalc(point, point);
        void spanCalc(point, point);
        //double shearCalc();
        void beamSelect();
    }
}

