#include "QtSceneDrawer.h"

void QtSceneDrawer::DrawVerticalLines(QGraphicsScene* scene, vector<Vertex> vertices, int &cols, int &rows, int& shift, QPen penForLine)
{
    for (int i = 0; i < cols; i++)
        for (int j = 0; j < rows - 1; j++)
            scene->addLine(vertices[i*cols+j].GetPosition().X+shift,
                    vertices[i*cols+j].GetPosition().Y, vertices[i*cols+j+1].GetPosition().X+shift,
                    vertices[i*cols+j+1].GetPosition().Y, penForLine);
}

void QtSceneDrawer::DrawHorizontalLines(QGraphicsScene *scene, vector<Vertex> vertices, int &cols, int &rows, int &shift, QPen penForLine)
{
    for(int i=0; i < cols -1 ;i++)
        for(int j=0; j < rows;j++)
            scene->addLine(vertices[i*cols+j].GetPosition().X+shift,
                    vertices[i*cols+j].GetPosition().Y, vertices[i*cols+j+rows].GetPosition().X+shift,
                    vertices[i*cols+j+rows].GetPosition().Y, penForLine);
}

void QtSceneDrawer::DrawVertices(QGraphicsScene *scene, vector<Vertex> vertices, int &cols, int &rows, int &shift, QPen penForPoint)
{
    for (int i = 0; i < cols; i++)
        for (int j = 0; j < rows; j++)
            scene->addLine(vertices[i*cols+j].GetPosition().X+shift,
                    vertices[i*cols+j].GetPosition().Y, vertices[i*cols+j].GetPosition().X+shift,
                    vertices[i*cols+j].GetPosition().Y, penForPoint);
}

void QtSceneDrawer::DrawScene(Scene& _scene, QGraphicsView* graph, int& model_count)
{
    int cols;
    int rows;
    QPen penForLine(Qt::black, 2);
    QPen penForPoint(Qt::black, 3);
    QGraphicsScene* scene = new QGraphicsScene();
    scene->clear();
    scene->setSceneRect(0, 0, 600, 600);
    graph->setScene(scene);
    int shift;
    for (int k = 0; k < model_count; k++)
    {
        shift = k*400 - 200;
        cols = _scene.GetColumns(k);
        rows = _scene.GetRows(k);
        vector<Vertex> vertices = _scene.GetFigures()[k].GetVertices();
        DrawHorizontalLines(scene, vertices, cols, rows, shift, penForLine);
        DrawVerticalLines(scene, vertices, cols, rows, shift, penForLine);
        DrawVertices(scene, vertices, cols, rows, shift, penForPoint);
    }
}
