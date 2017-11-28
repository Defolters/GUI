#pragma once
//Singletone
class UIDGenerator
{
private:
	int totalElements = 0;
	UIDGenerator();
	~UIDGenerator();
public:
	UIDGenerator(UIDGenerator const&) = delete;
	UIDGenerator& operator= (UIDGenerator const&) = delete;
	static UIDGenerator& Instance();
	int GenerateID();
};

