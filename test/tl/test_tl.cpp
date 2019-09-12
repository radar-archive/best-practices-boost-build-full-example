// Copyright 2019 RADAR, Inc. - All Rights Reserved
// Proprietary and confidential

/// @file

#define BOOST_TEST_MODULE test_tl

#include "boost/test/included/unit_test.hpp"

#include <iostream>

#include "tl/tl.hpp"

BOOST_AUTO_TEST_CASE (test_tl_all)
{
   std::cout << tl::s << "\n";
}
