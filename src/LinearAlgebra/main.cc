#include <iostream>
#include "Vector.h"

int main()
{
	float arr1[] = {0,1,2};
	float arr2[] = {3,4,5};
	float arr3[] = {6,7,8};

	Vector vec1 = Vector(3, arr1);
	Vector vec2 = Vector(3, arr2);
	Vector vec3 = Vector(3, arr3);

	vec1.addScalar(1);
	vec2.multiplyScaler(2);
	vec3.divideScaler(3);

	vec1.PrintVector();
	vec2.PrintVector();
	vec3.PrintVector();

	std::cout << "did i work? " << std::endl;

	return 0;
}