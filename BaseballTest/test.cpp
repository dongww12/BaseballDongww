#include "pch.h"
#include "../Baseball/Baseball.cpp"
#include <string>

using namespace std;

class BaseballTestFixture : public testing::Test {
public:
	void assertIllegalArgument(string guessNumber) {
		Baseball game;
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception& e) {
			// PASS
		}
	}
};

TEST_F(BaseballTestFixture, ThrowExceptionInvalidArg) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}
