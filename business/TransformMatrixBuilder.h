#ifndef TRANSFORMMATRIXBUILDER_H
#define TRANSFORMMATRIXBUILDER_H

#include <math.h>
#include <business/TransformMatrix.h>


class TransformMatrixBuilder
{
public:
    static TransformMatrix CreateRotationMatrix(float& x, float& y, float& z);
    static TransformMatrix CreateMoveMatrix(float x, float y, float z);
    static TransformMatrix CreateScaleMatrix(float k);
};

#endif // TRANSFORMMATRIXBUILDER_H
