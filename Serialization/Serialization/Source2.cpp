///.............Serialization Example with Author and Book Classes...........


#include<iostream>
#include<string.h>
#include<map>
#include<vector>

#include<fstream>

#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/text_oarchive.hpp>

#include<boost/serialization/vector.hpp>

class Book;

//template<typename T>
class Author {
private:

	//	Error	C2039	'serialize' : is not a member of 'std::vector<int,std::allocator<int>>'	Serialization	

	friend class boost::serialization::access;


	
	std::string name;
	std::vector<int> bookID;
	int* IDCounter = new int(0);

	//void serialize(Archive& ar, std::vector<int>& bookID, const unsigned int version)

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& name;

		//std::cout << "\n\nSize of IDCounter in serialize : " << this->getCounter();
		int count = this->getCounter();
		ar & count;
		//ar & IDCounter;
		ar & bookID;
	}

public:
	Author()
	{};
	//Author(std::string AuthName, std::vector<int> ID)
	Author(std::string AuthName)
	{
		std::cout << "\nConstructor of Author called";

		name = AuthName;
		IDCounter = new int(0);
	}
	Author(Author& newAuth)
	{
		std::cout << "\nCopy Constructor of Author called";

		name = newAuth.name;

		IDCounter = new int(0);
		IDCounter = newAuth.IDCounter;

		for (auto itr = newAuth.bookID.begin(); itr != newAuth.bookID.end(); itr++) {
			bookID.push_back(*itr);
			(*IDCounter)++;
		}

	}
	void setBookID(int id)
	{
		bookID.push_back(id);
		(*IDCounter)++;
	}
	std::vector<int> getBookIDs()
	{
		return bookID;
	}
	std::vector<int> getbookids()
	{
		return bookID;
	}
	int getCounter()
	{
		return *IDCounter;
	}
	std::string getName()
	{
		std::cout << "\n\nSize of IDCounter: " << this->getCounter() << "\n";
		return name;
	}
	Author& operator*()
	{
		return *this;

	}
	Author* operator->()
	{
		return this;
	}
	~Author() {
		std::cout << "\n\nDestructor of Author called\n\n";
	}

};


//template<typename T>
class Book {

private:
	/*friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& bookTitle;
		ar& ISBN;
		ar& publishYear;
		ar& bookDetail;
	}*/
	std::string bookTitle;
	int ISBN;
	int publishYear;
	std::string bookDetail;
public:
	Book() {};
	Book(std::string bTitle, int ID, int year, std::string detail)
	{

		std::cout << "\nConstructor of Book called";

		bookTitle = bTitle;
		ISBN = ID;
		publishYear = year;
		bookDetail = detail;

	}
	int getPublishyear()
	{
		return publishYear;
	}
	int getISBN()
	{
		return ISBN;
	}
	std::string getBookTitle()
	{
		return bookTitle;
	}
	std::string getBookDetail()
	{
		return bookDetail;
	}
	/*Book& operator=(std::shared_ptr<Author>& shPtr)
	{
		std::cout << "\nCopy operator of Author is called\n";

		return *this;
	}*/
	Book& operator*()
	{
		return *this;

	}
	Book* operator->()
	{
		return this;
	}
	~Book()
	{
		std::cout << "\n\nDestructor of Book called\n\n";
	}
};




int main()
{
	std::ofstream ofsAuth("AuthorFile");
	Book book1("BOOK1", 100, 2023, "\"New Book to be written\"\n");
	Book book2("BOOK2", 101, 2023, "\"New Book2 to be written\"");
	Book book3("BOOK23", 1301, 20223, "\"New Book233 to be written\"");


	Author author1("Author1");


	author1.setBookID(book1->getISBN());
	author1.setBookID(book2->getISBN());
	//.setBookID(book3->getISBN());

	////Saving Author class in File
	{
		boost::archive::text_oarchive oaAuth(ofsAuth);
		oaAuth& author1;
	}

	std::cout << author1.getName();

	std::cout << "\n\nGet Author's 2nd book ID: " << (author1.getBookIDs())[1];
	std::cout << "\nTotal number of books written by this Author: " << (author1.getCounter());

	Author newAuth;
	{
		std::ifstream ifs("AuthorFile");
		boost::archive::text_iarchive ia(ifs);
		//	    // read class state from archive
		ia& newAuth;
	}
	std::cout << newAuth.getName();

	std::cout << "\n\nGet Author's 2nd book ID: " << (newAuth.getBookIDs())[0];
	std::cout << "\n\nGet Author's 2nd book ID: " << (newAuth.getBookIDs())[1];
	//std::cout << "\n\nGet Author's 2nd book ID: " << (newAuth.getBookIDs())[2];
	std::cout << "\nTotal number of books written by this Author: " << (newAuth.getCounter());


	/*std::cout << "\n\nNewBook Title: " << newBook1.getBookTitle() << "\n";
	std::cout << "\nNewBook Number: " << newBook1.getISBN() << "\n";
	std::cout << "\nNewBook Year: " << newBook1.getPublishyear() << "\n";
	std::cout << "\nNewBook Detail: " << newBook1.getBookDetail() << "\n";
*/



	return 0;
}