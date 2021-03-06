#ifndef BUILDER_H

#define BUILDER_H
#include <string>

class Builder
{
protected:
	virtual bool Start();
	virtual bool Finish();
	virtual void Abort();
	void ParseVector(std::string value, int *vec, int lim);
	virtual bool HandleKey(std::string key, std::string value) = 0;
public:
	bool ParseFile(std::string fp);
	Builder();
	~Builder();
};

#endif /* BUILDER_H */

