#include "Vertex.h"

void Vertex::SetPosition(float X, float Y, float Z)
{
    _position.SetPoint(X, Y, Z);
}

Point3D Vertex::GetPosition()
{
    return _position;
}

void Vertex::Transform(TransformMatrix& _mtr)
{
    _position = _mtr.TransformPoint(_position);
}
