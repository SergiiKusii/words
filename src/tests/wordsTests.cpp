#define BOOST_TEST_MODULE WordsTest

#include <boost/test/unit_test.hpp>

#include "wordslib/Parser.h"
#include "wordslib/WordsInfo.h"

using namespace boost::unit_test::framework;

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
   BOOST_CHECK(wordsinfo.getMaxWord() == "aaaa" );
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
