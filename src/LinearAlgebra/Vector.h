class Vector 
{
	public:
		Vector(const int);
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
		void addScalar(const float);
		void multiplyScaler(const float);
		void divideScaler(const float);

	private: 
		int size;
		float* vec;
};