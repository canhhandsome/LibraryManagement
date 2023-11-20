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
	ArrListB books;
public:

	Library()
	{
		books.ReadFile("Book.txt");
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
		return true;
	}
	bool loginReader()
	{
		return true;
	}

	void LoginPage()
	{
		int choice;
		do {
			cout << "     Welcome to UTE_Library!\n";
			cout << "------------------------------------\n";
			cout << "| 1. Login Admin                   | \n";
			cout << "| 2. Login Reader                  |\n";
			cout << "| 3. Exit                          |\n";
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
				cout << "Exiting...\n";
				break;
			default:
				cout << "Invalid choice. Please enter a valid option.";
			}

		} while (choice != 3);
	}


	void addBook()
	{
		books.inputBook(1);
	}

	void addReader()
	{

	}

	void borrowBook()
	{

	}
	void findBook()
	{

	}
	void sortBook()
	{

	}

	void findReader()
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
			cout << "| 2. Add Reader                    |\n";
			cout << "| 3. Find Reader                   |\n";
			cout << "| 4. Sort Readers                  |\n";
			cout << "| 5. Update Library                |\n";
			cout << "| 6. Back to Main Menu             |\n";
			cout << "-----------------------------------\n";
			cout << "Enter your choice: ";
			cin >> adminChoice;

			switch (adminChoice) {
			case 1:
				addBook();
				break;
			case 2:
				addReader();
				break;
			case 3:
				findReader();
				break;
			case 4:
				sortReader();
				break;
			case 5:
				updateLibrary();
				break;
			case 6:
				cout << "Returning to Login Page...\n";
				_getch();
				system("cls");
				break;
			default:
				cout << "Invalid choice. Please enter a valid option.\n";
			}

		} while (adminChoice != 6);
	}


	void MenuReader() {
		int readerChoice;
		do {
			system("cls");
			books.displayInfor(1, books.len);
			cout << "\n         Reader Menu \n";
			cout << "-----------------------------------\n";
			cout << "| " << "Welcome " << r.name   << "                         |\n";
			cout << "| 1. Get Days Expired              |\n";
			cout << "| 2. Check Expired Books           |\n";
			cout << "| 3. Borrow a Book                 |\n";
			cout << "| 4. Find a Book                   |\n";
			cout << "| 5. Sort Books                    |\n";
			cout << "| 6. Back to Login Page            |\n";
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
				cout << "Returning to Login Page...\n";
				_getch();
				system("cls");
				break;
			default:
				cout << "Invalid choice. Please enter a valid option.\n";
			}

		} while (readerChoice != 6);
	}

	void ReadFile()
	{

	}

	void updateLibrary() // write file
	{

	}
};