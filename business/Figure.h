#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <fstream>

#include <business/Vertex.h>
#include <business/TransformMatrix.h>
#include <business/NormalizationParameters.h>

class Figure : public SceneObject
{
private:
    vector<Vertex> _vertices;
    vector<vector<string>> data;
public:
    vector<Vertex> GetVertices();
    void SetVertices(size_t& index, Point3D& point);
    void SetFigure(vector<vector<string>>& data);
    void Transform(TransformMatrix& mtr) override;
    void Normalize(NormalizationParameters& param);
    float GetMin();
    float GetMax();
    int GetDataCols();
    int GetDataRows();
    void operator=(const Figure figure);
};

#endif // FIGURE_H
