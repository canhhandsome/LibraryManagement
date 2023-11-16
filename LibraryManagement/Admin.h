#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include "Book.h"
using namespace std;

class Admin
{
private:
	string username;
	string password;
public:
	Admin() {}
	Admin(string username, string password)
	{
		this->username = username;
		this->password = password;
	}
	// Methods
	
	bool login()
	{
		cout << "Enter your username: "; cin >> this->username;
		cout << "Enter your password: "; cin >> this->password;
		if (username == "LibraryManagement" && password == "admin")
			return true;
		return false;
	}

	~Admin() {}
};

