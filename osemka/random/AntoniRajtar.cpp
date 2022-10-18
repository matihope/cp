#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){

        long long a;
        cin >> a;
        if (a < 10)
        {
            cout << a << endl;
        }
        else
        {
            long long k = 9, l = 9;
            int i = 1;
            while (a > k)
            {
                l *= 10;
                i++;
                k += l * i;
            }
            l *= i;
            k = k - l;
            a = a - k;
            long long m = a;
            m = m / i;
            if (a % i == 0)
            {
                m--;
                cout << m % 10 << endl;
            }
            else
            {
                long long z1, z = 1;
                for (int o = 1; o < i; o++)
                {
                    z = z * 10;
                }
                z1 = z + m;
                for (int r = 0; r < a % i - 1; r++)
                {
                    z = z / 10;
                }
                z1 = z1 / z;
                cout << z1 % 10 << endl;
            }
        }
    }

    return 0;
}
