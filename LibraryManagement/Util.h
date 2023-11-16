#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Util
{
public:
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

	void static addDay(string date, int numDay)
	{
		int d = 0, m = 0, y = 0;
		istringstream iss(date);
		string data;
		getline(iss, data, '/');	
		d = stoi(data);
		getline(iss, data, '/');	
		m = stoi(data);
		getline(iss, data, '/');	
		y = stoi(data);
		while (numDay--)
		{
			if (m == 12 && d == FindDay(m, y))
			{
				y++;
				m = 1;
				d = 1;
			}
			else if (m < 12 && d == FindDay(m, y))
			{
				m++;
				d = 1;
			}
			else d++;
		}
		cout << "\t\t\tThe next day: " << d << "/" << m << "/" << y << endl;
	}


};