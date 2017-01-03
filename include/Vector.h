#include <string>

class Vector 
{
	public:
		// Getters and Setters
		int GetSize();
		float* GetVectorArray();

		// Usefulc ommands
		std::string ToString();
		void PrintVector();

		// Scalar Calculations
		void AddScalar(const float);
		void SubtractScalar(const float);
		void MultiplyScaler(const float);
		void DivideScaler(const float);
		void ModulusScalar(const int);
		void RaisePowerScalar(const float);

		// Vector Calculations
		void Add(Vector*, Vector*);
		void Subtract(Vector*, Vector*);
		float Dot(Vector*);
		bool IsPerpindicular(Vector*);
		float Length();
		void ConvertToUnitVector();

		// operator overloading
		float& operator[](const int);
		Vector operator+(Vector);
		Vector operator-(Vector);
		float operator*(Vector);
		bool operator==(Vector);
		bool operator!=(Vector);

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