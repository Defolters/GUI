#include "UIDGenerator.h"



UIDGenerator::UIDGenerator()
{
}


UIDGenerator::~UIDGenerator()
{
}

UIDGenerator & UIDGenerator::Instance()
{
	static UIDGenerator s;
	return s;
}

int UIDGenerator::GenerateID()
{
	totalElements++;
	return totalElements-1;	
}
