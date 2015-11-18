#include "Word.h"
#include <istream>

Word::Word(const std::string val) : word { val } {}

void Word::read(std::istream & is) {
	std::string newVal {};
	char character {};

	while (is.get(character)) {
		if(newVal.empty())
			continue;
		else if (std::isalpha(character))
			newVal += character;
		else
			break;
	}

	if(newVal.length() > 0) {
		is.clear();
	}

	this->word = newVal;
}

void Word::print(std::ostream & os) const {
	os << this->word;
}