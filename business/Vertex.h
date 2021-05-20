#ifndef VERTEX_H
#define VERTEX_H
#include <business/Point3D.h>
#include <business/SceneObject.h>

class Vertex : public SceneObject
{
private:
    Point3D _position;
public:
    void SetPosition(float X, float Y, float Z);
    Point3D GetPosition();
    void Transform(TransformMatrix& _mtr) override;
};

#endif // VERTEX_H
