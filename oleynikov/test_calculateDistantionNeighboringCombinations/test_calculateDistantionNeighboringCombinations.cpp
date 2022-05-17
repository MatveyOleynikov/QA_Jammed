#include "pch.h"
#include "CppUnitTest.h"
#include "..\oleynikov\FUNCTIONS.H"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool equalMaps(map<vector<vector<char>>, Path>& firstMap, map<vector<vector<char>>, Path>& secondMap) {
	for (auto& i : firstMap) {
		pair< vector<vector<char>>, Path> p = i;
		if (firstMap[p.first].lengthPath != secondMap[p.first].lengthPath || firstMap[p.first].lastMoves != secondMap[p.first].lastMoves) {
			return false;
		}
	}

	return true;
}

namespace testcalculatedistantionneighboringcombinations
{
	TEST_CLASS(testcalculatedistantionneighboringcombinations)
	{
	public:

		TEST_METHOD(startingCombination)
		{
			int n = 2, m = 2;
			vector<vector<char>> currentCombination = { {'A', 'B'}, {'C', '#'} };
			map < vector<vector<char>>, Path> dist;
			Path path;
			path.lengthPath = 0;
			path.lastMoves = {};
			dist[currentCombination] = path;

			queue<vector<vector<char>>> combinations;

			map < vector<vector<char>>, Path> expectedDist = dist;

			path.lengthPath = 1;
			path.lastMoves = { Left };
			vector<vector<char>> combination = { {'A', 'B'}, { '#', 'C' } };
			expectedDist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Up };
			combination = { {'A', '#'}, { 'C', 'B' } };
			expectedDist[combination] = path;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(startingNeighborCombination)
		{
			int n = 2, m = 2;
			vector<vector<char>> currentCombination = { {'A', 'B'}, {'#', 'C'} };

			map < vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 0;
			path.lastMoves = { Left };
			vector<vector<char>> combination = { {'A', 'B'}, { 'C', '#' } };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Left };
			combination = { {'A', 'B'}, { '#', 'C' } };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Up };
			combination = { {'A', '#'}, { 'C', 'B' } };
			dist[combination] = path;

			queue<vector<vector<char>>> combinations;
			combinations.push({ {{'A', '#'}, {'C', 'B'}} });

			map < vector<vector<char>>, Path> expectedDist = dist;

			path.lengthPath = 2;
			path.lastMoves = { Up };
			combination = { {'#', 'B'}, { 'A', 'C' } };
			expectedDist[combination] = path;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(combinationBetweenStartedAndFinished)
		{
			int n = 2, m = 2;
			vector<vector<char>> currentCombination = { {'C', 'A'}, {'#', 'B'} };

			map < vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 1;
			path.lastMoves = { Left };
			vector<vector<char>> combination = { {'A', 'B'}, { '#', 'C' } };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Up };
			combination = { {'A', '#'}, { 'C', 'B' } };
			dist[combination] = path;

			path.lengthPath = 2;
			path.lastMoves = { Up };
			combination = { {'#', 'B'}, { 'A', 'C' } };
			dist[combination] = path;

			path.lengthPath = 2;
			path.lastMoves = { Left };
			combination = { {'#', 'A'}, { 'C', 'B' } };
			dist[combination] = path;

			path.lengthPath = 3;
			path.lastMoves = { Right };
			combination = { {'B', '#'}, { 'A', 'C' } };
			dist[combination] = path;

			path.lengthPath = 3;
			path.lastMoves = { Down };
			combination = { {'C', 'A'}, { '#', 'B' } };
			dist[combination] = path;

			queue<vector<vector<char>>> combinations;
			combinations.push({ {{'C', 'A'}, {'#', 'B'}} });

			map < vector<vector<char>>, Path> expectedDist = dist;

