#include "pch.h"
#include "CppUnitTest.h"
#include "..\oleynikov\FUNCTIONS.H"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testgeneratePathes
{
	TEST_CLASS(testgeneratePathes)
	{
	public:
        TEST_METHOD(startCombination)
        {
            int n = 2, m = 2;

            vector<vector<char>> currentCombination = { {'A', 'B'}, {'C', '#'} };

            map<vector<vector<char>>, Path> dist;

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

            stack<Direction> pathToCurrentCombination;

            vector<stack<Direction>> directionsPathes;

            generatePathes(n, m, currentCombination, dist, pathToCurrentCombination, directionsPathes);

            vector<stack<Direction>> expexctedDirectionsPathes(1);

            Assert::AreEqual(true, expexctedDirectionsPathes == directionsPathes);
        }

        TEST_METHOD(startingNeighborCombination)
        {
            int n = 2, m = 2;

            vector<vector<char>> currentCombination = { {'A', 'B'}, {'#', 'C'} };

            map<vector<vector<char>>, Path> dist;

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

            stack<Direction> pathToCurrentCombination;

            vector<stack<Direction>> directionsPathes;

            generatePathes(n, m, currentCombination, dist, pathToCurrentCombination, directionsPathes);

            vector<stack<Direction>> expexctedDirectionsPathes(1);
            expexctedDirectionsPathes[0].push(Left);

            Assert::AreEqual(true, expexctedDirectionsPathes == directionsPathes);
        }

        TEST_METHOD(combinationBetweenStartedAndFinished)
        {
            int n = 2, m = 2;

            vector<vector<char>> currentCombination = { {'B', '#'}, {'A', 'C'} };

            map<vector<vector<char>>, Path> dist;

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

            stack<Direction> pathToCurrentCombination;

            vector<stack<Direction>> directionsPathes;

            generatePathes(n, m, currentCombination, dist, pathToCurrentCombination, directionsPathes);

            vector<stack<Direction>> expexctedDirectionsPathes(1);
            expexctedDirectionsPathes[0].push(Right);
            expexctedDirectionsPathes[0].push(Up);
            expexctedDirectionsPathes[0].push(Left);

            Assert::AreEqual(true, expexctedDirectionsPathes == directionsPathes);
        }
        
        TEST_METHOD(finishingNeighborCombination)
        {
            int n = 2, m = 2;

            vector<vector<char>> currentCombination = { {'C', '#'}, {'B', 'A'} };

            map<vector<vector<char>>, Path> dist;

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

            stack<Direction> pathToCurrentCombination;

            vector<stack<Direction>> directionsPathes;

            generatePathes(n, m, currentCombination, dist, pathToCurrentCombination, directionsPathes);

            vector<stack<Direction>> expexctedDirectionsPathes(1);
            expexctedDirectionsPathes[0].push(Up);
            expexctedDirectionsPathes[0].push(Right);
            expexctedDirectionsPathes[0].push(Down);
            expexctedDirectionsPathes[0].push(Left);
            expexctedDirectionsPathes[0].push(Up);

            Assert::AreEqual(true, expexctedDirectionsPathes == directionsPathes);
        }
        TEST_METHOD(finishCombination)
		{
			int n = 2, m = 2;

			vector<vector<char>> currentCombination = { {'#', 'C'}, {'B', 'A'} };

            map<vector<vector<char>>, Path> dist;

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

            stack<Direction> pathToCurrentCombination;
            
            vector<stack<Direction>> directionsPathes;

            generatePathes(n, m, currentCombination, dist, pathToCurrentCombination, directionsPathes);

            vector<stack<Direction>> expexctedDirectionsPathes(2);
            expexctedDirectionsPathes[0].push(Left);
            expexctedDirectionsPathes[0].push(Up);
            expexctedDirectionsPathes[0].push(Right);
            expexctedDirectionsPathes[0].push(Down);
            expexctedDirectionsPathes[0].push(Left);
            expexctedDirectionsPathes[0].push(Up);

            expexctedDirectionsPathes[1].push(Up);
            expexctedDirectionsPathes[1].push(Left);
            expexctedDirectionsPathes[1].push(Down);
            expexctedDirectionsPathes[1].push(Right);
            expexctedDirectionsPathes[1].push(Up);
            expexctedDirectionsPathes[1].push(Left);

            Assert::AreEqual(true, expexctedDirectionsPathes == directionsPathes);
		}

        TEST_METHOD(stackNotEmpty)
        {
            int n = 2, m = 2;

            vector<vector<char>> currentCombination = { {'B', '#'}, {'A', 'C'} };

            map<vector<vector<char>>, Path> dist;

            Path path;
            path.lengthPath = 0;
            path.lastMoves = {};
            vector<vector<char>> combination = { {'B', '#'}, { 'A', 'C' } };
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

            stack<Direction> pathToCurrentCombination;
            pathToCurrentCombination.push(Down);

            vector<stack<Direction>> directionsPathes;

            generatePathes(n, m, currentCombination, dist, pathToCurrentCombination, directionsPathes);

            vector<stack<Direction>> expexctedDirectionsPathes(1);
            expexctedDirectionsPathes[0].push(Down);
            expexctedDirectionsPathes[0].push(Right);
            expexctedDirectionsPathes[0].push(Up);
            expexctedDirectionsPathes[0].push(Left);

            Assert::AreEqual(true, expexctedDirectionsPathes == directionsPathes);
        }

        TEST_METHOD(complexTest)
        {
            int n = 2, m = 2;

            vector<vector<char>> currentCombination = { {'A', 'B'}, {'C', '#'} };

            map<vector<vector<char>>, Path> dist;

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

            stack<Direction> pathToCurrentCombination;
            pathToCurrentCombination.push(Up);
            pathToCurrentCombination.push(Left);
            vector<stack<Direction>> directionsPathes;

            vector<stack<Direction>> expexctedDirectionsPathes;
            expexctedDirectionsPathes.push_back(pathToCurrentCombination);

            generatePathes(n, m, currentCombination, dist, pathToCurrentCombination, directionsPathes);

            Assert::AreEqual(true, expexctedDirectionsPathes == directionsPathes);
        }
	};
}
