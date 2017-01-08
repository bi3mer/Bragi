#include <math.h> 
#include <iostream>
#include "Vector.h"
#include "gtest/gtest.h"

float add1[] = {0,1,2};
float add2[] = {3,4,5};
float sub3[] = {0,-1,-2};
float bad1[] = {0,1};
float bad2[] = {1,2};

Vector vec1  = Vector(3, add1);
Vector vec2  = Vector(3, add2);
Vector vec3  = Vector(3, sub3);
Vector vec4  = Vector(2, bad1);
Vector vec5  = Vector(2, bad2);

// test if two arrays are equal. This doesn't account for
// different sizes in the aray.
bool arraysEqual(int size, const float* arr1, const float* arr2)
{
    bool isEqual = true;

    for(int i = 0; i < size; ++i)
    {
        if(*(arr1 + i) != *(arr2 + i))
        {
            isEqual = false;
            break;
        }
    }

    return isEqual;
}

TEST(cpp_google_test_functions, arrays_equal)
{
    float test1[] = {2,3,4,5};
    float test2[] = {2,3,4,5};
    float test3[] = {1,2,3,4};

    EXPECT_EQ(true, arraysEqual(3, test1, test2));
    EXPECT_EQ(false, arraysEqual(3, test1, test3));  
}

/// -------------------- useful commands --------------------
// testing GetSize
TEST(cpp_vector_test, vector_get_size)
{
    EXPECT_EQ(3, vec1.GetSize());
    EXPECT_EQ(2, vec4.GetSize());
}

// testing GetVectorArray
TEST(cpp_vector_test, vector_get_array)
{
    EXPECT_EQ(true, arraysEqual(3, vec1.GetVectorArray(), add1));
    EXPECT_EQ(false, arraysEqual(3, vec1.GetVectorArray(), add2));
    EXPECT_EQ(true, arraysEqual(2, vec4.GetVectorArray(), bad1));
}

// testing GetString
TEST(cpp_vector_test, vector_to_string)
{
    std::string vec1_str = std::string("0.000000, 1.000000, 2.000000");
    std::string vec2_str = std::string("0.000000, 1.000000");

    EXPECT_EQ(0, vec1.ToString().compare(vec1_str));
    EXPECT_EQ(0, vec4.ToString().compare(vec2_str));
}

/// -------------------- Scalar Calculations --------------------
// test AddScalar
TEST(cpp_vector_test, vector_add_scalar)
{
    float expected1[] = {3.0,4.0,5.0};
    float expected2[] = {3.0,4.0};

    Vector test1 = Vector(&vec1);
    Vector test2 = Vector(&vec4);

    test1.AddScalar(3);
    test2.AddScalar(3);

    EXPECT_EQ(true, arraysEqual(3, test1.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test2.GetVectorArray(), expected2));
}

// test SubtractScalar
TEST(cpp_vector_test, vector_sub_scalar)
{
    float expected1[] = {-3.0,-2.0,-1.0};
    float expected2[] = {-3.0,-2.0};

    Vector test1 = Vector(&vec1);
    Vector test2 = Vector(&vec4);

    test1.SubtractScalar(3);
    test2.SubtractScalar(3);

    EXPECT_EQ(true, arraysEqual(3, test1.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test2.GetVectorArray(), expected2));
}

// test MultiplyScaler
TEST(cpp_vector_test, vector_multiply_scalar)
{
    float expected1[] = {0.0,3.0,6.0};
    float expected2[] = {0.0,3.0};

    Vector test1 = Vector(&vec1);
    Vector test2 = Vector(&vec4);

    test1.MultiplyScaler(3);
    test2.MultiplyScaler(3);

    EXPECT_EQ(true, arraysEqual(3, test1.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test2.GetVectorArray(), expected2));
}

// test DivideScaler
TEST(cpp_vector_test, vector_divide_scalar)
{
    float expected2[] = {0.0,0.5};

    Vector test2 = Vector(&vec4);

    test2.DivideScaler(2);

    EXPECT_EQ(true, arraysEqual(2, test2.GetVectorArray(), expected2));
    EXPECT_THROW(test2.DivideScaler(0), std::overflow_error);
}

// test ModulusScalar
TEST(cpp_vector_test, vector_mudulus_scalar)
{
    float expected1[] = {0.0,1.0,0.0};
    float expected2[] = {0.0,1.0};

    Vector test1 = Vector(&vec1);
    Vector test2 = Vector(&vec4);

    test1.ModulusScalar(2);
    test2.ModulusScalar(2);

    EXPECT_EQ(true, arraysEqual(3, test1.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test2.GetVectorArray(), expected2));
    EXPECT_THROW(test2.ModulusScalar(0), std::overflow_error);
}

// test RaisePowerScalar
TEST(cpp_vector_test, vector_raise_power_scalar)
{
    float expected1[] = {0.0,1.0,4.0};
    float expected2[] = {0.0,1.0};

    Vector test1 = Vector(&vec1);
    Vector test2 = Vector(&vec4);

    test1.RaisePowerScalar(2);
    test2.RaisePowerScalar(2);

    EXPECT_EQ(true, arraysEqual(3, test1.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test2.GetVectorArray(), expected2));
}

