#include "pch.h"
#include "CppUnitTest.h"
#include "..\oleynikov\FUNCTIONS.H"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool correctMap(int n, int m, map<vector<vector<char>>, Path>& dist){
    for (auto& iter : dist) {
        pair< vector<vector<char>>, Path> p = iter;
        vector<vector<char>> currentCombination = p.first;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (currentCombination[i][j] == '#') {
                    vector<Move> neighbors = getMoves(n, m, i, j);
                    for (auto neighbor : neighbors) {
                        vector<vector<char>> nextCombination = currentCombination;
                        swap(nextCombination[i][j], nextCombination[neighbor.x][neighbor.y]);
                        if (!dist.count(nextCombination)) {
                            return false;
                            if (abs(dist[nextCombination].lengthPath - dist[currentCombination].lengthPath) > 1) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
	
	return true;
}

bool equalMaps(map<vector<vector<char>>, Path>& firstMap, map<vector<vector<char>>, Path>& secondMap) {
    for (auto& i : firstMap) {
        pair< vector<vector<char>>, Path> p = i;
        if (firstMap[p.first].lengthPath != secondMap[p.first].lengthPath || firstMap[p.first].lastMoves != secondMap[p.first].lastMoves) {
            return false;
        }
    }

    return true;
}

namespace testbfs
{
    TEST_CLASS(testbfs)
    {
    public:

        TEST_METHOD(sharpOnEdge)
        {
            int n = 2;
            int m = 2;
            vector<vector<char>> startCombination = { {'A', 'B'}, {'C', '#'} };
            map<vector<vector<char>>, Path> dist;
            bfs(n, m, startCombination, dist);
            map<vector<vector<char>>, Path> expectedDist;

            Path path;
            path.lengthPath = 0;
            path.lastMoves = {};
            vector<vector<char>> combination = { {'A', 'B'}, { 'C', '#' } };
            expectedDist[combination] = path;

            path.lengthPath = 1;
            path.lastMoves = { Left };
            combination = { {'A', 'B'}, { '#', 'C' } };
            expectedDist[combination] = path;

            path.lengthPath = 1;
            path.lastMoves = { Up };
            combination = { {'A', '#'}, { 'C', 'B' } };
            expectedDist[combination] = path;

            path.lengthPath = 2;
            path.lastMoves = { Up };
            combination = { {'#', 'B'}, { 'A', 'C' } };
            expectedDist[combination] = path;

            path.lengthPath = 2;
            path.lastMoves = { Left };
            combination = { {'#', 'A'}, { 'C', 'B' } };
            expectedDist[combination] = path;

            path.lengthPath = 3;
            path.lastMoves = { Right };
            combination = { {'B', '#'}, { 'A', 'C' } };
            expectedDist[combination] = path;

            path.lengthPath = 3;
            path.lastMoves = { Down };
            combination = { {'C', 'A'}, { '#', 'B' } };
            expectedDist[combination] = path;

            path.lengthPath = 4;
            path.lastMoves = { Down };
            combination = { {'B', 'C'}, { 'A', '#' } };
            expectedDist[combination] = path;

            path.lengthPath = 4;
            path.lastMoves = { Right };
            combination = { {'C', 'A'}, { 'B', '#' } };
            expectedDist[combination] = path;

            path.lengthPath = 5;
            path.lastMoves = { Left };
            combination = { {'B', 'C'}, { '#', 'A' } };
            expectedDist[combination] = path;

            path.lengthPath = 5;
            path.lastMoves = { Up };
            combination = { {'C', '#'}, { 'B', 'A' } };
            expectedDist[combination] = path;

            path.lengthPath = 6;
            path.lastMoves = { Left, Up };
            combination = { {'#', 'C'}, { 'B', 'A' } };
            expectedDist[combination] = path;

            Assert::AreEqual(true, equalMaps(dist, expectedDist));
        }

        TEST_METHOD(sharpOnBorder)
        {
			int n = 2;
            int m = 4;
            vector<vector<char>> startCombination = {{'A', 'B', 'C', 'D'}, {'E', 'F', '#', 'G'}};
            map<vector<vector<char>>, Path> dist;
            bfs(n, m, startCombination, dist);
			
            Assert::AreEqual(true, correctMap(n, m, dist));
        }

        TEST_METHOD(sharpInCenter)
        {
			int n = 3;
            int m = 3;
            vector<vector<char>> startCombination = {{'A', 'B', 'C'}, {'D', '#', 'E'}, {'F', 'G', 'H'}};
            map<vector<vector<char>>, Path> dist;
            bfs(n, m, startCombination, dist);
			
            Assert::AreEqual(true, correctMap(n, m, dist));
        }

        TEST_METHOD(size1x9)
        {
			int n = 1;
            int m = 9;
            vector<vector<char>> startCombination = {{'A', 'B', 'C', 'D', 'E', 'F', '#', 'G', 'H'}};
            map<vector<vector<char>>, Path> dist;
            bfs(n, m, startCombination, dist);
            map<vector<vector<char>>, Path> expectedDist;

            Path path;
            path.lengthPath = 0;
            path.lastMoves = {};
            vector<vector<char>> combination = {{'A', 'B', 'C', 'D', 'E', 'F', '#', 'G', 'H'}};
            expectedDist[combination] = path;

            path.lengthPath = 1;
            path.lastMoves = { Left };
            combination = {{'A', 'B', 'C', 'D', 'E', '#', 'F', 'G', 'H'}};
            expectedDist[combination] = path;

            path.lengthPath = 1;
            path.lastMoves = { Right };
            combination = {{'A', 'B', 'C', 'D', 'E', 'F', 'G', '#', 'H'}};
            expectedDist[combination] = path;

            path.lengthPath = 2;
            path.lastMoves = { Left };
            combination = {{'A', 'B', 'C', 'D', '#', 'E', 'F', 'G', 'H'}};
            expectedDist[combination] = path;

            path.lengthPath = 2;
            path.lastMoves = { Right };
            combination = {{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '#'}};
            expectedDist[combination] = path;

            path.lengthPath = 3;
            path.lastMoves = { Left };
            combination = {{'A', 'B', 'C', '#', 'D', 'E', 'F', 'G', 'H'}};
            expectedDist[combination] = path;

            path.lengthPath = 4;
            path.lastMoves = { Left };
            combination = {{'A', 'B', '#', 'C', 'D', 'E', 'F', 'G', 'H'}};
            expectedDist[combination] = path;

            path.lengthPath = 5;
            path.lastMoves = { Left };
            combination = {{'A', '#', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}};
            expectedDist[combination] = path;

            path.lengthPath = 6;
            path.lastMoves = { Left };
            combination = {{'#', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}};
            expectedDist[combination] = path;

            Assert::AreEqual(true, equalMaps(dist, expectedDist));
        }

        TEST_METHOD(size1x1)
        {
			int n = 1;
            int m = 1;
            vector<vector<char>> startCombination = { {'#'} };
            map<vector<vector<char>>, Path> dist;
            bfs(n, m, startCombination, dist);
            map<vector<vector<char>>, Path> expectedDist;
			
			Path path;
            path.lengthPath = 0;
            path.lastMoves = {};
            vector<vector<char>> combination = { {'#'} };
            expectedDist[combination] = path;

            Assert::AreEqual(true, equalMaps(dist, expectedDist));
        }

        TEST_METHOD(complexTest)
        {
			int n = 3;
            int m = 3;
            vector<vector<char>> startCombination = {{'A', 'B', 'C'}, {'D', 'E', 'F'},  {'G', 'H', '#'}};
            map<vector<vector<char>>, Path> dist;
            bfs(n, m, startCombination, dist);
			
            Assert::AreEqual(true, correctMap(n, m, dist));
        }
    };
};