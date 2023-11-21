#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <conio.h>
#include "Book.h"
#include "Admin.h"
#include "Reader.h"
using namespace std;

class Library
{
private:
	Reader r;
	Admin admin;
	SLListR readers;
	ArrListB* books = new ArrListB();
public:

	Library()
	{
		books->ReadFile("Book.txt");
		readers.ReadFile("Reader.txt");
	}

	//Methods
	/*
	void loginPage();
	bool loginAdmin();
	bool loginReader();
	void addBook();
	void addReader();
	void borrowBook();
	void findBook();
	void sortBook();
	void findReader();
	void sortReader();
	void getDayExpired();
	void checkExpired();
	void fine();
	void MenuAdmin();
	void MenuReader();
	void ReadFile();
	void UpdateLibrary();
	*/
	//Methods

	bool loginAdmin()
	{
		return admin.login();

	}
	bool loginReader()
	{
		return readers.login(r);
	}

	void LoginPage()
	{
		int choice;
		do {
			system("cls");
			cout << "     Welcome to UTE_Library!\n";
			cout << "------------------------------------\n";
			cout << "| 1. Login Admin                   | \n";
			cout << "| 2. Login Reader                  |\n";
			cout << "| 3. Register Reader               |\n";
			cout << "| 4. Exit                          |\n";
			cout << "------------------------------------\n";
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 1:
				if (loginAdmin())
				{
					MenuAdmin();
				}
				else {
					cout << "Login failed. Invalid username or password.\n";
					_getch();
					system("cls");
				}
				break;
			case 2:
				if (loginReader())
				{
					MenuReader();
				}
				else {
					cout << "Login failed. Invalid username or password.";
					_getch();
					system("cls");
				}
				break;
			case 3:
				addReader();
				break;
			case 4:
				cout << "Exiting...\n";
				break;
			default:
				cout << "Invalid choice. Please enter a valid option.";
			}

		} while (choice != 4);
	}


	void addBook()
	{
		books->inputBook(1);
	}

	void addReader()
	{
		readers.inputReader();
	}

	void borrowBook()
	{
		int readerChoice;
		do {
			system("cls");
			books->displayInfor(1, books->len);
			cout << "Welcome " << r.name;
			cout << "\n        Borrow Menu \n";
			cout << "-----------------------------------\n";
			cout << "| 1. Get Days Expired             |\n";
			cout << "| 2. Check Expired Books          |\n";
			cout << "| 3. Borrow a Book                |\n";
			cout << "| 4. Find ID Book                 |\n";
			cout << "| 5. Find Name Book               |\n";
			cout << "| 6. Find Publisher               |\n";
			cout << "| 7. Find Authors                 |\n";
			cout << "| 8. Sort ID Book                 |\n";
			cout << "| 9. Sort Name Book               |\n";
			cout << "| 10. Sort Genre                  |\n";
			cout << "| 11. Sort Publisher              |\n";
			cout << "| 12. Sort Authors                |\n";
			cout << "| 13. Sort Date Publish           |\n";
			cout << "| 14. Back to Menu Page           |\n";
			cout << "-----------------------------------\n";
			cout << "Enter your choice: ";
			cin >> readerChoice;

			switch (readerChoice) {
			case 1:
				getDayExpired();
				break;
			case 2:
				checkExpired();
				break;
			case 3:
				borrowBook();
				break;
			case 4:
				findBook();
				break;
			case 5:
				sortBook();
				break;
			case 6:
				getDayExpired();
				break;
			case 7:
				checkExpired();
				break;
			case 8:
				books->sortID();
				break;
			case 9:
				books->sortNameBook();
				break;
			case 10:
				books->sortGenre();
				break;
			case 11:
				books->sortPublisher();
				break;
			case 12:
				books->sortAuthor();
				break;
			case 13:
				checkExpired();
				break;
			case 14:
				cout << "Returning to Menu Page...\n";
				_getch();
				system("cls");
				break;
			default:
				cout << "Invalid choice. Please enter a valid option.\n";
			}

		} while (readerChoice != 14);
	}
	void findBook()
	{

	}
	void sortBook()
	{

	}


	void sortReader()
	{

	}


	void getDayExpired()
	{

	}


	void checkExpired()
	{

	}

	void fine()
	{

	}

	void MenuAdmin() {
		int adminChoice;
		do {
			system("cls");
			cout << "\nAdmin Menu:\n";
			cout << "-----------------------------------\n";
			cout << "| 1. Add Book                      |\n";
			cout << "| 2. Find ID Reader                |\n";
			cout << "| 3. Find Name Reader              |\n";
			cout << "| 4. Sort ID Reader                |\n";
			cout << "| 5. Sort Name Reader              |\n";
			cout << "| 6. Update Library                |\n";
			cout << "| 7. Back to Main Menu             |\n";
			cout << "-----------------------------------\n";
			cout << "Enter your choice: ";
			cin >> adminChoice;

			switch (adminChoice) {
			case 1:
				addBook();
				break;
			case 2:
			{
				string id;
				cout << "Enter ID Reader: "; cin >> id;
				Reader k = readers.SearchId(id);
				if (k.name.empty()) cout << "There aren't reader you want to find!\n";
				else k.display();
				break;
			}
			case 3:
			{
				string name;
				cout << "Enter Name Reader: "; getline(cin, name);
				Reader k = readers.SearchId(name);
				if (k.name.empty()) cout << "There aren't reader you want to find!\n";
				else k.display();
				break;
			}
			case 4:
			{
				readers.SortID();
				readers.displayReader();
				break;
			}
			case 5:
				readers.SortName();
				readers.displayReader();
				break;
			case 6:
				updateLibrary();
				break;
			case 7:
				cout << "Returning to Login Page...\n";
				_getch();
				system("cls");
				break;
			default:
				cout << "Invalid choice. Please enter a valid option.\n";
			}

		} while (adminChoice != 7);
	}


	void MenuReader() {
		int readerChoice;
		do {
			system("cls");
			cout << "\n         Reader Menu \n";
			int welcomePadding = static_cast<int>((36 - r.name.length()) / 2.0);
			cout << "-----------------------------------\n";
			cout << "| " << "Welcome " << setw(welcomePadding + r.name.length()) << r.name << "|\n";
			cout << "| 1. Borrow Book                  |\n";
			cout << "| 2. Display your books           |\n";
			cout << "| 3. Check Fine                   |\n";
			cout << "| 4. Display Information          |\n";
			cout << "| 5. Back to Login Page           |\n";
			cout << "-----------------------------------\n";
			cout << "Enter your choice: ";
			cin >> readerChoice;

			switch (readerChoice) {
			case 1:
				borrowBook();
				break;
			case 2:
				checkExpired();
				break;
			case 3:
				borrowBook();
				break;
			case 4:
				findBook();
				break;
			case 5:
				cout << "Returning to Login Page...\n";
				_getch();
				system("cls");
				break;
			default:
				cout << "Invalid choice. Please enter a valid option.\n";
			}

		} while (readerChoice != 5);
	}


	void ReadFile()
	{

	}

	void updateLibrary() // write file
	{
		readers.UpdateFile("Reader.txt");
		books->UpdateBook("Book.txt");
	}
};