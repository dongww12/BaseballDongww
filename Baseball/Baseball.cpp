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

class Baseball {
public:
	void guess(const string& guessNumer) {
		if (guessNumer.size() != 3)
			throw LengthError("length should be 3!\n");
		for (auto ch : guessNumer) {
			if (ch < '0' || ch > '9')
				throw InvaildArgument("should be number!\n");
		}
	}
};