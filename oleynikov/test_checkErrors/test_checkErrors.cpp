#include "pch.h"
#include "CppUnitTest.h"
#include "..\oleynikov\Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testcheckErrors
{
	TEST_CLASS(testcheckErrors)
	{
	public:
		
		TEST_METHOD(noErrors)
		{
			vector <Error> errors;
			try {
				checkErrors(errors);
				Assert::AreEqual(true, true);
			}
			catch (int error){
				Assert::AreEqual(true, false);
			}

		}

		TEST_METHOD(oneErrors)
		{
			vector <Error> errors;
			Error error(SharpError, StartCombination);
			errors.push_back(error);

			try {
				checkErrors(errors);
				Assert::AreEqual(true, false);
			}
			catch (int error) {
				Assert::AreEqual(true, true);
			}

		}

		TEST_METHOD(manyErrors)
		{
			vector <Error> errors;
			Error error1(SharpError, StartCombination);
			Error error2(WrongSymbolType, 1, 1, StartCombination);
			errors.push_back(error1);
			errors.push_back(error2);

			try {
				checkErrors(errors);
				Assert::AreEqual(true, false);
			}
			catch (int error) {
				Assert::AreEqual(true, true);
			}
		}

		TEST_METHOD(equalErrors)
		{
			vector <Error> errors;
			Error error1(WrongSymbolType, 0, 0, StartCombination);
			Error error2(WrongSymbolType, 1, 1, StartCombination);
			errors.push_back(error1);
			errors.push_back(error2);

			try {
				checkErrors(errors);
				Assert::AreEqual(true, false);
			}
			catch (int error) {
				Assert::AreEqual(true, true);
			}
		}

		TEST_METHOD(firstComplexTest)
		{
			vector <Error> errors;
			Error error1(InputFileNotFound);
			Error error2(OutputFileNotCreate);
			errors.push_back(error1);
			errors.push_back(error2);

			try {
				checkErrors(errors);
				Assert::AreEqual(true, false);
			}
			catch (int error) {
				Assert::AreEqual(true, true);
			}
		}

		TEST_METHOD(secondComplexTest)
		{
			vector <Error> errors;
			Error error1(WrongTypeSize, 0, 0);
			Error error2(WrongTypeSize, 0, 2);
			Error error3(MultiplicationSizeOutOfRange);
			errors.push_back(error1);
			errors.push_back(error2);
			errors.push_back(error3);

			try {
				checkErrors(errors);
				Assert::AreEqual(true, false);
			}
			catch (int error) {
				Assert::AreEqual(true, true);
			}
		}

		TEST_METHOD(thirdComplexTest)
		{
			vector <Error> errors;
			for (auto combination : {StartCombination, FinishCombination}) {
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						Error error(WrongSymbolType, i, j, combination);
						errors.push_back(error);
					}
				}
			}

			try {
				checkErrors(errors);
				Assert::AreEqual(true, false);
			}
			catch (int error) {
				Assert::AreEqual(true, true);
			}
		}
	};
}
