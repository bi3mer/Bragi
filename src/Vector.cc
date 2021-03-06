#include <iostream>
#include <algorithm>
#include <stddef.h>
#include <math.h> 
#include "Vector.h"

// -------------------- Get and Set Methods --------------------
int Vector::GetSize() const 
{
	return this->size;
}

const float*  Vector::GetVectorArray() const
{
	return this->vec;
}

/// -------------------- useful commands --------------------
// conver the array that represents the vector into a
// string with commas between values.
std::string Vector::ToString() const
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
void Vector::PrintVector() const
{
	std::cout << this->ToString() << std::endl;
}

// check whether length squared of vector has been calculated or not
bool Vector::LengthSquaredCalculated() const
{
	return this->lengthSquared != -1;
}

// check whether length of vector has been calculated or not
bool Vector::LengthCalculated() const
{
	return this->length != -1;
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

// subtract a scalar number from the array representing
// a vector in the class
void Vector::SubtractScalar(const float scalar)
{
	for(int i = 0; i < this->size; ++i)
	{
		(*this)[i] -= scalar;
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
void Vector::ModulusScalar(const int scalar)
{
	// avoid divide by 0 case
	if(scalar == 0)
	{
		throw std::overflow_error("Divide by zero exception");
	}
	
	for(int i = 0; i < this->size; ++i)
	{
		(*this)[i] = fmodf((*this)[i], scalar);
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
// test if the two vectors are equal to eachother
bool Vector::Equals(const Vector* const vec) const
{
	// check for matching sizes
	if(this->size == vec->GetSize())
	{
		for(int i = 0; i < this->size; ++i)
		{
			// if values are not the same return false
			if((*this)[i] != (*vec)[i])
			{
				return false;
			}
		}
	}
	else
	{
		// return for mismatching sizes
		return false;
	}

	return true;
}

// add this vector and another to create a new vector
void Vector::Add(const Vector* const vecToAdd, Vector* const vecReference) const
{
	// check for mismatching vectors
	if(this->size != vecToAdd->size || this->size != vecReference->size)
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
void Vector::Subtract(const Vector* const vecToSub, Vector* const vecReference) const
{
	// check for mismatching vectors
	if(this->size != vecToSub->size || this->size != vecReference->size)
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
float Vector::Dot(const Vector* const vector) const
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
bool Vector::IsPerpindicular(const Vector* const vector) const
{
	return this->Dot(vector) == 0;
}

// todo: implement with matrix class in the fute
void Vector::PerpindicularVector(const Vector* const vector) const
{
	throw "PerpindicularVector not implmented. Awaiting matrix class.";
}

// compute the length of the vector without getting the length
float Vector::LengthSquared() const
{
	// check if length squred has been calculated
	if(!this->LengthSquaredCalculated())
	{
		// calculate length squred
		this->lengthSquared = this->Dot(this);
	}

	return this->lengthSquared;
}

// Compute the length of the vector.
float Vector::Length() const
{
	// check if length has been calculated
	if(!this->LengthCalculated())
	{
		// check if length squared has ben calculated
		if(!this->LengthSquaredCalculated())
		{
			this->LengthSquared();
		}

		// calculate the length
		this->length = sqrt(this->lengthSquared);
	}

	return this->length;
}

// convert this vector to a unit vector.
void Vector::ConvertToUnitVector()
{
	// divide each entry by the length of the vector
	this->DivideScaler(this->Length());
}

// get value of cosine theta with (v*w)/(||v|| ||w||)
float Vector::CosineTheta(const Vector* const vector) const
{
	return this->Dot(vector)/(this->Length() * vector->Length());
}

// get angle between two vectors
float Vector::Angle(const Vector* const vector) const
{
	return acos(this->CosineTheta(vector));
}

/// -------------------- operator overloading --------------------
// Currently duplicate code is being used as all the operators
// are using very simple operations. Should these become more 
// complex, casts will be used in the non constant versions of 
// the functions. 
float& Vector::operator[](const int index)
{
	return this->vec[index];
}

const float& Vector::operator[](const int index) const 
{
	return this->vec[index];
}

// create a vector and add this and the passed in vector and
// return the new vector
Vector Vector::operator+(const Vector vec) const
{
	Vector newVector = Vector(this->size);
	this->Add(&vec, &newVector);
	return newVector;
}

Vector Vector::operator-(const Vector vec) const
{
	Vector newVector = Vector(this->size);
	this->Subtract(&vec, &newVector);
	return newVector;
}

// for vectors this will represent the dot product
float Vector::operator*(const Vector vec) const
{
	return this->Dot(&vec);
}

// add vectors together
void Vector::operator+=(const Vector vec)
{
	this->Add(&vec, this);
}

void Vector::operator+=(const Vector* const vec)
{
	this->Add(vec, this);
}

// subract vectors together
void Vector::operator-=(const Vector vec)
{
	this->Subtract(&vec, this);
}

void Vector::operator-=(const Vector* const vec)
{
	this->Subtract(vec, this);
}

// check if the two vectors are equal to each other
bool Vector::operator==(const Vector vec) const
{
	return this->Equals(&vec);
}

// check if two vectors are not equal to each other
bool Vector::operator!=(const Vector vec) const
{
	// return opposite of ==
	return !this->Equals(&vec);
}

/// -------------------- Constructors --------------------
// Create vector of size x with values y
Vector::Vector(const int size, const float val) : lengthSquared(-1), length(-1)
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
Vector::Vector(const int size, const float data[]) : lengthSquared(-1), length(-1)
{
	this->size = size;

	// copy array into new one
	this->vec = new float[size];
	std::copy(data, data + this->size, this->vec);
}

// Construct this vector by copying another vector
Vector::Vector(const Vector* const vec)
{
	// TODO: save length and lengthSqured
	this->size = vec->GetSize();
	this->vec  = new float[this->size];
	std::copy(vec->GetVectorArray(), vec->GetVectorArray() + this->size, this->vec);
	
	// assign values based on what has and has not been calculated
	this->length        = vec->Length();
	this->lengthSquared = vec->LengthSquared();
}


// -------------------- Destructor --------------------
Vector::~Vector()
{
	// pass
}





