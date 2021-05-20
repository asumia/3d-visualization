#include "Scene.h"

vector<Figure> Scene::GetFigures()
{
    return _figures;
}

void Scene::AddFigure(vector<vector<string>>& data)
{
    Figure figure;
    figure.SetFigure(data);
    _figures.push_back(figure);
}

void Scene::SetPoints(size_t &index, Point3D& point)
{
    _figures[0].SetVertices(index, point);
}

void Scene::TransfomFigures(TransformMatrix mtr, size_t number)
{
    if(_figures.empty())
        throw myException("Модель не была загружена!");
    _figures[number-1].Transform(mtr);
}

void Scene::NormalizePoint(NormalizationParameters &param)
{
    for(size_t i = 0; i < _figures.size(); i++)
        _figures[i].Normalize(param);
}

int Scene::GetColumns(int count)
{
    return _figures[count].GetDataCols();
}

int Scene::GetRows(int count)
{
    return _figures[count].GetDataRows();
}