			path.lengthPath = 4;
			path.lastMoves = { Right };
			combination = { {'C', 'A'}, { 'B', '#' } };
			expectedDist[combination] = path;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(finishingNeighborCombination)
		{
			int n = 2, m = 2;
			vector<vector<char>> currentCombination = { {'C', '#'}, {'B', 'A'} };

			map < vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 0;
			path.lastMoves = {};
			vector<vector<char>> combination = { {'A', 'B'}, { 'C', '#' } };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Left };
			combination = { {'A', 'B'}, { '#', 'C' } };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Up };
			combination = { {'A', '#'}, { 'C', 'B' } };
			dist[combination] = path;

			path.lengthPath = 2;
			path.lastMoves = { Up };
			combination = { {'#', 'B'}, { 'A', 'C' } };
			dist[combination] = path;

			path.lengthPath = 2;
			path.lastMoves = { Left };
			combination = { {'#', 'A'}, { 'C', 'B' } };
			dist[combination] = path;

			path.lengthPath = 3;
			path.lastMoves = { Right };
			combination = { {'B', '#'}, { 'A', 'C' } };
			dist[combination] = path;

			path.lengthPath = 3;
			path.lastMoves = { Down };
			combination = { {'C', 'A'}, { '#', 'B' } };
			dist[combination] = path;

			path.lengthPath = 4;
			path.lastMoves = { Down };
			combination = { {'B', 'C'}, { 'A', '#' } };
			dist[combination] = path;

			path.lengthPath = 4;
			path.lastMoves = { Right };
			combination = { {'C', 'A'}, { 'B', '#' } };
			dist[combination] = path;

			path.lengthPath = 5;
			path.lastMoves = { Left };
			combination = { {'B', 'C'}, { '#', 'A' } };
			dist[combination] = path;

			path.lengthPath = 5;
			path.lastMoves = { Up };
			combination = { {'C', '#'}, { 'B', 'A' } };
			dist[combination] = path;

			path.lengthPath = 6;
			path.lastMoves = { Up };
			combination = { {'#', 'C'}, { 'B', 'A' } };
			dist[combination] = path;


			queue<vector<vector<char>>> combinations;
			combinations.push({ {{'C', '#'}, {'B', 'A'}} });

			map < vector<vector<char>>, Path> expectedDist = dist;

			expectedDist[combination].lastMoves.push_back(Left);

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(finishingCombination)
		{
			int n = 2, m = 2;
			vector<vector<char>> currentCombination = { {'#', 'C'}, {'B', 'A'} };

			map < vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 0;
			path.lastMoves = {};
			vector<vector<char>> combination = { {'A', 'B'}, { 'C', '#' } };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Left };
			combination = { {'A', 'B'}, { '#', 'C' } };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Up };
			combination = { {'A', '#'}, { 'C', 'B' } };
			dist[combination] = path;

			path.lengthPath = 2;
			path.lastMoves = { Up };
			combination = { {'#', 'B'}, { 'A', 'C' } };
			dist[combination] = path;

			path.lengthPath = 2;
			path.lastMoves = { Left };
			combination = { {'#', 'A'}, { 'C', 'B' } };
			dist[combination] = path;

			path.lengthPath = 3;
			path.lastMoves = { Right };
			combination = { {'B', '#'}, { 'A', 'C' } };
			dist[combination] = path;

			path.lengthPath = 3;
			path.lastMoves = { Down };
			combination = { {'C', 'A'}, { '#', 'B' } };
			dist[combination] = path;

			path.lengthPath = 4;
			path.lastMoves = { Down };
			combination = { {'B', 'C'}, { 'A', '#' } };
			dist[combination] = path;

			path.lengthPath = 4;
			path.lastMoves = { Right };
			combination = { {'C', 'A'}, { 'B', '#' } };
			dist[combination] = path;

			path.lengthPath = 5;
			path.lastMoves = { Left };
			combination = { {'B', 'C'}, { '#', 'A' } };
			dist[combination] = path;

			path.lengthPath = 5;
			path.lastMoves = { Up };
			combination = { {'C', '#'}, { 'B', 'A' } };
			dist[combination] = path;

			path.lengthPath = 6;
			path.lastMoves = { Left, Up };
			combination = { {'#', 'C'}, { 'B', 'A' } };
			dist[combination] = path;


			queue<vector<vector<char>>> combinations;

			map < vector<vector<char>>, Path> expectedDist = dist;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(sharpOnBorder)
		{
			int n = 2;
			int m = 4;
			vector<vector<char>> currentCombination = { {'A', 'B', 'C', 'D'}, {'E', 'F', '#', 'G'} };
			map<vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 0;
			path.lastMoves = {};

			dist[currentCombination] = path;
			queue<vector<vector<char>>> combinations;

			map < vector<vector<char>>, Path> expectedDist = dist;

			path.lengthPath = 1;
			path.lastMoves = {Right};
			vector<vector<char>> combination = { {'A', 'B', 'C', 'D'}, {'E', 'F', 'G', '#'} };
			expectedDist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Left };
			combination = { {'A', 'B', 'C', 'D'}, {'E', '#', 'F', 'G'} };
			expectedDist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Up };
			combination = { {'A', 'B', '#', 'D'}, {'E', 'F', 'C', 'G'} };
			expectedDist[combination] = path;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(sharpInCenter)
		{
			int n = 3;
			int m = 3;
			vector<vector<char>> currentCombination = { {'A', 'B', 'C'}, {'D', '#', 'E'}, {'F', 'G', 'H'} };
			map<vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 0;
			path.lastMoves = {};

			dist[currentCombination] = path;
			queue<vector<vector<char>>> combinations;

			map < vector<vector<char>>, Path> expectedDist = dist;

			path.lengthPath = 1;
			path.lastMoves = { Right };
			vector<vector<char>> combination = { {'A', 'B', 'C'}, {'D', 'E', '#'}, {'F', 'G', 'H'} };
			expectedDist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Left };
			combination = { {'A', 'B', 'C'}, {'#', 'D', 'E'}, {'F', 'G', 'H'} };
			expectedDist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Up };
			combination = { {'A', '#', 'C'}, {'D', 'B', 'E'}, {'F', 'G', 'H'} };
			expectedDist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Down };
			combination = { {'A', 'B', 'C'}, {'D', 'G', 'E'}, {'F', '#', 'H'} };
			expectedDist[combination] = path;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(size1x9)
		{
			int n = 1;
			int m = 9;
			vector<vector<char>> currentCombination = { {'A', 'B', 'C', 'D', 'E', 'F', '#', 'G', 'H'} };
			map<vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 0;
			path.lastMoves = {};

			dist[currentCombination] = path;
			queue<vector<vector<char>>> combinations;

			map < vector<vector<char>>, Path> expectedDist = dist;

			path.lengthPath = 1;
			path.lastMoves = { Right };
			vector<vector<char>> combination = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', '#', 'H'} };
			expectedDist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Left };
			combination = { {'A', 'B', 'C', 'D', 'E', '#', 'F', 'G', 'H'} };
			expectedDist[combination] = path;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(size1x1)
		{
			int n = 1;
			int m = 1;
			vector<vector<char>> currentCombination = { {'#'} };
			map<vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 0;
			path.lastMoves = {};

			dist[currentCombination] = path;
			queue<vector<vector<char>>> combinations;

			map < vector<vector<char>>, Path> expectedDist = dist;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(firstComplexTest)
		{
			int n = 1;
			int m = 9;
			vector<vector<char>> currentCombination = { {'A', 'B', 'C', 'D', 'E', 'F', '#', 'G', 'H'} };
			map<vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 0;
			path.lastMoves = {};

			dist[currentCombination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Right };
			vector<vector<char>> combination = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', '#', 'H'} };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Left };
			combination = { {'A', 'B', 'C', 'D', 'E', '#', 'F', 'G', 'H'} };
			dist[combination] = path;

			path.lengthPath = 2;
			path.lastMoves = { Right };
			combination = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '#'} };
			dist[combination] = path;

			path.lengthPath = 2;
			path.lastMoves = { Left };
			combination = { {'A', 'B', 'C', 'D', '#', 'E', 'F', 'G', 'H'} };
			dist[combination] = path;

			queue<vector<vector<char>>> combinations;

			map < vector<vector<char>>, Path> expectedDist = dist;

			currentCombination = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '#'} };

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(secondComplexTest)
		{
			int n = 2;
			int m = 4;
			vector<vector<char>> currentCombination = { {'B', '#', 'C', 'D'}, { 'E', 'A', 'F', 'G' } };
			map<vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 6;
			path.lastMoves = { Left };
			vector<vector<char>> combination = { {'B', 'A', 'C', 'D'}, { 'E', '#', 'F', 'G' } };
			dist[combination] = path;

			path.lengthPath = 6;
			path.lastMoves = { Up };
			combination = { {'B', 'C', '#', 'D'}, {'E', 'A', 'F', 'G'} };
			dist[combination] = path;

			path.lengthPath = 7;
			path.lastMoves = { Up, Left };
			combination = { {'B', '#', 'C', 'D'}, { 'E', 'A', 'F', 'G' } };
			dist[combination] = path;

			queue<vector<vector<char>>> combinations;

			map < vector<vector<char>>, Path> expectedDist = dist;

			path.lengthPath = 8;
			path.lastMoves = { Left };
			combination = { {'#', 'B', 'C', 'D'}, { 'E', 'A', 'F', 'G' } };
			expectedDist[combination] = path;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(thirdComplexTest)
		{
			int n = 3;
			int m = 3;
			vector<vector<char>> currentCombination = { {'B', '#', 'C'}, {'D', 'E', 'A'}, {'F', 'G', 'H'} };
			map<vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 6;
			path.lastMoves = { Left };
			vector<vector<char>> combination = { {'B', 'E', 'C'}, { 'D', '#', 'A' }, { 'F', 'G', 'H' } };
			dist[combination] = path;

			path.lengthPath = 6;
			path.lastMoves = { Up };
			combination = { {'B', 'C', '#'}, {'D', 'E', 'A'}, {'F', 'G', 'H'} };
			dist[combination] = path;

			path.lengthPath = 7;
			path.lastMoves = { Up, Left };
			combination = { {'B', '#', 'C'}, {'D', 'E', 'A'}, {'F', 'G', 'H'} };
			dist[combination] = path;

			queue<vector<vector<char>>> combinations;

			map < vector<vector<char>>, Path> expectedDist = dist;

			path.lengthPath = 8;
			path.lastMoves = { Left };
			combination = { {'#', 'B', 'C'}, {'D', 'E', 'A'}, {'F', 'G', 'H'} };
			expectedDist[combination] = path;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}

		TEST_METHOD(fourthComplexTest)
		{
			int n = 3;
			int m = 3;
			vector<vector<char>> currentCombination = { {'A', '#', 'C'}, {'D', 'B', 'E'}, {'F', 'G', 'H'} };
			map<vector<vector<char>>, Path> dist;
			Path path;

			path.lengthPath = 0;
			path.lastMoves = {};
			vector<vector<char>> combination = { {'A', 'B', 'C'}, { 'D', '#', 'E' }, { 'F', 'G', 'H' } };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = { Up };
			combination = { {'A', '#', 'C'}, {'D', 'B', 'E'}, {'F', 'G', 'H'} };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = {Down};
			combination = { {'A', 'B', 'C'}, { 'D', 'G', 'E' }, { 'F', '#', 'H' } };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = {Left};
			combination = { {'A', 'B', 'C'}, { '#', 'D', 'E' }, { 'F', 'G', 'H' } };
			dist[combination] = path;

			path.lengthPath = 1;
			path.lastMoves = {Right};
			combination = { {'A', 'B', 'C'}, { 'D', 'E', '#' }, { 'F', 'G', 'H' } };
			dist[combination] = path;

			queue<vector<vector<char>>> combinations;

			map < vector<vector<char>>, Path> expectedDist = dist;

			path.lengthPath = 2;
			path.lastMoves = { Left };
			combination = { {'#', 'A', 'C'}, {'D', 'B', 'E'}, {'F', 'G', 'H'} };
			expectedDist[combination] = path;

			path.lengthPath = 2;
			path.lastMoves = { Right };
			combination = { {'A', 'C', '#'}, {'D', 'B', 'E'}, {'F', 'G', 'H'} };
			expectedDist[combination] = path;

			calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);

			Assert::AreEqual(true, equalMaps(dist, expectedDist));
		}
	};
};