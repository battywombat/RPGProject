#include <iostream>

#include "MapBuilder.h"


bool MapBuilder::_AddRow(std::string row)
{
	if (row.size() != this->_width) {
		return false;
	}
	auto newRow = std::vector<std::shared_ptr<Space>>();
	for (auto iter = row.begin(); iter != row.end(); iter++) {
		newRow.push_back(std::shared_ptr<Space>(new Space(this->_aliases[*iter].get())));
	}
	this->_data.push_back(newRow);
	return true;
}

bool MapBuilder::_HandleAliasKey(std::string key, std::string value)
{
	if (key == "CAPACITY") {
		this->_alias_capacity = stoi(value);
	}
	else {
		return false;
	}
	return true;
}

void MapBuilder::_CreateAlias()
{
	Symbol *s = new Symbol(this->_alias_sym);
	this->_aliases[this->_alias_sym] = std::unique_ptr<Space>(new Space(s, this->_alias_capacity));
}

bool MapBuilder::Start()
{
	this->_m = nullptr;
	this->_data = std::vector<std::vector<std::shared_ptr<Space>>>();
	this->_width = -1;
	this->_rows = std::vector<std::string>();
	this->_building_alias = false;
	this->_aliases = std::map<char, std::unique_ptr<Space>>();
	return true;
}

bool MapBuilder::Finish()
{
  //if (this->_width == -1) {
  //		return false;
  //	}

	for (auto iter = this->_rows.begin(); iter != this->_rows.end(); iter++) {
		if (!this->_AddRow(*iter)) {
			return false;
		}
	}
	this->_m = new Map(this->_name, this->_data);
	return true;
}

Map * MapBuilder::GetMap()
{
	return this->_m;
}

MapBuilder::MapBuilder()
{
}

MapBuilder::~MapBuilder()
{
}

bool MapBuilder::HandleKey(std::string key, std::string value)
{
	if (this->_building_alias) {
		if (this->_HandleAliasKey(key, value)) {
			return true;
		}
		else {
			this->_CreateAlias();
		}
	}
	if (key == "NAME") {
		this->_name = value;
	}
	else if (key == "WIDTH") {
		this->_width = std::stoi(value);
	}
	else if (key == "ADD_ROW") {
		this->_rows.push_back(value);
	}
	else if (key == "SYMBOL_ALIAS") {
		this->_building_alias = true;
		this->_alias_sym = value[0];
	}
	else {
		return false;
	}

	return true;
}

