#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)


namespace Lib {
	const int MAX_LEN = 21;
	const int MAX_SIZE = 10;

	enum class Status { Available, Borrowed, Reserved };

	struct Book {
		char title[MAX_LEN];
		char author[MAX_LEN];
		int publicationYear;
		Status status;
	};

	struct Library {
		Book Books[MAX_SIZE];
		char name[MAX_LEN];
		int bookCount;
	};

	void addBook(Library& l, const char* title, const char* author, int year) {
		if (l.bookCount == 10 || !title || !author)
			return;
		Book& b = l.Books[l.bookCount];
		strcpy(b.title, title);
		strcpy(b.author, author);
		b.publicationYear = year;
		b.status = Status::Available;
		l.bookCount++;
	}

	void borrowBook(Book& b) {
		if (b.status == Status::Available)
			b.status = Status::Borrowed;
		else
			std::cout << "Book not available";
	}

	void reserveBook(Book& b) {
		if (b.status == Status::Available)
			b.status = Status::Reserved;
		else
			std::cout << "Book not available";
	}

	void PrintStatus(const Book b) {
		switch (b.status)
		{
		case Status::Available:
			std::cout << "Book status: Available";
			break;
		case Status::Reserved:
			std::cout << "Book status: Reserved";
			break;
		case Status::Borrowed:
			std::cout << "Book status: Borrowed";
			break;
		}
	}

	void printLibrary(const Library& l) {
		std::cout << l.name << std::endl;
		std::cout << "------------------------------" << std::endl;
		for (size_t i = 0; i < l.bookCount; i++)
		{
			std::cout <<
				"Book title: " << l.Books[i].title << std::endl <<
				"Book author: " << l.Books[i].author << std::endl <<
				"Book publish date: " << l.Books[i].publicationYear << std::endl;
			PrintStatus(l.Books[i]);
			std::cout << std::endl << "------------------------------" << std::endl;
		}
	}
}

int main() {
	Lib::Library myLibrary;
	strcpy(myLibrary.name, "My Library");
	myLibrary.bookCount = 0;

	//add
	Lib::addBook(myLibrary, "1984", "George Orwell", 1949);
	Lib::addBook(myLibrary, "To Kill a Mockingbird", "Harper Lee", 1960);
	Lib::addBook(myLibrary, "The Great Gatsby", "F. Scott Fitzgerald", 1925);

	Lib::printLibrary(myLibrary);	//print

	Lib::borrowBook(myLibrary.Books[0]);	//borrow
	Lib::printLibrary(myLibrary);

	Lib::reserveBook(myLibrary.Books[1]);	//reserve
	Lib::printLibrary(myLibrary);


	return 0;
}