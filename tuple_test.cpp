//
// Created by kerpackie on 22/08/2026.
//

#include "tuple.h"

#include <gtest/gtest.h>

TEST(TupleTest, TupleCreatesPoint) {
    Tuple t = Tuple(4.3f, -4.2f, 3.1f, 1.0f);
    ASSERT_EQ(t.x, 4.3f);
    ASSERT_EQ(t.y, -4.2f);
    ASSERT_EQ(t.z, 3.1f);
    ASSERT_EQ(t.w, 1.0f);
}

TEST(TupleTest, TupleCreatesVector) {
    Tuple t = Tuple(4.3f, -4.2f, 3.1f, 0.0f);
    ASSERT_EQ(t.x, 4.3f);
    ASSERT_EQ(t.y, -4.2f);
    ASSERT_EQ(t.z, 3.1f);
    ASSERT_EQ(t.w, 0.0f);
}

TEST(TupleTest, CreatesAPoint) {
    Tuple p = Tuple::point(1.0f, 2.0f, 3.0f);
    ASSERT_EQ(p.w, 1.0f);
}

TEST(TupleTest, CreatesAVector) {
    Tuple v = Tuple::vector(1.0f, 2.0f, 3.0f);
    ASSERT_EQ(v.w, 0.0f);
}

TEST(TupleEquality, TupleWithinEpsilon) {
    Tuple a = Tuple(1.0f, 2.0f, 3.0f, 4.0f);
    Tuple b = Tuple(1.0f + 0.000001f, 2.0f - 0.000001f, 3.0f + 0.000001f, 4.0f - 0.000001f);
    ASSERT_TRUE(a == b);
}

TEST(TupleEquality, TupleOutsideEpsilon) {
    Tuple a = Tuple(1.0f, 2.0f, 3.0f, 4.0f);
    Tuple b = Tuple(1.0f + 0.05, 2.0f, 3.0f, 4.0f);
    ASSERT_FALSE(a == b);
}

TEST(TupleAddition, AddingTwoTuples) {
    Tuple a = Tuple(3.0f, -2.0f, 5.0f, 1.0f);
    Tuple b = Tuple(-2.0f, 3.0f, 1.0f, 0.0f);
    Tuple c = a + b;

    ASSERT_EQ(c.x, 1.0f);
    ASSERT_EQ(c.y, 1.0f);
    ASSERT_EQ(c.z, 6.0f);
    ASSERT_EQ(c.w, 1.0f);
}

TEST(TupleSubtraction, SubtractingTwoPoints) {
    Tuple p1 = Tuple::point(3.0f, 2.0f, 1.0f);
    Tuple p2 = Tuple::point(5.0f, 6.0f, 7.0f);
    Tuple result = p1 - p2;

    ASSERT_EQ(result.x, -2.0f);
    ASSERT_EQ(result.y, -4.0f);
    ASSERT_EQ(result.z, -6.0f);
    ASSERT_EQ(result.w, 0.0f); // Result should be a vector
}

TEST(TupleSubtraction, SubtractingTwoVectors) {
    Tuple v1 = Tuple::vector(3.0f, 2.0f, 1.0f);
    Tuple v2 = Tuple::vector(5.0f, 6.0f, 7.0f);

    Tuple v3 = v1 - v2;

    ASSERT_EQ(v3.x, -2.0f);
    ASSERT_EQ(v3.y, -4.0f);
    ASSERT_EQ(v3.z, -6.0f);
    ASSERT_EQ(v3.w, 0.0f);

}

TEST(TupleSubtraction, SubtractingVectorFromAPoint) {
    Tuple point = Tuple::point(3.0f, 2.0f, 1.0f);
    Tuple vector = Tuple::vector(5.0f, 6.0f, 7.0f);

    Tuple result = point - vector;

    ASSERT_EQ(result.x, -2.0f);
    ASSERT_EQ(result.y, -4.0f);
    ASSERT_EQ(result.z, -6.0f);
    ASSERT_EQ(result.w, 1.0f);
}

TEST(TupleNegation, SubtractingVectorFromZeroVector) {
    Tuple zero = Tuple::vector(0.0f, 0.0f, 0.0f);
    Tuple vector = Tuple::vector(1.0f, -2.0f, 3.0f);
    Tuple result = zero - vector;

    ASSERT_EQ(result.x, -1.0f);
    ASSERT_EQ(result.y, 2.0f);
    ASSERT_EQ(result.z, -3.0f);
}

TEST(TupleNegation, NegatingATupleUsingNegationOperator) {
    Tuple a = Tuple(1.0f, -2.0f, 3.0f, -4.0f);
    Tuple negated = -a;

    ASSERT_EQ(negated.x, -1.0f);
    ASSERT_EQ(negated.y, 2.0f);
    ASSERT_EQ(negated.z, -3.0f);
    ASSERT_EQ(negated.w, 4.0f);
}