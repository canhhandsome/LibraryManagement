// LibraryManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "Reader.h"
#include "Book.h"
#include "Library.h"
using namespace std;

int main()
{
	
	//Library library;
	//library.LoginPage();
	ArrListB booklist;
	booklist.ReadFile("Book.txt");
	//Library l;
	//l.LoginPage();
	Reader a("22","22","22","Nguyen Nhat An", "211331", &booklist);
	Reader b("21","21","21","Nguyen Le Bn", "221n331", &booklist);
	Reader c("11", "11", "11", "Nguyen Van b", "1111111", &booklist);
	SLListR readerlist;
	readerlist.AddReader(b);
	readerlist.AddReader(a);

	Reader test = readerlist.SearchName("   Nhat AN");
	ArrListB* e = booklist.searchDatePublish("10/4");
	e->displayInfor(1, e->len);
	string s = "10/4";
	Util::StandardlizeDate(s);
	
	return 0;
}