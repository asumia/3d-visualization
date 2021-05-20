#include "Figure.h"

vector<Vertex> Figure::GetVertices()
{
    return _vertices;
}

void Figure::SetVertices(size_t &index, Point3D& point)
{
    _vertices[index].SetPosition(point.X, point.Y, point.Z);
}

void Figure::Transform(TransformMatrix& mtr)
{
    for(size_t i = 0; i < _vertices.size(); ++i)
        _vertices[i].Transform(mtr);
}

void Figure::SetFigure(vector<vector<string>> &data)
{
    Vertex _vertex;
    this->data = data;
    for(size_t i = 0; i < data.size(); i++)
        for(size_t j = 0; j < data.size(); j++)
        {
            _vertex.SetPosition(j, stof(data[i][j]), i);
            _vertices.push_back(_vertex);
        }
}

void Figure::Normalize(NormalizationParameters& param)
{
    float min = this->GetMin();
    float max = this->GetMax();
    int t = 0;
     for(size_t i = 0; i < data.size(); i++)
        for(size_t j = 0; j < data[i].size(); j++)
        {
            _vertices[t].SetPosition(j*param.DxStep, i*param.DyStep,
                                     param.Min + (stof(data[i][j]) - min) * (param.Max-param.Min) / (max-min));
            t++;
        }
}

float Figure::GetMin()
{
    float min = stof(data[0][0]);
    for(size_t i = 0; i < data.size(); i++)
        for(size_t j = 0; j < data[i].size(); j++)
            if(stof(data[i][j]) < min)
                min = stof(data[i][j]);
    return min;
}

float Figure::GetMax()
{
    float max = stof(data[0][0]);
    for(size_t i = 0; i < data.size(); i++)
        for(size_t j = 0; j < data[i].size(); j++)
            if(stof(data[i][j]) > max)
                max = stof(data[i][j]);
    return max;
}

int Figure::GetDataCols()
{
    return this->data.size();
}

int Figure::GetDataRows()
{
    return this->data[0].size();
}

void Figure::operator=(const Figure figure)
{
    this->_vertices = figure._vertices;
    this->data = figure.data;
}
