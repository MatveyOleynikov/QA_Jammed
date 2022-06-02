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
    //считываем размеры комбинации
    fin >> n >> m;

    //если размер "n" комбинации не входит в диапазон [1..9]...
    if (n <= 0 || n >= 10) {
        //записываем ошибку неправильного типа размера n
        Error error(WrongTypeSize, 0, 0);
        errors.push_back(error);
    }

    //если размер "m" комбинации не входит в диапазон [1..9]...
    if (m <= 0 || m >= 10) {
        //записываем ошибку неправильного типа размера m
        Error error(WrongTypeSize, 0, 2);
        errors.push_back(error);
    }

    //если произведение размеров комбинации не входит в диапазон [1..9]...
    if (n * m <= 0 || n * m >= 10) {
        //записываем ошибку, что произведение размеров не входит в диапазон [1..9]
        Error error(MultiplicationSizeOutOfRange);
        errors.push_back(error);
    }

    //если в размерах есть ошибка...
    if (errors.size() > 0) {
        //выходим из функции досрочно
        return;
    }

    //обозначаем размер стартовой комбинация и финишной комбинации как (n, 1)

    //считываем стартовую комбинацию
    readCombination(n, m, fin, errors, startCombination, StartCombination);

    //считываем финишную комбинацию
    readCombination(n, m, fin, errors, finishCombination, FinishCombination);

    return;
}

vector<Move> getMoves(const int& n, const int& m, const int& i, const int& j) {
    //Создадим результирующий вектор
    vector<Move> result;

    //Если текущая строка не является последней
    if (i < n - 1) {
        //Создаём ход вниз и добавляем в вектор возможных ходов
        Move downMove(Down, i + 1, j);
        result.push_back(downMove);
    }

    //Если текущая строка не является первой
    if (i > 0) {
        //Создаём ход вверх и добавляем в вектор возможных ходов
        Move upMove(Up, i - 1, j);
        result.push_back(upMove);
    }

    //Если текущий столбец не является последним
    if (j < m - 1) {
        //Создаём ход вправо и добавляем в вектор возможных ходов
        Move rightMove(Right, i, j + 1);
        result.push_back(rightMove);
    }

    //Если текущий столбец не является первым
    if (j > 0) {
        //Создаём ход влево и добавляем в вектор возможных ходов
        Move leftMove(Left, i, j - 1);
        result.push_back(leftMove);
    }

    return result;
}

void calculateDistantionNeighboringCombinations(const int& n, const int& m, const vector<vector<char>>& currentCombination, map < vector<vector<char>>, Path>& dist, queue<vector<vector<char>>>& combinations) {
    //Для всех строк текущей комбинации...
    for (int i = 0; i < n; ++i) {
        //Для всех столбцов текущей комбинации...
        for (int j = 0; j < m; ++j) {
            //Если символ на позиции i, j равен '#'... 
            if (currentCombination[i][j] == '#') {
                //Получаем возможные ходы 
                vector<Move> neighbors = getMoves(n, m, i, j);

                //Для всех возможных ходов
                for (auto neighbor : neighbors) {
                    //Сохраняем в следующую комбинацию текущую комбинацию
                    vector<vector<char>> nextCombination = currentCombination;

                    //Переставляем символ '#' в координаты хода
                    swap(nextCombination[i][j], nextCombination[neighbor.x][neighbor.y]);
                    
                    //Если в map нет пути до следующей комбинации
                    if (!dist.count(nextCombination)) {
                        //Обозначаем длину пути для следующей комбинации как длину пути для текущей комбинации + 1 
                        dist[nextCombination].lengthPath = dist[currentCombination].lengthPath + 1;
                        //Добавляем в вектор возможных направлений перемещение до следующей комбинации направление текущего перемещения
                        dist[nextCombination].lastMoves.push_back(neighbor.direction);
                        //Добавляем в очередь следующую комбинацию
                        combinations.push(nextCombination);
                    }
                    //иначе если растояние до следующей вершины равно расстоянию для текущей вершины + 1...
                    else if (dist[nextCombination].lengthPath == dist[currentCombination].lengthPath + 1) {
                        //Добавляем в вектор возможных направлений перемещение до следующей комбинации направление текущего перемещения
                        dist[nextCombination].lastMoves.push_back(neighbor.direction);
                    }
                }
            }
        }
    }
}

void bfs(const int& n, const int& m, const vector<vector<char>>& startCombination, map < vector<vector<char>>, Path>& dist) {
    //Создаём путь до стартовой комбинации и обозначаем его длину как 0
    Path startPath;
    startPath.lengthPath = 0;

    //Сохраняем путь до стартовой комбинации в map
    dist[startCombination] = startPath;

    //Создаём очередь из комбинаций и добавляет туда стартовую комбинацию
    queue<vector<vector<char>>> combinations;
    combinations.push(startCombination);

    //Пока очередь из комбинации не пуста...
    while (!combinations.empty()) {

        //Достаём из очереди первую комбинацию в ней и обозначаем её как текущую комбинацию
        vector<vector<char>> currentCombination = combinations.front();
        combinations.pop();

        //Получаем расстояния для соседних комбинаций от текущей комбинации
        calculateDistantionNeighboringCombinations(n, m, currentCombination, dist, combinations);
    }
}

