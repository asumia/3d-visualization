#include "FileReader.h"

Scene FileReader::ReadFigure(string &path, Scene& scene)
{
    vector<vector<string>> data = FileRead(path);
    scene.AddFigure(data);
    read_count++;
    return scene;
}

vector<vector<string>> FileReader::FileRead(string& path)
{
    vector<vector<string>> data;
    string line;
    ifstream f(path);
    while (getline(f, line))
    {
        vector<string> v = Split(line, ',');
        data.push_back(v);
    }
    return data;
}
