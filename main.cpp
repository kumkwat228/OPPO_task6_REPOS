#include <iostream>
using namespace std;

double my_pow(double a, unsigned int n)
{
	double ch = a;

	for (unsigned int i = 0; i < n - 1; i++)
		a *= ch;

	return a;
}

double BinaryPower(double b, unsigned long long e) {
	double v = 1.0;
	while (e != 0) {
		if ((e & 1) != 0) {
			v *= b;
		}
		b *= b;
		e >>= 1;
	}
	return v;
}

double OldApproximatePower(double b, double e) {
	union {
		double d;
		long long i;
	} u = { b };
	u.i = (long long)(4606853616395542500L + e * (u.i - 4606853616395542500L));
	return u.d;
}
double FastPowerDividing(double b, double e) {
	if (b == 1.0 || e == 0.0) {
		return 1.0;
	}

	double eAbs = fabs(e);
	double el = ceil(eAbs);
	double basePart = OldApproximatePower(b, eAbs / el);
	double result = BinaryPower(basePart, (unsigned long long)el);

	if (e < 0.0) {
		return 1.0 / result;
	}
	return result;
}

double FastPowerFractional(double b, double e) {
	if (b == 1.0 || e == 0.0) {
		return 1.0;
	}

	double absExp = fabs(e);
	unsigned long long eIntPart = (long long)absExp;
	double eFractPart = absExp - eIntPart;
	double result = OldApproximatePower(b, eFractPart) * BinaryPower(b, eIntPart);
	if (e < 0.0) {
		return 1.0 / result;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int a;
	unsigned int n;
	cout << "Ввод числа: \n";

	while (cin >> a)
	{
		cout << "Ввод степени: \n";
		cin >> n;
		cout << endl << my_pow(a, n) << endl;
		cout << endl << BinaryPower(a, n) << endl;
		cout << endl << FastPowerDividing(a, n) << endl;
		cout << endl << FastPowerFractional(a, n) << endl;
		cout << "Ввод числа: \n";
	}
	return 0;
}

