//#include<iostream>
//#include <fstream>
//
//// include headers that implement a archive in simple text format
//#include<boost/archive/text_oarchive.hpp>
//#include<boost/archive/text_iarchive.hpp>
//
//#include<boost/serialization/access.hpp>
//
///////////////////////////////////////////////////////////////
//// Time
////
//// illustrates serialization for a simple type
////
//class TimeClass
//{
//private:
//    friend class boost::serialization::access;
//    // The declaration friend boost::serialization::access will grant to the serialization library access to private member variables and functions.
//
//
//    // When the class Archive corresponds to an output archive, the & operator is defined similar to <<.    
//    // Likewise, when the class Archive is a type of input archive the & operator is defined similar to >>.
//  
//    
//    template<class Archive>
//    void serialize(Archive& ar, const unsigned int version)
//    {
//        ar& hour;
//        ar& minutes;
//        ar& seconds;
//    }
//
//    int hour;
//    int minutes;
//    float seconds;
//public:
//    TimeClass() : hour(0), minutes(0), seconds(0.0)
//    {}
//    TimeClass(int d, int m, float s) : hour(d), minutes(m), seconds(s)
//    {}
//    int getHour()
//    {
//        return this->hour;
//    }
//    int getMin()
//    {
//        return this->minutes;
//    }
//    float getSec()
//    {
//        return this->seconds;
//    }
//};
//
//
//
//int main() {
//    // create and open a character archive for output
//    std::ofstream ofs("filename");
//
//    // create class instance
//    const TimeClass t1(35, 59, 2919.567f);
//
//    // save data to archive
//    {
//        boost::archive::text_oarchive oa(ofs);
//        // write class instance to archive
//        //oa << t1;  // also working for writing in file
//        oa & t1;
//        // archive and stream closed when destructors are called
//    }
//
//    // ... some time later restore the class instance to its orginal state
//    TimeClass newT;
//    {
//        // create and open an archive for input
//        std::ifstream ifs("filename");
//        boost::archive::text_iarchive ia(ifs);
//        // read class state from archive
//        ia & newT;
//        // archive and stream closed when destructors are called
//    }
//
//    std::cout << newT.getHour() << std::endl;
//    std::cout << newT.getMin() << std::endl;
//    std::cout << newT.getSec() << std::endl;
//
//    return 0;
//}