#if !defined(BOOST_VMD_DETAIL_SEQUENCE_HPP)
#define BOOST_VMD_DETAIL_SEQUENCE_HPP

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/control/while.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/preprocessor/seq/push_back.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/push_back.hpp>
#include <boost/preprocessor/tuple/replace.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/vmd/array.hpp>
#include <boost/vmd/identifier.hpp>
#include <boost/vmd/is_begin_tuple.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/list.hpp>
#include <boost/vmd/number.hpp>
#include <boost/vmd/seq.hpp>
#include <boost/vmd/tuple.hpp>
#include <boost/vmd/types.hpp>

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
	BOOST_PP_TUPLE_ELEM(0,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state) \
	BOOST_PP_TUPLE_ELEM(1,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_IS_EMPTY(state) \
	BOOST_VMD_IS_EMPTY \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_FROM_EMPTY(state,ttuple) \
	(ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_TO_SEQ(state,ttuple) \
	BOOST_PP_SEQ_PUSH_BACK(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state),ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD(state,ttuple) \
	BOOST_PP_IIF \
	 	( \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_IS_EMPTY(state), \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_FROM_EMPTY, \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_TO_SEQ \
	 	) \
	 (state,ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state) \
		BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state),BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state) \
		BOOST_PP_TUPLE_ELEM(2,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state) \
		BOOST_PP_TUPLE_ELEM(3,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_UNKNOWN(d,state) \
	( \
	, \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD(state,(BOOST_VMD_TYPE_UNKNOWN,BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state))), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state), \
	BOOST_PP_INC(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state)) \
	) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_GET_FULL_TYPE(state) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_TYPE_, \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state) \
		) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_PROCESS(state,tuple) \
	( \
	BOOST_PP_TUPLE_ELEM(1,tuple), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD \
		( \
		state, \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_GET_FULL_TYPE(state), \
			BOOST_PP_TUPLE_ELEM(0,tuple) \
			) \
		), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state), \
	BOOST_PP_INC(BOOST_PP_TUPLE_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state))) \
	) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ_SINGLE(tuple) \
	BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(0,tuple)),1) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_ISEQ(state,tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_GET_FULL_TYPE(state), \
			BOOST_VMD_TYPE_SEQ \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ_SINGLE, \
		BOOST_VMD_IDENTITY(0) \
		) \
	(tuple) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ(state,tuple) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_ISEQ(state,tuple)) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND(state,tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ(state,tuple), \
		BOOST_VMD_DETAIL_SEQUENCE_INCREMENT_INDEX, \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_PROCESS \
		) \
	(state,tuple) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_INCREMENT_INDEX(state,tuple) \
	BOOST_PP_TUPLE_REPLACE(state,3,BOOST_PP_INC(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state))) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_TUPLE(state,tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_PP_TUPLE_ELEM(0,tuple) \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_INCREMENT_INDEX, \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND \
		) \
	(state,tuple) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE(call,state) \
	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_TUPLE \
		( \
		state, \
		call(BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state)) \
		) \
/**/
	
#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE \
		( \
		BOOST_PP_CAT \
			( \
			BOOST_VMD_, \
			BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state) \
			), \
		state \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state), \
			BOOST_PP_TUPLE_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state)) \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_UNKNOWN, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_PRED(d,state) \
	BOOST_PP_NOT_EQUAL \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state), \
		BOOST_PP_INC(BOOST_PP_TUPLE_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state))) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN(d,state) \
	BOOST_PP_WHILE_ ## d \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_PRED, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP, \
		BOOST_PP_TUPLE_PUSH_BACK(BOOST_PP_TUPLE_PUSH_BACK(state,(SEQ,LIST,ARRAY,TUPLE)),0) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_ID_LOOP(d,state) \
	BOOST_PP_WHILE_ ## d \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_PRED, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP, \
		BOOST_PP_TUPLE_PUSH_BACK(BOOST_PP_TUPLE_PUSH_BACK(state,(NUMBER,IDENTIFIER)),0) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_ID_EL(d,state) \
	( \
	BOOST_VMD_AFTER_LIST_D(d,BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state)), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD(state,(BOOST_VMD_TYPE_LIST,BOOST_PP_NIL)) \
	) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_ID(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY_LIST \
			( \
			BOOST_VMD_BEGIN_IDENTIFIER \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
				) \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_OP_ID_EL, \
		BOOST_VMD_DETAIL_SEQUENCE_OP_ID_LOOP \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_REDUCE_STATE(state) \
	(BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state),BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_OP_REDUCE_STATE \
		( \
		BOOST_PP_IIF \
			( \
			BOOST_VMD_IS_BEGIN_TUPLE \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
				), \
			BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN, \
			BOOST_VMD_DETAIL_SEQUENCE_OP_ID \
			) \
		(d,state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PRED(d,state) \
	BOOST_PP_NOT \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE(vseq) \
	BOOST_PP_TUPLE_ELEM \
		( \
		1, \
		BOOST_PP_WHILE \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_PRED, \
			BOOST_VMD_DETAIL_SEQUENCE_OP, \
			(vseq,) \
			) \
		) \
/**/

#endif /* BOOST_VMD_DETAIL_SEQUENCE_HPP */
