class Vector 
{
	public:
		Vector(const int, const float);
		Vector(const int, float[]);

		~Vector();

		// Getters and Setters
		int GetSize();

		// TODO: try const int index and data
		void SetVectorPoint(const int, const float);
		float* GetVectorArray();

		// Usefulc ommands
		void PrintVector();

		// Scalar Calculations
		void AddScalar(const float);
		void MultiplyScaler(const float);
		void DivideScaler(const float);

		// Vector Calculations
		float Dot(Vector*);

	private: 
		int size;
		float* vec;
};