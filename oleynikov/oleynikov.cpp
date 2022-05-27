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
    //если вектор ошибок не пуст
    if (errors.size()) {
        //для всех ошибок...
        for (size_t i = 0; i < errors.size(); ++i) {
            //выводим текущую ошибку
            cout << convertErrorToString(errors[i]);
        }
        //завершаем работу программы с кодом 0
        throw 0;
    }
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
    //если количество файлов в командной строке не равно 3
    if (argc != 3) {
        //записываем ошибку о том, что файлов неверное количество и завершаем работу функции
        Error error(WrongNumberFiles);
        errors.push_back(error);
        return;
    }

    //приравниваем строку с названием входного файла к названию второго файла в командной строке
    string file1 = argv[1];

    //приравниваем строку с названием выходного файла к названию второго файла в командной строке
    string file2 = argv[2];

    //если расширение первого файла не равно txt
    if (file1.substr(file1.rfind('.') + 1, string::npos) != "txt") {
        //записываем ошибку, о том, что расширение первого файла неверное и завершаем работу функции
        Error error(IncorrectInputFilePermission);
        errors.push_back(error);
        return;
    }

    //если расширение второго файла не равно txt
    if (file2.substr(file2.rfind('.') + 1, string::npos) != "txt") {
        //записываем ошибку, о том, что расширение второго файла неверное и завершаем работу функции
        Error error(IncorrectOutputFilePermission);
        errors.push_back(error);
        return;
    }

    //пытаемя открыть файл для чтения
    fin.open(file1);

    //если файл для чтения удалось открыть
    if (!fin.is_open()) {
        //записываем ошибку о том, что нам не удалось открыть входной файл и завершаем работу функции
        Error error(InputFileNotFound);
        errors.push_back(error);
        return;
    }

    //пытаемя открыть файл для записи
    fout.open(file2);

    //если файл для записи удалось открыть
    if (!fout.is_open()) {
        //записываем ошибку о том, что нам не удалось открыть выходной файл и завершаем работу функции
        Error error(OutputFileNotCreate);
        errors.push_back(error);
        return;
    }
}

void readCombination(int n, int m, ifstream& fin, vector<Error>& errors, vector<vector<char>>& combination, Combination typeCombination) {
    //обозначаем размер стартовой комбинация и финишной комбинации как (n, 1)
    combination.resize(n);

    //обозначаем количеству символов '#' в текущей комбинации как 0
    int countSharp = 0;

    //для всех строк комбинации...
    for (int i = 0; i < n; ++i) {
        //для всех столбцов комбинации...
        for (int j = 0; j < m; ++j) {
            //считываем текущий символ
            char sym;

            //если символ считать не удаётся...
            if (!(fin >> sym)) {
                //записываем ошибку о том, что символов слишком мало и завершаем работу функции
                Error error(TooFewCharacters, typeCombination);
                errors.push_back(error);
                return;
            }

            //если символ не равен букве, цифре или символу '#'
            if (!isalnum(sym) && sym != '#') {
                //записываем ошибку о том, что в i строке j символ текущей комбинации - ошибочный
                Error error(WrongSymbolType, i, j, typeCombination);
                errors.push_back(error);
            }

            //если символ равен решётке, то увеличиваем количество символов '#' на единицу
            countSharp += (sym == '#');

            //добавляем символ в i строку комбинации
            combination[i].push_back(sym);
        }
    }

    //если количество символов '#' не равно 1
    if (countSharp != 1) {
        //записываем ошибку о том, что символов решётка в текущей комбинации слишком мало или слишком много
        Error error(SharpError, typeCombination);
        errors.push_back(error);
    }
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