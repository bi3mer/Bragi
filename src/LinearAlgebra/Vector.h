class Vector 
{
	public:
		// constructors
		Vector(const int, const float val=0);
		Vector(const int, float[]);

		// destructor
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
		// modulus scalar
		// pow scalar

		// Vector Calculations
		void Add(Vector*, Vector*);
		void Sub(Vector*, Vector*);
		float Dot(Vector*);

	private: 
		int size;
		float* vec;
};