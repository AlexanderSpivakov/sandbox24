#pragma once
#include <limits>
#include <array>

#ifdef _WIN32
	#define QUAD_EQ_EXPORT __declspec(dllexport)
	#define STDCALL
#else
	#define QUAD_EQ_EXPORT
	#define STDCALL
#endif

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

extern "C" QUAD_EQ_EXPORT
EQStatus STDCALL SolveQuadEq(std::array<double, 3>);
