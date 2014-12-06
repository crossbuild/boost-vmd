#if !defined(BOOST_VMD_DETAIL_AFTER_NUMBER_HPP)
#define BOOST_VMD_DETAIL_AFTER_NUMBER_HPP

#include <boost/vmd/generic/elem.hpp>
#include <boost/vmd/types.hpp>
#include <boost/vmd/detail/elem_after.hpp>

#define BOOST_VMD_DETAIL_ELEM_AFTER_NUMBER(elem,vseq) \
	BOOST_VMD_DETAIL_ELEM_AFTER(BOOST_VMD_ELEM(elem,vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE,BOOST_VMD_RETURN_AFTER),BOOST_VMD_TYPE_NUMBER) \
/**/

#endif /* BOOST_VMD_DETAIL_AFTER_NUMBER_HPP */
