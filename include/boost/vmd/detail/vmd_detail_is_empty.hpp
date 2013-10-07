#if !defined(VMD_DETAIL_IS_EMPTY_HPP)
#define VMD_DETAIL_IS_EMPTY_HPP

#if BOOST_VMD_MSVC

# pragma warning(once:4002)

#define VMD_DETAIL_IS_EMPTY_IIF_0(t, b) b
#define VMD_DETAIL_IS_EMPTY_IIF_1(t, b) t

#else

#define VMD_DETAIL_IS_EMPTY_IIF_0(t, ...) __VA_ARGS__
#define VMD_DETAIL_IS_EMPTY_IIF_1(t, ...) t

#endif /* BOOST_VMD_MSVC */

#define VMD_DETAIL_IS_EMPTY_PRIMITIVE_CAT(a, b) a ## b
#define VMD_DETAIL_IS_EMPTY_IIF(bit) \
    VMD_DETAIL_IS_EMPTY_PRIMITIVE_CAT(VMD_DETAIL_IS_EMPTY_IIF_,bit) \
/**/

#define VMD_DETAIL_IS_EMPTY_NON_FUNCTION_C() ()

#endif /* VMD_DETAIL_IS_EMPTY_HPP */