#include "Vector.h"
#include "gtest/gtest.h"

float add1[]      = {0,1,2};
float add2[]      = {3,4,5};
float sub3[]      = {0,-1,-2};
float bad1[]      = {0,1};
float bad2[]      = {1,2};

Vector vec1 = Vector(3, add1);
Vector vec2 = Vector(3, add2);
Vector vec3 = Vector(3, sub3);
Vector vec4 = Vector(2, bad1);
Vector vec5 = Vector(2, bad2);

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