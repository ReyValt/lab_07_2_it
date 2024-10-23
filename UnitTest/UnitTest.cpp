#include "pch.h"
#include "CppUnitTest.h"
#include "../pr_07_2_it/pr_07_2_it.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCreate)
		{
			const int k = 3;
			const int n = 4;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			Create(a, k, n, 1, 10);
			for (int i = 0; i < k; i++) {
				for (int j = 0; j < n; j++) {
					Assert::IsTrue(a[i][j] >= 1 && a[i][j] <= 10);
				}
			}

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSearchMinOfMax)
		{
			const int k = 4; 
			const int n = 3;

			int** a = new int* [k];
			for (int i = 0; i < k; i++) {
				a[i] = new int[n];
			}

			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; 
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 6; 
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9; 
			a[3][0] = 10; a[3][1] = 11; a[3][2] = 12; 

			int minMax;
			bool found = SearchMinOfMax(a, k, n, minMax);

			Assert::IsTrue(found); 
			Assert::AreEqual(3, minMax); 

			for (int i = 0; i < k; i++) {
				delete[] a[i];
			}
			delete[] a;
		}

	};
}
