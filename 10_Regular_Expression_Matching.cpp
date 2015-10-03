// if you have idea use dp to solove it 
// please share me :
// 391393515@qq.com
bool isMatch(const char *s, const char *p) {
	if (*p == '\0') {
		return (*s) == '\0';
	}
	if (*(p + 1) == '*') {
		while ((*p) == (*s) || (*p == '.' && *s != '\0'))
		{
			if (isMatch(s, p + 2)) {
				return true;
			}
			s++;
		}
		return isMatch(s, p + 2);

	}
	else {
		return (*p == *s || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
	}
}