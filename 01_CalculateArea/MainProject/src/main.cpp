#include <iostream>
#include "ShapeArea.h"

using namespace std;
using namespace AreaAlgorithm;

static unique_ptr<Shape> CreateShape(int choice) {
    switch (choice) {
    case 1: {
        double radius;
        cout << "������Բ�İ뾶: ";
        cin >> radius;
        return make_unique<Circle>(radius);
    }
    case 2: {
        double length, width;
        cout << "��������εĳ���: ";
        cin >> length;
        cout << "��������εĿ��: ";
        cin >> width;
        return make_unique<Rectangle>(length, width);
    }
    /*case 3: {
        double base, height;
        cout << "�����������εĵױ߳���: ";
        cin >> base;
        cout << "�����������εĸ߶�: ";
        cin >> height;
        return make_unique<Triangle>(base, height);
    }*/
    default:
        return nullptr;
    }
}

int main() {
	int choice;
	cout << "���������" << endl;
	cout << "1. ����Բ�����" << endl;
	cout << "2. ������ε����" << endl;

	cin >> choice;
	auto shape = CreateShape(choice);
    if (shape) {
        cout << shape->GetName() << "�����Ϊ: " << shape->CalculateArea() << endl;
    }
    else {
        cout << "��Ч��ѡ��!" << endl;
        return 1;
    }
	return 0;
}