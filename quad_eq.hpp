#pragma once

#include <limits>
#include <array>

enum SolState { none, any, same, two };

struct EQStatus
{
	SolState solState;
	std::array<double, 2> solution;
};

EQStatus SolveQuadEq(std::array<double, 3>);
