#include "pch.h"
#include "CppUnitTest.h"
#include "..\oleynikov\FUNCTIONS.H"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testgetNeighboringCombination
{
	TEST_CLASS(testgetNeighboringCombination)
	{
	public:
		
		TEST_METHOD(up)
		{
			int n = 2, m = 2;
			vector<vector<char>> currentCombination = { {'A', 'B'}, {'C', '#'} };
			Direction direction = Down;
			vector<vector<char>> nextCombination = getNeighboringCombination(n, m, currentCombination, direction);

			const vector<vector<char>> expectedNextCombination = { {'A', '#'}, {'C', 'B'} };

			Assert::AreEqual(true, expectedNextCombination == nextCombination);
		}

		TEST_METHOD(down)
		{
			int n = 2, m = 2;
			const vector<vector<char>> currentCombination = { {'A', '#'}, {'C', 'B'} };
			Direction direction = Up;
			vector<vector<char>> nextCombination = getNeighboringCombination(n, m, currentCombination, direction);

			const vector<vector<char>> expectedNextCombination = { {'A', 'B'}, {'C', '#'} };

			Assert::AreEqual(true, expectedNextCombination == nextCombination);
		}

		TEST_METHOD(left)
		{
			int n = 2, m = 2;
			const vector<vector<char>> currentCombination = { {'A', 'B'}, {'C', '#'} };
			Direction direction = Right;
			vector<vector<char>> nextCombination = getNeighboringCombination(n, m, currentCombination, direction);


			const vector<vector<char>> expectedNextCombination = { {'A', 'B'}, {'#', 'C'} };

			Assert::AreEqual(true, expectedNextCombination == nextCombination);
		}

		TEST_METHOD(right)
		{
			int n = 2, m = 2;
			const vector<vector<char>> currentCombination = { {'A', 'B'}, {'#', 'C'} };
			Direction direction = Left;
			vector<vector<char>> nextCombination = getNeighboringCombination(n, m, currentCombination, direction);

			const vector<vector<char>> expectedNextCombination = { {'A', 'B'}, {'C', '#'} };

			Assert::AreEqual(true, expectedNextCombination == nextCombination);
		}

		TEST_METHOD(size3x3)
		{
			int n = 3, m = 3;
			const vector<vector<char>> currentCombination = { {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', '#'} };
			Direction direction = Down;
			vector<vector<char>> nextCombination = getNeighboringCombination(n, m, currentCombination, direction);


			const vector<vector<char>> expectedNextCombination = { {'A', 'B', 'C'}, {'D', 'E', '#'}, {'G', 'H', 'F'} };

			Assert::AreEqual(true, expectedNextCombination == nextCombination);
		}

		TEST_METHOD(size2x4)
		{
			int n = 2, m = 4;
			const vector<vector<char>> currentCombination = { {'A', 'B', 'C', 'D'}, {'E', 'F', 'G', '#'} };
			Direction direction = Down;
			vector<vector<char>> nextCombination = getNeighboringCombination(n, m, currentCombination, direction);

			const vector<vector<char>> expectedNextCombination = { {'A', 'B', 'C', '#'}, {'E', 'F', 'G', 'D'} };

			Assert::AreEqual(true, expectedNextCombination == nextCombination);
		}

		TEST_METHOD(size1x9)
		{
			int n = 1, m = 9;
			const vector<vector<char>> currentCombination = { { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '#' } };
			Direction direction = Right;
			vector<vector<char>> nextCombination = getNeighboringCombination(n, m, currentCombination, direction);

			const vector<vector<char>> expectedNextCombination = { { 'A', 'B', 'C', 'D', 'E', 'F', 'G', '#', 'H' } };

			Assert::AreEqual(true, expectedNextCombination == nextCombination);
		}

		TEST_METHOD(sharpOnBorder)
		{
			int n = 3, m = 3;
			const vector<vector<char>> currentCombination = { {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', '#', 'H'} };
			Direction direction = Down;
			vector<vector<char>> nextCombination = getNeighboringCombination(n, m, currentCombination, direction);

			const vector<vector<char>> expectedNextCombination = { {'A', 'B', 'C'}, {'D', '#', 'F'}, {'G', 'E', 'H'} };

			Assert::AreEqual(true, expectedNextCombination == nextCombination);
		}

		TEST_METHOD(sharpInCenter)
		{
			int n = 3, m = 3;
			const vector<vector<char>> currentCombination = { {'A', 'B', 'C'}, {'D', '#', 'E'}, {'G', 'H', 'F'} };
			Direction direction = Down;
			vector<vector<char>> nextCombination = getNeighboringCombination(n, m, currentCombination, direction);

			const vector<vector<char>> expectedNextCombination = { {'A', '#', 'C'}, {'D', 'B', 'E'}, {'G', 'H', 'F'} };

			Assert::AreEqual(true, expectedNextCombination == nextCombination);
		}
	};
}
