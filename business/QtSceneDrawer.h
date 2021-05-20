#ifndef QTSCENEDRAWER_H
#define QTSCENEDRAWER_H

#include <business/SceneDrawerBase.h>

class QtSceneDrawer : public SceneDrawerBase
{
protected:
    void DrawVerticalLines(QGraphicsScene* scene, vector<Vertex> vertices, int &cols, int &rows, int& shift, QPen penForLine) override;
    void DrawHorizontalLines(QGraphicsScene* scene, vector<Vertex> vertices, int &cols, int &rows, int& shift, QPen penForLine) override;
    void DrawVertices(QGraphicsScene* scene, vector<Vertex> vertices, int &cols, int &rows, int& shift, QPen penForPoint) override;
public:
    ~QtSceneDrawer() override {};
    void DrawScene(Scene& _scene, QGraphicsView* graph, int& model_count) override;
};

#endif // QTSCENEDRAWER_H
