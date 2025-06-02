#include <iostream>
#include "ShapeArea.h"

using namespace std;
using namespace AreaAlgorithm;

static unique_ptr<Shape> CreateShape(int choice) {
    switch (choice) {
    case 1: {
        double radius;
        cout << "请输入圆的半径: ";
        cin >> radius;
        return make_unique<Circle>(radius);
    }
    case 2: {
        double length, width;
        cout << "请输入矩形的长度: ";
        cin >> length;
        cout << "请输入矩形的宽度: ";
        cin >> width;
        return make_unique<Rectangle>(length, width);
    }
    /*case 3: {
        double base, height;
        cout << "请输入三角形的底边长度: ";
        cin >> base;
        cout << "请输入三角形的高度: ";
        cin >> height;
        return make_unique<Triangle>(base, height);
    }*/
    default:
        return nullptr;
    }
}

int main() {
	int choice;
	cout << "面积计算器" << endl;
	cout << "1. 计算圆的面积" << endl;
	cout << "2. 计算矩形的面积" << endl;

	cin >> choice;
	auto shape = CreateShape(choice);
    if (shape) {
        cout << shape->GetName() << "的面积为: " << shape->CalculateArea() << endl;
    }
    else {
        cout << "无效的选择!" << endl;
        return 1;
    }
	return 0;
}