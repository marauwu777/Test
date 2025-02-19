#include <iostream>
#include <cmath>
#include <iomanip>
#include "Header.h"
using namespace std;
// функция ввода вектора
template<typename Type>
void input_vector(Type* vector, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the vector element" << endl;
        cin >> vector[i];
    }
}

// Функция для вычисления скалярного произведения
template<typename Type>
double scalar_product(Type* vec1, Type* vec2, int size) {
    double result = 0;
    for (int i = 0; i < size; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}
// функция вычисления длины вектора
template<typename Type>
double vector_length(int size, Type* vector) {
    return sqrt(scalar_product(vector, vector, size));
}
// функция вычисления угла между векторами
template<typename Type>
double vectorAngle(int size, Type* vector1, Type* vector2) {
    Type dotProd = scalar_product(vector1, vector2, size);

    double length1 = vector_length(size, vector1);
    double length2 = vector_length(size, vector2);

    // защита от деления на ноль
    if (length1 == 0.0 || length2 == 0.0) {
        cout << "Один из векторов имеет нулевую длину. Угол не может быть вычислен." << endl;
        return -1;
    }

    // Косинус угла между векторами
    double cosTheta = dotProd / (length1 * length2);
    if (cosTheta > 1.0) cosTheta = 1.0;
    if (cosTheta < -1.0) cosTheta = -1.0;

    return acos(cosTheta);
}

template void input_vector<int>(int*, int);
template void input_vector<double>(double*, int);
template int scalar_product<int>(int*, int*, int);
template double scalar_product<double>(double*, double*, int);
template double vector_length<int>(int, int*);
template double vector_length<double>(int, double*);
template double vectorAngle<int>(int, int*, int*);
template double vectorAngle<double>(int, double*, double*);