vector<vector<char>> getNeighboringCombination(const int n, const int m, const vector<vector<char>>& currentCombination, const Direction& direction){
    //Для всех строк текущей комбинации...
    for (int i = 0; i < n; ++i) {
        //Для всех столбцов текущей комбинации...
        for (int j = 0; j < m; ++j) {
            //Если символ на позиции i, j равен '#'... 
            if (currentCombination[i][j] == '#') {
                //Создаём соседнюю комбинацию и приравниваем её к текущей комбинации
                vector<vector<char>> neighboringCombination = currentCombination;

                //Выбор
                switch (direction)
                {
                //При направлении равном: влево 
                case Left:
                    //Возвращаем символ '#' в координату (i, j + 1)
                    swap(neighboringCombination[i][j], neighboringCombination[i][j + 1]);
                    break;

                //При направлении равном: влево 
                case Right:
                    //Возвращаем символ '#' в координату (i, j - 1)
                    swap(neighboringCombination[i][j], neighboringCombination[i][j - 1]);
                    break;

                //При направлении равном: влево 
                case Up:
                    //Возвращаем символ '#' в координату (i + 1, j)
                    swap(neighboringCombination[i][j], neighboringCombination[i + 1][j]);
                    break;

                //При направлении равном: влево 
                case Down:
                    //Возвращаем символ '#' в координату (i - 1, j)
                    swap(neighboringCombination[i][j], neighboringCombination[i - 1][j]);
                    break;
                }
                return neighboringCombination;
            }
        }
    }
}

char convertDirectionToChar(Direction direction) {
    //Выбор
    switch (direction)
    {
    //При направлении равном: влево 
    case Left:
        //Возвращаем символ 'L'
        return 'L';

    //При направлении равном: вправо
    case Right:
        //Возвращаем символ 'R'
        return 'R';

    //При направлении равном: вверх
    case Up:
        //Возвращаем символ 'U'
        return 'U';

    //При направлении равном: вниз
    case Down:
        //Возвращаем символ 'D'
        return 'D';
    }
}

void generatePathes(const int n, const int m, const vector<vector<char>>& currentCombination, map < vector<vector<char>>, Path>& dist, stack<Direction> pathToCurrentCombination, vector<stack<Direction>>& directionsPathes) {
    //Если расстояние до текущей вершины равно 0...
    if (dist[currentCombination].lengthPath == 0) {
        //добавляем в вектор возможных путей текущий путь
        directionsPathes.push_back(pathToCurrentCombination);
    }
    //иначе...
    else {
        //Для всех возможных оптимальных направлений перемещений в текущую комбинацию...
        for (int i = 0; i < dist[currentCombination].lastMoves.size(); ++i) {
            //Получаем предыдущую комбинацию, идя в обратном направлении от того, в котором была получена текущая комбинация
            vector<vector<char>> previousCombination = getNeighboringCombination(n, m, currentCombination, dist[currentCombination].lastMoves[i]);
            
            //Создаём стек направление для предыдущей комбинации как стек направление для текущей комбинации
            stack<Direction> pathToPreviousCombination = pathToCurrentCombination;

            //Кладём в созданный стек направление, в котором мы получили текущую комбинацию 
            pathToPreviousCombination.push(dist[currentCombination].lastMoves[i]);
            
            //Генерируем пути для предыдущей комбинации
            generatePathes(n, m, previousCombination, dist, pathToPreviousCombination, directionsPathes);
        }
    }
}

void outputData(int numberPathes, vector<stack<Direction>>& directionsPathes, ofstream& fout) {
    //Для всех стеков вектора оптимальных путей
    for (auto pathToCurrentCombination : directionsPathes) {
        //Пока стек с направлениями не пуст...
        while (!pathToCurrentCombination.empty()) {
            //Выводим направление в стеке, конвертирую его в символ.
            fout << convertDirectionToChar(pathToCurrentCombination.top()) << "";
            //Достаём направление из стека
            pathToCurrentCombination.pop();
        }

        //Выводим перевод строки
        fout << "\n";
    }
}

bool operator == (const Error& first, const Error& second) {
    return first.numberRow == second.numberRow && first.numberCol == second.numberCol && first.combination == second.combination && first.type == second.type;
}

bool operator == (const Move& first, const Move& second) {
    return first.x == second.x && first.y == second.y && first.direction == second.direction;
}