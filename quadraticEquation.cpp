#include <stdio.h>
#include <iostream>
#include <cmath>

int quadraticEquation(double a, double b, double c){
	
	const double d = b*b-4*a*c;
	const double root = sqrt(d);
	const double t = 2*a;
	
	if (t==0.0){
	        	cout << "Ошибка, деление на 0";
	        	return 1;
		};
	if (d>0.0){
			const double x1 = ((-b) + root) / t;
			const double x2 = ((-b) - root) / t;
			cout << "x1 =" << x1 << "\n";
			cout << "x2 =" << x2 << "\n";
		};

	if (d==0.0){
			const double x1 = -(b/t);
			cout << "x1 = x2 = " << x1 << "\n";
		};

	if (d<0.0){
			cout << "D<0, корней не существует";
		};

	return 0;
}