#pragma once
/*!
\brief Генератор ID

Выдает id поочереди начиная с 0
*/
class UIDGenerator
{
private:
	int totalElements = 0;//!< количество имеющихся элементов
	UIDGenerator();
	~UIDGenerator();
public:
	UIDGenerator(UIDGenerator const&) = delete;
	UIDGenerator& operator= (UIDGenerator const&) = delete;
	/*!
	\brief возвращает ссылку на единственный экземпляр генератора
	*/
	static UIDGenerator& Instance();
	/*!
	\brief метод возвращающий ID
	*/
	int GenerateID();
};
