#ifndef ALGOSFIRSTPROJECT_HEAPSORT_H
#define ALGOSFIRSTPROJECT_HEAPSORT_H
#include <iostream>
#include <vector>


void heapify(std::vector<int> &v, int len, int i)
{
    int max=i;
    int L = 2*i + 1;
    int R = 2*i + 2;
    if(L <  len && v[L] > v[max])
        max = L;
    if(R < len && v[R] > v[max])
        max = R;
    if(max != i)
    {
        std::swap(v[i], v[max]);
        heapify(v, len, max);
    }
}

void heapsort(std::vector<int>& v)
{
    int len = v.size();
    for(int i = (len/2)-1; i>=0;i--)
        heapify(v, len, i);
    for(int i = len-1; i >= 0 ; i--)
    {
        std::swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}


#endif //ALGOSFIRSTPROJECT_HEAPSORT_H