/// -------------------- Vector Calculations --------------------
// test Equals
TEST(cpp_vector_test, vector_equals)
{
    EXPECT_EQ(true, vec1.Equals(&vec1));
    EXPECT_EQ(false, vec1.Equals(&vec2));
    EXPECT_EQ(false, vec1.Equals(&vec5));
}

// test Add
TEST(cpp_vector_test, vector_add)
{
    float expected1[] = {3.0,5.0,7.0};
    float expected2[] = {1.0,3.0};

    Vector test1 = Vector(3);
    Vector test2 = Vector(2);

    vec1.Add(&vec2, &test1);
    vec4.Add(&vec5, &test2);

    EXPECT_EQ(true, arraysEqual(3, test1.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test2.GetVectorArray(), expected2));
}

// test Subtract
TEST(cpp_vector_test, vector_subtract)
{
    float expected1[] = {-3.0,-3.0,-3.0};
    float expected2[] = {-1.0,-1.0};

    Vector test1 = Vector(3);
    Vector test2 = Vector(2);

    vec1.Subtract(&vec2, &test1);
    vec4.Subtract(&vec5, &test2);

    EXPECT_EQ(true, arraysEqual(3, test1.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test2.GetVectorArray(), expected2));
}

// test Dot
TEST(cpp_vector_test, vector_dot)
{
    EXPECT_EQ(14, vec1.Dot(&vec2));
    EXPECT_EQ(2,  vec4.Dot(&vec5));
    EXPECT_THROW(vec1.Dot(&vec4), std::overflow_error);
}

// test IsPerpindicular
TEST(cpp_vector_test, vector_is_perpindicular)
{
    EXPECT_EQ(false, vec1.IsPerpindicular(&vec2));

    float exp1[] = {1,2};
    float exp2[] = {-2,1};

    Vector perp1 = Vector(2, exp1);
    Vector perp2 = Vector(2, exp2);

    EXPECT_EQ(true, perp1.IsPerpindicular(&perp2));
}

// test PerpindicularVector
TEST(cpp_vector_test, vector_get_perpindicular)
{
    EXPECT_ANY_THROW(vec1.PerpindicularVector(&vec1));
}

// test Length
TEST(cpp_vector_test, vector_length_squared)
{
    float a1[] = {1,1,1,1};
    Vector v1 = Vector(4, a1);
    EXPECT_EQ(4, v1.LengthSquared());
}

// test Length
TEST(cpp_vector_test, vector_length)
{
    float a1[] = {1,1,1,1};
    Vector v1 = Vector(4, a1);
    EXPECT_EQ(2, v1.Length());
}

// test ConvertToUnitVector
TEST(cpp_vector_test, vector_conver_to_unit_vector)
{
    // get result for unit vector
    float val = 1 / sqrt(2);
    float exp[] = {val, val};
    float arr[] = {1,1};
    Vector v1 = Vector(2, arr);
    v1.ConvertToUnitVector();
    EXPECT_EQ(true, arraysEqual(2, v1.GetVectorArray(), exp));
}

// test CosineTheta
TEST(cpp_vector_test, vector_cosine_theta)
{
    float a1[] = {2,1};
    float a2[] = {1,2};
    float exp  = 4.0/5.0;

    Vector v1 = Vector(2,a1);
    Vector v2 = Vector(2,a2);

    EXPECT_EQ(exp, v1.CosineTheta(&v2));
    EXPECT_THROW(v1.CosineTheta(&vec1), std::overflow_error);
}

// test Angle
TEST(cpp_vector_test, vector_angle)
{
    float a1[] = {2,1};
    float a2[] = {1,2};
    float exp  = 4.0/5.0;

    Vector v1 = Vector(2,a1);
    Vector v2 = Vector(2,a2);

    EXPECT_NEAR(acos(exp), v1.Angle(&v2), 0.001);
    EXPECT_THROW(v1.Angle(&vec1), std::overflow_error);
}

/// -------------------- operator overloading --------------------
// test: [] operation
TEST(cpp_vector_test, vector_operator_brackets)
{
    for(int i = 0; i < vec1.GetSize(); ++i)
    {
        EXPECT_EQ(add1[i], vec1[i]);
    }
}

// test: vec1 + vec2 operation
TEST(cpp_vector_test, vector_operator_add)
{
    float expected1[] = {3,5,7};
    float expected2[] = {0,0,0};
    float expected3[] = {1,3};

    Vector exp1 = Vector(3, expected1);
    Vector exp2 = Vector(3, expected2);
    Vector exp3 = Vector(2, expected3);

    // test basic addition
    Vector result1 = vec1 + vec2;
    bool additionResult = result1 == exp1;
    EXPECT_EQ(true, additionResult);

    // test basic addition with subtraction
    result1 = vec1 + vec3;
    additionResult = result1 == exp2;
    EXPECT_EQ(true, additionResult);

    // test different size
    result1 = vec4 + vec5;
    additionResult = result1 == exp3;
    EXPECT_EQ(true, additionResult);

    // test mismatching sizes
    EXPECT_THROW(vec4 + vec1, std::overflow_error);
}

