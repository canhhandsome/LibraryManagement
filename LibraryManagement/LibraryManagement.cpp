// LibraryManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "Reader.h"
#include "Book.h"
#include "Library.h"
using namespace std;

int main()
{
	ArrListB b;
	b.ReadFile("Book.txt");
	b.displayInfor(1, b.len);
	/*b.inputBook(1);
	b.UpdateBook("Book.txt");*/
	return 0;
}