#ifndef ALGOSFIRSTPROJECT_TIMEIT_H
#define ALGOSFIRSTPROJECT_TIMEIT_H
#include<iostream>
#include<vector>
#include<chrono>
#include <cassert>

//timeit for Mergesort and Heapsort testing sorted vector:
auto timeit(std::vector<int> &v , void what(std::vector<int> &v)) {


    auto begin = std::chrono::steady_clock::now();
    what(v);
    auto end = std::chrono::steady_clock::now();
    assert(std::is_sorted(v.begin(),v.end()));
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
return duration;
}

//timeit for Quicksort testing sorted vector:

auto timeit(std::vector<int> &v , void what(std::vector<int> &,int,int),int S,int E) {

    auto begin = std::chrono::steady_clock::now();
    what(v,S,E);
    auto end = std::chrono::steady_clock::now();
    assert(std::is_sorted(v.begin(),v.end()));
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    return duration;
}


//timeit for Mergesort and Heapsort testing shuffled vectors
auto timeit_shuffled(std::vector<int> v, void what(std::vector<int> &v)) {

    auto begin = std::chrono::steady_clock::now();
    what(v);
    auto end = std::chrono::steady_clock::now();
    assert(std::is_sorted(v.begin(),v.end()));
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    return duration;
}

//timeit for Quicksort testing shuffled vector:
auto timeit_shuffled(std::vector<int> v, void what(std::vector<int> &,int,int),int S,int E) {

    auto begin = std::chrono::steady_clock::now();
    what(v,S,E);
    auto end = std::chrono::steady_clock::now();
    assert(std::is_sorted(v.begin(),v.end()));
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    return duration;
}
#endif //ALGOSFIRSTPROJECT_TIMEIT_H
