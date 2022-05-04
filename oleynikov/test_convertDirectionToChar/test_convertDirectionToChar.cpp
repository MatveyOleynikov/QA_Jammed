#include "pch.h"
#include "CppUnitTest.h"
#include "..\oleynikov\Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testconvertDirectionToChar
{
	TEST_CLASS(testconvertDirectionToChar)
	{
	public:
		
		TEST_METHOD(left)
		{
			Assert::AreEqual('L', convertDirectionToChar(Left));
		}
		TEST_METHOD(right)
		{
			Assert::AreEqual('R', convertDirectionToChar(Right));
		}
		TEST_METHOD(up)
		{
			Assert::AreEqual('U', convertDirectionToChar(Up));
		}
		TEST_METHOD(down)
		{
			Assert::AreEqual('D', convertDirectionToChar(Down));
		}
	};
}
