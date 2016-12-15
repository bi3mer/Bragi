#include <iostream>
#include "Vector.h"

int main()
{
	float arr1[] = {0,1,2};
	float arr2[] = {3,4,5};
	float arr3[] = {6,7,8};

	Vector vec = Vector(3);
	Vector vec1 = Vector(3, arr1);
	Vector vec2 = Vector(3, arr2);
	Vector vec3 = Vector(3, arr3);
	Vector vec4 = Vector(3, 1);

	vec1.AddScalar(1);
	vec2.MultiplyScaler(2);
	vec3.DivideScaler(3);

	vec1.PrintVector();
	vec2.PrintVector();
	vec3.PrintVector();
	vec4.PrintVector();

	std::cout << "Dot Product of vector 1 and 2: " << vec1.Dot(&vec2) << std::endl;

	// test addition
	vec1.Add(&vec2, &vec);
	std::cout << "Addition of vector 1 and 2: " << std::endl;
	vec.PrintVector();

	// test subtraction
	vec1.Sub(&vec2, &vec);
	std::cout << "Subtraction of vector 1 and 2: " << std::endl;
	vec.PrintVector();


	std::cout << "did i work? " << std::endl;

	return 0;
}