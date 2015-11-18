#ifndef KWIC_H_
#define KWIC_H_

#include "Word.h"
#include <iosfwd>
#include <vector>
#include <set>

void kwic(std::istream &is, std::ostream &os);
std::set<std::vector<Word>> getRotationsForWords(std::vector<Word> words);

#endif
