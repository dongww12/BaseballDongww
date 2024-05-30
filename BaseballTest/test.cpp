#include "pch.h"
#include "../Baseball/Baseball.cpp"
#include <string>

using namespace std;

class BaseballTestFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNumber) {
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
	assertIllegalArgument("121");
}

TEST_F(BaseballTestFixture, ReturnSolved) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(result.strikes, 3);
	EXPECT_EQ(result.balls, 0);
}

TEST_F(BaseballTestFixture, TwoStrikes) {
	GuessResult result = game.guess("124");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 2);
	EXPECT_EQ(result.balls, 0);
}

TEST_F(BaseballTestFixture, TwoBalls) {
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 1);
	EXPECT_EQ(result.balls, 2);
}
