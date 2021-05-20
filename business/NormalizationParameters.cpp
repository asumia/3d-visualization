#include "NormalizationParameters.h"

void NormalizationParameters::SetParameters(float _min, float _max, float _DxStep, float _DyStep)
{
    Min = _min;
    Max = _max;
    DxStep = _DxStep;
    DyStep = _DyStep;
}
