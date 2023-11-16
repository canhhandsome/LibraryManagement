//Single Linklist
#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include "Book.h"
#include "Util.h"
using namespace std;

class Reader
{
private:
	string username;
	string password;
	string id;
	string name;
	string phone;
public:
	ArrListB b;
	Reader() {}
	Reader(string username, string password, string id, string name, string phone, ArrListB b)
	{
		this->username = username;
		this->password = password;
		this->id = id;
		this->name = Util::StandizeName(name);
		this->phone = phone;
		this->b = b;
	}

	string getName()
	{
		return name;
	}
	// Methods
	/*
	bool Login();
	void borrowBook(Book b);
	void returnBook(Book b);
	string checkExpired(Book b);
	void displayInfor();
	*/

	~Reader(){}
};

//Single Linklist
//Single Linklist
//Single Linklist


struct NodeR
{
	Reader data;
	NodeR* next;
};

class SLListR
{
private:
	NodeR* head = NULL;
public:

	//Methods
	/*
	NodeR* makeNodeR(Reader x);
	void addReader(Reader x);
	void removeReader(Reader x);
	Reader searchId(string ID); 1 
	Reader searchName(string name); 
	void sortID(); // bubble
	void sortName(); // bubble
	void displayReader();
	void ReadFile();
	void inputReader();
	void UpdateReader();
	*/
	//Methods


	NodeR* makeNodeR(Reader x) {
		NodeR* newNodeR = new NodeR();
		newNodeR->data = x;
		newNodeR->next = NULL;
		return newNodeR;
	}
	void AddReader(Reader x) {
		NodeR* newNode = makeNodeR(x);
		newNode->next = head;
		head = newNode;
	}
	void RemoveReader() {
		if (head == NULL) {
			return;
		}
		NodeR* firstNode = head;
		head = head->next;
		delete firstNode;
	}
};
//Single Linklist
//Single Linklist
//Single Linklist
