#include "Word.h"
#include "Kwic.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void testWordCompareLess() {
	Word w1 {"halle"};
	Word w2 {"hallo"};

	ASSERT_LESS(w1, w2);
	ASSERT_NOT_EQUAL_TO(w1, w2);
}

void testWordCompareLessEq() {
	Word w1 {"halle"};
	Word w1_ {"halle"};
	Word w2 {"hallo"};

	ASSERT_LESS_EQUAL(w1, w2);
	ASSERT_LESS_EQUAL(w1_, w2);
}

void testWordCompareGreater() {
	Word w1 {"halle"};
	Word w2 {"hallo"};

	ASSERT_GREATER(w2, w1);
	ASSERT_NOT_EQUAL_TO(w1, w2);
}

void testWordCompareGreaterEq() {
	Word w1 {"halle"};
	Word w1_ {"halle"};
	Word w2 {"hallo"};

	ASSERT_GREATER_EQUAL(w2, w1);
	ASSERT_GREATER_EQUAL(w1_, w1);
}

void testWordCompareEqual() {
	Word w1 {"hello"};
	Word w2 {"hello"};
	Word w3 {"HeLlO"};

	ASSERT_EQUAL(w1, w2);
	ASSERT_EQUAL(w2, w3);
}

void testLeftShiftToPrint() {
	std::ostringstream outstream;
	Word w1 {"hello"};
	outstream << w1;
	ASSERT_EQUAL("hello", outstream.str());
}

void testEmptyInput() {
	std::istringstream iss { "     " };
	Word w {};
	iss >> w;
	ASSERT_EQUAL(Word(""), w);
}

void testRightShiftToInput() {
	const int nrOfWrds = 6;
	std::istringstream instream {"   compl33tely ~ weird !!?? !! 4matted in_put"};
	const std::array<std::string, nrOfWrds> res = {"compl", "tely", "weird", "matted", "in", "put"};
	std::array<Word, nrOfWrds> words;
	for(int i = 0; i < nrOfWrds; i++) {
		instream >> words[i];
		ASSERT_EQUAL(Word(res[i]), words[i]);
	}
}

void testKwic() {
    std::istringstream iss {
            "this is a test\n"
            "this is another test"};
    std::string expected {
            "a test this is \n"
            "another test this is \n"
            "is a test this \n"
            "is another test this \n"
            "test this is a \n"
            "test this is another \n"
            "this is a test \n"
            "this is another test \n"};
    std::ostringstream oss;
    kwic(iss, oss);
    ASSERT_EQUAL(expected, oss.str());
}

void testRotationsForWords() {
    std::vector<Word> words = {Word("this"), Word("is"), Word("a"), Word("test")};
    std::set<std::vector<Word>> expected {
            {Word("a"), Word("test"), Word("this"), Word("is")},
            {Word("is"), Word("a"), Word("test"), Word("this")},
            {Word("test"), Word("this"), Word("is"), Word("a")},
            {Word("this"), Word("is"), Word("a"), Word("test")}
    };

    std::set<std::vector<Word>> results = getRotationsForWords(words);
    ASSERT_EQUAL(expected, results);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
    // Word.h
	s.push_back(CUTE(testWordCompareLess));
	s.push_back(CUTE(testWordCompareLessEq));
	s.push_back(CUTE(testWordCompareGreater));
	s.push_back(CUTE(testWordCompareGreaterEq));
	s.push_back(CUTE(testWordCompareEqual));
	s.push_back(CUTE(testLeftShiftToPrint));
    s.push_back(CUTE(testEmptyInput));
	s.push_back(CUTE(testRightShiftToInput));
    // Kwic.h
    s.push_back(CUTE(testKwic));
    s.push_back(CUTE(testRotationsForWords));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



