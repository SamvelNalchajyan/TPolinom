#include "gtest.h"
#include "../TPolinom/TPolinom.h"

TEST(TPolinom, can_create_polinomial)
{
	ASSERT_NO_THROW(TPolinom P);
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
	ASSERT_NO_THROW(P == P);
	EXPECT_EQ(true, P == P);
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

/*...................................................*/

TEST(TMonom, can_ins_monom_with_pos_coef)
{
	TMonom m;
	m.px = 0;
	m.py = 0;
	m.pz = 0;
	ASSERT_NO_THROW(m.coeff = 1);
}

TEST(TMonom, can_ins_monom_with_neg_coef)
{
	TMonom m;
	m.px = 0;
	m.py = 0;
	m.pz = 0;
	ASSERT_NO_THROW(m.coeff = -1);
}

TEST(TMonom, can_ins_monom_with_neg_step)
{
	TMonom m;
	m.px = 1;
	m.py = 1;
	m.pz = 1;
	ASSERT_NO_THROW(m.coeff = 5);
}

TEST(TMonom, can_ins_monom_with_pos_step)
{
	TMonom m;
	m.px = -1;
	m.py = -1;
	m.pz = -1;
	ASSERT_NO_THROW(m.coeff = -5);
}

TEST(TMonom, can_compare_the_monomials)
{
	TMonom m1, m2;
	m1.coeff = 5;
	m1.px = 1;
	m1.py = 1;
	m1.pz = 1;
	m2.coeff = 7;
	m2.px = 1;
	m2.py = 1;
	m2.pz = 1;
	EXPECT_EQ(m1 == m2, 1);
}

TEST(TMonom, can_ne_monoms)
{
	TMonom m1, m2;
	m1.coeff = 5;
	m1.px = 1;
	m1.py = 1;
	m1.pz = 1;
	m2.coeff = 7;
	m2.px = 1;
	m2.py = 2;
	m2.pz = 3;
	EXPECT_EQ(m1 != m2, 1);
}

TEST(TMonom, Sravnenie)
{
	TMonom m1, m2;
	m1.coeff = 5;
	m1.px = 1;
	m1.py = 1;
	m1.pz = 1;
	m2.coeff = 7;
	m2.px = 1;
	m2.py = 2;
	m2.pz = 3;
	EXPECT_EQ(m1 < m2, 1);
	EXPECT_EQ(m1 > m2, 0);
}

TEST(TPolinom, can_create_polynom)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, can_create_polynom_with_arr)
{
	int arr[2][2];
	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[0][1] = 1;
	arr[1][1] = 1;
	ASSERT_NO_THROW(TPolinom p(arr, 2));
}

TEST(TPolinom, can_copy_polynom)
{
	int arr[2][2];
	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[0][1] = 1;
	arr[1][1] = 1;
	TPolinom p(arr, 2);
	ASSERT_NO_THROW(TPolinom p_copy(p));
}

TEST(TPolinom, can_add_monom)
{
	TPolinom p;
	TMonom a;
	a.coeff = 1;
	a.px = 1;
	a.py = 1;
	a.pz = 1;
	ASSERT_NO_THROW(p += a);
	ASSERT_NO_THROW(p * 5);
	ASSERT_NO_THROW(p *= 5);
	ASSERT_NO_THROW(p * a);
	ASSERT_NO_THROW(p *= a);
}