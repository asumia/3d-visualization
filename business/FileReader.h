#ifndef FILEREADER_H
#define FILEREADER_H

#include <business/BaseFileReader.h>

class FileReader : public BaseFileReader
{
public:
    ~FileReader() override {};
    size_t read_count = 0;
    Scene ReadFigure(string& path, Scene& scene) override;
    vector<vector<string>> FileRead(string& path);
};

#endif // FILEREADER_H
