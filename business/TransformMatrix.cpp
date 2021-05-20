#include "TransformMatrix.h"

Point3D TransformMatrix::TransformPoint(Point3D& point)
{
    Point3D p;
    p.X = point.X*_matr[0][0] + point.Y*_matr[0][1] + point.Z*_matr[0][2] + _matr[3][0];
    p.Y = point.X*_matr[1][0] + point.Y*_matr[1][1] + point.Z*_matr[1][2] + _matr[3][1];
    p.Z = point.X*_matr[2][0] + point.Y*_matr[2][1] + point.Z*_matr[2][2] + _matr[3][2];
    return p;
}

void TransformMatrix::SetMatrix(array<array<float, MTR_SIZE>, MTR_SIZE>& matr)
{
    _matr = matr;
}
