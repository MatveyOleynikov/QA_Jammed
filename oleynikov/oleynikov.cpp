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
    //Выбор
    switch (error.type)
    {
    //При типе ошибке: неверное количество входных файлов
    case WrongNumberFiles:
        // Вывести строку: "Входных файлов больше или меньше чем 3."
        return "Входных файлов больше или меньше чем 3.\n";
    //При типе ошибке: входной файл не найден
    case InputFileNotFound:
        // Вывести строку: "Неверно указан файл с входными данными. Возможно, файл не существует."
        return "Неверно указан файл с входными данными. Возможно, файл не существует.\n";
    //При типе ошибке: неверное расширение входного файла
    case IncorrectInputFilePermission:
        // Вывести строку: "Неверно указано расширение файла. Файл должен иметь расширение .txt."
        return "Неверно указано расширение файла. Файл должен иметь расширение .txt.\n";
    //При типе ошибке: выходной файл не создан
    case OutputFileNotCreate:
        // Вывести строку: "Неверно указан файл для выходных данных. Возможно указанного расположения не существует."
        return "Неверно указан файл для выходных данных. Возможно указанного расположения не существует.\n";
    //При типе ошибке: неверное расширение выходного файла
    case IncorrectOutputFilePermission:
        // Вывести строку: "Неверно указан файл для выходных данных. Возможно указанного расположения не существует."
        return "Неверно указано расширение выходного файла. Файл должен иметь расширение .txt.\n";
    //При типе ошибке: неправильный тип для размера
    case WrongTypeSize:
        // Вывести строку: "Размер {размер в котором ошибка} не является натуральным числом."
        return error.numberCol == 0 ? "Размер «n» не является натуральным числом.\n" : "Размер «m» не является натуральным числом.\n";
    //При типе ошибке: произведение размеров вне допустимого диапазона
    case MultiplicationSizeOutOfRange:
        // Вывести строку: "Произведение размеров не принадлежит диапазону [1.. 9]."
        return "Произведение размеров не принадлежит диапазону [1.. 9].\n";
    //При типе ошибке: неправильный тип символа
    case WrongSymbolType:
        //Вывести строку: “Не опознан символ в строке {номер строки}, столбце {номер столбца} {комбинация, в которой происходит ошибка}.”
        return "Не опознан символ в строке " + to_string(error.numberRow + 1) + ", столбце " + to_string(error.numberCol + 1) + ((error.combination == StartCombination) ? " начальной комбинации" : " конечной комбинации") + ".\n";
    //При типе ошибке: Ошибка, связанная с символом '#'
    case SharpError:
        // Вывести строку: "Символ решетка в {комбинация, в которой происходит ошибка} встречается более или менее одного раза."
        return ((error.combination == StartCombination) ? "Символ решетка в начальной комбинации встречается более или менее одного раза.\n" : "Символ решетка в конечной комбинации встречается более или менее одного раза.\n");
    //При типе ошибке: слишком мало символов
    case TooFewCharacters:
        // Вывести строку: "Суммарное количество символов недостаточно для того, чтобы составить 2 комбинации."
        return (error.combination == StartCombination) ? "Суммарное количество символов недостаточно для того, чтобы составить начальную комбинацию.\n" : "Суммарное количество символов недостаточно для того, чтобы составить конечную комбинацию.\n";
    }
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