#include <iostream>
#include <stddef.h>
#include "Vector.h"

/// --------------------Constructors --------------------
Vector::Vector(const int size)
{
	this->size = size;
}

Vector::Vector(const int size, float data[])
{
	this->size = size;
	this->vec = data;
}

// -------------------- Destructor --------------------
Vector::~Vector()
{
	// pass
}

// -------------------- Get and Set Methods --------------------
int Vector::GetSize()
{
	return this->size;
}

// TODO: try const int index and data
void Vector::SetVectorPoint(const int index, const float data)
{
	this->vec[index] = data;
}

float* Vector::GetVectorArray()
{
	return NULL;
}

/// -------------------- useful commands --------------------
void Vector::PrintVector()
{
	for(int i = 0; i < this->size; ++i)
	{
		std::cout << this->vec[i] << std::endl;
	}
}

/// -------------------- Scalar Calculations --------------------
// add a scalar number to the array representing a 
// vector in the class.
void Vector::addScalar(const float scalar)
{
	for(int i = 0; i < this->size; ++i)
	{
		this->vec[i] += scalar;
	}
}

// multiplies a scalar number to the array representing
// a vector in the class.
void Vector::multiplyScaler(const float scalar)
{
	for(int i = 0; i < this->size; ++i)
	{
		this->vec[i] *= scalar;
	}
}

// divides a scalar number to the array representing a
// vector in the class. Adiditonarlly, it checks to 
// make sure it doesn't divide by 0. Should this be the
// case an error is thrown.
void Vector::divideScaler(const float scalar)
{
	// avoid divide by 0 case
	if(scalar == 0)
	{
		throw std::overflow_error("Divide by zero exception");
	}

	for(int i = 0; i < this->size; ++i)
	{
		this->vec[i] /= scalar;
	}
}










