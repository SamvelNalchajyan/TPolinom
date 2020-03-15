#include "gtest.h"
#include "../TPolinom/TPolinom.h"

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom mon);
}

TEST(TMonom, assignment_operators_works_correctly)
{
	TMonom m1, m2;
	EXPECT_EQ(true, m1 == m2);
	EXPECT_EQ(false, m1 != m2);
	m1.coeff = 5;
	m1.px = 1;
	m1.py = 2;
	m1.pz = 3;
	EXPECT_EQ(false, m1 == m2);
	EXPECT_EQ(true, m1 != m2);
	m2.coeff = 5;
	m2.px = 1;
	m2.py = 2;
	m2.pz = 3;
	EXPECT_EQ(true, m1 == m2);
	EXPECT_EQ(false, m1 != m2);
	m2.px = 2;
	EXPECT_EQ(true, m1 < m2);
	EXPECT_EQ(true, m1 <= m2);
	EXPECT_EQ(false, m1 > m2);
	EXPECT_EQ(false, m1 >= m2);
}

/*.................................................*/

TEST(TPolinom, can_create_polinomial)
{
	ASSERT_NO_THROW(TPolinom P);
}

TEST(TPolinom, can_create_polinomial_through_array)
{
	int arr[2][2];
	arr[0][0] = 2;
	arr[1][0] = 1;
	arr[0][1] = 222;
	arr[1][1] = 111;
	ASSERT_NO_THROW(TPolinom p(arr, 2));
}

TEST(TPolinom, equality_operator_works_correctly)
{
	TMonom mon;
	mon.coeff = 5.9;
	mon.px = 11;
	mon.py = 5;
	mon.pz = 0;
	TPolinom P;
	P += mon;
	TPolinom Q;
	Q += mon;
	ASSERT_NO_THROW(P == Q);
	EXPECT_EQ(true, P == Q);
}

TEST(TPolinom, can_copy_polinomials)
{
	TMonom mon;
	mon.coeff = 5.9;
	mon.px = 11;
	mon.py = 5;
	mon.pz = 0;
	TPolinom P;
	P += mon;
	ASSERT_NO_THROW(TPolinom Q(P));
	TPolinom Q(P);
	EXPECT_EQ(true, P == Q);
}

TEST(TPolinom, assignment_operator_works_correctly)
{
	TPolinom P, Q;
	TMonom mon;
	mon.coeff = 5.9;
	mon.px = 11;
	mon.py = 5;
	mon.pz = 0;
	Q += mon;
	EXPECT_NE(true, P == Q);
	P = Q;
	EXPECT_EQ(true, P == Q);
}

TEST(TPolinom, can_add_monom)
{
	TPolinom p;
	TMonom mon;
	mon.coeff = 5;
	mon.px = 6;
	mon.py = 11;
	mon.pz = 9;
	ASSERT_NO_THROW(p += mon);
	ASSERT_NO_THROW(p = p + mon);
	TPolinom P;
	P += mon;
	mon.coeff = 7;
	P += mon;
	P.Reset();
	EXPECT_EQ(12, P.GetCurrEl().coeff);
}

TEST(TPolinom, addition_works_correctly)
{
	TPolinom P;
	TMonom mon;
	mon.coeff = 5;
	mon.px = 6;
	mon.py = 11;
	mon.pz = 9;
	P += mon;
	TPolinom Q = P * 2;
	P += mon;
	EXPECT_EQ(true, P == Q);
	TMonom m1, m2, m3;
	m1.coeff = -10;
	m1.px = 6;
	m1.py = 11;
	m1.pz = 9;
	P += m1;
	TPolinom empty;
	EXPECT_EQ(true, P == empty);
	P = Q;
	m2.coeff = 5;
	m2.px = 5;
	m2.py = 5;
	m2.pz = 5;
	P += m2;
	m3.coeff = 6;
	m3.px = 5;
	m3.py = 5;
	m3.pz = 5;
	P += m3;
	Q = P * (-1);
	P += Q;
	EXPECT_EQ(true, P == empty);
	P = P + Q;
	Q *= -1;
	P += Q;
	EXPECT_EQ(true, P == empty);
}

TEST(TPolinom, can_multiply_monom)
{
	TPolinom P;
	TMonom mon;
	mon.coeff = 5;
	mon.px = 6;
	mon.py = 11;
	mon.pz = 9;
	P += mon;
	TPolinom p;
	ASSERT_NO_THROW(p *= mon);
	P *= mon;
	P.Reset();
	EXPECT_EQ(25, P.GetCurrEl().coeff);
	EXPECT_EQ(12, P.GetCurrEl().px);
	EXPECT_EQ(22, P.GetCurrEl().py);
	EXPECT_EQ(18, P.GetCurrEl().pz);
}