#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>
#include <fstream>

using namespace std;

class Point3D
{
public:
    float X;
    float Y;
    float Z;
    void SetPoint(float& _X, float& _Y, float& _Z);
    Point3D() {};
    Point3D(float& _X, float& _Y, float& _Z);
};

ostream& operator<<(ostream& os, const Point3D& point);

istream& operator>>(istream& is, Point3D& point);

#endif // POINT3D_H
