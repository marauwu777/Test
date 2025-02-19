#include <iostream>
#include <cmath>
#include <iomanip>
#include "Header.h"
using namespace std;
int main() {
	double pi = 3.1415926535;
	int size;

	while (true) {
		cout << "Enter the dimension of the vectors" << endl;
		cin >> size;

		if (size == 0) {
			break;
		}

		if (size < 0) {
			cout << "dimension error" << endl;
			continue;
		}

		double* vec1 = new double[size];
		double* vec2 = new double[size];
		int* vec3 = new int[size];
		int* vec4 = new int[size];
		cout << "Enter the elements of the first double vector" << endl;
		input_vector<double>(vec1, size);

		cout << "Enter the elements of the second double vector" << endl;
		input_vector<double>(vec2, size);
		cout << "The length of the first double vector - " << vector_length<double>(size, vec1) << endl;
		cout << "The length of the second double vector - " << vector_length<double>(size, vec2) << endl;
		double angle1 = vectorAngle<double>(size, vec1, vec2);
		cout << fixed << setprecision(6) << "The angle between the double vectors in radians and degrees " << endl << vectorAngle<double>(size, vec1, vec2) << ' ';
		cout << fixed << setprecision(6) <<  angle1 * 180 / pi << endl;
		delete[] vec1;
		delete[] vec2;
		cout << "Enter the elements of the first int vector" << endl;
		input_vector<int>(vec3, size);

		cout << "Enter the elements of the second int vector" << endl;
		input_vector<int>(vec4, size);
		cout << "The length of the first int vector - " << vector_length<int>(size, vec3) << endl;
		cout << "The length of the second int vector - " << vector_length<int>(size, vec4) << endl;
		double angle2 = vectorAngle<int>(size, vec3, vec4);
		cout << fixed << setprecision(6) << "The angle between the int vectors in radians and degrees " << endl << vectorAngle<int>(size, vec3, vec4) << ' ';
		cout << fixed << setprecision(6) <<  angle2 * 180 / pi << endl;
		delete[] vec3;
		delete[] vec4;
	}
}