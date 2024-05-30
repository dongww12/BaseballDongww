#include <string>

using namespace std;

class LengthError : public std::exception {
public:
	explicit LengthError(char const* msg)
		: message(msg) {}
private:
	char const* message;
};

class InvaildArgument : public std::exception {
public:
	explicit InvaildArgument(char const* msg)
		: message(msg) {}
private:
	char const* message;
};

struct GuessResult {
	bool solved{};
	int strikes{};
	int balls{};
};

class Baseball {
public:
	Baseball(const string& ans)
		: answer(ans) {}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == answer)
			return {true, 3, 0};
		return { false, strikes(guessNumber), balls(guessNumber) };
	}

private:
	bool hasDuplicateNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.size() != 3)
			throw LengthError("length should be 3!\n");
		for (auto ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw InvaildArgument("should be number!\n");
		}
		if (hasDuplicateNumber(guessNumber))
			throw LengthError("should not have the same number!\n");
	}

	int strikes(const std::string& guessNumber) {
		int result{};
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == answer[i])
				++result;
		}
		return result;
	}

	int balls(const std::string& guessNumber) {
		int result{};
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				if (i == k) continue;
				if (guessNumber[i] == answer[k])
					++result;
			}
		}
		return result;
	}

	string answer;
};