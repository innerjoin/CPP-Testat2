#include "Word.h"
#include "Kwic.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

using set_vect = std::set<std::vector<Word>>;
using vect_vect = std::vector<std::vector<Word>>;
using isw_it = std::istream_iterator<Word>;

std::ostream& operator << (std::ostream &os, std::vector<Word> const &sentence) {
    copy(sentence.begin(), sentence.end(), std::ostream_iterator<Word>(os, " "));
    return os;
}

void kwic(std::istream &is, std::ostream &os) {
    vect_vect lines {};
    set_vect rLines {};
    std::string line;
    while(std::getline(is, line)) {
        std::istringstream lineStream { line };
        std::vector<Word> sentence;
        std::copy(isw_it(lineStream), isw_it(), std::back_inserter(sentence));
        lines.push_back(sentence);
    }

    std::for_each(lines.begin(), lines.end(), [&rLines](std::vector<Word> sentence){
    	auto rotations = getRotationsForWords(sentence);
    	rLines.insert(rotations.begin(), rotations.end());
    });

    std::for_each(rLines.begin(), rLines.end(), [&os](auto rLine){
    	os << rLine << "\n";
    });
}

 set_vect getRotationsForWords(std::vector<Word> words) {
     set_vect rotations { };
     for (size_t i=0; i< words.size();++i) {
         std::rotate(words.begin(), words.begin() + 1, words.end());
         rotations.insert(words);
     }
     return rotations;
}