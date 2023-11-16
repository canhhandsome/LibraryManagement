// LibraryManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "Reader.h"
#include "Book.h"
#include "Library.h"
using namespace std;

int main()
{
	ArrListB booklist;
	booklist.ReadFile("Book.txt");
	booklist.displayInfor(1, booklist.len);
	Library l;
	l.LoginPage();
	return 0;
}