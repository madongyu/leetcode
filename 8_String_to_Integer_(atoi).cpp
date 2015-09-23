#include <string>
using std::string;
// how to know it is out of range ?
int myAtoi(string str) {
	long long re = 0;
	int base = 0;
	int flag = false;

	while (base < str.size() && str[base] == ' ')
	{
		base++;
	}

	if (base == str.size()) {
		return 0;
	}

	if (str[base] == '-') {
		flag = true;
		base++;
	}
	else if (str[base] == '+') {
		flag = false;
		base++;
	}
	for (int i = base; i < str.size(); i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			re = re * 10 + str[i] - '0';
			if (!flag && re > INT_MAX) {
				return INT_MAX;
			}
			if (flag && -re < INT_MIN){
				return INT_MIN;
			}
		}
		else {
			break;
		}
	}

	if (flag) {
		return -re;
	}
	else {
		return re;
	}
}