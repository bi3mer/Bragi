#include <iostream>
#include <stddef.h>
#include "Vector.h"

/// --------------------Constructors --------------------
// Create vector of size x with values y
Vector::Vector(const int size, const float val)
{
	this->size = size;

	// initialize array and set all values to val
	this->vec = new float[size];
	for(int i = 0; i < size; ++i)
	{
		this->vec[i] = val;
	}
}

// Create vector with size y that will be the same size
// as the array passed in. No checking is done to account
// for ensuring this, so if a mistake is made it is on the
// user's end. 
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
	return this->vec;
}

/// -------------------- useful commands --------------------
void Vector::PrintVector()
{
	for(int i = 0; i < this->size; ++i)
	{
		// print value
		std::cout << this->vec[i];

		// check if should print comma or not
		if(i < this->size - 1)
		{
			std::cout << ", ";
		}
		
	}

	std::cout << std::endl;
}

/// -------------------- Scalar Calculations --------------------
// add a scalar number to the array representing a 
// vector in the class.
void Vector::AddScalar(const float scalar)
{
	for(int i = 0; i < this->size; ++i)
	{
		this->vec[i] += scalar;
	}
}

// multiplies a scalar number to the array representing
// a vector in the class.
void Vector::MultiplyScaler(const float scalar)
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
void Vector::DivideScaler(const float scalar)
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

/// -------------------- Vector Calculations --------------------
// compute dot product between two vectors. If sizes don't match
// overflow_error error is thrown
float Vector::Dot(Vector* vector)
{
	// check if sizes don't match
	if(this->size != vector->size)
	{
		throw std::overflow_error("Vector sizes do not match.");
	}

	// compute dot product
	float total = 0;
	for(int i = 0; i < this->size; ++i)
	{
		total += this->vec[i] * vector->GetVectorArray()[i];
	}

	return total;
}









