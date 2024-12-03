#pragma once

#include <limits>
#include <array>
#include <Windows.h>

enum SolState { none, any, same, two };

struct EQStatus
{
	SolState solState;
	std::array<double, 2> solution;

	bool operator==(const EQStatus& other) const
	{
		return (solState == other.solState) && (solution[0] == other.solution[0]) && (solution[1] == other.solution[1]);
	}
};

extern "C" __declspec(dllexport)
EQStatus __stdcall SolveQuadEq(std::array<double, 3>);
