#include <iostream>
#include <stddef.h>
#include <math.h> 
#include "Vector.h"

// -------------------- Get and Set Methods --------------------
int Vector::GetSize()
{
	return this->size;
}

float* Vector::GetVectorArray()
{
	return this->vec;
}

/// -------------------- useful commands --------------------
// conver the array that represents the vector into a
// string with commas between values.
std::string Vector::ToString()
{
	std::string str = "";

	for(int i = 0; i < this->size; ++i)
	{
		str += std::to_string((*this)[i]);

		if(i < this-> size - 1)
		{
			str += ", ";
		}
	}

	return str;
}

// print result of ToString with a new line.
void Vector::PrintVector()
{
	std::cout << this->ToString() << std::endl;
}

/// -------------------- Scalar Calculations --------------------
// add a scalar number to the array representing a 
// vector in the class.
void Vector::AddScalar(const float scalar)
{
	for(int i = 0; i < this->size; ++i)
	{
		(*this)[i] += scalar;
	}
}

// multiplies a scalar number to the array representing
// a vector in the class.
void Vector::MultiplyScaler(const float scalar)
{
	for(int i = 0; i < this->size; ++i)
	{
		(*this)[i] *= scalar;
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
		(*this)[i] /= scalar;
	}
}

// compute modulus on all elements of the vector
void Vector::ModulusScalar(const int mod)
{
	for(int i = 0; i < this->size; ++i)
	{
		(*this)[i] = fmodf((*this)[i], mod);
	}
}

// raie all elements of vector to power x
void Vector::RaisePowerScalar(const float power)
{
	for(int i = 0; i < this->size; ++i)
	{
		(*this)[i] = pow((*this)[i], power);
	}
}

/// -------------------- Vector Calculations --------------------
// add this vector and another to create a new vector
void Vector::Add(Vector* vecToAdd, Vector* vecReference)
{
	// check for mismatching vectors
	if(this->size != vecToAdd->size && this->size != vecReference->size)
	{
		throw std::overflow_error("Mismatching sizes for addition of two vectors.");
	}

	// add vectors
	for(int i = 0; i < this->size; ++i)
	{
		(*vecReference)[i] = (*this)[i] + (*vecToAdd)[i];
	}
}

// subtract this vector and another to create a new vecor
void Vector::Sub(Vector* vecToSub, Vector* vecReference)
{
	// check for mismatching vectors
	if(this->size != vecToSub->size && this->size != vecReference->size)
	{
		throw std::overflow_error("Mismatching sizes for subraction of two vectors.");
	}

	// add vectors
	for(int i = 0; i < this->size; ++i)
	{
		(*vecReference)[i] = (*this)[i] - (*vecToSub)[i];
	}
}

// compute dot product between two vectors. If sizes don't match
// overflow_error error is thrown
float Vector::Dot(Vector* vector)
{
	// check if sizes don't match
	if(this->size != vector->size)
	{
		throw std::overflow_error("Mismatching sizes for dot product of two vectors.");
	}

	// compute dot product
	float total = 0;
	for(int i = 0; i < this->size; ++i)
	{
		total += (*this)[i] * (*vector)[i];
	}

	return total;
}

// Check if this vector is perpindicular to the passed vector
// by computing the dot product and seeing if the result is 0.
bool Vector::IsPerpindicular(Vector* vector)
{
	return this->Dot(vector) == 0;
}

// Compute the length of the vector.
float Vector::Length()
{
	// return the square root of the dot product which is
	// representative of the length of a vector.
	return sqrt(this->Dot(this));
}

// convert this vector to a unit vector.
void Vector::ConvertToUnitVector()
{
	// divide each entry by the length of the vector
	this->DivideScaler(this->Length());
}

/// -------------------- operator overloading --------------------
float& Vector::operator[](const int index)
{
	return this->vec[index];
}

// create a vector and add this and the passed in vector and
// return the new vector
Vector Vector::operator+(Vector vec)
{
	Vector newVector = Vector(this->size);
	this->Add(&vec, &newVector);
	return newVector;
}

Vector Vector::operator-(Vector vec)
{
	Vector newVector = Vector(this->size);
	this->Sub(&vec, &newVector);
	return newVector;
}

// for vectors this will represent the dot product
float Vector::operator*(Vector vec)
{
	return this->Dot(&vec);
}

/// -------------------- Constructors --------------------
// Create vector of size x with values y
Vector::Vector(const int size, const float val)
{
	this->size = size;

	// initialize array and set all values to val
	this->vec = new float[size];
	for(int i = 0; i < size; ++i)
	{
		(*this)[i] = val;
	}
}

// Create vector with size y that will be the same size
// as the array passed in. No checking is done to account
// for ensuring this, so if a mistake is made it is on the
// user's end. 
Vector::Vector(const int size, float data[])
{
	this->size = size;

	// copy array into new one
	this->vec = new float[size];
	for(int i = 0; i < size; ++i)
	{
		(*this)[i] = data[i];
	}
}

// Construct this vector by copying another vector
Vector::Vector(Vector* vec)
{
	this->size = vec->GetSize();
	this->vec = new float[this->size];

	for(int i = 0; i < this->size; ++i)
	{
		(*this)[i] = (*vec)[i];
	}
}


// -------------------- Destructor --------------------
Vector::~Vector()
{
	// pass
}





