#if !defined(BOOST_VMD_DETAIL_MATCH_IDENTIFIER_HPP)
#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_HPP

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/control/while.hpp>
#include <boost/preprocessor/logical/bitand.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/replace.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/detail/idprefix.hpp>

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_ID(state) \
	BOOST_PP_TUPLE_ELEM(0,state) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_KEY_TUPLE(state) \
	BOOST_PP_TUPLE_ELEM(1,state) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_KEY_TUPLE_SIZE(state) \
	BOOST_PP_TUPLE_ELEM(2,state) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_KEY_CURRENT(state) \
	BOOST_PP_TUPLE_ELEM \
		( \
		BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_INDEX(state), \
		BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_KEY_TUPLE(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_INDEX(state) \
	BOOST_PP_TUPLE_ELEM(3,state) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_RESULT(state) \
	BOOST_PP_TUPLE_ELEM(4,state) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP_CREATE_ID_RESULT(id,keyid) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_DETAIL_IDENTIFIER_DETECTION_PREFIX, \
		BOOST_PP_CAT \
			( \
			keyid, \
			BOOST_PP_CAT \
				( \
				_, \
				id \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP_CMP_IDS(id,keyid) \
	BOOST_VMD_IS_EMPTY \
		( \
		BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP_CREATE_ID_RESULT(id,keyid) \
		) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_PRED(d,state) \
	BOOST_PP_BITAND \
		( \
		BOOST_PP_EQUAL \
			( \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_RESULT(state), \
			0 \
			), \
		BOOST_PP_NOT_EQUAL \
			( \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_INDEX(state), \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_KEY_TUPLE_SIZE(state) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP_FOUND(d,state) \
	BOOST_PP_TUPLE_REPLACE \
		( \
		state, \
		4, \
		BOOST_PP_INC \
			( \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_INDEX(state) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP_CONTINUE(d,state) \
	BOOST_PP_TUPLE_REPLACE \
		( \
		state, \
		3, \
		BOOST_PP_INC \
			( \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_INDEX(state) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP_CMP_IDS \
			( \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_ID(state), \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_STATE_KEY_CURRENT(state) \
			), \
		BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP_FOUND, \
		BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP_CONTINUE \
		) \
	(d,state) \
/**/

/*

  Return index starting with 1 of the tuple id the identifier matches, or 0 if there are no matches.

*/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER(id,keytuple) \
	BOOST_PP_TUPLE_ELEM \
		( \
		4, \
		BOOST_PP_WHILE \
			( \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_PRED, \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP, \
				( \
				id, \
				keytuple, \
				BOOST_PP_TUPLE_SIZE(keytuple), \
				0, \
				0 \
				) \
			) \
		) \
/**/

/*

  Return index starting with 1 of the tuple id the identifier matches, or 0 if there are no matches.

*/

#define BOOST_VMD_DETAIL_MATCH_IDENTIFIER_D(d,id,keytuple) \
	BOOST_PP_TUPLE_ELEM \
		( \
		4, \
		BOOST_PP_WHILE_ ## d \
			( \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_PRED, \
			BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP, \
				( \
				id, \
				keytuple, \
				BOOST_PP_TUPLE_SIZE(keytuple), \
				0, \
				0 \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_MATCH_SINGLE_IDENTIFIER(id,key) \
	BOOST_VMD_DETAIL_MATCH_IDENTIFIER_OP_CMP_IDS(id,key) \
/**/

#endif /* BOOST_VMD_DETAIL_MATCH_IDENTIFIER_HPP */
