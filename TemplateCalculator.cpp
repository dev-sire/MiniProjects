#include <iostream> 
using namespace std;

template <typename T> class Calculator { 
	public: 
		T add(T num1, T num2){ 
			return num1 + num2; 
		} 
		T subtract(T num1, T num2){ 
			return abs(num1 - num2);
		} 
		T multiply(T num1, T num2){ 
			return num1 * num2;
		} 
		T divide(T num1, T num2) { 
			if (num2 == 0){ 
				throw "Divisible by zero not possible"; 
				return 0; 
			} 
			return num1 / num2; 
		} 
		T modulus(T num1, T num2){ 
			if (num2 == 0){ 
				throw "Divisible by zero not possible"; 
				return 0; 
			} 
			return num1 % num2; 
		} 
};

int main(){ 
	Calculator<int> calculator; 
	int a,b; 
	cin >> a; 
	cin >> b; 
	cout << "Sum: " << calculator.add(a,b) << endl; 
	cout << "Subtract: " << calculator.subtract(a,b) << endl; 
	cout << "Multiply: " << calculator.multiply(a,b) << endl; 
	try { 
		cout << "Divide: " << calculator.divide(a, b) << endl; 
	} 
	catch (const char *e){ 
		cerr << e << endl;
	} 
	try{ 
		cout << "Modulus: " << calculator.modulus(a,b) << endl; 
	} 
	catch (const char *e){ 
		cerr << e << endl;
	} 
	return 0; 
}