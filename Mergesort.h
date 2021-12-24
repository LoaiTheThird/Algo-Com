#ifndef ALGOSFIRSTPROJECT_MERGESORT_H
#define ALGOSFIRSTPROJECT_MERGESORT_H
#include <vector>
#include <iostream>

void merge(std::vector<int> &L,std::vector<int> &R,std::vector<int> &O)
{
    int lenL = L.size();
    int lenR = R.size();
    //index of L:
    int l=0;
    //index of R:
    int r=0;
    //index of O:
    int o=0;
    while(l<lenL && r<lenR)
    {
        if(L[l]<=R[r])
        {
            O[o] = L[l];
            l++;
        }
        else
        {
            O[o]=R[r];
            r++;
        }
        o++;
    }
    while(l<lenL)
    {
        O[o]=L[l];
        l++;
        o++;
    }
    while(r<lenR)
    {
        O[o]=R[r];
        r++;
        o++;
    }
}

void mergesort(std::vector<int> &O)
{
    int lenO = O.size();
    if(lenO<2)
        return;
    int mid = lenO/2;
    std::vector<int> L(mid);
    std::vector<int> R(O.size()-mid);
    for(int l=0;l<mid;l++)
    {
        L[l]=O[l];
    }
    for(int r=mid;r<lenO;r++)
    {
        R[r-mid]=O[r];
    }
    mergesort(L);
    mergesort(R);
    merge(L,R,O);
}

#endif //ALGOSFIRSTPROJECT_MERGESORT_H
