#include <iostream>
using namespace std;

double my_pow(double a, int n)
{
    double ch = a;

    if (n < 0)
        while ((n - 1) != 0)
        {
            a /= ch;
            n++;
        }
    else
        if (n > 0)
            while ((n - 1) != 0)
            {
                a *= ch;
                n--;
            }
        else a = 1;



    return a;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int a;
    int n;
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

