#if !defined(BOOST_VMD_DETAIL_SPLIT_TUPLE_HPP)
#define BOOST_VMD_DETAIL_SPLIT_TUPLE_HPP

#include <boost/vmd/generic/elem.hpp>
#include <boost/vmd/types.hpp>
#include <boost/vmd/detail/elem_split.hpp>

#define BOOST_VMD_DETAIL_ELEM_SPLIT_TUPLE(elem,...) \
	BOOST_VMD_DETAIL_ELEM_SPLIT(BOOST_VMD_ELEM(elem,__VA_ARGS__,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE),BOOST_VMD_TYPE_TUPLE) \
/**/

#define BOOST_VMD_DETAIL_ELEM_SPLIT_TUPLE_D(d,elem,...) \
	BOOST_VMD_DETAIL_ELEM_SPLIT(BOOST_VMD_ELEM_D(d,elem,__VA_ARGS__,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE),BOOST_VMD_TYPE_TUPLE) \
/**/

#endif /* BOOST_VMD_DETAIL_SPLIT_TUPLE_HPP */
