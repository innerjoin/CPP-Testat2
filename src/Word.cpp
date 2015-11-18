#include "Word.h"
#include <istream>

Word::Word(const std::string val) : word { val } {}

void Word::read(std::istream & is) {
	std::string newVal {};
	char character {};

	while (is.get(character)) {
		if (std::isalpha(character))
			newVal += character;
		else if(!newVal.empty())
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