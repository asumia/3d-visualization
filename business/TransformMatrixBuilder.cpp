#include "TransformMatrixBuilder.h"

TransformMatrix TransformMatrixBuilder::CreateRotationMatrix(float& x, float& y, float& z)
{
    array<array<float, 4>, 4> mtx;

    if(x!=0)
    {
        mtx =
        { {
        {1, 0, 0, 0},
        {0, cosf(x), -sinf(x), 0},
        {0, sinf(x), cosf(x), 0},
        {0, 0, 0, 0}
        } };
    }
    else if(y!=0)
    {
        mtx =
        { {
        {cosf(y), 0, sinf(y), 0},
        {0, 1, 0, 0},
        {-sinf(y), 0, cosf(y), 0},
        {0, 0, 0, 0}
        } };
    }
    else if(z!=0)
    {
        mtx =
        { {
        {cosf(z), -sinf(z), 0, 0},
        {sinf(z), cosf(z), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
        } };
    }
    TransformMatrix _matrix;
    _matrix.SetMatrix(mtx);
    return  _matrix;
}

TransformMatrix TransformMatrixBuilder::CreateMoveMatrix(float x, float y, float z)
{
    array<array<float, 4>, 4> mtx =
    { {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {x, y, z, 1}
    } };

    TransformMatrix _matrix;
    _matrix.SetMatrix(mtx);
    return  _matrix;
}

TransformMatrix TransformMatrixBuilder::CreateScaleMatrix(float k)
{
    array<array<float, 4>, 4> mtx;
    if(k!=0)
    {
        mtx =
        { {
        {k, 0, 0, 0},
        {0, k, 0, 0},
        {0, 0, k, 0},
        {0, 0, 0, 0}
        } };
    }
    TransformMatrix _matrix;
    _matrix.SetMatrix(mtx);
    return  _matrix;
}
