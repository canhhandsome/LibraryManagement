//Array List
#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "Util.h"
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
        StandizeData();
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

    void StandizeData()
    {
        title = Util::StandizeName(title);
        publisher = Util::StandizeName(publisher);
        author = Util::StandizeName(author);
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

    int partition(int low, int high, const string& fieldName) {
        Book pivot = books[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (fieldName == "idbook" && books[j].idbook < pivot.idbook) {
                i++;
                swap(books[i], books[j]);
            }
            else if (fieldName == "genre" && books[j].genre < pivot.genre) {
                i++;
                swap(books[i], books[j]);
            }
        }

        swap(books[i + 1], books[high]);
        return i + 1;
    }

    // Quicksort algorithm for sorting an array of strings
    void quickSort(int low, int high, const string& fieldName) {
        if (low < high) {
            int pi = partition(low, high, fieldName);

            quickSort(low, pi - 1, fieldName);
            quickSort(pi + 1, high, fieldName);
        }
    }

    void sortID()   //quick
    {
        quickSort(0, len - 1, "idbook");
    }
    void sortNameBook(); // quick
    void sortGenre()    // quick
    {
        quickSort(0, len - 1, "genre");
    }
    void sortPublisher(); // quick

    void sortAuthor(); // quick




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
            bk.StandizeData();
            // Add the read book to the list
            addItem(bk, len);
        }

        file.close();
        return 1;
    }

    void mergeDatePublish(int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        Book* leftArr = new Book[n1];
        Book* rightArr = new Book[n2];
        for (int i = 0; i < n1; i++)
            leftArr[i] = books[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = books[mid + 1 + j];
        int i = 0;
        int j = 0;
        int k = left;
        while (i < n1 && j < n2)
        {
            int index1 = 0, index2 = 0;
            string date1[3];
            string date2[3];
            string contain1;
            string contain2;
            stringstream ss1(leftArr[i].datepublish);
            stringstream ss2(rightArr[j].datepublish);
            while (getline(ss1, contain1, '/'))
            {
                date1[index1++] = contain1;
            }
            while (getline(ss2, contain2, '/'))
            {
                date2[index2++] = contain2;
            }
            for (int i = 0; i < 3; i++)
            {
                cout << date1[i] << " ";
            }
            while (index1 >= 0 && index2 >= 0)
            {
                index1--;
                index2--;
                if (date1[index1] <= date2[index2])
                {
                    books[k] = leftArr[i];
                    i++;
                    break;
                }
                else
                {
                    books[k] = rightArr[j];
                    j++;
                    break;
                }
            }
            k++;
        }
        while (i < n1)
        {
            books[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            books[k] = rightArr[j];
            j++;
            k++;
        }

        // Free the memory allocated for temporary arrays
        delete[] leftArr;
        delete[] rightArr;
    }

    // Recursive function to perform merge sort on datepublish
    void mergeSortDatePublish(int left, int right)
    {
        if (left < right)
        {
            // Same as (left+right)/2, but avoids overflow for large left and right
            int mid = left + (right - left) / 2;

            // Recursively sort the first and second halves
            mergeSortDatePublish(left, mid);
            mergeSortDatePublish(mid + 1, right);

            // Merge the sorted halves based on datepublish
            mergeDatePublish(left, mid, right);
        }
    }
    void sortDatePublish() // merge
    {
        mergeSortDatePublish(0, len - 1);
    }

    int UpdateBook(string filename)
    {
        std::ofstream file(filename);
        if (!file)
        {
            std::cerr << "Error opening file for writing: " << filename << std::endl;
            return 0;
        }

        for (int i = 0; i < len; ++i)
        {
            const Book& bk = books[i];

            // Write book data to the file
            file << bk.idbook << ';'
                << bk.title << ';'
                << bk.genre << ';'
                << bk.publisher << ';'
                << bk.author << ';'
                << bk.datepublish << ';'
                << bk.amount << '\n';
        }

        file.close();
        return 1;
    }

};

