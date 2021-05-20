#include "Facade.h"

FacadeOperationResult Facade::DrawScene(QGraphicsView *graph, int& model_count)
{
    FacadeOperationResult result;
    if (_previous_scene_loaded)
        _previous_scene_loaded = 0;
    _sceneDrawer->DrawScene(_scene, graph, model_count);
    return result;
}


void Facade::SaveSettings()
{
    fstream user_settings;
    user_settings.open(_settings_path, fstream::out);
    user_settings << filepaths[0] << '\n';
    int cols = _scene.GetColumns(0);
    int rows = _scene.GetRows(0);
    for (int i = 0; i < rows * cols; i++)
        user_settings << _scene.GetFigures()[0].GetVertices()[i].GetPosition() << '\n';
    user_settings.close();
}


void Facade::EditSettings()
{
    fstream user_settings;
    user_settings.open(_settings_path, fstream::in);
    string prev_path;
    user_settings >> prev_path;
    if (prev_path == filepaths[0] && user_settings.is_open())
    {
        int cols = _scene.GetRows(0);
        int rows = _scene.GetColumns(0);
        Point3D point;
        for (size_t i = 0; i < rows * cols; i++)
        {
            user_settings >> point;
            _scene.SetPoints(i, point);
        }
        _previous_scene_loaded = 1;
    }
        user_settings.close();
}

bool Facade::previous_scene_loaded()
{
    return _previous_scene_loaded;
}

FacadeOperationResult Facade::LoadScene(string &path)
{
    FacadeOperationResult result;
    bool check = 1;
    if (filepaths.size() != 0)
        for (size_t i = 0; i < filepaths.size(); ++i)
            if (path == filepaths[i])
                check = 0;
    if (check)
    {
        _scene = _fileReader->ReadFigure(path, _scene);
        filepaths.push_back(path);
        _scene_loaded = true;
    }
    else
    {
        result.SetBoolValue(false);
        result.SetErrorMessage("Данный файл уже выбран!");
    }
    return result;
}

FacadeOperationResult Facade::RotateScene(float x, float y, float z, size_t number)
{
    FacadeOperationResult result;
    try
    {
        _scene.TransfomFigures(TransformMatrixBuilder::CreateRotationMatrix(x, y, z), number);
    }
    catch (myException& err)
    {
        result.SetBoolValue(false);
        result.SetErrorMessage(err.what());
    }
    return result;
}

FacadeOperationResult Facade::MoveScene(float x, float y, float z, size_t number)
{
    FacadeOperationResult result;
    try
    {
        _scene.TransfomFigures(TransformMatrixBuilder::CreateMoveMatrix(x, y, z), number);

    }
    catch(myException& err)
    {
        result.SetBoolValue(false);
        result.SetErrorMessage(err.what());
    }
    return result;
}

FacadeOperationResult Facade::ScaleScene(float koef, size_t number)
{
    FacadeOperationResult result;
    try
    {
        _scene.TransfomFigures(TransformMatrixBuilder::CreateScaleMatrix(koef), number);
    }
    catch (myException& err)
    {
        result.SetBoolValue(false);
        result.SetErrorMessage(err.what());
    }
    return result;
}

bool Facade::is_empty()
{
    return _scene_loaded == false;
}

Scene Facade::GetScene()
{
    return _scene;
}

void Facade::Normalize(NormalizationParameters& param)
{
    _scene.NormalizePoint(param);
}
