#ifndef BASEFILEREADER_H
#define BASEFILEREADER_H

#include <business/Scene.h>
#include <business/NormalizationParameters.h>
#include <business/Auxiliary.h>

class BaseFileReader
{
public:
    virtual Scene ReadFigure (string& path, Scene& scene) = 0;
    virtual ~BaseFileReader() {};
};

#endif // BASEFILEREADER_H
