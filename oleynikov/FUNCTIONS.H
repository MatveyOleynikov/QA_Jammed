#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string.h>
#include <fstream>
#include <string>  
#define NotExist -1

using namespace std;

//Перечисление возможных ошибок
enum TypesErrors{
	WrongNumberFiles, // Неправильное количество файлов
	InputFileNotFound, // Входной файл не найден
	IncorrectInputFilePermission, // Некорректное разрешение входного файла
	OutputFileNotCreate, // Невозможно создать выходной файл
	IncorrectOutputFilePermission, // Некорректное разрешение выходного файла
	WrongTypeSize, // Неправильный тип размера
	MultiplicationSizeOutOfRange, // Перемножение размеров выходит за границы указанного диапазона
	WrongSymbolType, // Неправильный тип символа
	SharpError, // Ошибка, связанная с символом '#'
	TooFewCharacters // Слишком мало символов
};

//Комбинация
enum Combination {
	StartCombination, // Стартовая комбинация
	FinishCombination // Целевая комбинация
};

//Структура ошибки
struct Error{
	TypesErrors type; // Тип ошибки
	int numberRow; // Номер строки ошибки
	int numberCol; // Номер столбца ошибки
	Combination combination; // Комбинация, в которой произошла ошибка
	Error(TypesErrors type) : type(type), numberRow(NotExist), numberCol(NotExist) {};
	Error(TypesErrors type, Combination combination) : type(type), combination(combination), numberRow(NotExist), numberCol(NotExist) {};
	Error(TypesErrors type, int numberRow, int numberCol) : type(type), numberRow(numberRow), numberCol(numberCol) {};
	Error(TypesErrors type, int numberRow, int numberCol, Combination combination) : type(type), numberRow(numberRow), numberCol(numberCol), combination(combination) {};
};

bool operator == (const Error& first, const Error& second);

//Перечисление направлений
enum Direction {
	Left, //Влево
	Right, //Вправо
	Up, //Вверх
	Down, //Вниз
	NotSet //Не задано
};

//Структура пути к определённой вершине
struct Path {
	int lengthPath; //длина пути
	vector<Direction> lastMoves; // последний ход в пути
};

//Структура перемещения символа '#'
struct Move {
	int x, y; //координата перемещения символа '#'
	Direction direction; //направление перемещения символа '#'
	Move() : direction(NotSet), x(0), y(0) {};
	Move(Direction direction, int x, int y) : direction(direction), x(x), y(y){};
};

bool operator == (const Move& first, const Move& second);

/*! Чтение комбинации
	\param[in] n количество строк
	\param[in] m количество столбцов
	\param[in] fin файл для чтения
	\param[out] errors вектор ошибок
	\param[out] combination комбинация для записи
	\param[in] typeCombination тип комбинации для записи
*/
void readCombination(int n, int m, ifstream& fin, vector<Error>& errors, vector<vector<char>>& combination, Combination typeCombination);

/*! Проверка, есть ли уже ошибка в векторе ошибок
	\param[in] errors вектор ошибок
*/
void checkErrors(vector<Error>& errors);

/*! Открытие файлов из командной строки
	\param[in] argc количество файлов
	\param[in] argv имена файлов
	\param[out] errors вектор ошибок
	\param[out] fin файл для чтения
	\param[out] fout файл для вывода
*/
void openFiles(int argc, char* argv[], vector<Error>& errors, ifstream& fin, ofstream& fout);

/*! Получить входные данные
	\param[out] n количество строк в комбинациях
	\param[out] m количество столбцов в комбинациях
	\param[out] startCombination стартовая комбинация
	\param[out] finishCombination конечная комбинация
	\param[out] errors вектор ошибок
	\param[in] fin файл для чтения
*/
void inputData(int& n, int& m, vector<vector<char>>& startCombination, vector<vector<char>>& finishCombination, vector<Error>& errors, ifstream& fin);

/*! Получить возможные ходы по заданным координатам
	\param[in] n количество строк
	\param[in] m количество столбцов
	\param[in] i заданная строка
	\param[in] j заданный столбец
	\return вектор возможных перемещений
*/
vector<Move> getMoves(const int& n, const int& m, const int& i, const int& j);

/*! Получаем расстояния для соседних комбинаций
	\param[in] n количество строк в комбинациях
	\param[in] m количество столбцов в комбинациях
	\param[in] currentCombination текущая комбинация
	\param[in|out] dist map расстояний до комбинаций
	\param[in|out] combinations очередь необработанных комбинаций
*/
void calculateDistantionNeighboringCombinations(const int& n, const int& m, const vector<vector<char>>& currentCombination, map < vector<vector<char>>, Path>& dist, queue<vector<vector<char>>>& combinations);

/*! Обход в ширину графа
	\param[in] n количество строк в комбинациях
	\param[in] m количество столбцов в комбинациях
	\param[in] startCombination комбинация, с которой мы начинаем обход в ширину
	\param[out] dist map расстояний до комбинаций
*/
void bfs(const int& n, const int& m, const vector<vector<char>>& startCombination, map < vector<vector<char>>, Path>& dist);

/*! Получить соседнюю комбинацию
	\param[in] n количество строк в комбинациях
	\param[in] m количество столбцов в комбинациях
	\param[in] currentCombination текущая комбинация
	\param[in] direction направление, в котором текущая комбинация лежит от соседней комбинации
	\return соседняя комбинация
*/
vector<vector<char>> getNeighboringCombination(const int n, const int m, const vector<vector<char>>& currentCombination, const Direction& direction);

/*! Сгенерировать все пути до заданной комбинации
	\param[in] n количество строк в комбинациях
	\param[in] m количество столбцов в комбинациях
	\param[in] currentCombination текущая комбинация
	\param[in] dist map расстояний до комбинаций
	\param[in|out] pathToCurrentCombination путь до текущей вершины
	\param[out] directionsPathes вектор оптимальных путей до начальной вершины
*/
void generatePathes(const int n, const int m, const vector<vector<char>>& currentCombination, map < vector<vector<char>>, Path>& dist, stack<Direction> pathToCurrentCombination, vector<stack<Direction>>& directionsPathes);

/*! Конвертировать направление в символ
	\param[in] direction направление
	\return символ соответствующий направлению
*/
char convertDirectionToChar(Direction direction);

/*! Вывести все оптимальные пути
	\param[in] numberPathes количество путей
	\param[in] directionsPathes вектор стеков оптимальных путей
	\param[out] fout файл для вывода
*/
void outputData(int numberPathes, vector<stack<Direction>>& directionsPathes, ofstream& fout);

/*! Конвертировать ошибку в строку
	\param[in] error ошибка
	\return строка соответствующая ошибке
*/
string convertErrorToString(Error error);