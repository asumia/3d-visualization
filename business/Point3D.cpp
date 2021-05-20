#include <business/Point3D.h>

void Point3D::SetPoint(float& _X, float& _Y, float& _Z)
{
    X = _X;
    Y = _Y;
    Z = _Z;
}

Point3D::Point3D(float& _X, float& _Y, float& _Z)
{
    SetPoint(_X, _Y, _Z);
}

ostream& operator<<(ostream& os, const Point3D& point)
{
    os << point.X << ' ' << point.Y << ' ' << point.Z;
    return os;
}

istream& operator>>(istream& is, Point3D& point)
{
    is >> point.X >> point.Y >> point.Z;
    return is;
}
