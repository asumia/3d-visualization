#ifndef NORMALIZATIONPARAMETERS_H
#define NORMALIZATIONPARAMETERS_H


class NormalizationParameters
{
public:
    float Min;
    float Max;
    float DxStep;
    float DyStep;
    void SetParameters(float _min, float _max, float _DxStep, float _DyStep);
};

#endif // NORMALIZATIONPARAMETERS_H
