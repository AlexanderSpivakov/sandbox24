#pragma once

#include <limits>
#include <array>

enum SolState { none, any, same, two };

struct EQStatus
{
	SolState solState;
	std::array<double, 2> solution;

	bool operator==(const EQStatus& other) const
	{
		if ((solState == other.solState) && (solution[0] == other.solution[0]) && (solution[1] == other.solution[1]))
			return true;
		else
			return false;
	}
};

//bool operator==(EQStatus const& r, EQStatus const& l) const
//{
//	return (r.solState == l.solState) && (r.solution[0] == l.solution[0]) && (r.solution[1] == l.solution[1]);
//}

EQStatus SolveQuadEq(std::array<double, 3>);
