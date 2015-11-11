#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iosfwd>

class Word {

private:
	std::string word = "";

public:
	explicit Word(const std::string word="");

	void read(std::istream &is);
	void print(std::ostream &os) const;

	inline bool operator >(const Word &w) const {
	    return std::lexicographical_compare(
				this->word.begin(), this->word.end(),
	    		w.word.begin(), w.word.end(),
	    		[](const char l, const char r){
	    	return std::tolower(l) > std::tolower(r);
	    });
	}

	inline bool operator <(const Word &w) const {
		return w > *this;
	}

	inline bool operator >=(const Word &w) const {
		return !(*this < w);
	}

	inline bool operator <=(const Word &w) const {
		return !(*this > w);
	}

	inline bool operator ==(const Word &w) const {
		return !(w > *this && w < *this);
	}

	inline bool operator !=(const Word &w) const {
		return (w > *this || w < *this);
	}
};

inline std::istream & operator>>(std::istream &is, Word &w) {
	w.read(is);
	return is;
}

inline std::ostream & operator<<(std::ostream &os, const Word &w) {
	w.print(os);
	return os;
}

//inline bool is_palindrome(std::string ps){
////	int i = 0;
////	int j = ps.length() - 1;
////	for(; i <= j; i++, j--) {
////		if(tolower(ps[i]) != tolower(ps[j])) return false;
////	}
////	return true;
////
////	std::transform(ps.begin(), ps.end(), ps.begin(), tolower);
//    std::cout << "hello" + ps; // test only!!
//    return equal(ps.begin(), ps.end(), ps.rbegin(),[](char l,char r){
//    	return tolower(l)!=tolower(r);
//    });
//
//}

#endif
