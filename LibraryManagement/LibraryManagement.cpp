// LibraryManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "Reader.h"
#include "Book.h"
#include "Library.h"
using namespace std;

int main()
{
<<<<<<< HEAD
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
	//  cout << "truoc khi sap xep:"<<endl;
	// readerlist.duyet();
	// cout <<"sau khi sort: "<<endl;
	// readerlist.SortName();
	//  readerlist.duyet();
	/*Reader test = readerlist.SearchName("   Nguyen nhat AN");
	cout <<test.id<<endl;*/
	booklist.inputBook(1);
	booklist.displayInfor(1,booklist.len);
	booklist.displayInfor(1, booklist.len);
=======
	ArrListB b;
	b.ReadFile("Book.txt");
	b.displayInfor(1, b.len);
	b.inputBook(1);
	b.UpdateBook("Book.txt");
>>>>>>> a94dc3d4d8cec59b96a3a4a3ab72b4d6ebd5be5b
	return 0;
}