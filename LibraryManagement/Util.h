#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#define BorrowAdress "./ReaderBorrowed/"
using namespace std;



class Util
{
public:


	bool static CheckFile(string filename)
	{
		fstream file;
		file.open(filename);
		if (!file.is_open()) return false;
		if (!file.eof()) return false;
		file.close();
		return true;
	}

	std::string static StandizeName(string& s) {
		std::string result = s;

		// Convert the first letter of each word to uppercase
		bool capitalizeNext = true;
		for (char& c : result) {
			if (std::isalpha(c)) {
				if (capitalizeNext) {
					c = std::toupper(c);
					capitalizeNext = false;
				}
				else {
					c = std::tolower(c);
				}
			}
			else {
				capitalizeNext = true;
			}
		}

		// Remove extra spaces
		char pos = result.find("  ");
		while (pos != std::string::npos) {
			result.erase(pos, 1);
			pos = result.find("  ");
		}
		// Trim leading and trailing spaces
		char firstNonSpace = result.find_first_not_of(" ");
		char lastNonSpace = result.find_last_not_of(" ");
		result = result.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);

		return result;
	}


	string static StandardlizeDate(string &s)
	{
		if(s[2] != '/' && s[2] != string::npos)
		{
			s = "0" + s;
		}
		if(s[5] != '/' && s[5] != string::npos)
		{
			s.insert(3, "0");
		}
		else
		{
			if(s.size() > 3)
			{
				s.insert(3, "0");
			}
		}
	}
	bool static isLeepYear(int year)
	{
		if (year % 400 == 0)
			return true;

		if (year % 4 == 0 && year % 100 != 0)
			return true;

		return false;
	}



	int static FindDay(int month, int year)
	{
		switch (month)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		{
			return 31;
			break;
		}
		case 2:
		{
			if (isLeepYear(year))
			{
				return 29;
			}
			return 28;
		}
		case 4:case 6:case 9:case 11:
		{
			return 30;
		}
		}
	}

	void static addDay(string date, int numDay) {
		int d, m, y;
		istringstream iss(date);
		char delimiter;

		if (!(iss >> d >> delimiter >> m >> delimiter >> y)) {
			cout << "Invalid date format: " << date << endl;
			return;
		}

		while (numDay--) {
			int daysInMonth = FindDay(m, y);

			if (d == daysInMonth) {
				d = 1;

				if (m == 12) {
					m = 1;
					y++;
				}
				else {
					m++;
				}
			}
			else {
				d++;
			}
		}
	}

};