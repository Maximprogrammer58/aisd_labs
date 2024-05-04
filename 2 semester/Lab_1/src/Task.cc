#include "../include/Task.h"

Set Union(Set& set_a, Set& set_b) {
	Set set;
	for (auto el1 : set_a) 
		set.insert(el1);
	for (auto el2 : set_b) 
		set.insert(el2);
	return set;
}

Set symmetricDifference(Set& set_a, Set& set_b) {
	Set difference1 = Difference(set_a, set_b);
	Set difference2 = Difference(set_b, set_a);
	return Union(difference1, difference2);
}

Set Difference(Set& set_a, Set& set_b) {
	Set set = set_a;
	for (auto el : set_b)
		set.erase(el);
	return set;
}
