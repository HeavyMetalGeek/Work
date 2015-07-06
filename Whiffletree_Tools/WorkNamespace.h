
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

namespace work
{
    using std::string;
    using std::vector;
    using std::cout;
    using std::endl;

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
        static const int maxShearStrength = 26000;
        static const int maxBearingStrength = 56000;

        string name;
        double arm, span, other;
        double momentOfInertia;
        double shearStress;
        double bendingStress;
        point armPoint;
        point otherPoint;
        point takeoffPoint;

        void armCalc();
        void spanCalc();
        void beamSelect();

        private:
        static const vector<double> _beamList_t;
        static const vector<string> _beamList_shape;
        static const vector<double> _beamList_tf;
        static const vector<double> _beamList_weight;
        static const vector<double> _beamList_area;
        static const vector<double> _beamList_I;
        static const vector<double> _beamList_S;
    };
}
