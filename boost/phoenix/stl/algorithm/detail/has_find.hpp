#line 1 "include/boost/phoenix/stl/algorithm/detail/has_find.hpp"
///////////////////////////////////////////////////////////////////////////////
// Copyright 2005 Daniel Wallin.
// Copyright 2005 Joel de Guzman.
// Copyright 2015 John Fletcher
//
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// Modeled after range_ex, Copyright 2004 Eric Niebler
///////////////////////////////////////////////////////////////////////////////
//
// has_find.hpp
//
/////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_PHOENIX_HAS_FIND_EN_14_12_2004
#define BOOST_PHOENIX_HAS_FIND_EN_14_12_2004

#include <boost/mpl/or.hpp>
#include "./is_std_map.hpp"
#include "./is_std_set.hpp"
#include "./is_std_hash_map.hpp"
#include "./is_std_hash_set.hpp"
#include "./is_unordered_set_or_map.hpp"

namespace boost
{
    // Specialize this for user-defined types
    template<typename T>
    struct has_find
        : boost::mpl::or_<
            boost::mpl::or_<
                is_std_map<T>
              , is_std_multimap<T>
              , is_std_set<T>
              , is_std_multiset<T>
            >
          , boost::mpl::or_<
                is_std_hash_map<T>
              , is_std_hash_multimap<T>
              , is_std_hash_set<T>
              , is_std_hash_multiset<T>
          >
          , boost::mpl::or_<
                is_std_unordered_map<T>
              , is_std_unordered_multimap<T>
              , is_std_unordered_set<T>
              , is_std_unordered_multiset<T>
            >
        >
    {
    };
}

#endif
