#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string.h>
#include <fstream>
#include <string>  
#include "Functions.h"

using namespace std;

int main(int argc, char* argv[])
{
	return 0;
}

void checkErrors(vector<Error>& errors) {
	return;
}

string convertErrorToString(Error error){
	return "";
}

void openFiles(int argc, char* argv[], vector<Error>& errors, ifstream &fin, ofstream &fout) {
	return;
}

void readCombination(int n, int m, ifstream& fin, vector<Error>& errors, vector<vector<char>>& combination, Combination typeCombination) {
    return;
}

void inputData(int& n, int& m, vector<vector<char>>& startCombination, vector<vector<char>>& finishCombination, vector<Error>& errors, ifstream& fin) {
    return;
}

vector<Move> getMoves(const int& n, const int& m, const int& i, const int& j) {
    //Создадим результирующий вектор
    vector<Move> result;

    return result;
}

void calculateDistantionNeighboringCombinations(const int& n, const int& m, const vector<vector<char>>& currentCombination, map < vector<vector<char>>, Path>& dist, queue<vector<vector<char>>>& combinations) {
    return;
}

void bfs(const int& n, const int& m, const vector<vector<char>>& startCombination, map < vector<vector<char>>, Path>& dist) {
    return;
}

vector<vector<char>> getNeighboringCombination(const int n, const int m, const vector<vector<char>>& currentCombination, const Direction& direction){
    vector<vector<char>> neighboringCombination;
	return neighboringCombination;
}

char convertDirectionToChar(Direction direction) {
	return 'A';
}

void generatePathes(const int n, const int m, const vector<vector<char>>& currentCombination, map < vector<vector<char>>, Path>& dist, stack<Direction> pathToCurrentCombination, vector<stack<Direction>>& directionsPathes) {
    return;
}


void outputData(int numberPathes, vector<stack<Direction>>& directionsPathes, ofstream& fout) {
    return;
}