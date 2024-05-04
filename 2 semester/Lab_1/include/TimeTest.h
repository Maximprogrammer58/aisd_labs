#ifndef LAB_1_INCLUDE_TIMETEST_H
#define LAB_1_INCLUDE_TIMETEST_H

#include <algorithm>
#include <chrono>
#include "Random.h"

const size_t numOfAttempts = 100;

template<typename T>
double averageFillingTime(T generate_func, size_t lenght) {
    double totalTime = 0.0;

    for (int i = 0; i < numOfAttempts; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        generate_func(lenght);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }

    double averageTime = totalTime / numOfAttempts;
    return averageTime;
} 

double averageFindVector(const std::vector<size_t>& vec, size_t value) {
    double totalTime = 0.0;

    for (int i = 0; i < numOfAttempts; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        std::find(vec.begin(), vec.end(), value);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }

    double averageTime = totalTime / numOfAttempts;
    return averageTime;
}

double averageFindSet(const Set& set, size_t value) {
    double totalTime = 0.0;

    for (int i = 0; i < numOfAttempts; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        set.find(value);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }

    double averageTime = totalTime / numOfAttempts;
    return averageTime;
}

double averageInsertSet(Set& set, size_t value) {
    double totalTime = 0.0;

    for (int i = 0; i < numOfAttempts; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        set.insert(value);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }

    double averageTime = totalTime / numOfAttempts;
    return averageTime;
}

double averageEraseSet(Set& set, size_t value) {
    double totalTime = 0.0;

    for (int i = 0; i < numOfAttempts; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        set.erase(value);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }

    double averageTime = totalTime / numOfAttempts;
    return averageTime;
}

double averageInsertVector(std::vector<size_t>& vec, size_t index, size_t value) {
    double totalTime = 0.0;

    for (int i = 0; i < numOfAttempts; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        vec.insert(vec.begin() + index, value);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }

    double averageTime = totalTime / numOfAttempts;
    return averageTime;
}

double averageEraseVector(std::vector<size_t>& vec, size_t index) {
    double totalTime = 0.0;

    for (int i = 0; i < numOfAttempts; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        vec.erase(vec.begin() + index);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }

    double averageTime = totalTime / numOfAttempts;
    return averageTime;
}

#endif