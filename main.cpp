#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>
#include "Quicksort.h"
#include "Mergesort.h"
#include "Heapsort.h"
#include "VectorsDataGen.h"
#include "Timeit.h"



constexpr int step = 100;
constexpr int maxlen = 10000;
constexpr int times = 100;



int main() {


    std::random_device rd;
    std::mt19937 gen(rd());

    std::ofstream out("results.txt");
    out << "Elements,Quicksort_sorted,Mergesort_sorted,Heapsort_sorted,Quicksort,Mergesort,Heapsort"<<std::endl;



    for (int len = step; len < maxlen; len += step) {


            std::chrono::nanoseconds qu_sort(0);
            std::chrono::nanoseconds me_sort(0);
            std::chrono::nanoseconds he_sort(0);
            std::chrono::nanoseconds qu_sort_sorted(0);
            std::chrono::nanoseconds me_sort_sorted(0);
            std::chrono::nanoseconds he_sort_sorted(0);



            std::vector<int> Original;
            std::vector<int> Copy;

            FillVec(Original, len);
            Copy=Original;
            ShuffleVec(Copy,gen);



            for(int i = 0; i < times; i++) {

                qu_sort_sorted += timeit(Original,&quicksort,0,len-1);
                me_sort_sorted += timeit(Original,&mergesort);
                he_sort_sorted += timeit(Original,&heapsort);


                qu_sort += timeit_shuffled(Copy,&quicksort,0,len-1);
                me_sort += timeit_shuffled(Copy,&mergesort);
                he_sort += timeit_shuffled(Copy,&heapsort);

            }

        out << len << "," << qu_sort_sorted.count()/times << "," <<  me_sort_sorted.count()/times << "," <<he_sort_sorted.count()/times
            << "," << qu_sort.count()/times << "," << me_sort.count()/times << "," << he_sort.count()/times << std::endl;


        }
    out.close();
}