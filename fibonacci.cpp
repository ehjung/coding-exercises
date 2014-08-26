#include <iostream>
#include <vector>
using namespace std;

// this is O(2^n)
int fibonacciRecurse (int n) {
	if (n == 0 || n == 1) return n;
	else return fibonacciRecurse(n - 1) + fibonacciRecurse (n - 2);
}

// this is O(n)
int fibonacci (int n) {
	int prevNum1 = 0;
	int prevNum2 = 1;
	int currentNum;
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		for (int i = 2; i <= n ; i++) {
			currentNum = prevNum1 + prevNum2;
			prevNum1 = prevNum2;
			prevNum2 = currentNum;
		}
		return currentNum;
	}
}

// but both of the above functions have to recalcuate every time the function is called
// some alternatives:
// can make a dynamic array or vector to store the values with each calculation, then 
// with random access, we could jump to whichever array element we needed
int fibonacciStore (int n, vector<int>* fibonacciSeries) {
	if (n - 1 <= fibonacciSeries->size()) {
		return fibonacciSeries->at(n-1);
	} else {
		for (int i = fibonacciSeries->size(); i <= n ; i++) {
			int num = fibonacciSeries->at(i - 1) + fibonacciSeries->at(i - 2);
			fibonacciSeries->push_back(num);
		}
		return fibonacciSeries->at(n);
	}
}

int main() {
	vector<int> fibonacciSeries;
	fibonacciSeries.push_back(0);
	fibonacciSeries.push_back(1);
	
	//some radom shit
	vector< vector<int> > testVector;
	vector <int> temp1;
	vector <int> temp2;
	temp1.push_back(1);
	temp2.push_back(2);
	testVector.push_back(temp1);
	testVector.push_back(temp2);

	// just testing to see that 20 works for all 3 methods of fibonacci implementation
	int num1 = fibonacciRecurse(20);
	int num2 = fibonacci(20);
	int num3 = fibonacciStore(20, &fibonacciSeries);
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
	return 0;
}
