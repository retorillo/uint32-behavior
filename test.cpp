#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <climits>

// 0U - uX == UINT_MAX - uX + 1U
TEST_CASE( "UINT32 negative overflow" ){
  SECTION( "(0U - 1U) should be UINT_MAX" ) {
    REQUIRE( 0U - 1U == UINT_MAX - 1U + 1U );
  }
  SECTION( "(0 - 2U) should be (UINT_MAX - 1U)" ) {
    REQUIRE( 0U - 2U == UINT_MAX - 2U + 1U );
  }
  SECTION( "(0 - UINT_MAX) should be 1U" ) {
    REQUIRE( 0U - UINT_MAX == UINT_MAX - UINT_MAX + 1U );
  }
}

// UINTMAX + uX == uX - 1U
TEST_CASE( "UINT32 positive overflow" ){
  SECTION ( "(UINT_MAX + 1U) should be 0U" ) {
    REQUIRE( UINT_MAX + 1U == 1U - 1U );
  }
  SECTION ( "(UINT_MAX + UINT_MAX) should be (UINT_MAX - 1U)" ) {
    REQUIRE( UINT_MAX + UINT_MAX == UINT_MAX - 1U );
  }
}
