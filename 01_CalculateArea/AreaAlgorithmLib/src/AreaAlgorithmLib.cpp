// AreaAlgorithmLib.cpp : 定义静态库的函数。
#include "ShapeArea.h"
#include <cmath>


#ifndef M_PI  
#define M_PI 3.14159265358979323846 // 定义 M_PI 如果未定义  
#endif

namespace AreaAlgorithm
{
	Rectangle::Rectangle(double width, double height): 
	width_(width),
	height_(height) {
	}

	double Rectangle::CalculateArea() const {
		return width_ * height_;
	}

	Circle::Circle(double radius) :
	radius_(radius) {
	}

	double Circle::CalculateArea() const {
		return M_PI * radius_ * radius_;
	}

}

