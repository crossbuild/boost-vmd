#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/elem.hpp>
#include <boost/vmd/is_empty.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/list/at.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS

  #define BOOST_VMD_REGISTER_ggh (ggh)
  
  #define ANIDENTIFIER ggh
  #define ANUMBER 249
  #define ASEQ (25)(26)(27)
  #define ATUPLE (0,1,2,3,((a,b))((c,d))((e))((f,g,h)))
  #define ALIST (0,(1,(2,(3,BOOST_PP_NIL))))
  #define ALIST2 (10,(11,(12,(13,BOOST_PP_NIL))))
  #define ALIST3 (100,(101,(102,(103,BOOST_PP_NIL))))
  #define ALIST5 (200,(201,(202,(203,BOOST_PP_NIL))))
  #define ANARRAY (3,(a,b,38))
  #define ANARRAY2 (5,(c,d,133,22,15))
  #define ASEQUENCE ANUMBER ALIST ATUPLE ANIDENTIFIER ANARRAY ASEQ
  #define ASEQUENCE2 ANIDENTIFIER ANARRAY2 ASEQ ALIST2 ATUPLE
  #define ASEQUENCE3 ASEQ ANIDENTIFIER ATUPLE ALIST3
  #define ASEQUENCE4
  #define ASEQUENCE5 ALIST5 ASEQ ATUPLE ANIDENTIFIER

  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(0,ASEQUENCE,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(0,ASEQUENCE2,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(0,ASEQUENCE3,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST))));
  
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(1,ASEQUENCE,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST))));
  BOOST_TEST_EQ(BOOST_PP_LIST_AT(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(1,ASEQUENCE,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST)),3),3);
  BOOST_TEST_EQ(BOOST_PP_LIST_AT(BOOST_VMD_ELEM(1,ASEQUENCE,BOOST_VMD_TYPE_LIST),2),2);
  
  BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(3,BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(3,ASEQUENCE2,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST))),3);
  BOOST_TEST_EQ(BOOST_PP_LIST_AT(BOOST_VMD_ELEM(3,ASEQUENCE2,BOOST_VMD_TYPE_LIST),1),11);
  
  BOOST_TEST_EQ(BOOST_PP_LIST_AT(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(3,ASEQUENCE3,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST)),2),102);
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(3,ASEQUENCE3,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST))));
  BOOST_TEST_EQ(BOOST_PP_LIST_AT(BOOST_VMD_ELEM(3,ASEQUENCE3,BOOST_VMD_TYPE_LIST),0),100);
 
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(0,ASEQUENCE4,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(0,ASEQUENCE4,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,ASEQUENCE4,BOOST_VMD_TYPE_LIST)));
  
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(0,ASEQUENCE5,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_LIST))));
  BOOST_TEST_EQ(BOOST_PP_LIST_AT(BOOST_VMD_ELEM(0,ASEQUENCE5,BOOST_VMD_TYPE_LIST),2),202);
  
#else

BOOST_ERROR("No variadic macro support");
  
#endif

  return boost::report_errors();
  
  }