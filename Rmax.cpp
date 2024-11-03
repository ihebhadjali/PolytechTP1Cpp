#include "Rmax.h"
#include <iostream>
#include <strstream>

using namespace std;

namespace math
{
    Rmax::Rmax() : _val(epsilon()) {};
    Rmax::Rmax(double val) : _val(val) {};
    Rmax::Rmax(const Rmax& v) : _val(v._val) {};
    Rmax::~Rmax() {};
    double Rmax::getVal() const { return _val; };
    void Rmax::setVal(double v) { _val = v; };

    double Rmax::epsilon() {
        return std::numeric_limits<double>::lowest();
    };

    Rmax Rmax::operator+(const Rmax& r) const {
        return Rmax(std::max(_val, r._val));
    };
    
    Rmax Rmax::operator*(const Rmax& r) const {
        return Rmax(_val + r._val);
    };

    ostream& operator<<(ostream& flot, const Rmax& r)
    {
        if (r.getVal() == Rmax::epsilon())
            flot << "eps";
        else
            flot << r.getVal();
        return flot;
    };
}
