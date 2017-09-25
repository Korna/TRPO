// SimpleParserLab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <regex>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите правило:";

	std::string rule;

	getline(cin, rule);
	std::cout << "\nПравило:" + rule;

	std::cout << "\nВведите строку:";

	std::string input;
	getline(cin, input);
	std::cout << "\nСтрока:" + input;

	std::string newRule;

	regex parseRule(rule);
	smatch matchedStrings;
	if (!regex_match(input, matchedStrings, parseRule))//если запрос был введен неверно
		std::cout << "\nНеверный запрос" << endl;
	else
		std::cout << "\nВерно" << endl;


	getline(cin, input);


	string str = "aaabxxxaab";
	regex rx("ab");

	vector<int> index_matches; // results saved here 
							   // (should be {2, 8}, but always get only {2})

	for (auto it = std::sregex_iterator(str.begin(), str.end(), rx);
		it != std::sregex_iterator();
		++it)
	{
		index_matches.push_back(it->position());
	}


    return 0;
}