// test: vec1 - vec2 operation
TEST(cpp_vector_test, vector_operator_sub)
{
    float expected1[] = {-3,-3,-3};
    float expected2[] = {0,2,4};
    float expected3[] = {-1,-1};

    Vector exp1 = Vector(3, expected1);
    Vector exp2 = Vector(3, expected2);
    Vector exp3 = Vector(2, expected3);

    // test basic addition
    Vector result1 = vec1 - vec2;
    bool additionResult = result1 == exp1;
    EXPECT_EQ(true, additionResult);

    // test basic addition with subtraction
    result1 = vec1 - vec3;
    additionResult = result1 == exp2;
    EXPECT_EQ(true, additionResult);

    // test different size
    result1 = vec4 - vec5;
    additionResult = result1 == exp3;
    EXPECT_EQ(true, additionResult);

    // test mismatching sizes
    EXPECT_THROW(vec4 - vec1, std::overflow_error);
}

// test: vec1 * vec2 operation
TEST(cpp_vector_test, vector_operator_dot)
{
    EXPECT_EQ(14, vec1 * vec2);
    EXPECT_EQ(2,  vec4 * vec5);
    EXPECT_THROW(vec1 * vec4, std::overflow_error);
}

// test: vec1 += vec2 operation
TEST(cpp_vector_test, vector_operator_plus_equals)
{
    float expected1[] = {3.0,5.0,7.0};
    float expected2[] = {1.0,3.0};

    Vector test1 = Vector(3, add1);
    Vector test2 = Vector(2, bad1);

    test1 += vec2;
    test2 += vec5;

    EXPECT_EQ(true, arraysEqual(3, test1.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test2.GetVectorArray(), expected2));

    Vector test3 = Vector(3, add1);
    Vector test4 = Vector(2, bad1);

    test3 += &vec2;
    test4 += &vec5;

    EXPECT_EQ(true, arraysEqual(3, test3.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test4.GetVectorArray(), expected2));
}

// test: vec1 -= vec2 operation
TEST(cpp_vector_test, vector_operator_minus_equals)
{
    float expected1[] = {-3.0,-3.0,-3.0};
    float expected2[] = {-1.0,-1.0};

    Vector test1 = Vector(3, add1);
    Vector test2 = Vector(2, bad1);

    test1 -= vec2;
    test2 -= vec5;

    EXPECT_EQ(true, arraysEqual(3, test1.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test2.GetVectorArray(), expected2));

    Vector test3 = Vector(3, add1);
    Vector test4 = Vector(2, bad1);

    test3 -= &vec2;
    test4 -= &vec5;

    EXPECT_EQ(true, arraysEqual(3, test3.GetVectorArray(), expected1));
    EXPECT_EQ(true, arraysEqual(2, test4.GetVectorArray(), expected2));
}

// test: vec1 == vec2 operation
TEST(cpp_vector_test, vector_operator_equal_equals)
{
    EXPECT_EQ(true, vec1  == vec1);
    EXPECT_EQ(false, vec1 == vec2);
    EXPECT_EQ(false, vec1 == vec5);
}

// test: vec1 != vec2 operation
TEST(cpp_vector_test, vector_operator_not_equal)
{
    EXPECT_EQ(false, vec1 != vec1);
    EXPECT_EQ(true, vec1  != vec2);
    EXPECT_EQ(true, vec1  != vec5);
}

/// -------------------- Constructors -------------------- 
// test initialization with only size and potentially value
TEST(cpp_vector_test, vector_constructor_size_and_value)
{
    Vector test = Vector(3);
    float exp1[] = {0,0,0};
    EXPECT_EQ(3, test.GetSize());
    EXPECT_EQ(true, arraysEqual(3, test.GetVectorArray(), exp1));

    test = Vector(4,1);
    float exp2[] = {1,1,1,1};
    EXPECT_EQ(4, test.GetSize());
    EXPECT_EQ(true, arraysEqual(4, test.GetVectorArray(), exp2));
}

// test initialization with size and array
TEST(cpp_vector_test, vector_constructor_size_and_array)
{
    Vector test = Vector(3, add1);
    EXPECT_EQ(3, test.GetSize());
    EXPECT_EQ(true, arraysEqual(3, test.GetVectorArray(), add1));
}

// test copy constructor
TEST(cpp_vector_test, vector_copy_constructor)
{
    Vector vec = Vector(3, add1);
    Vector test = Vector(&vec);
    EXPECT_EQ(3, test.GetSize());
    EXPECT_EQ(true, arraysEqual(3, test.GetVectorArray(), add1));
}

int main(int argc, const char * argv[])
{
    testing::InitGoogleTest(&argc, (char**)argv);
    return RUN_ALL_TESTS();
}