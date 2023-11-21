//Single Linklist
#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include "Book.h"
#include "Util.h"
using namespace std;

struct Reader
{
	string username;
	string password;
	string id;
	string name;
	string phone;
<<<<<<< HEAD

	ArrListB *b= new ArrListB();
	Reader() {}
	Reader(string username, string password, string id, string name, string phone,ArrListB *b)
=======
	ArrListB* b = new ArrListB();
	
	Reader() {}
	Reader(string username, string password, string id, string name, string phone, ArrListB* b)
>>>>>>> a94dc3d4d8cec59b96a3a4a3ab72b4d6ebd5be5b
	{
		this->username = username;
		this->password = password;
		this->id = id;
		this->name = name; //Util::StandizeName(name);
		this->phone = phone;
		this->b = b;
	}

	bool ReadFile()
	{
		string filename = BorrowAdress + id + ".txt";
		if (Util::CheckFile(filename)) {
			return false;
		}
		b->ReadFile(filename);
		return true;
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
	NodeR* makeNodeR(Reader x); done
	void addReader(Reader x); done
	void removeReader(Reader x); done
	int SizeOfList(); done
	Reader searchId(string ID); done
	Reader searchName(string name); done
	void sortID(); // bubble done
	void sortName(); // bubble done
	void displayReader(); 
	void ReadFile(); 
	void inputReader(); 
	void UpdateReader();
	*/
	//Methods
	

	NodeR* makeNodeR(Reader x) 
	{
		NodeR* newNodeR = new NodeR();
		newNodeR->data = x;
		newNodeR->next = NULL;
		return newNodeR;
	}
	void AddReader(Reader x) 
	{
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
	int SizeOfList()
	{
        int cnt = 0;
        NodeR *current = head;
        while(current != NULL)
		{
            ++cnt;
            current = current->next;
        }
        return cnt;
    }
	void SortID()
	{
		int size = SizeOfList();
		if(size == 1 || size == 0) return;
		for(int i = 0; i < size - 1; i++)
		{
			NodeR *tmp1 = head;
			NodeR *tmp2 = head->next;
			for(int j = 0; j < size - 1 - i; j++)
			{
				if(tmp1->data.id > tmp2->data.id)
				{
					swap(tmp1->data, tmp2->data);
				}
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}
		}
	}
	void SortName()
	{
		int size = SizeOfList();
		if(size == 1 || size == 0) return;
		for(int i = 0; i < size - 1; i++)
		{
			NodeR *tmp1 = head;
			NodeR *tmp2 = head->next;
			for(int j = 0; j < size - 1 - i; j++)
			{
				int index1 = 0, index2 = 0;
				string name1[100];
				string name2[100];
				string contain1;
				string contain2;
				stringstream ss1(tmp1->data.name);
				stringstream ss2(tmp2->data.name);
				while(ss1 >> contain1)
				{
					name1[index1++] = contain1;
				}
				while(ss2 >> contain2)
				{
					name2[index2++] = contain2;
				}
				while(index1 >= 0 && index2 >= 0)
				{
					index1--;
					index2--;
					if(name1[index1] > name2[index2])
					{
						swap(tmp2->data, tmp1->data);
						break;
					}
				}
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}
		}
	}
	void displayReader() {
		cout << "--------------------------------------------------------------\n";
		cout << "| No. | Reader ID | Name                | Phone              |\n";
		cout << "--------------------------------------------------------------\n";

		NodeR* current = head;
		int count = 1;

		while (current != NULL) {
			cout << "|" << setw(5) << count << "|";
			cout << setw(11) << current->data.id << "|";
			cout << setw(21) << current->data.name << "|";
			cout << setw(20) << current->data.phone << "|\n";

			current = current->next;
			count++;
		}

		cout << "--------------------------------------------------------------\n";
	}

	Reader SearchId(string ID)
    {
        NodeR* current = head;
        while (current != NULL)
        {
            if (current->data.id == ID)
            {
                return current->data;
            }
            current = current->next;
        }
        // Return an empty Reader object if the ID is not found
        return Reader();
    }
	Reader SearchName(string Name)
    {
        NodeR* current = head;
        while (current != NULL)
        {
            // Assuming that the search should be case-insensitive
            if (current->data.name == Util::StandizeName(Name))
            {
                return current->data;
            }
            current = current->next;
        }
        // Return an empty Reader object if the name is not found
        return Reader();
    }

	bool ReadFile(string filename)
	{
		ifstream file(filename);
		if (!file) {
			cerr << "Error opening file: " << filename << endl;
			return 0;
		}

		string line;
		while (getline(file, line)) {
			istringstream ss(line);
			// Read using stringstream to avoid issues with mixed reading methods
			Reader reader;
			getline(ss, reader.username, ';');
			getline(ss, reader.password, ';');			
			getline(ss, reader.id, ';');
			getline(ss, reader.name, ';');
			reader.name = Util::StandizeName(reader.name);
			getline(ss, reader.phone);
			if (!reader.ReadFile())
				cout << "Reader " << reader.name << " doesn't borrow any books\n";
			AddReader(reader);
		}

		file.close();
		return 1;
	}
};
//Single Linklist
//Single Linklist
//Single Linklist
