#include "CharacterBuilder.h"

bool CharacterBuilder::_HandleSymKey(std::string key, std::string value)
{
	if (key == "BG") {
		ParseVector(value, (int *)this->_bg, 3);
	}
	else if (key == "FG") {
		ParseVector(value, (int *)this->_fg, 3);
	}
	else {
		return false;
	} 
	return true;
}

CharacterBuilder::CharacterBuilder()
{
	_c = nullptr;
}


CharacterBuilder::~CharacterBuilder()
{
}

Character * CharacterBuilder::GetCharacter()
{
	return _c;
}

bool CharacterBuilder::HandleKey(std::string key, std::string value)
{
	if (_parsing_sym) {
		if (!_HandleSymKey(key, value)) {
			_parsing_sym = false;
		}
		else {
			return true;
		}
	}
	if (key == "SYMBOL") {
		_symnum = stoi(value);
		_parsing_sym = true;
	}
	else {
		return false;
	}
	return true;
}

bool CharacterBuilder::Start()
{
	_c = nullptr;
	return true;
}

bool CharacterBuilder::Finish()
{
	_c = new Character(new Symbol(_symnum, _fg[0], _fg[1], _fg[2], _bg[0], _bg[1], _bg[2]));
	return true;
}
