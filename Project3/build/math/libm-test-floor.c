/* Test floor.
   Copyright (C) 1997-2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include "libm-test-driver.c"

static const struct test_f_f_data floor_test_data[] =
  {
    { "0.0", LIT (0.0), { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0", minus_zero, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "inf", plus_infty, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf", minus_infty, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "qNaN", qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN", -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN", snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN", -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },

    { "lit_pi", lit_pi, { LIT (3.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (3.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (3.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (3.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-lit_pi", -lit_pi, { LIT (-4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "min_subnorm_value", min_subnorm_value, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "min_value", min_value, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0.1", LIT (0.1), { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0.25", LIT (0.25), { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0.625", LIT (0.625), { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1", 1, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "2", 2, { 2, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 2, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 2, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 2, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p23", LIT (0x1p23), { LIT (0x1p23), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p23), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p23), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p23), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p24", LIT (0x1p24), { LIT (0x1p24), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p24), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p24), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p24), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p25", LIT (0x1p25), { LIT (0x1p25), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p25), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p25), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p25), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p52", LIT (0x1p52), { LIT (0x1p52), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p52), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p52), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p52), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p53", LIT (0x1p53), { LIT (0x1p53), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p53), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p53), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p53), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p54", LIT (0x1p54), { LIT (0x1p54), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p54), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p54), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p54), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p63", LIT (0x1p63), { LIT (0x1p63), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p63), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p63), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p63), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p64", LIT (0x1p64), { LIT (0x1p64), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p64), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p64), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p64), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p65", LIT (0x1p65), { LIT (0x1p65), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p65), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p65), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p65), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p105", LIT (0x1p105), { LIT (0x1p105), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p105), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p105), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p105), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p106", LIT (0x1p106), { LIT (0x1p106), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p106), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p106), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p106), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p107", LIT (0x1p107), { LIT (0x1p107), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p107), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p107), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p107), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p112", LIT (0x1p112), { LIT (0x1p112), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p112), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p112), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p112), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p113", LIT (0x1p113), { LIT (0x1p113), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p113), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p113), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p113), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x1p114", LIT (0x1p114), { LIT (0x1p114), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p114), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p114), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0x1p114), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "max_value", max_value, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-min_subnorm_value", -min_subnorm_value, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-min_value", -min_value, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0.1", LIT (-0.1), { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0.25", LIT (-0.25), { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0.625", LIT (-0.625), { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-1", -1, { -1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-2", -2, { -2, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -2, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -2, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -2, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p23", LIT (-0x1p23), { LIT (-0x1p23), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p23), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p23), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p23), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p24", LIT (-0x1p24), { LIT (-0x1p24), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p24), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p24), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p24), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p25", LIT (-0x1p25), { LIT (-0x1p25), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p25), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p25), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p25), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p52", LIT (-0x1p52), { LIT (-0x1p52), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p52), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p52), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p52), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p53", LIT (-0x1p53), { LIT (-0x1p53), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p53), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p53), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p53), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p54", LIT (-0x1p54), { LIT (-0x1p54), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p54), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p54), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p54), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p63", LIT (-0x1p63), { LIT (-0x1p63), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p63), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p63), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p63), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p64", LIT (-0x1p64), { LIT (-0x1p64), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p64), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p64), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p64), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p65", LIT (-0x1p65), { LIT (-0x1p65), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p65), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p65), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p65), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p105", LIT (-0x1p105), { LIT (-0x1p105), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p105), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p105), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p105), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p106", LIT (-0x1p106), { LIT (-0x1p106), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p106), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p106), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p106), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p107", LIT (-0x1p107), { LIT (-0x1p107), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p107), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p107), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p107), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p112", LIT (-0x1p112), { LIT (-0x1p112), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p112), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p112), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p112), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p113", LIT (-0x1p113), { LIT (-0x1p113), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p113), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p113), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p113), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1p114", LIT (-0x1p114), { LIT (-0x1p114), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p114), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p114), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x1p114), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-max_value", -max_value, { -max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

#if MANT_DIG >= 64
    /* The result can only be represented in long double.  */
    { "4503599627370495.5", LIT (4503599627370495.5), { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370496.25", LIT (4503599627370496.25), { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370496.5", LIT (4503599627370496.5), { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370496.75", LIT (4503599627370496.75), { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370497.5", LIT (4503599627370497.5), { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# if MANT_DIG > 100
    { "4503599627370494.5000000000001", LIT (4503599627370494.5000000000001), { LIT (4503599627370494.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370494.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370494.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370494.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370495.5000000000001", LIT (4503599627370495.5000000000001), { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370496.5000000000001", LIT (4503599627370496.5000000000001), { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# endif

    { "-4503599627370495.5", LIT (-4503599627370495.5), { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370496.25", LIT (-4503599627370496.25), { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370496.5", LIT (-4503599627370496.5), { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370496.75", LIT (-4503599627370496.75), { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370497.5", LIT (-4503599627370497.5), { LIT (-4503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# if MANT_DIG > 100
    { "-4503599627370494.5000000000001", LIT (-4503599627370494.5000000000001), { LIT (-4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370495.5000000000001", LIT (-4503599627370495.5000000000001), { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370496.5000000000001", LIT (-4503599627370496.5000000000001), { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# endif

    { "9007199254740991.5", LIT (9007199254740991.5), { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740992.25", LIT (9007199254740992.25), { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740992.5", LIT (9007199254740992.5), { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740992.75", LIT (9007199254740992.75), { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740993.5", LIT (9007199254740993.5), { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

# if MANT_DIG > 100
    { "9007199254740991.0000000000001", LIT (9007199254740991.0000000000001), { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740992.0000000000001", LIT (9007199254740992.0000000000001), { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740993.0000000000001", LIT (9007199254740993.0000000000001), { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740991.5000000000001", LIT (9007199254740991.5000000000001), { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740992.5000000000001", LIT (9007199254740992.5000000000001), { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740993.5000000000001", LIT (9007199254740993.5000000000001), { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# endif

    { "-9007199254740991.5", LIT (-9007199254740991.5), { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740992.25", LIT (-9007199254740992.25), { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740992.5", LIT (-9007199254740992.5), { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740992.75", LIT (-9007199254740992.75), { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740993.5", LIT (-9007199254740993.5), { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

# if MANT_DIG > 100
    { "-9007199254740991.0000000000001", LIT (-9007199254740991.0000000000001), { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740992.0000000000001", LIT (-9007199254740992.0000000000001), { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740993.0000000000001", LIT (-9007199254740993.0000000000001), { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740991.5000000000001", LIT (-9007199254740991.5000000000001), { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740992.5000000000001", LIT (-9007199254740992.5000000000001), { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740993.5000000000001", LIT (-9007199254740993.5000000000001), { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# endif

    { "72057594037927935.5", LIT (72057594037927935.5), { LIT (72057594037927935.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927935.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927935.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927935.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "72057594037927936.25", LIT (72057594037927936.25), { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "72057594037927936.5", LIT (72057594037927936.5), { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "72057594037927936.75", LIT (72057594037927936.75), { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "72057594037927937.5", LIT (72057594037927937.5), { LIT (72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "-72057594037927935.5", LIT (-72057594037927935.5), { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-72057594037927936.25", LIT (-72057594037927936.25), { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-72057594037927936.5", LIT (-72057594037927936.5), { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-72057594037927936.75", LIT (-72057594037927936.75), { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-72057594037927937.5", LIT (-72057594037927937.5), { LIT (-72057594037927938.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927938.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927938.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927938.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "10141204801825835211973625643007.5", LIT (10141204801825835211973625643007.5), { LIT (10141204801825835211973625643007.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643007.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643007.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643007.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "10141204801825835211973625643008.25", LIT (10141204801825835211973625643008.25), { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "10141204801825835211973625643008.5", LIT (10141204801825835211973625643008.5), { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "10141204801825835211973625643008.75", LIT (10141204801825835211973625643008.75), { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "10141204801825835211973625643009.5", LIT (10141204801825835211973625643009.5), { LIT (10141204801825835211973625643009.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643009.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643009.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643009.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "0xf.ffffffffffffff8p+47", LIT (0xf.ffffffffffffff8p+47), { LIT (0xf.fffffffffffep+47), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffep+47), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffep+47), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffep+47), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x8.000000000000004p+48", LIT (-0x8.000000000000004p+48), { LIT (-0x8.000000000001p+48), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x8.000000000001p+48), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x8.000000000001p+48), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0x8.000000000001p+48), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
#endif
  };

static void
floor_test (void)
{
  ALL_RM_TEST (floor, 1, floor_test_data, RUN_TEST_LOOP_f_f, END);
}

static void
do_test (void)
{
  floor_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */
