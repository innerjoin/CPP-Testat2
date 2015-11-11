#include "Word.h"
#include "Kwic.h"
#include <algorithm>

void kwic(std::istream &is, std::ostream &os) {

}

std::set<std::vector<Word>> getRotationsForWords(std::vector<Word> words) {
    std::set<std::vector<Word>> rotations { };

    for (auto _unused_ : words) {
        std::rotate(words.begin(), words.begin() + 1, words.end());
        rotations.insert(words);
    }

    return rotations;
}
