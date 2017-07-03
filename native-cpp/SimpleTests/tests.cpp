#include <vector>
#include <algorithm>
#include <iostream>
#include <ppl.h>

void CompareExpressions(void)
{
	std::cout << std::endl << "CompareExpressions()" << std::endl;
	std::vector<int> v1 = { 1, 2, 3, 4, 5 };

	// Print the content of a vector using a loop. The most traditional way.
	for (auto it = v1.cbegin(); it != v1.cend(); ++it)
		std::cout << *it;
	std::cout << std::endl;

	// Print the content of a vector using a ranged loop. C++11 way.
	for (auto &n : v1)
		std::cout << n;
	std::cout << std::endl;

	// Print the content of a vector using an algorithm function and a lambda expression.
	std::for_each(v1.cbegin(), v1.cend(), [](const int &n) { std::cout << n; });
	std::cout << std::endl;

	// Declare and define an anonymous function (with a name) as a lambda expression.
	auto AddTwo = [] (int a, int b) { return a + b; };
	std::cout << 2 << '+' << 3 << '=' << AddTwo(2, 3) << std::endl;

	// Following expression won't compile. NOT sure why ???
	//int AddTwo_2 = [](int a, int b) { return a + b; };

	// Find the iterator of the first even value.
	// The lambda expression returns bool data type, and std::find_if() stops when the function object returns true.
	// Single return does not requires '-> return type', which is '[](const int &n) -> bool' here.
	const std::vector<int>::const_iterator it = std::find_if(v1.cbegin(), v1.cend(),
		[](const int &n) { return (n % 2) == 0; });
	if (it != v1.cend())
		std::cout << "First even value = " << *it << std::endl;
	else
		std::cout << "There is no even value." << std::endl;
}

void TestAccessExternalVariables(void)
{
	std::cout << std::endl << "TestAccessExternalVariables()" << std::endl;
	std::vector<int> v1(5), v2(5), v3(5), v4(5), v5(5), v6(5), v7(5);
	int value1(1), value2(2), value3(3), value4(4), value5(5), value6(6), value7(7), value8(8);

	// Assign the content of a vector using an algorithm function, and a lambda expression.
	// Can NOT access any (local) external variable.
	std::generate(v1.begin(), v1.end(), []() { return 0; });						// {0, 0, 0, 0, 0}

	// Print the content.
	std::for_each(v1.cbegin(), v1.cend(), [](const int &n) { std::cout << n; });
	std::cout << std::endl;
	
	// Assign the content of a vector using an algorithm function, and a lambda expression.
	// Capture any (local) external variable as a value, but it is NOT modifiable.
	std::generate(v2.begin(), v2.end(), [=]() { int a = value1; return value2; });	// {2, 2, 2, 2, 2}

	// Print the content.
	std::for_each(v2.cbegin(), v2.cend(), [](const int &n) { std::cout << n; });
	std::cout << std::endl;

	// Assign the content of a vector using an algorithm function, and a lambda expression.
	// Capture only a specific (local) external variable as a value, but it is NOT modifiable.
	std::generate(v3.begin(), v3.end(),
		[value3]()
	{
		//int a = value2;
		return value3;
	});				// {3, 3, 3, 3, 3}

	// Print the content.
	std::for_each(v3.cbegin(), v3.cend(), [](const int &n) { std::cout << n; });
	std::cout << std::endl;

	// Assign the content of a vector using an algorithm function, and a lambda expression.
	// Can access any (local) external variable as a value, but it IS modifiable as the lambda expression is declared as mutable.
	// Q. Then, how is mutable different from using references?
	std::generate(v4.begin(), v4.end(), [=]() mutable
	{
		++value4;
		return ++value5;
	});		// {6, 7, 8, 9, 10}

	// Print the content.
	// The referred external variables are NOT modified because they were copied by value. 
	std::for_each(v4.cbegin(), v4.cend(), [](const int &n) { std::cout << n; });
	std::cout << std::endl << value4 << ',' << value5 << std::endl;					// 4, 5

	// Assign the content of a vector using an algorithm function, and a lambda expression.
	// Can access any (local) external variable as a reference, and it IS modifiable.
	std::generate(v5.begin(), v5.end(), [&]()	
	{
		++value6;
		return ++value7;
	});		// {8, 9, 10, 11, 12}

	// Print the content.
	// The referred external variables ARE modified because they were copied by value. 
	std::for_each(v5.cbegin(), v5.cend(), [](const int &n) { std::cout << n; });
	std::cout << std::endl << value6 << ',' << value7 << std::endl;							// 11, 12

	// Assign the content of a vector using an algorithm function, and a lambda expression.
	// Capture only a specific (local) external variable as a reference, and it IS modifiable.
	std::generate(v6.begin(), v6.end(),
		[&value8]() {
		//++value7;;
		return ++value8; });			// {9, 10, 11, 12, 13}
	
	// Print the content.
	std::for_each(v6.cbegin(), v6.cend(), [](const int &n) { std::cout << n; });
	std::cout << std::endl << value8 << std::endl;												// 13

	// Read the content of a vector, do something, and update the content to a new vector.
	std::transform(v6.cbegin(), v6.cend(), v7.begin(), [](const int &n) { return n + 1; });		// v6 + 1
	std::for_each(v7.cbegin(), v7.cend(), [](const int &n) {std::cout << n; });
	std::cout << std::endl;
}

void TestPPL(void)
{
	std::vector<int> v1(5);
	int src_1(1);
	std::vector<int> v_src_1 = { 1, 2, 3, 4, 5 };
	std::vector<int> v_dst_1(5), v_dst_2(5);

	std::cout << std::endl << "TestPPL()" << std::endl;

	// Assign the content of a vector with a serial algorithm function and a lambda expression.
	// Capture only a specific (local) external value as a value, so it can be used as an input but it is not modifiable.
	std::generate(v_dst_1.begin(), v_dst_1.end(), [src_1]() { return src_1; });

	// Print the content of a vector with a serial algorithm function and a lambda expression.
	std::for_each(v_dst_1.cbegin(), v_dst_1.cend(), [](const int &n) { std::cout << n; });	// {1, 1, 1, 1, 1}
	std::cout << std::endl;

	// Read the content of a vector with a parallel algorithm function, do something, and update the content to a new vector.
	concurrency::parallel_transform(v_src_1.cbegin(), v_src_1.cend(), v_dst_2.begin(), [](const int &n) { return n + 1; });
	std::for_each(v_dst_2.cbegin(), v_dst_2.cend(), [](const int &n) { std::cout << n; });	// {2, 3, 4, 5, 6}
	std::cout << std::endl;
}

int main(void)
{
	CompareExpressions();
	TestAccessExternalVariables();
	TestPPL();
}