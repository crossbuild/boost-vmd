#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/array/array_elem.hpp>
#include <boost/vmd/is_empty.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>
#include <boost/preprocessor/array/elem.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/tuple/elem.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS

  #define BOOST_VMD_REGISTER_ggh (ggh)
  #define BOOST_VMD_REGISTER_dvd (dvd)
  
  #define ANIDENTIFIER ggh
  #define ANIDENTIFIER2 dvd
  #define ANUMBER 249
  #define ANUMBER2 17
  #define ASEQ (25)(26)(27)
  #define ATUPLE (0,1,2,3,((a,b))((c,d))((e))((f,g,h)))
  #define ALIST (0,(1,(2,(3,BOOST_PP_NIL))))
  #define ANARRAY (3,(a,b,38))
  #define ANARRAY2 (5,(c,d,133,22,15))
#if !BOOST_VMD_MSVC_V8
  #define ANARRAY_EMPTY (0,())
#endif
  #define ASEQUENCE ANUMBER ALIST ATUPLE ANIDENTIFIER ANARRAY ASEQ
  #define ASEQUENCE2 ANIDENTIFIER2 ANARRAY2 ASEQ ALIST ANUMBER ATUPLE
  #define ASEQUENCE3 ASEQ ANUMBER2 ATUPLE
  #define ASEQUENCE4
#if !BOOST_VMD_MSVC_V8
  #define ASEQUENCE5 ASEQ ANUMBER ANARRAY_EMPTY ATUPLE
#endif
  
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ARRAY_ELEM(0,ANIDENTIFIER,BOOST_VMD_RETURN_AFTER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ARRAY_ELEM(0,ANIDENTIFIER,BOOST_VMD_RETURN_AFTER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ARRAY_ELEM(0,ANIDENTIFIER)));
  
  BOOST_TEST_EQ(BOOST_PP_SEQ_ELEM(2,BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ARRAY_ELEM(4,ASEQUENCE,BOOST_VMD_RETURN_AFTER))),27);
  BOOST_TEST_EQ(BOOST_PP_ARRAY_ELEM(2,BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ARRAY_ELEM(4,ASEQUENCE,BOOST_VMD_RETURN_AFTER))),38);
  BOOST_TEST_EQ(BOOST_PP_ARRAY_SIZE(BOOST_VMD_ARRAY_ELEM(4,ASEQUENCE)),3);
  
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ARRAY_ELEM(1,ASEQUENCE2,BOOST_VMD_RETURN_AFTER))));
  BOOST_TEST_EQ(BOOST_PP_ARRAY_ELEM(3,BOOST_VMD_ARRAY_ELEM(1,ASEQUENCE2)),22);
  
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ARRAY_ELEM(1,ASEQUENCE3,BOOST_VMD_RETURN_AFTER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ARRAY_ELEM(1,ASEQUENCE3,BOOST_VMD_RETURN_AFTER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ARRAY_ELEM(1,ASEQUENCE3)));
 
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ARRAY_ELEM(0,ASEQUENCE4,BOOST_VMD_RETURN_AFTER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ARRAY_ELEM(0,ASEQUENCE4,BOOST_VMD_RETURN_AFTER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ARRAY_ELEM(0,ASEQUENCE4)));
  
#if !BOOST_VMD_MSVC_V8
  BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(2,BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ARRAY_ELEM(2,ASEQUENCE5,BOOST_VMD_RETURN_AFTER))),2);
  BOOST_TEST_EQ(BOOST_PP_ARRAY_SIZE(BOOST_VMD_ARRAY_ELEM(2,ASEQUENCE5)),0);
#endif
  
#endif

  return boost::report_errors();
  
  }
