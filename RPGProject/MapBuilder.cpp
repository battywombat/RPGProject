#include "MapBuilder.h"

bool MapBuilder::_AddRow(std::string row)
{
	if (row.size() != _width) {
		return false;
	}
	auto newRow = std::vector<Space *>();
	for (auto iter = row.begin(); iter != row.end(); iter++) {
		newRow.push_back(new Space(_aliases[*iter].get()));
	}
	_data.push_back(newRow);
	return true;
}

bool MapBuilder::_HandleAliasKey(std::string key, std::string value)
{
	if (key == "CAPACITY") {
		_a_capacity = stoi(value);
	}
	else if (key == "NUM") {
		_a_num = stoi(value);
	}
	else if (key == "FG_COLOR") {
		ParseVector(value, (int *)_a_fg, 3);
	}
	else if (key == "BG_COLOR") {
		ParseVector(value, (int *)_a_bg, 3);
	}
	else if (key == "CHARACTER") {
		_a_char = value;
	}
	else {
		return false;
	}
	return true;
}

void MapBuilder::_CreateAlias()
{
	Symbol *sym = new Symbol(_a_num, _a_fg[0], _a_fg[1], _a_fg[2], _a_bg[0], _a_bg[1], _a_bg[2]);
	Space *s = new Space(sym, _a_capacity);
	if (_a_char != "") {
		_char_builder->ParseFile(_a_char);
		auto c = _char_builder->GetCharacter();
		if (c != nullptr) {
			s->AddContents(c);
		}
	}
	_aliases[_alias_sym] = std::unique_ptr<Space>(s);
}

bool MapBuilder::Start()
{
	_m = nullptr;
	_data = std::vector<std::vector<Space *>>();
	_width = -1;
	_rows = std::vector<std::string>();
	_building_alias = false;
	_aliases = std::map<char, std::unique_ptr<Space>>();
	return true;
}

bool MapBuilder::Finish()
{
  if (_width == -1) {
  		return false;
  	}

	for (auto iter = _rows.begin(); iter != _rows.end(); iter++) {
		if (!_AddRow(*iter)) {
			return false;
		}
	}
	_m = new Map(_name, _data);
	return true;
}

Map *MapBuilder::GetMap()
{
	return _m;
}

MapBuilder::MapBuilder()
{
	_char_builder = std::make_unique<CharacterBuilder>();
}

MapBuilder::~MapBuilder()
{
}

bool MapBuilder::HandleKey(std::string key, std::string value)
{
	if (_building_alias) {
		if (_HandleAliasKey(key, value)) {
			return true;
		}
		else {
			_CreateAlias();
			_building_alias = false;
		}
	}
	if (key == "NAME") {
		_name = value;
	}
	else if (key == "WIDTH") {
		_width = std::stoi(value);
	}
	else if (key == "ADD_ROW") {
		_rows.push_back(value);
	}
	else if (key == "SYMBOL_ALIAS") {
		_building_alias = true;
		_alias_sym = value[0];
		_a_bg[0] = _a_bg[1] = _a_bg[2] = 0;
		_a_fg[0] = _a_fg[1] = _a_fg[2] = 255;
		_a_char = std::string();
	}
	else {
		return false;
	}

	return true;
}

