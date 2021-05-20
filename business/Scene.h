#ifndef SCENE_H
#define SCENE_H

#include <business/Figure.h>
#include <business/TransformMatrix.h>
#include <business/NormalizationParameters.h>
#include <business/FacadeOperationResult.h>

using namespace std;

class Scene
{
private:
    vector<Figure> _figures;
public:
    vector<Figure> GetFigures();
    void AddFigure(vector<vector<string>>& data);
    void SetPoints(size_t& index, Point3D& point);
    void TransfomFigures(TransformMatrix mtr, size_t number);
    void NormalizePoint(NormalizationParameters& param);
    int GetColumns(int count);
    int GetRows(int count);
    void SetPath(string& filepath, int count);
};

#endif // SCENE_H
