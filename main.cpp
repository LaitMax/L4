#include <iostream>
#include <cmath>
#include "Header.h"

using namespace std;
double iter;
double a = 0.1, b = 1.4, eps = 0.00001;//Input data
int main()
{
	cout << "\nThe root of the equation f(x)==0 is equal to:\n";
	cout << "By the method of half division:\t" << division(a, b, eps, iter) << '\t' << iter << '\n';
	if (f(a) * f_pr2(a) > 0)
	{
		cout << "By the method of secant (chords):\t" << horda(a, b, eps, iter) << '\t' << iter << '\n';
	}
	else
	{
		cout << "By the method of secant (chords)\t" << horda(b, a, eps, iter) << '\t' << iter << '\n';
	}
	cout << "Newton 's method:\t" << newton(a, b, eps, iter) << '\t' << iter << '\n';

	//	cout << "f(x)" << f(0.75) << '\t' << "f(a)" << f(0.1) << '\t' << "f(x) * f(a)" << f(0.75) * f(0.1) << '\t' << "b - a" << 0.75 - 0.1;
}