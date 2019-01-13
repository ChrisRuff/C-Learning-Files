#include <iostream>

using namespace std;

class Book
{
	private:
		string title;
	  	string author;
	   	int pages;

	public:
		Book()
		{
			title = "N/A";
			author = "N/A";
			pages = 0;
		}
			
	   	Book(string name, string author, int pages)
		{
			title = name;
			this->author = author;
			this->pages = pages;
		}
		void setTitle(string title)
		{
			this->title = title;
		}
		void setAuthor(string author)
		{
			this->author = author;
		}
		void setPages(int pages)
		{
			this->pages = pages;
		}
		string getTitle()
		{
			return title;
		}
		string getAuthor()
		{
			return author;
		}
		int getPages()
		{
			return pages;
		}
		
};

class Novel : public Book
{
	private:
		int chapters;
	public:
		Novel(string name, string author, int pages, int chapters)
		{
		 	Book(name, author, pages);
			this->chapters = chapters;
		}	
	
		void setChapters(int chapters)
		{
			this->chapters = chapters;
		}
		int getChapters()
		{
			return chapters;
		}
};

int main()
{
	Book book("Harry Potter", "JK Rowling", 500);
	//book1.setTitle = "Harry Potter";
	//book1.setAuthor = "JK Rowling";
	//book1.setPages = 500;

	Novel novel("Lord of the Rings", "Tolkein", 1000, 50);
	//book2.setTitle = "Lord of the Rings";
	//book2.setAuthor = "Tolkein";
	//book2.setPages = 1000;

	Book book3;

	cout << book.getAuthor() << endl;	
	cout << novel.getChapters() << endl;
	cout << book3.getTitle();
	return 0;	
}