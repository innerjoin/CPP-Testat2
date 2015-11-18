#include "Word.h"
#include "Kwic.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

using set_vect = std::set<std::vector<Word>>;

std::ostream& operator << (std::ostream &os, std::vector<Word> const &sentence) {
    copy(sentence.begin(), sentence.end(), std::ostream_iterator<Word>(os, " "));
    return os;
}

void kwic(std::istream &is, std::ostream &os) {
    //using iterator = std::istream_iterator<std::vector<Word>>;
    std::vector<std::vector<Word>> lines;
    std::set<std::vector<Word>> rLines{ };
    std::string line;
    while(std::getline(is, line)) {
        std::vector<Word> sentence;
        std::istringstream lineStream { line };
        Word w;
        while(lineStream >> w) {
            sentence.push_back(w);
        }
        lines.push_back(sentence);
    }

    for (auto sentence : lines) {
		auto rotations = getRotationsForWords(sentence);
		rLines.insert(rotations.begin(), rotations.end());
	}

    for (auto rLine : rLines) {
        os << rLine << "\n";
	}
}

 set_vect getRotationsForWords(std::vector<Word> words) {
     set_vect rotations { };
     for (auto _unused_ : words) {
         std::rotate(words.begin(), words.begin() + 1, words.end());
         rotations.insert(words);
     }
     return rotations;
}