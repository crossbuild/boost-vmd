#if !defined(VMD_TUPLE_HPP)
#define VMD_TUPLE_HPP

#include "detail/vmd_detail_setup.hpp"

#if BOOST_VMD_VARIADICS

#if BOOST_VMD_PPLIB
#include "vmd_tuple_pplib.hpp"
#else
#include "vmd_tuple_native.hpp"
#endif /* BOOST_VMD_PPLIB */

#endif /* BOOST_VMD_VARIADICS */
#endif /* VMD_TUPLE_HPP */