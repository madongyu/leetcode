bool isPalindrome(int x) {
	int length = 0;
	int base = 1;
	int y = x;
	while (y)
	{
		length++;
		y = y / 10;
		if (y == 0) {
			break;
		}
		base *= 10;
	}
	while (base)
	{
		int left = x / base;
		int right = x % 10;
		if (left != right) {
			return false;
		}
		x = (x - left*base - right) / 10;
		base /= 100;
	}
	return true;
}