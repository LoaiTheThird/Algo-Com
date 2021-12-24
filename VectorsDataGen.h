#ifndef ALGOSFIRSTPROJECT_VECTORSDATAGEN_H
#define ALGOSFIRSTPROJECT_VECTORSDATAGEN_H
#include <vector>
#include <iostream>
#include <random>

//pretty useless headerfile but I still decided to keep it because why not ( it used to be more complicated)

void FillVec(std::vector<int> &v, int len)
{
    for(int i=0; i<len;i++)
    {
        v.push_back(i);
    }
}
void ShuffleVec(std::vector<int> &v,std::mt19937 &generator)
{
    std::shuffle(begin(v), end(v), generator);
}
#endif //ALGOSFIRSTPROJECT_VECTORSDATAGEN_H
