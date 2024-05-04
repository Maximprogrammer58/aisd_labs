#ifndef LAB_1_INCLUDE_RANDOM_H
#define LAB_1_INCLUDE_RANDOM_H

#include <vector>
#include "Set.h"

size_t lcg();

Set generateRandomSet(size_t lenght);

std::vector<size_t> generateRandomVector(size_t lenght);

#endif