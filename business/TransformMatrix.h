#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H

#define MTR_SIZE 4

#include <business/Point3D.h>
#include <array>
using namespace  std;

class TransformMatrix
{
private:
    array<array<float, MTR_SIZE>, MTR_SIZE> _matr;
public:
    Point3D TransformPoint(Point3D& point);
    void SetMatrix(array<array<float, MTR_SIZE>, MTR_SIZE>& matr);
};

#endif // TRANSFORMMATRIX_H
