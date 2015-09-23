#include <iostream>
// care for the out of range input
// use long long 
int reverse(int in) {
	bool neg = false;
	long long x = in;
	if (x < 0) {
		neg = true;
		x = -x;
	}
	long long re = 0;
	while (x) {
		re = re * 10 + x % 10;
		if (re > INT_MAX) {
			return 0;
		}
		else if (-re < INT_MIN) {
			return 0;
		}
		x = x / 10;
	}
	if (neg) {
		return -re;
	}
	else {
		return re;
	}
}


