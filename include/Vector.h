#include <string>

class Vector 
{
	public:
		// Getters and Setters
		const int GetSize() const;
		const float* GetVectorArray() const;

		// Useful ommands
		const std::string ToString() const;
		void PrintVector() const;

		// Scalar Calculations
		void AddScalar(const float);
		void SubtractScalar(const float);
		void MultiplyScaler(const float);
		void DivideScaler(const float);
		void ModulusScalar(const int);
		void RaisePowerScalar(const float);

		// Vector Calculations
		const bool Equals(const Vector *) const;
		const void Add(const Vector*, Vector*) const;
		const void Subtract(const Vector*, Vector*) const;
		const float Dot(const Vector*) const;
		const bool IsPerpindicular(const Vector*) const;
		void PerpindicularVector(const Vector*) const;
		const float Length() const;
		void ConvertToUnitVector();
		const float CosineTheta(const Vector*) const;
		const float Angle(const Vector*) const;

		// operator overloading
		float& operator[](const int);
		const float& operator[](const int) const;
		const Vector operator+(const Vector) const;
		const Vector operator-(const Vector) const;
		const float operator*(const Vector) const;
		void operator+=(const Vector);
		void operator+=(const Vector*);
		void operator-=(const Vector);
		void operator-=(const Vector*);
		const bool operator==(const Vector) const;
		const bool operator!=(const Vector) const;

		// constructors
		Vector(const int, const float val=0);
		Vector(const int, float[]);
		Vector(Vector*);

		// destructor
		~Vector();

	private: 
		int size;
		float* vec;
};