#pragma once
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
#include <string>

namespace AreaAlgorithm {
	// 定义一个基类：平面图形
	class Shape {
	public:
		virtual double CalculateArea() const = 0; // 纯虚函数，计算面积
		virtual std::string GetName() const = 0;  // 纯虚函数，获取图形名称
		virtual ~Shape() {} // 虚析构函数
	};

	// 定义一个派生类：矩形
	class Rectangle : public Shape {
		double width_;
		double height_;
	public:
		Rectangle(double width, double height);
		double CalculateArea() const override;
		std::string GetName() const override { return "Rectangle"; }
	};

	// 定义一个派生类：圆形
	class Circle : public Shape {
		double radius_;
	public:
		Circle(double radius);
		double CalculateArea() const override;
		std::string GetName() const override { return "Circle"; }
	};

}  // namespace AreaAlgorithm
