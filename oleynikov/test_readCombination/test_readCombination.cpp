#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string.h>
#include <fstream>
#include <string>  
#include "pch.h"
#include "CppUnitTest.h"
#include "..\oleynikov\Functions.h"

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testreadCombination
{
	TEST_CLASS(testreadCombination)
	{
	public:
		
		TEST_METHOD(size_1x1)
		{
			int n = 1, m = 1;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\size1x1.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = {{'#'}};
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(size_1x9)
		{
			int n = 1, m = 9;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\size1x9.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'A', 'C', 'M', '8', '0', '0', '2', '#', 'C'}};
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(size_9x1)
		{
			int n = 9, m = 1;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\size9x1.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'A'}, {'C'}, {'M'}, {'8'}, {'0'}, {'0'}, {'2'}, {'#'}, {'C'} };
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(size_3x3)
		{
			int n = 3, m = 3;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\size3x3.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'A', 'C', 'M'}, {'8', '0', '0'}, {'2', '#', 'C'} };
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(size_4x2)
		{
			int n = 4, m = 2;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\size4x2.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'A', 'C'}, {'M', '8'}, {'0', '0' }, {'2', '#'} };
			vector<Error> expectedErrors;
			
			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(size_2x4)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\size2x4.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'A', 'C', 'M', '8'}, {'0', '0', '2', '#'} };
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(size_2x2)
		{
			int n = 2, m = 2;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\size2x2.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'A', 'C'}, {'0', '#'} };
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(numberSymbolsSmallerSizeCombination)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\numberSymbolsSmallerSizeCombination.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<Error> expectedErrors;
			Error error(TooFewCharacters, StartCombination);
			expectedErrors.push_back(error);
			Assert::AreEqual(true, errors == expectedErrors);
		}

		TEST_METHOD(numberSymbolsBiggerSizeCombination)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\numberSymbolsBiggerSizeCombination.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'A', 'C', 'M', '8'}, {'0', '0', '2', '#'} };
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(onlyLetters)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\onlyLetters.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'A', 'C', 'M', 'I'}, {'C', 'P', 'C', '#'} };
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(onlyDigits)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\onlyDigits.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'2', '0', '0', '8'}, {'0', '0', '9', '#'} };
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(countSharpZero)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\countSharpZero.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<Error> expectedErrors;
			Error error(SharpError, StartCombination);
			expectedErrors.push_back(error);

			Assert::AreEqual(true, errors == expectedErrors);
		}

		TEST_METHOD(countSharpBiggerOne)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\countSharpBiggerOne.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<Error> expectedErrors;
			Error error(SharpError, StartCombination);
			expectedErrors.push_back(error);

			Assert::AreEqual(true, errors == expectedErrors);
		}

		TEST_METHOD(haveInvalidSymbols)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\haveInvalidSymbols.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<Error> expectedErrors;
			Error error(WrongSymbolType, 0, 2, StartCombination);
			expectedErrors.push_back(error);

			Assert::AreEqual(true, errors == expectedErrors);
		}

		TEST_METHOD(firstComplexTest)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\firstComplexTest.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<Error> expectedErrors;
			Error error(TooFewCharacters, StartCombination);
			expectedErrors.push_back(error);

			Assert::AreEqual(true, errors == expectedErrors);
		}

		TEST_METHOD(secondComplexTest)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\secondComplexTest.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'A', 'C', '#', '8'}, {'0', '0', '2', '0'} };
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}

		TEST_METHOD(thirdComplexTest)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\thirdComplexTest.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<Error> expectedErrors;
			Error error(SharpError, StartCombination);
			expectedErrors.push_back(error);

			Assert::AreEqual(true, errors == expectedErrors);
		}

		TEST_METHOD(fourthComplexTest)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\fourthComplexTest.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<Error> expectedErrors;
			Error error1(WrongSymbolType, 0, 2, StartCombination);
			Error error2(TooFewCharacters, StartCombination);
			expectedErrors.push_back(error1);
			expectedErrors.push_back(error2);

			Assert::AreEqual(true, errors == expectedErrors);
		}

		TEST_METHOD(fifthComplexTest)
		{
			int n = 2, m = 4;
			ifstream fin;
			fin.open("..\\test_readCombination\\my_tests\\fifthComplexTest.txt");
			vector<Error> errors;
			vector<vector<char>> combination;

			readCombination(n, m, fin, errors, combination, StartCombination);

			vector<vector<char>> expectedCombination = { {'A', 'C', 'M', '8'}, {'0', '0', '2', '#'} };
			vector<Error> expectedErrors;

			Assert::AreEqual(true, expectedCombination == combination && errors == expectedErrors);
		}
	};
}
