typedef unsigned long long ull;

#include <iostream>
#include <cmath>

using namespace std;


int base2dec(string number, ull base){
	ull num = pow(base, number.length()-1) * (number[0] - (number[0] >= 'A' ? 'A'-10 : '0'));
	if (number.length() == 1)
		return num;
	
	return num + base2dec(number.substr(1), base); 
}

string dec2base(ull dec, ull p, ull base){
	if (p <= 0) return "";
	return char((dec / p) <= 9 ? '0' + (dec / p) : 'A' + (dec / p) - 10) + dec2base(dec % p, p/base, base);
}

int main()
{
	ull dec, base;
	cin >> base >> dec;

	ull p = 1;
	while(p*base <= dec)
		p *= base;

	cout << dec2base(dec, p, base) << endl;

	return 0;
}