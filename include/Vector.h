#include <string>

class Vector 
{
	public:
		// Getters and Setters
		int GetSize() const;
		const float* GetVectorArray() const;

		// Useful ommands
		std::string ToString() const;
		void PrintVector() const;
		bool LengthSquaredCalculated() const;
		bool LengthCalculated() const;

		// Scalar Calculations
		void AddScalar(const float);
		void SubtractScalar(const float);
		void MultiplyScaler(const float);
		void DivideScaler(const float);
		void ModulusScalar(const int);
		void RaisePowerScalar(const float);

		// Vector Calculations
		bool Equals(const Vector * const) const;
		void Add(const Vector* const, Vector* const) const;
		void Subtract(const Vector* const, Vector* const) const;
		float Dot(const Vector* const) const;
		bool IsPerpindicular(const Vector* const) const;
		void PerpindicularVector(const Vector* const) const;
		float LengthSquared() const;
		float Length() const;
		void ConvertToUnitVector();
		float CosineTheta(const Vector* const) const;
		float Angle(const Vector* const) const;

		// operator overloading
		float& operator[](const int);
		const float& operator[](const int) const;
		Vector operator+(const Vector) const;
		Vector operator-(const Vector) const;
		float operator*(const Vector) const;
		void operator+=(const Vector);
		void operator+=(const Vector* const);
		void operator-=(const Vector);
		void operator-=(const Vector* const);
		bool operator==(const Vector) const;
		bool operator!=(const Vector) const;

		// constructors
		Vector(const int, const float val=0);
		Vector(const int, const float[]);
		Vector(const Vector* const);

		// destructor
		~Vector();

	private:
		void initializeClassVariables() const;
		int size;
		mutable float lengthSquared;
		mutable float length;
		mutable float* vec;
};