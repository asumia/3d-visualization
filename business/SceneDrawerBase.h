#ifndef SCENEDRAWERBASE_H
#define SCENEDRAWERBASE_H

#include <business/Scene.h>
#include <QGraphicsScene>
#include <QGraphicsView>

#define I_COUNT 20
#define J_COUNT 20

class SceneDrawerBase
{
protected:
    virtual void DrawVerticalLines(QGraphicsScene* scene, vector<Vertex> vertices, int &cols, int &rows, int& shift, QPen penForLine) = 0;
    virtual void DrawHorizontalLines(QGraphicsScene* scene, vector<Vertex> vertices, int &cols, int &rows, int& shift, QPen penForLine) = 0;
    virtual void DrawVertices(QGraphicsScene* scene, vector<Vertex> vertices, int &cols, int &rows, int& shift, QPen penForPoint) = 0;
public:
    virtual void DrawScene(Scene& _scene, QGraphicsView* graph, int& model_count) = 0;
    virtual ~SceneDrawerBase(){};
};

#endif // SCENEDRAWERBASE_H
