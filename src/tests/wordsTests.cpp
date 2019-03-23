#define BOOST_TEST_MODULE WordsTest

#include <boost/test/unit_test.hpp>

#include <thread>

#include "wordslib/Parser.h"
#include "wordslib/WordsInfo.h"

using namespace boost::unit_test::framework;

void test_in_thread(const std::string& inWords, const size_t count, const std::string& mostFriquent)
{
   Parser parser;
   auto words = parser.parse(inWords);
   WordsInfo wordsinfo(words);

   BOOST_CHECK(wordsinfo.getCount() == count);

   BOOST_CHECK(wordsinfo.getMostFrequentWord() == mostFriquent );
}

BOOST_AUTO_TEST_CASE( wordsTest1 )
{
   Parser parser;
   auto words = parser.parse("aaaa bbb ccc ccc");
   WordsInfo wordsinfo(words);

   BOOST_CHECK(wordsinfo.getCount() == 4);

   auto revers = wordsinfo.getReverse();
   auto itbegin = std::begin(revers);
   BOOST_CHECK(itbegin != std::end(revers));
   BOOST_CHECK(*itbegin == "ccc" );

   BOOST_CHECK(wordsinfo.getMostFrequentWord() == "ccc" );
   BOOST_CHECK(wordsinfo.getLongestWord() == "aaaa" );
}

BOOST_AUTO_TEST_CASE( wordsTest2 )
{
   Parser parser;
   auto words = parser.parse("aaa  q  bbb");
   WordsInfo wordsinfo(words);

   BOOST_CHECK( wordsinfo.getCount() == 3 );

   words = parser.parse(" aaa   bbb ");

   BOOST_CHECK(wordsinfo.getCount() == 2);
   BOOST_CHECK(*words.begin() == "aaa");
}

BOOST_AUTO_TEST_CASE( wordsTestMultithread )
{
   std::thread th1(test_in_thread, "first second last most last", 5, "last");
   std::thread th2(test_in_thread, "1 2 2 3 3 3 4 4 4 4 5 5 5 5 5", 15, "5");

   if (th1.joinable()){
      th1.join();
   }

   if (th2.joinable()){
      th2.join();
   }
}
