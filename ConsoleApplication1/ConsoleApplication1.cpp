// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

long long pow(int num, int pow) 
{
	long long D = 1;
	for (int i = 0; i < pow; ++i) {
		D = D * num;
	}
	return D;
}

static long X0 = 33;
long long m = pow(2, 31);
static long a = pow(2, 16);
static long c = 28657;

static const std::string file_name = "Sequency.txt";


int get_pseudo_rand(int n, long X0, long long m, long a, long c)
{
	int counter = 1, period = -1;
	long start, prev;
	static long Xn;
	std::ofstream out(file_name);

	if (!out.is_open())
		return -2;

	Xn = X0;
	Xn = (a * Xn + c) % m;
	start = Xn;

	for (int i = 0; i < n; ++i) {
		std::cout << Xn << " ";
		out << Xn << " ";
		prev = Xn;
		Xn = (a * Xn + c) % m;

		counter++;
		if (start == Xn || prev == Xn) {
			period = counter;
			out << Xn << std::endl;
			std::cout << Xn << std::endl;

			out.close();
			return period;
		}
	}
	out << Xn << std::endl;
	std::cout << Xn << std::endl;

	out.close();
	return period;
}

int main()
{
	int count, period = 0;
	char c;

	std::cout << "Input a count of number in sequency : ";
	std::cin >> count;
	std::cout << "Do you want to input new values? else to continue with default constants. Type [y/n]: ";
	std::cin >> c;
	if (c == 'y') {
		long m_num, m_pow, m_minus, a_num, a_pow;
		std::cout << "Input m_num, m_pow, m_minus, a_num, a_pow, c, X0: ";
		std::cin >> m_num >> m_pow >> m_minus >> a_num >> a_pow >> c >> X0;


		m = pow(m_num, m_pow) + m_minus;
		a = pow(a_num, a_pow);
		period = get_pseudo_rand(count, X0, m, a, c);
	}
	else if (c == 'n')
		period = get_pseudo_rand(count, X0, m, a, c);
	else
		return 0;

	if (period > 0)
		std::cout << "Period of sequency: " << period << std::endl;
	else
		std::cout << "Cant reach end of the period" << std::endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
