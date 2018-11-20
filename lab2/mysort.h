//
// Created by arch0n on 18-11-16.
//

#ifndef LAB2_MYSORT_H
#define LAB2_MYSORT_H

#include "arOptions.h"

namespace merge{
    void merge(std::vector<int> &a, std::vector<int> &aux, size_t lo, size_t mid, size_t hi, bool(*cmp)(const int&, const int&)) {
        for(auto k = lo; k <= hi; k++)
            aux[k] = a[k];
        auto i = lo, j = mid+1;
        for (auto k = lo; k <= hi; k++) {
            if      (i > mid)                a[k] = aux[j++];
            else if (j > hi)                 a[k] = aux[i++];
            else if (cmp(aux[j], aux[i]))    a[k] = aux[j++];
            else                             a[k] = aux[i++];
        }
    }

    void mergeSortBase(std::vector<int> &a, std::vector<int> &aux, size_t lo, size_t hi, bool(*cmp)(const int&, const int&)) {
        if (hi <= lo) return;
        auto mid = lo + (hi - lo) / 2;
        mergeSortBase(a, aux, lo, mid, cmp);
        mergeSortBase(a, aux, mid + 1, hi, cmp);
        merge::merge(a, aux, lo, mid, hi, cmp);
    }

    void sort(std::vector<int> &a, bool(*cmp)(const int&, const int&) = [](const int& lhs, const int& rhs){ return lhs < rhs;}){
        size_t n = a.size();
        std::vector<int> aux(n);
        mergeSortBase(a, aux, 0, n-1, cmp);
    }
}

namespace mergeBU{
    void sort(std::vector<int> &a, bool(*cmp)(const int&, const int&) = [](const int& lhs, const int& rhs){ return lhs < rhs;}) {
        size_t n = a.size();
        std::vector<int> aux(n);
        for (size_t len = 1; len < n; len *= 2) {
            for (size_t lo = 0; lo < n-len; lo += len+len) {
                size_t mid  = lo + len - 1;
                size_t hi = std::min(lo + len + len - 1, n-1);
                merge::merge(a, aux, lo, mid, hi, cmp);
            }
        }
    }
}

namespace quick{
    int partition(std::vector<int> &a, int lo, int hi, bool (*cmp)(const int&, const int&)) {
        auto i = lo;
        auto j = hi + 1;
        int v = a[lo];
        while (true) {
            while (cmp(a[++i], v)) {
                if (i == hi) break;
            }
            while (cmp(v, a[--j])) {
                if (j == lo) break;
            }
            if (i >= j) break;
            std::swap(a[i], a[j]);
        }
        std::swap(a[lo], a[j]);
        return j;
    }

    void quicksortBase(std::vector<int> &a, int lo, int hi, bool(*cmp)(const int&, const int&)) {
        if (hi <= lo) return;
        auto j = quick::partition(a, lo, hi, cmp);
        //std::cerr << j <<std::endl;
        quick::quicksortBase(a, lo, j-1, cmp);
        quick::quicksortBase(a, j+1, hi, cmp);
    }

    void sort(std::vector<int> &a, bool(*cmp)(const int&, const int&) = [](const int& lhs, const int& rhs){ return lhs < rhs;}){
        quicksortBase(a, 0, static_cast<int>(a.size()) - 1, cmp);
    }
}


namespace quick3way{
    void quick3wayBase(std::vector<int> &a, int lo, int hi, bool(*cmp)(const int&, const int&)) {
        if (hi <= lo) return;
        auto lt = lo, gt = hi;
        auto v = a[lo];
        auto i = lo + 1;
        while (i <= gt) {
            if(a[i] == v) i++;
            else if (cmp(a[i], v)) std::swap(a[lt++], a[i++]);
            else std::swap(a[i], a[gt--]);
        }
        quick3wayBase(a, lo, lt-1, cmp);
        quick3wayBase(a, gt+1, hi, cmp);
    }

    void sort(std::vector<int> &a, bool(*cmp)(const int&, const int&) = [](const int& lhs, const int& rhs){ return lhs < rhs;}){
        quick3way::quick3wayBase(a, 0, static_cast<int>(a.size()) - 1, cmp);
    }
}

namespace bubble{
    void sort(std::vector<int> &a, bool(*cmp)(const int&, const int&) = [](const int& lhs, const int& rhs){ return lhs < rhs;}){
        auto len = a.size() - 1;
        for(size_t i = 0; i < len; i++) {
            for(size_t j = 0; j < len - i; j++){
                if(cmp(a[j+1], a[j]))
                    std::swap(a[j], a[j+1]);
            }
        }
    }
}

namespace insertion{
    void sort(std::vector<int> &a, bool(*cmp)(const int&, const int&) = [](const int& lhs, const int& rhs){ return lhs < rhs;}){
        int n = static_cast<int>(a.size());
        for (int i = 0; i < n; i++) {
            for (int j = i; j > 0 && cmp(a[j], a[j-1]); j--) {
                std::swap(a[j], a[j-1]);
            }
        }
    }
}

namespace std_stable{
    void sort(std::vector<int> &a, bool(*cmp)(const int&, const int&) = [](const int& lhs, const int& rhs){ return lhs < rhs;}){
        std::stable_sort(a.begin(), a.end(), cmp);
    }
}

namespace std_sort{
    void sort(std::vector<int> &a, bool(*cmp)(const int&, const int&) = [](const int& lhs, const int& rhs){ return lhs < rhs;}){
        std::sort(a.begin(), a.end(), cmp);
    }
}

#endif //LAB2_MYSORT_H
