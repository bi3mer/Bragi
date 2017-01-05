#include "Vector.h"
#include <iostream>
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
bool arraysEqual(int size, float* arr1, float* arr2)
{
    bool equal = true;

    for(int i = 0; i < size; ++i)
    {
        if(*(arr1 + i) != *(arr2 + i))
        {
            equal = false;
            break;
        }
    }

    return equal;
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
    EXPECT_EQ(true, arraysEqual(2, vec4.GetVectorArray(), bad1));
}

// testing GetString
TEST(cpp_vector_test, vector_to_string)
{
    std::string vec1_str = "0.000000, 1.000000, 2.000000";
    std::string vec2_str = "0.000000, 1.000000";

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

int main(int argc, const char * argv[])
{
    testing::InitGoogleTest(&argc, (char**)argv);
    return RUN_ALL_TESTS();
}