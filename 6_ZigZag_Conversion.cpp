#include <string>
using std::string;
string convert(string s, int numRows) {
	if (s.size() <= numRows) {
		return s;
	}
	if (numRows == 1) {
		return s;
	}
	int iter = 0;

	int cube_per_pattern = (numRows - 1) * 2;
	int num_of_pattern = s.size() / cube_per_pattern + 1;

	int max_width = num_of_pattern * (numRows - 1);



	char** buffer = new char*[numRows];
	for (int i = 0; i < numRows; i++) {
		buffer[i] = new char[max_width];
		for (int j = 0; j < max_width; j++) {
			buffer[i][j] = 0;
		}
	}

	int k = 0;
	for (k = 0; iter < s.size(); k++) {
		for (int i = 0; i < numRows && iter <s.size(); i++) {
			buffer[i][k] = s[iter++];
		}
		for (int i = numRows - 2; i >= 1 && iter < s.size(); i--) {
			k++;
			buffer[i][k] = s[iter++];
		}
	}
	string re = "";

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < k; j++) {
			if (buffer[i][j]) {
				re += buffer[i][j];
			}
		}
	}
	for (int i = 0; i < numRows; i++) {
		delete buffer[i];
	}
	return re;
}