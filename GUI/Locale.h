#pragma once
#include "General\json.hpp"
#include <fstream>
// for convenience
using json = nlohmann::json;

class Locale
{
	json data;
public:
	std::string GetDescription(const char*);
	std::string GetInvite(const char*);
	std::string GetElementName(const char*);
	Locale(const char*);
	~Locale();
};

