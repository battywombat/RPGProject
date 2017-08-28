#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>

#include "Builder.h"

// trim from start (in place)
static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
	}));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

bool Builder::Start()
{
	return true;
}

bool Builder::Finish()
{
	return true;
}

void Builder::Abort()
{
}

bool Builder::ParseFile(std::string fp)
{
	std::string line;
	std::ifstream f;

	f.open(fp);

	if (!f) {
		return false;
	}

	if (!Start()) {
		f.close();
		Abort();
		return false;
	}

	std::string::iterator colon_pos;
	std::string key, value;

	while (!f.eof()) {
		std::getline(f, line);
		ltrim(line);
		rtrim(line);
		if (line.size() < 5 || line[0] != '[' || line[line.size() - 1] != ']') {
			continue;
		}
		colon_pos = std::find(line.begin(), line.end(), ':');
		if (colon_pos == line.end()) {
			f.close();
			Abort();
			return false;
		}
		key = std::string(line.begin() + 1, colon_pos);
		value = std::string(colon_pos + 1, line.end() - 1);
		if (!this->HandleKey(key, value)) {
			Abort();
			f.close();
			return false;
		}
		
	}

	f.close();
	return Finish();
}

void Builder::ParseVector(std::string value, int * vec, int lim)
{
	std::stringstream ss;
	ss.str(value);
	std::string item;
	int i = 0;
	while (std::getline(ss, item, ',')) {
		vec[i++] = stoi(item);
		if (i >= lim) {
			break;
		}
	}
}

Builder::Builder()
{
}


Builder::~Builder()
{
}
