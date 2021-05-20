#ifndef FACADE_H
#define FACADE_H

#include "business/FacadeOperationResult.h"
#include "business/TransformMatrixBuilder.h"
#include "business/QtSceneDrawer.h"
#include "business/Point3D.h"
#include "business/Scene.h"
#include "FileReader.h"

class Facade
{
private:
    string _settings_path = "D:/OOP_4/oop_4/usersettings.TXT";
    Scene _scene;
    BaseFileReader* _fileReader;
    SceneDrawerBase* _sceneDrawer;
    vector<string> filepaths;
    bool _scene_loaded = 0;
    bool _previous_scene_loaded = 0;
public:
    Facade()
    {
        _fileReader = new FileReader;
        _sceneDrawer = new QtSceneDrawer;
    }
    ~Facade()
    {
        if (!this->is_empty())
            SaveSettings();
        delete _fileReader;
        delete _sceneDrawer;
    }
    void SaveSettings();
    void EditSettings();
    bool previous_scene_loaded();
    FacadeOperationResult DrawScene(QGraphicsView* graph, int& model_count);
    FacadeOperationResult LoadScene(string& path);
    FacadeOperationResult RotateScene(float x, float y, float z, size_t number);
    FacadeOperationResult MoveScene(float x, float y, float z, size_t number);
    FacadeOperationResult ScaleScene(float koef, size_t number);
    bool is_empty();
    Scene GetScene();
    void Normalize(NormalizationParameters& param);
};

#endif // FACADE_H
