#include "pch.h"
#include "CppUnitTest.h"
#include "..\oleynikov\FUNCTIONS.H"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testgetmoves
{
	TEST_CLASS(testgetmoves)
	{
	public:

		TEST_METHOD(case1)
		{
			int n = 1, m = 1, i = 0, j = 0;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case2)
		{
			int n = 2, m = 1, i = 1, j = 0;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(upMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case3)
		{
			int n = 3, m = 1, i = 0, j = 0;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(downMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case4)
		{
			int n = 3, m = 1, i = 1, j = 0;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(downMove);
			expectedMoves.push_back(upMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case5)
		{
			int n = 1, m = 3, i = 0, j = 0;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(rightMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case6)
		{
			int n = 2, m = 3, i = 1, j = 0;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(upMove);
			expectedMoves.push_back(rightMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case7)
		{
			int n = 3, m = 3, i = 0, j = 0;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(downMove);
			expectedMoves.push_back(rightMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case8)
		{
			int n = 3, m = 3, i = 1, j = 0;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(downMove);
			expectedMoves.push_back(upMove);
			expectedMoves.push_back(rightMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case9)
		{
			int n = 1, m = 3, i = 0, j = 2;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(leftMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case10)
		{
			int n = 2, m = 3, i = 1, j = 2;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(upMove);
			expectedMoves.push_back(leftMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case11)
		{
			int n = 3, m = 3, i = 0, j = 2;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(downMove);
			expectedMoves.push_back(leftMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case12)
		{
			int n = 3, m = 3, i = 1, j = 2;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(downMove);
			expectedMoves.push_back(upMove);
			expectedMoves.push_back(leftMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case13)
		{
			int n = 1, m = 3, i = 0, j = 1;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(rightMove);
			expectedMoves.push_back(leftMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case14)
		{
			int n = 2, m = 3, i = 1, j = 1;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(upMove);
			expectedMoves.push_back(rightMove);
			expectedMoves.push_back(leftMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case15)
		{
			int n = 3, m = 3, i = 0, j = 1;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(downMove);
			expectedMoves.push_back(rightMove);
			expectedMoves.push_back(leftMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}

		TEST_METHOD(case16)
		{
			int n = 3, m = 3, i = 1, j = 1;
			vector<Move> moves = getMoves(n, m, i, j);

			vector<Move> expectedMoves;
			Move downMove(Down, i + 1, j);
			Move upMove(Up, i - 1, j);
			Move rightMove(Right, i, j + 1);
			Move leftMove(Left, i, j - 1);
			expectedMoves.push_back(downMove);
			expectedMoves.push_back(upMove);
			expectedMoves.push_back(rightMove);
			expectedMoves.push_back(leftMove);

			Assert::AreEqual(true, expectedMoves == moves);
		}
	};
};