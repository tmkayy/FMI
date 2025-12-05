#include <iostream>
#include <fstream>

//hw
namespace consts{
	constexpr int MAX_LEN = 50;
}

namespace logs {
	enum class messageType {
		INFO, ERROR
	};

	struct message {
		messageType type;
		char message[consts::MAX_LEN];
	};



	void inputMessage() {

	}
}

int main() {
	return 0;
}