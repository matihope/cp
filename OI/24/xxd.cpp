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
	int new_base; 
	cin >> new_base;

	string custom_base_num;
	cin >> custom_base_num;


	cout << base2dec(custom_base_num, new_base) << endl;

	return 0;
}