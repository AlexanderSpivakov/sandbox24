#include <gtest/gtest.h>
#include "quad_eq.hpp"

TEST(QuadEquationTests, TwoSolutions)
{
	std::array<double, 3> input = { 1.0, -7.0, 6.0 };
	EQStatus equationStatus = SolveQuadEq(input);

	EQStatus expectedStatus = { two, {6.0, 1.0} };

	bool res = equationStatus == expectedStatus;

	EXPECT_EQ(equationStatus, expectedStatus);
}

TEST(QuadEquationTests, OneSolution)
{
	std::array<double, 3> input = { 2.0, -8.0, 8.0 };
	EQStatus equationStatus = SolveQuadEq(input);

	EQStatus expectedStatus = { same, {-2.0, -2.0} };

	EXPECT_EQ(equationStatus, expectedStatus);
}

TEST(QuadEquationTests, QuadEquationNoSolutions)
{
	std::array<double, 3> input = { 3.0, 2.0, 6.0 };
	EQStatus equationStatus = SolveQuadEq(input);

	EQStatus expectedStatus = { none, {0.0, 0.0} };

	EXPECT_EQ(equationStatus, expectedStatus);
}

TEST(QuadEquationTests, AnySolution)
{
	std::array<double, 3> input = { 0.0, 0.0, 0.0 };
	EQStatus equationStatus = SolveQuadEq(input);

	EQStatus expectedStatus = { any, {0.0, 0.0} };

	EXPECT_EQ(equationStatus, expectedStatus);
}

TEST(QuadEquationTests, ZeroABNoSolutions)
{
	std::array<double, 3> input = { 0.0, 0.0, 6.0 };
	EQStatus equationStatus = SolveQuadEq(input);

	EQStatus expectedStatus = { none, {0.0, 0.0} };

	EXPECT_EQ(equationStatus, expectedStatus);
}

TEST(QuadEquationTests, ZeroACSolution)
{
	std::array<double, 3> input = { 0.0, -7.0, 0.0 };
	EQStatus equationStatus = SolveQuadEq(input);

	EQStatus expectedStatus = { same, {0.0, 0.0} };

	EXPECT_EQ(equationStatus, expectedStatus);
}

TEST(QuadEquationTests, LinearEquationSolution)
{
	std::array<double, 3> input = { 0.0, 2.0, -6.0 };
	EQStatus equationStatus = SolveQuadEq(input);

	EQStatus expectedStatus = { same, {3.0, 3.0} };

	EXPECT_EQ(equationStatus, expectedStatus);
}