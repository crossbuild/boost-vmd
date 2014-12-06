#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/number/after_number_elem.hpp>
#include <boost/vmd/is_empty.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS
    
  #define BOOST_VMD_REGISTER_ggh (ggh)
  
  #define ANIDENTIFIER ggh
  #define ANUMBER 249
  #define ANUMBER2 25
  #define ANUMBER3 158
  #define ANUMBER5 73
  #define ASEQ (25)(26)(27)
  #define ATUPLE (0,1,2,3,((a,b))((c,d))((e))((f,g,h)))
  #define ALIST (0,(1,(2,(3,BOOST_PP_NIL))))
  #define ANARRAY (3,(a,b,38))
  #define ANARRAY2 (5,(c,d,133,22,15))
  #define ASEQUENCE ANUMBER ALIST ATUPLE ANIDENTIFIER ANARRAY ASEQ
  #define ASEQUENCE2 ANIDENTIFIER ANARRAY2 ASEQ ALIST ANUMBER2 ATUPLE
  #define ASEQUENCE3 ASEQ ANUMBER3 ANIDENTIFIER ATUPLE
  #define ASEQUENCE4
  #define ASEQUENCE5 ASEQ ANUMBER5 ATUPLE ANIDENTIFIER

  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_AFTER_NUMBER_ELEM(0,ASEQUENCE)));
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_AFTER_NUMBER_ELEM(4,ASEQUENCE2)));
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_AFTER_NUMBER_ELEM(1,ASEQUENCE3)));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_AFTER_NUMBER_ELEM(0,ASEQUENCE4)));
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_AFTER_NUMBER_ELEM(1,ASEQUENCE5)));
  
#endif

  return boost::report_errors();
  
  }
