#pragma once
#include "General\json.hpp"
#include <fstream>
// for convenience
using json = nlohmann::json;
/*!
\brief Класс локализации

Десериализует файл с локалью формата json и предоставляет доступ к нему
*/
class Locale
{
	json data;//!< файл с локализацией
public:
	/*!
	\brief Получение локализированной строки
	\param request название запроса

	Метод возвращающий локализированную строку описания
	*/
	std::string GetDescription(const char*);
	/*!
	\brief Получение локализированной строки
	\param request название запроса

	Метод возвращающий локализированную строку приглашения пользователя к действию
	*/
	std::string GetInvite(const char*);
	/*!
	\brief Получение локализированной строки
	\param request название запроса

	Метод возвращающий локализированную строку с названием элемента
	*/
	std::string GetElementName(const char*);
	/*!
	\brief Конструктор класса

	\param locale_path адрес файла с локалью

	Конструктор класса с локализацией из json файла
	*/
	Locale(const char*);
	~Locale();
};
