#include "pch.h"
#include "CppUnitTest.h"
#include "..\oleynikov\Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testconvertErrorToString
{
	TEST_CLASS(testconvertErrorToString)
	{
	public:
		TEST_METHOD(wrongNumberFiles)
		{
			Error error(WrongNumberFiles);
			string result = "Входных файлов больше или меньше чем 3.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(inputFileNotFound)
		{
			Error error(InputFileNotFound);
			string result = "Неверно указан файл с входными данными. Возможно, файл не существует.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(incorrectInputFilePermission)
		{
			Error error(IncorrectInputFilePermission);
			string result = "Неверно указано расширение файла. Файл должен иметь расширение .txt.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(outputFileNotCreate)
		{
			Error error(OutputFileNotCreate);
			string result = "Неверно указан файл для выходных данных. Возможно указанного расположения не существует.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(incorrectOutputFilePermission)
		{
			Error error(IncorrectOutputFilePermission);
			string result = "Неверно указано расширение выходного файла. Файл должен иметь расширение .txt.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}
		TEST_METHOD(multiplicationSizeOutOfRange)
		{
			Error error(MultiplicationSizeOutOfRange);
			string result = "Произведение размеров не принадлежит диапазону [1.. 9].\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongTypeSizeN)
		{
			Error error(WrongTypeSize, 0, 0);
			string result = "Размер «n» не является натуральным числом.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongTypeSizeM)
		{
			Error error(WrongTypeSize, 0, 2);
			string result = "Размер «m» не является натуральным числом.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongSymbolTypeFirstRow)
		{
			Error error(WrongSymbolType, 0, 1, StartCombination);
			string result = "Не опознан символ в строке 1, столбце 2 начальной комбинации.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongSymbolTypeFirstCol)
		{
			Error error(WrongSymbolType, 1, 0, StartCombination);
			string result = "Не опознан символ в строке 2, столбце 1 начальной комбинации.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongSymbolTypeMiddle)
		{
			Error error(WrongSymbolType, 1, 1, StartCombination);
			string result = "Не опознан символ в строке 2, столбце 2 начальной комбинации.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongSymbolTypeFirstSymbol)
		{
			Error error(WrongSymbolType, 0, 0, StartCombination);
			string result = "Не опознан символ в строке 1, столбце 1 начальной комбинации.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		/*
		case SharpError:
			// Вывести строку: "Символ решетка в {комбинация, в которой происходит ошибка} встречается более или менее одного раза."
			return ((error.combination == StartCombination) ? "Символ решетка в начальной комбинации встречается более или менее одного раза.\n" : "Символ решетка в начальной комбинации встречается более или менее одного раза.\n");
			break;*/
		TEST_METHOD(sharpErrorStartCombination)
		{
			Error error(SharpError, StartCombination);
			string result = "Символ решетка в начальной комбинации встречается более или менее одного раза.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(sharpErrorFinishCombination)
		{
			Error error(SharpError, FinishCombination);
			string result = "Символ решетка в конечной комбинации встречается более или менее одного раза.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(tooFewCharactersStartCombination)
		{
			Error error(TooFewCharacters, StartCombination);
			string result = "Суммарное количество символов недостаточно для того, чтобы составить начальную комбинацию.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(tooFewCharactersFinishCombination)
		{
			Error error(TooFewCharacters, FinishCombination);
			string result = "Суммарное количество символов недостаточно для того, чтобы составить конечную комбинацию.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}
	};
}
