#include <string>

class Vector 
{
	public:
		// Getters and Setters
		int GetSize();

		// TODO: try const int index and data
		void SetVectorPoint(const int, const float);
		float* GetVectorArray();

		// Usefulc ommands
		std::string ToString();
		void PrintVector();

		// Scalar Calculations
		void AddScalar(const float);
		void MultiplyScaler(const float);
		void DivideScaler(const float);
		// modulus scalar
		// pow scalar

		// Vector Calculations
		void Add(Vector*, Vector*);
		void Sub(Vector*, Vector*);
		float Dot(Vector*);
		bool IsPerpindicular(Vector*);
		float Length();
		void ConvertToUnitVector();

		// operator overloading
		float& operator[](const int);

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