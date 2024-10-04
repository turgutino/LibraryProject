#include<iostream>
using namespace std;

struct Book
{
	int history;
	double price;
	char* author;
	char* title;
};

struct BookItem
{
	Book* book;
	int quantity;
};

struct Library
{
	BookItem** items;
	int size = 0;
};

void Show_Book(Book*& book) {
	cout << "Date of publication : " << book->history << endl;
	cout << "Book Price : " << book->price << " $ " << endl;
	cout << "Book Author : " << book->author << endl;
	cout << "Book title : " << book->title << endl;
}

void Show_BookItem(BookItem*& bookItem) {
	Show_Book(bookItem->book);
	cout << "Quantity : " << bookItem->quantity << endl;
}



void Show_Library(Library*& library) {
	for (size_t i = 0; i < library->size; i++)
	{
		cout << "------------------- No " << i + 1 << " -------------------" << endl;
		Show_BookItem(library->items[i]);
	}
}





void Add_Book(Library*& library) {
	Book* book = new Book{ 0,0,new char[30] {},new char[60] {} };

	cout << "Enter Book History : ";
	cin >> book->history;

	cout << "Enter Book Price : ";
	cin >> book->price;

	cout << "Enter Book Author : ";
	cin >> book->author;

	cout << "Enter Book Name : ";
	cin >> book->title;


	BookItem* item = new BookItem{ book,0 };
	cout << "Enter Book Quantity : ";
	cin >> item->quantity;

	auto items = new BookItem * [library->size + 1] {};

	for (size_t i = 0; i < library->size; i++)
	{
		items[i] = library->items[i];
	}
	items[library->size] = item;
	library->size += 1;
	library->items = items;

	cin.ignore();

}


void Search_Book(Library*& library) {
	int ID;
	cout << "Enter Book ID : ";
	cin >> ID;
	ID = ID - 1;


	for (size_t i = 0; i < library->size; i++)
	{
		if (i == ID) {

			cout << "------------------- No " << ID + 1 << " -------------------" << endl;
			Show_BookItem(library->items[i]);
		}
	}

}

void Update_Book(Library*& library) {
	int ID;
	cout << "Enter Book ID to update : ";
	cin >> ID;
	ID = ID - 1;

	if (ID >= 0 && ID < library->size) {
		Book* book = library->items[ID]->book;

		cout << "Enter new Book History : ";
		cin >> book->history;

		cout << "Enter new Book Price : ";
		cin >> book->price;

		cin.ignore();
		cout << "Enter new Book Author : ";
		cin.getline(book->author, 30);

		cout << "Enter new Book Title : ";
		cin.getline(book->title, 60);

		cout << "Enter new Book Quantity: ";
		cin >> library->items[ID]->quantity;

		cout << "Book successfully updated!" << endl;
	}
	else {
		cout << "Invalid Book ID!" << endl;
	}
}



void Delete_Book(Library*& library) {
	int ID;
	cout << "Enter Book ID to delete: ";
	cin >> ID;
	ID = ID - 1;

	if (ID < 0 || ID >= library->size) {
		cout << "Invalid ID!" << endl;
		return;
	}


	delete[] library->items[ID]->book->author;
	delete[] library->items[ID]->book->title;
	delete library->items[ID]->book;
	delete library->items[ID];


	auto newItems = new BookItem * [library->size - 1] {};


	for (int i = 0, j = 0; i < library->size; i++) {
		if (i != ID) {
			newItems[j] = library->items[i];
			j++;
		}
	}

	delete[] library->items;
	library->items = newItems;
	library->size -= 1;
	cout << "Book successfully deleted!" << endl;
}

void Clear_Library(Library*& library) {
	for (int i = 0; i < library->size; i++) {
		delete[] library->items[i]->book->author;
		delete[] library->items[i]->book->title;
		delete library->items[i]->book;
		delete library->items[i];
	}
	delete[] library->items;
	library->size = 0;
	cout << "Library cleared!" << endl;
}


int main() {
	Book* b1 = new Book{ 1997,12.99,new char[30] {"J.K Rowling"},new char[60] {"Harry Potter and the Philosopher's Stone"} };
	Book* b2 = new Book{ 1998,14.99,new char[30] {"J.K Rowling"},new char[60] {"Harry Potter and the Chamber of Secrets"} };
	Book* b3 = new Book{ 1999,13.99,new char[30] {"J.K Rowling"},new char[60] {"Harry Potter and the Prisoner of Azkaban"} };
	Book* b4 = new Book{ 2000,13.99,new char[30] {"J.K Rowling"},new char[60] {"Harry Potter and the Goblet of Fire"} };
	Book* b5 = new Book{ 2003,16.99,new char[30] {"J.K Rowling"},new char[60] {"Harry Potter and the Order of the Phoenix "} };


	BookItem* item1 = new BookItem{ b1,2 };
	BookItem* item2 = new BookItem{ b2,11 };
	BookItem* item3 = new BookItem{ b3,6 };
	BookItem* item4 = new BookItem{ b4,8 };
	BookItem* item5 = new BookItem{ b5,3 };


	Library* library = new Library;
	library->items = new BookItem * [5] {item1, item2, item3, item4, item5};
	library->size = 5;

	while (true) {
		cout << endl;
		cout << "----------------------------------------You can make some changes to the book----------------------------------------" << endl;
		cout << endl;
		cout << "1 -> Show Library" << endl;
		cout << "2 -> Add Book" << endl;
		cout << "3 -> Search Book" << endl;
		cout << "4 -> Uptade Book" << endl;
		cout << "5 -> Delete Book" << endl;
		cout << "6 -> Cleaner Library" << endl;
		cout << "7 -> EXIT" << endl;
		cout << endl;
		char select;
		cout << "Enter choose one : ";
		cin >> select;
		if (select == '1') {
			cout << endl;
			cout << endl;
			cout << "---------------------------------------------------Our Library------------------------------------------------- " << endl;
			cout << endl;
			cout << endl;
			Show_Library(library);
		}
		else if (select == '2') {
			cout << endl;
			cout << endl;
			cout << "---------------------------------------------------Add Book------------------------------------------------- " << endl;
			cout << endl;
			cout << endl;
			Add_Book(library);
			cout << endl;
			cout << "The book was successfully added" << endl;
			cout << endl;
		}
		else if (select == '3') {
			cout << endl;
			cout << endl;
			cout << "---------------------------------------------------Search Book------------------------------------------------- " << endl;
			cout << endl;
			cout << endl;
			Search_Book(library);
			cout << endl;

			cout << endl;
		}
		else if (select == '4') {
			cout << endl;
			cout << endl;
			cout << "---------------------------------------------------Update Book------------------------------------------------- " << endl;
			cout << endl;
			cout << endl;
			Update_Book(library);

			cout << endl;

			cout << endl;
		}
		else if (select == '5') {
			cout << endl;
			cout << endl;
			cout << "---------------------------------------------------Delete Book------------------------------------------------- " << endl;
			cout << endl;
			cout << endl;
			Delete_Book(library);
			cout << endl;

			cout << endl;
		}
		else if (select == '6') {
			cout << endl;
			cout << endl;
			cout << "---------------------------------------------------Cleaner Library------------------------------------------------- " << endl;
			cout << endl;
			cout << endl;
			Clear_Library(library);
			cout << endl;

			cout << endl;
		}
		else if (select == '7') {
			cout << "----------------------------------------------------------EXIT----------------------------------------------------------";
			break;
		}
		else {
			cout << "Please select correct one!!!";
		}

	}
	return 0;

}
