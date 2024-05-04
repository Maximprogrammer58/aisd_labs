#include "../include/polyline.h"
#include <cmath>

double angle_between_line(Point<double> p1, Point<double> p2, Point<double> res) {
	return ((p2.x-p1.x) * (res.x-p2.x) + (p2.y-p1.y) * (res.y-p2.y)) / (sqrt((pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2))*(pow((res.x - p2.x), 2) + pow((res.x - res.y), 2))));
}

Polyline<double> find_triangle(double lenght, double angle) {
	Polyline<double> triangle(3);

	Point<double> point1(0, 0);
	Point<double> point2;
	Point<double> point3;

	triangle += point1;

	bool flag = true;
	

	for (int x = 0; x < 100; ++x) {
		for (int y = 0; y < 100; ++y) {
			Point<double> res(x, y);
			if (point1.Distance(res) == lenght) {
				triangle += res;
				flag = false;
				break;
			}
		}
		if (flag == false) break;
	}

	flag = true;

	for (int x = 0; x < 100; ++x) {
		for (int y = 0; y < 100; ++y) {
			Point<double> res(x, y);
			if ((point2.Distance(res) == lenght) && (std::fabs(cos(angle) - angle_between_line(point1, point2, res)))) {
				triangle += res;
				flag = false;
				break;
			}
		}
		if (flag == false) break;
	}

	return triangle;
}

int main() {
	Polyline<int> polyline(7);
	
	Point<int> point1(50, 100);
	Point<int> point2(50, 50);
	Point<int> point3(100, 50);
	Point<int> point4(100, 100);
	Point<int> point5(100, 50);
	Point<int> point6(150, 50);
	Point<int> point7(150, 100);

	polyline += point2;
	polyline += point3;
	polyline += point4;
	polyline.PushBack(point5);
	polyline.PushBack(point6);
	polyline.PushBack(point7);
	polyline.PushFront(point1);

	std::cout << "Size: " << polyline.size() << std::endl;
	std::cout << polyline << std::endl;

	std::cout << find_triangle(5, 10 * 3.14 / 180);

	return 0;
}