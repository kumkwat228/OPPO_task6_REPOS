#include <iostream>
using namespace std;

double my_pow(double a, unsigned int n)
{
	double ch = a;

	for (unsigned int i = 0; i < n-1; i++)
		a *= ch;

	return a;
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
		cout << "Ввод числа: \n";
	}
	return 0;
}

