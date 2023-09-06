#pragma once
double f(double x) { return log(pow(x, 4) + pow(x, 3)) + cos(x); }// возвращает значение f(x)
double f_pr1(double x) { return (4 * pow(x, 3) + 3 * pow(x, 2)) / (pow(x, 4) + pow(x, 3)) - sin(x); }//возвращает значение f '(x)
double f_pr2(double x) { return -cos(x) + ((6 * (2 * x + 1)) / (pow(x, 2) * (x + 1))) - ((pow((4 * x + 3), 2)) / ((pow(x, 2) * pow(x + 1, 2)))); }//возвращает значение f ''(x)
double division(double a, double b, double eps, double& iter)
{
	double i = 0;
	double x;
	do
	{
		x = (a + b) / 2;
		if (f(x) * f(a) < 0)
		{
			b = x;
		}
		else
		{
			a = x;
		}
		i++;
	} while (b - a > eps);
	iter = i;
	return x;
}

double horda(double a, double b, double eps, double& iter)
{
	double i = 0;
	double x;
	do
	{
		x = a - f(a) * (b - a) / (f(b) - f(a));
		b = x;
		i++;
	} while (abs(f(x)) > eps);
	iter = i;
	return x;
}


double newton(double a, double b, double eps, double& iter)
{
	double i = 0;
	double x = f(a) * f_pr2(a) > 0 ? a : b;
	if (f(a) * f_pr2(a) > 0)
	{
		x = a;
	}
	else if (f(b) * f_pr2(b) > 0)
	{
		x = b;
	}
	//double x= f(a) * f_pr2(a) > 0 ? a : b;
	//do
	while (abs(f(x)) > eps)
	{
		x -= (f(x)) / (f_pr1(x));
		i++;
	}
	iter = i;
	return x;
}