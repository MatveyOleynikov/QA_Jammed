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
			string result = "������� ������ ������ ��� ������ ��� 3.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(inputFileNotFound)
		{
			Error error(InputFileNotFound);
			string result = "������� ������ ���� � �������� �������. ��������, ���� �� ����������.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(incorrectInputFilePermission)
		{
			Error error(IncorrectInputFilePermission);
			string result = "������� ������� ���������� �����. ���� ������ ����� ���������� .txt.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(outputFileNotCreate)
		{
			Error error(OutputFileNotCreate);
			string result = "������� ������ ���� ��� �������� ������. �������� ���������� ������������ �� ����������.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(incorrectOutputFilePermission)
		{
			Error error(IncorrectOutputFilePermission);
			string result = "������� ������� ���������� ��������� �����. ���� ������ ����� ���������� .txt.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}
		TEST_METHOD(multiplicationSizeOutOfRange)
		{
			Error error(MultiplicationSizeOutOfRange);
			string result = "������������ �������� �� ����������� ��������� [1.. 9].\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongTypeSizeN)
		{
			Error error(WrongTypeSize, 0, 0);
			string result = "������ �n� �� �������� ����������� ������.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongTypeSizeM)
		{
			Error error(WrongTypeSize, 0, 2);
			string result = "������ �m� �� �������� ����������� ������.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongSymbolTypeFirstRow)
		{
			Error error(WrongSymbolType, 0, 1, StartCombination);
			string result = "�� ������� ������ � ������ 1, ������� 2 ��������� ����������.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongSymbolTypeFirstCol)
		{
			Error error(WrongSymbolType, 1, 0, StartCombination);
			string result = "�� ������� ������ � ������ 2, ������� 1 ��������� ����������.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongSymbolTypeMiddle)
		{
			Error error(WrongSymbolType, 1, 1, StartCombination);
			string result = "�� ������� ������ � ������ 2, ������� 2 ��������� ����������.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(wrongSymbolTypeFirstSymbol)
		{
			Error error(WrongSymbolType, 0, 0, StartCombination);
			string result = "�� ������� ������ � ������ 1, ������� 1 ��������� ����������.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		/*
		case SharpError:
			// ������� ������: "������ ������� � {����������, � ������� ���������� ������} ����������� ����� ��� ����� ������ ����."
			return ((error.combination == StartCombination) ? "������ ������� � ��������� ���������� ����������� ����� ��� ����� ������ ����.\n" : "������ ������� � ��������� ���������� ����������� ����� ��� ����� ������ ����.\n");
			break;*/
		TEST_METHOD(sharpErrorStartCombination)
		{
			Error error(SharpError, StartCombination);
			string result = "������ ������� � ��������� ���������� ����������� ����� ��� ����� ������ ����.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(sharpErrorFinishCombination)
		{
			Error error(SharpError, FinishCombination);
			string result = "������ ������� � �������� ���������� ����������� ����� ��� ����� ������ ����.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(tooFewCharactersStartCombination)
		{
			Error error(TooFewCharacters, StartCombination);
			string result = "��������� ���������� �������� ������������ ��� ����, ����� ��������� ��������� ����������.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}

		TEST_METHOD(tooFewCharactersFinishCombination)
		{
			Error error(TooFewCharacters, FinishCombination);
			string result = "��������� ���������� �������� ������������ ��� ����, ����� ��������� �������� ����������.\n";
			Assert::AreEqual(result, convertErrorToString(error));
		}
	};
}
