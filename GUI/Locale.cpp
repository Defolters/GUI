#include "Locale.h"


std::string Locale::GetDescription(const char * request)
{
	return data["descriptions"][request];
}

std::string Locale::GetInvite(const char * request)
{
	return data["invites"][request];
}

std::string Locale::GetElementName(const char * request)
{
	return data["elements_names"][request];
}

Locale::Locale(const char * locale_path)
{
	std::ifstream locale(locale_path);
	locale >> data;
}

Locale::~Locale()
{
}
