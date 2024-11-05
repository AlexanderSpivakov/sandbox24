#include <math.h>
#include <iostream>

#include "quad_eq.hpp"

 EQStatus SolveQuadEq(std::array<double, 3> input)
{
	 EQStatus equationStatus{ none, (0, 0) };
	 const double a = input[0], b = input[1], c = input[2];

	if (std::fabs(a - 0.0) < std::numeric_limits<double>::epsilon())
	{
		if (std::fabs(b - 0.0) < std::numeric_limits<double>::epsilon())
			if (std::fabs(c - 0.0) < std::numeric_limits<double>::epsilon())
				equationStatus.solState = any;
			else
				equationStatus.solState = none;
		else
		{
			if (std::fabs(c - 0.0) < std::numeric_limits<double>::epsilon())
			{
				equationStatus.solState = same;
				equationStatus.solution[0] = equationStatus.solution[1] = 0;
			}
			else
			{
				const double x = -c / b;
				equationStatus.solState = same;
				equationStatus.solution[0] = equationStatus.solution[1] = x;
			}
		}

		return equationStatus;
	}

	// Дискриминант
	const double d = (b * b) - (4.0 * a * c);

	if (d > 0.0)
	{
		const double root = sqrt(d);
		const double x1 = (-b + root) / (2.0 * a);
		const double x2 = (-b - root) / (2.0 * a);

		equationStatus.solState = two;
		equationStatus.solution[0] = x1;
		equationStatus.solution[1] = x2;
	}
	else if (std::fabs(d - 0.0) < std::numeric_limits<double>::epsilon())
	{
		const double x = -b / (2.0 * a);

		equationStatus.solState = same;
		equationStatus.solution[0] = equationStatus.solution[1] = x;
	}

	return equationStatus;
}
