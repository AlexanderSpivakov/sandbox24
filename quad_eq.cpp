#include <math.h>
#include <iostream>

#include "quad_eq.hpp"

 std::pair<double, double> SolveQuadEq(double a, double b, double c)
{
	//Дискриминант
	const double d = (b * b) - (4 * a * c);
	const double root = sqrt(d);

	std::pair<double, double> result;

	if (d > 0.)
	{
		const double x1 = (-b + root) / (2 * a);
		const double x2 = (-b - root) / (2 * a);

		return result = {x1, x2};
	}
	else if (std::fabs(d - 0.0) < std::numeric_limits<double>::epsilon())
	{
		const double x = -b / (2 * a);

		return result = {x, x};
	}
	else
	{
		return result = {INFINITY, INFINITY};
	}
}