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
	//Library l;
	//l.LoginPage();
	//Book a("B013", "Con Cho", BookGenre::Fantasy, "Adam Smith", "Tyler Robinson", "22/11/2003", 5);
	//  Reader a("22","22","22","Nguyen Nhat An", "211331", &booklist);
	//  Reader b("21","21","21","Nguyen Le Bn", "221n331", &booklist);
	// SLListR readerlist;
	// readerlist.AddReader(b);
	// readerlist.AddReader(a);

	// // cout << "truoc khi sap xep:"<<endl;
	// // readerlist.duyet();
	// // cout <<"sau khi sort: "<<endl;
	// // readerlist.SortName();
	// // readerlist.duyet();
	// booklist.sortDatePublish();
	// booklist.displayInfor(1, booklist.len);
	booklist.inputBook(1);
	return 0;
}