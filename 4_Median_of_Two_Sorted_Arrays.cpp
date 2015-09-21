#include <vector>
using namespace std;


// version1:
// merge two array
// O(m+n)
double findMedianSortedArrays(vector<int> &num1, vector<int>& num2) {
	vector<int> buffer;
	vector<int>::iterator iter_1, iter_2;
	iter_1 = num1.begin();
	iter_2 = num2.begin();
	while (iter_1 != num1.end() && iter_2 != num2.end())
	{
		if (*iter_1 < *iter_2) {
			buffer.push_back(*iter_1);
			iter_1++;
		}
		else {
			buffer.push_back(*iter_2);
			iter_2++;
		}
	}
	vector<int>::iterator remind_iter, end_iter;
	remind_iter = iter_1;
	end_iter = num1.end();
	if (iter_2 != num2.end()) {
		remind_iter = iter_2;
		end_iter = num2.end();
	}
	while (remind_iter != end_iter)
	{
		buffer.push_back(*remind_iter);
		remind_iter++;
	}
	double median = buffer.size() % 2 == 1 ?
		buffer[buffer.size() / 2] :
		(buffer[buffer.size() / 2] + buffer[(buffer.size() - 1) / 2]) / 2.0;
	return median;
}


//http://blog.csdn.net/yutianzuijin/article/details/11499917/
// version2: divid into two part
// O(log(m+n))
// a[k/2-1] b[k/2-1], drop the part due to the sorted array
// 
int findKth(int *a, int la, int *b, int lb, int k) {
	if (la > lb) {
		return findKth(b, lb, a, la, k);
	}
	if (la == 0) {
		return b[k - 1];
	}
	if (k == 1) {
		return a[0] < b[0] ? a[0] : b[0];
	}
	int pa = k / 2 < la ? k / 2 : la;
	int pb = k - pa;
	if (a[pa - 1] > b[pb - 1]) {
		return findKth(a, la, b + pb, lb - pb, k - pb);
	}
	else if (a[pa - 1] < b[pb - 1]) {
		return findKth(a + pa, la - pa, b, lb, k - pa);
	}
	else {
		return a[pa - 1];
	}
}


// the version without recursion
//  looks a bit dirty;
int findKthByVector(const vector<int> &a, const vector<int> &b, int k) {
	int cur_a = 0, cur_b = 0;
	int la = a.size();
	int lb = b.size();
	if (la == 0) {
		return b[k - 1];
	}
	if (lb == 0) {
		return a[k - 1];
	}

	while (k != 1)
	{
		int pa, pb;
		if (la < lb) {
			pa = k / 2 < la ? k / 2 : la;
			pb = k - pa;
		}
		else {
			pb = k / 2 < lb ? k / 2 : lb;
			pa = k - pb;
		}

		if (a[cur_a + pa - 1] > b[cur_b + pb - 1]) {
			cur_b += pb;
			lb -= pb;
			k -= pb;
			if (cur_b == b.size()) {
				return a[cur_a + k - 1];
			}
		}
		else if (a[cur_a + pa - 1] < b[cur_b + pb - 1]) {
			cur_a += pa;
			la -= pa;
			k -= pa;
			if (cur_a == a.size()) {
				return b[cur_b + k - 1];
			}
		}
		else {
			return a[cur_a + pa - 1];
		}
	}
	return a[cur_a] < b[cur_b] ? a[cur_a] : b[cur_b];
}



double findMedian(int*a, int la, int *b, int lb) {
	int l = la + lb;
	if (l % 2 == 1) {
		return findKth(a, la, b, lb, l / 2 + 1);
	}
	else {
		return (findKth(a, la, b, lb, l / 2)
			+ findKth(a, la, b, lb, l / 2 + 1)) / 2.0;
	}
}

double findMedianByVector(vector<int>& num1, vector<int>& num2) {
	int l = num1.size() + num2.size();
	if (l % 2 == 1) {
		return findKthByVector(num1, num2, l / 2 + 1);
	}
	else {
		return  (findKthByVector(num1, num2, l / 2)
			+ findKthByVector(num1, num2, l / 2 + 1)) / 2.0;
	}
}