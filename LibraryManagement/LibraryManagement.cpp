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
	Reader a("22","22","22","Nguyen Nhat An", "211331", booklist);
	Reader b("21","21","21","Nguyen Le Bn", "221n331", booklist);
	SLListR readerlist;
	readerlist.AddReader(b);
	readerlist.AddReader(a);
<<<<<<< HEAD
	  cout << "truoc khi sap xep:"<<endl;
	 readerlist.duyet();
	 cout <<"sau khi sort: "<<endl;
	 readerlist.SortName();
	  readerlist.duyet();
=======
	cout << "truoc khi sap xep:"<<endl;
	readerlist.duyet();
	cout <<"sau khi sort: "<<endl;
	readerlist.SortName();
	readerlist.duyet();
>>>>>>> 05dbdf000ab583b281aad6ac16e5bad9866dd6ec
	Reader test = readerlist.SearchName("   Nguyen nhat AN");
	cout <<test.name<<endl;
	return 0;
}