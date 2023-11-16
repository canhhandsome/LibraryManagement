//Array List
#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#define MAX 1000
using namespace std;

enum BookGenre
{
    Mystery = '1',
    ScienceFiction = '2',
    Romance = '3',
    Fantasy = '4',
    NonFiction = '5'
};

struct Book
{
    string idbook;
    string title;
    BookGenre genre;
    string publisher;
    string author;
    string datepublish;
    int amount;
    string dateborrow = "";
    string datereturn = "";

    Book() {}

    Book(string idbook, string title, BookGenre genre, string publisher, string author, string datepublish, int amount)
    {
        this->idbook = idbook;
        this->title = title;
        this->genre = genre;
        this->publisher = publisher;
        this->author = author;
        this->datepublish = datepublish;
        this->amount = amount;
    }

    string BookGenreToString()
    {
        switch (genre)
        {
        case Mystery:
            return "Mystery";
        case ScienceFiction:
            return "Science Fiction";
        case Romance:
            return "Romance";
        case Fantasy:
            return "Fantasy";
        case NonFiction:
            return "Non-Fiction";
        default:
            return "Unknown Genre";
        }
    }

};

struct ArrListB
{
    Book books[MAX];
    int len;
    int maxLen;

    ArrListB()
    {
        len = 0;
        maxLen = MAX;
    }
    // Methods -- 9/21 Functions
    /*
    int isEmpty(); 1
    int isFull(); 1
    int addItem(Book X, int p); 1
    int removeItem(int p); 1
    int GetItem(int p, Book& bk); 1
    Book searchId(string ID);
    ArrListB searchName(string name); //binary search
    ArrListB searchGenre(string Genre); //binary search
    ArrListB searchPublisher(string publisher); //binary search
    ArrListB searchAuthor(string author); //binary search
    ArrListB searchDatePublish(string date); (day, month, year)
    void sortID();// quick
    void sortNameBook(); // quick
    void sortGenre(); // quick
    void sortPublisher(); // quick
    void sortAuthor(); // quick
    void sortDatePublish(); // merge
    int inputBook(int n); 1
    void displayInfor(int f, int t); 1
    int ReadFile(string& filename); 1
    int UpdateBook();
    */
    //Methods


    int isEmpty()
    {
        return len == 0;
    }

    int isFull()
    {
        return len == maxLen;
    }

    int addItem(Book X, int p)
    {
        if (isFull())
        {
            cout << "Danh sach da day, khong them duoc" << endl;
            return 0;
        }
        if (p < 0) p = 0;
        if (p > len) p = len;
        for (int i = len; i > p; i--)
        {
            books[i] = books[i - 1];
        }
        books[p] = X;
        len++;
        return 1;
    }

    int removeItem(int p)
    {
        if (p < 0) p = 0;
        if (p >= len) p = len - 1;
        for (int i = p; i < len - 1; i++)
        {
            books[i] = books[i + 1];
        }
        len--;
        return 1;
    }

    int GetItem(int p, Book& bk)
    {
        if (p < 0 || p >= len) return 0;
        else
        {
            bk = books[p];
            return 1;
        }
    }

    int searchId(string bookId)
    {
        for (int i = 0; i < len; i++)
        {
            if (books[i].idbook == bookId)
            {
                return i + 1;
            }
        }
        return -1;
    }

    int inputBook(int n)
    {
        if (len + n > maxLen)
        {
            return 0;
        }
        else
        {
            Book bk;
            for (int i = 1; i <= n; i++)
            {
                cout << "Book " << i << endl;
                cout << "Enter book ID: ";
                cin >> bk.idbook;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, bk.title);
                cout << "1. Mystery - 2. Science Fiction - 3. Romance - 4. Fantasy - 5. Non-Fiction\n";
                cout << "Enter the genre of the book: ";
                int genreNumber;
                cin >> genreNumber;
                bk.genre = static_cast<BookGenre>(genreNumber);
                cout << "====================" << endl;
                addItem(bk, len);
            }
            return 1;
        }
    }




    void displayInfor(int f, int t) {
        cout << "\n| No. | Book ID | Title                                      | Genre            | Publisher                        | Author                   | Publish Date | Amount |\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        Book bk;
        for (int i = f - 1; i < t; i++) {
            if (GetItem(i, bk) == 0) break;
            cout << "|" << setw(4) << i + 1 << "|";
            cout << setw(9) << bk.idbook << "|";
            cout << setw(45) << bk.title << "|";
            cout << setw(17) << bk.BookGenreToString() << "|";
            cout << setw(35) << bk.publisher << "|";
            cout << setw(26) << bk.author << "|";
            cout << setw(14) << bk.datepublish << "|";
            cout << setw(8) << bk.amount << "|\n";
        }
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }



    int ReadFile(string filename)
    {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file: " << filename << endl;
            return 0;
        }

        string line;
        while (getline(file, line)) {
            istringstream ss(line);
            Book bk;

            // Read using stringstream to avoid issues with mixed reading methods
            getline(ss, bk.idbook, ';');
            getline(ss, bk.title, ';');

            string genreNumber;
            getline(ss, genreNumber, ';');
            char genreChar = genreNumber[0];

            switch (genreChar) {
            case '1':
                bk.genre = Mystery;
                break;
            case '2':
                bk.genre = ScienceFiction;
                break;
            case '3':
                bk.genre = Romance;
                break;
            case '4':
                bk.genre = Fantasy;
                break;
            case '5':
                bk.genre = NonFiction;
                break;
            default:
                cerr << "Invalid genre: " << genreNumber << endl;
                // Handle the error accordingly
            }
            // Use getline for publisher to handle spaces and special characters
            getline(ss, bk.publisher, ';');
            getline(ss, bk.author, ';');
            getline(ss, bk.datepublish, ';');
            ss >> bk.amount;

            // Add the read book to the list
            addItem(bk, len);
        }

        file.close();
        return 1;
    }
};