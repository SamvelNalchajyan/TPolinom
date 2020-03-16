#include "gtest.h"
#include "../TPolinom/TPolinom.h"

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom mon);
}

TEST(TMonom, assignment_operators_work_correctly)
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
	mon.pz = 1;
	Q += mon;
	EXPECT_EQ(false, P == Q);
	P = Q;
	EXPECT_EQ(true, P == Q);
	P *= 2;
	EXPECT_EQ(false, P == Q);
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

TEST(TPolinom, first_link_sokr)
{
	TPolinom P, Q, RES;
	TMonom p1, p2, p3, q1;
	p1.coeff = 8; p1.px = 8; p1.py = 8; p1.pz = 8;
	p2.coeff = 9; p2.px = 7; p2.py = 8; p2.pz = 9;
	p3.coeff = 7; p3.px = 6; p3.py = 3; p3.pz = 0;
	q1.coeff = -8; q1.px = 8; q1.py = 8; q1.pz = 8;
	P += p1;
	P += p2;
	P += p3;
	Q += q1;
	RES += p2;
	RES += p3;
	P += Q;
	EXPECT_EQ(true, RES == P);
}

TEST(TPolinom, midle_link_sokr)
{
	TPolinom P, Q, RES;
	TMonom p1, p2, p3, q1;
	p1.coeff = 8; p1.px = 8; p1.py = 8; p1.pz = 8;
	p2.coeff = 9; p2.px = 7; p2.py = 8; p2.pz = 9;
	p3.coeff = 7; p3.px = 6; p3.py = 3; p3.pz = 0;
	q1.coeff = -9; q1.px = 7; q1.py = 8; q1.pz = 9;
	P += p1;
	P += p2;
	P += p3;
	Q += q1;
	RES += p1;
	RES += p3;
	P += Q;
	EXPECT_EQ(true, RES == P);
}

TEST(TPolinom, last_link_sokr)
{
	TPolinom P, Q, RES;
	TMonom p1, p2, p3, q1;
	p1.coeff = 8; p1.px = 8; p1.py = 8; p1.pz = 8;
	p2.coeff = 9; p2.px = 7; p2.py = 8; p2.pz = 9;
	p3.coeff = 7; p3.px = 6; p3.py = 3; p3.pz = 0;
	q1.coeff = -7; q1.px = 6; q1.py = 3; q1.pz = 0;
	P += p1;
	P += p2;
	P += p3;
	Q += q1;
	RES += p1;
	RES += p2;
	P += Q;
	EXPECT_EQ(true, RES == P);
}