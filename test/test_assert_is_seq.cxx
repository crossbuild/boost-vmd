#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/assert_is_seq.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS

  BOOST_VMD_ASSERT_IS_SEQ((x))
  BOOST_VMD_ASSERT_IS_SEQ((x)(y))
  BOOST_VMD_ASSERT_IS_SEQ((x)(y)(z)(2)(3)(4))
  BOOST_VMD_ASSERT_IS_SEQ((x)(y)(z)((1,2))(3)(4))
  BOOST_VMD_ASSERT_IS_SEQ((x)(y)(z)((1,2))(3)((4,(x,BOOST_VMD_NIL))))
  BOOST_VMD_ASSERT_IS_SEQ((x)(y)((x)(y)(z)(2)(3)(4))((1,2))(3)((4,(x,BOOST_VMD_NIL))))

#endif

  return boost::report_errors();
  
  }
