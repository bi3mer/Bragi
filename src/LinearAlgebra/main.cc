#include <iostream>
#include "Vector.h"

int main()
{
	float arr1[] = {0,1,2};
	float arr2[] = {3,4,5};
	float arr3[] = {6,7,8};
	float arr4[] = {2,2,-2};

	Vector vec  = Vector(3);
	Vector vec1 = Vector(3, arr1);
	Vector vec2 = Vector(3, arr2);
	Vector vec3 = Vector(3, arr3);
	Vector vec4 = Vector(3, 1);
	Vector perp = Vector(3, arr4);
	Vector test = Vector(&perp);

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
	vec1.Subtract(&vec2, &vec);
	std::cout << "Subtraction of vector 1 and 2: " << std::endl;
	vec.PrintVector();

	// test perpindicular
	std::cout << "is perpindicular: " << vec1.IsPerpindicular(&perp) << std::endl;

	// test length
	vec1.PrintVector();
	std::cout << "length: " << vec1.Length() << std::endl;

	// convert to unit vector
	std::cout << "convert to unit vector before and after: " << std::endl;
	vec3.PrintVector();
	vec3.ConvertToUnitVector();
	vec3.PrintVector();

	// testing [] operator overloading
	vec3[1] = 2;
	vec3.PrintVector();
	std::cout << vec3[1] << " + " <<  vec4[1] << ": " << vec3[1] + vec4[1] << std::endl;

	// testing + operator overloading
	vec1.PrintVector();
	vec2.PrintVector();
	(vec1 + vec2).PrintVector();
	(vec1 - vec2).PrintVector();
	std::cout << (vec1 * vec2) << std::endl;

	std::cout << "did i work? " << std::endl;

	std::cout << "test: " << std::endl;

	return 0;
}