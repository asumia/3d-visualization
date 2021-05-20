#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <business/TransformMatrix.h>

class SceneObject
{
public:
    virtual void Transform(TransformMatrix& _mtr) = 0;
};

#endif // SCENEOBJECT_H
