#ifndef ALGOSFIRSTPROJECT_QUICKSORT_H
#define ALGOSFIRSTPROJECT_QUICKSORT_H
#include<iostream>
#include<vector>


int partition(std::vector<int>& v, int start, int end) {
    int pivot = v[end];
    int i = start-1;
    for(int j=start;j<end;j++)
    {
        if (v[j]<pivot)
        {
            i++;
            std::swap(v[i],v[j]);
        }
    }
    std::swap(v[i+1],v[end]);
    return i+1;
}

void quicksort(std::vector<int>& v, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(v, start, end);
        quicksort(v, start, pivot - 1);
        quicksort(v, pivot+1,end);
    }
}

#endif //ALGOSFIRSTPROJECT_QUICKSORT_H
