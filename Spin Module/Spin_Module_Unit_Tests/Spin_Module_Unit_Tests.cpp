#include "pch.h"
#include "CppUnitTest.h"

extern "C" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpinModuleUnitTests
{
	TEST_CLASS(SpinModuleUnitTests)
	{
	public:
		
		TEST_METHOD(TestCalculateWinnings)
		{
			//// Test 1: No matching lines, no winnings
			//char spin_results1[3][3] = { { '[7]', '[~]', '[!]' }, { '[@]', '[#]', '[$]' }, { '[%]', '[^]', '[&]' } };
			//Assert::AreEqual(0.0f, calculate_winnings(1, 10.0f, spin_results1));

			//// Test 2: One matching line, base winnings
			//char spin_results2[3][3] = { { '[7]', '[7]', '[7]' }, { '[@]', '[#]', '[$]' }, { '[%]', '[^]', '[&]' } };
			//Assert::AreEqual(10.0f, calculate_winnings(1, 10.0f, spin_results2)); // Assuming the value of '[7]' is 10.0

			//// Test 3: Two matching lines, 2x winnings
			//char spin_results3[3][3] = { { '[7]', '[7]', '[7]' }, { '[7]', '[7]', '[7]' }, { '[%]', '[^]', '[&]' } };
			//Assert::AreEqual(20.0f, calculate_winnings(2, 10.0f, spin_results3)); // Assuming the value of '[7]' is 10.0

			//// Test 4: Three matching lines forming an "X", 3x winnings plus 2x bonus
			//char spin_results4[3][3] = { { '[7]', '[~]', '[7]' }, { '[@]', '[7]', '[$]' }, { '[7]', '[^]', '[7]' } };
			//Assert::AreEqual(60.0f, calculate_winnings(3, 10.0f, spin_results4)); // Assuming the value of '[7]' is 10.0
		}
	};
}
