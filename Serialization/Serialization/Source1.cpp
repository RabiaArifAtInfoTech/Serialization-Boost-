/////.............Serialization Example with Author and Book Classes...........
//
//
//#include<iostream>
//#include<string.h>
//#include<map>
//#include<vector>
//
//#include<fstream>
//
//#include<boost/archive/text_iarchive.hpp>
//#include<boost/archive/text_oarchive.hpp>
//
//
//class Book {
//	
//private:
//	friend class boost::serialization::access;
//	template<class Archive>
//	void serialize(Archive& ar, const unsigned int version)
//	{
//		ar& bookTitle;
//		ar& ISBN;
//		ar& publishYear;
//		ar& bookDetail;
//	}
//	std::string bookTitle;
//	int ISBN;
//	int publishYear;
//	std::string bookDetail;
//public:
//	Book()
//	{
//		std::cout << "\nDefault Constructor of Book called";
//	}
//	Book(std::string bTitle, int ID, int year, std::string detail)
//	{
//
//		std::cout << "\nConstructor of Book called";
//
//		bookTitle = bTitle;
//		ISBN = ID;
//		publishYear = year;
//		bookDetail = detail;
//
//	}
//	int getPublishyear()
//	{
//		return publishYear;
//	}
//	int getISBN()
//	{
//		return ISBN;
//	}
//	std::string getBookTitle()
//	{
//		return bookTitle;
//	}
//	std::string getBookDetail()
//	{
//		return bookDetail;
//	}
//	/*Book& operator=(std::shared_ptr<Author>& shPtr)
//	{
//		std::cout << "\nCopy operator of Author is called\n";
//
//		return *this;
//	}*/
//	Book& operator*()
//	{
//		return *this;
//
//	}
//	Book* operator->()
//	{
//		return this;
//	}
//	~Book()
//	{
//		std::cout << "\nDestructor of Book called\n";
//	}
//};
//
//
//
//
//int main()
//{
//	std::ofstream ofsBook("BookFile");
//	Book book1("BOOK1", 100, 2023, "\"New Book to be written in file BookFile\"\n");
//
//	
//	//Book book2("BOOK2", 101, 2023, "New Book2 to be written in file");
//	//Saving Author class in File
//	{
//		boost::archive::text_oarchive oaBook(ofsBook);
//	    // write class instance to archive
//		oaBook & book1;
//	}
//
//	Book newBook1;
//	{
//        // create and open an archive for input
//		std::ifstream ifs("BookFile");
//	    boost::archive::text_iarchive ia(ifs);
//	    // read class state from archive
//		ia& newBook1;
//	        // archive and stream closed when destructors are called
//	}
//		
//	std::cout << "\n\nNewBook Title: " << newBook1.getBookTitle();
//	std::cout << "\nNewBook Number: " << newBook1.getISBN();
//	std::cout << "\nNewBook Year: " << newBook1.getPublishyear();
//	std::cout << "\nNewBook Detail: " << newBook1.getBookDetail();
//	
//	
//
//
//	//std::cout << "\n\n\n";
//	return 0;
//}