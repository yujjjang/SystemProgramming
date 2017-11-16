/* Test nearbyint.
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

static const struct test_f_f_data nearbyint_test_data[] =
  {
    { "qNaN", qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN", -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN", snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN", -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "inf", plus_infty, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf", minus_infty, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "4.5", LIT (4.5), { LIT (4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (5.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "3.5", LIT (3.5), { LIT (3.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (3.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "2.5", LIT (2.5), { LIT (2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (3.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "2.0", LIT (2.0), { LIT (2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1.5", LIT (1.5), { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1.0", LIT (1.0), { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0.5", LIT (0.5), { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0.0", LIT (0.0), { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0", minus_zero, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0.5", LIT (-0.5), { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-1.0", LIT (-1.0), { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-1.5", LIT (-1.5), { LIT (-2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-2.0", LIT (-2.0), { LIT (-2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-2.5", LIT (-2.5), { LIT (-3.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-3.5", LIT (-3.5), { LIT (-4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-3.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-3.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4.5", LIT (-4.5), { LIT (-5.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0.1", LIT (0.1), { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0.25", LIT (0.25), { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0.625", LIT (0.625), { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0.1", LIT (-0.1), { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0.25", LIT (-0.25), { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0.625", LIT (-0.625), { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-0.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "262144.75", LIT (262144.75), { LIT (262144.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (262145.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (262144.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (262145.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "262142.75", LIT (262142.75), { LIT (262142.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (262143.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (262142.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (262143.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "524286.75", LIT (524286.75), { LIT (524286.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (524287.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (524286.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (524287.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "524288.75", LIT (524288.75), { LIT (524288.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (524289.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (524288.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (524289.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1048576.75", LIT (1048576.75), { LIT (1048576.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1048577.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1048576.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1048577.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "2097152.75", LIT (2097152.75), { LIT (2097152.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2097153.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2097152.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2097153.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "2492472.75", LIT (2492472.75), { LIT (2492472.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2492473.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2492472.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2492473.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "2886220.75", LIT (2886220.75), { LIT (2886220.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2886221.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2886220.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (2886221.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "3058792.75", LIT (3058792.75), { LIT (3058792.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (3058793.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (3058792.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (3058793.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-1048576.75", LIT (-1048576.75), { LIT (-1048577.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1048577.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1048576.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1048576.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-2097152.75", LIT (-2097152.75), { LIT (-2097153.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2097153.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2097152.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2097152.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-2492472.75", LIT (-2492472.75), { LIT (-2492473.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2492473.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2492472.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2492472.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-2886220.75", LIT (-2886220.75), { LIT (-2886221.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2886221.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2886220.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-2886220.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-3058792.75", LIT (-3058792.75), { LIT (-3058793.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-3058793.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-3058792.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-3058792.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
#if !TEST_COND_binary32
    { "70368744177664.75", LIT (70368744177664.75), { LIT (70368744177664.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (70368744177665.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (70368744177664.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (70368744177665.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "140737488355328.75", LIT (140737488355328.75), { LIT (140737488355328.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (140737488355329.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (140737488355328.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (140737488355329.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "281474976710656.75", LIT (281474976710656.75), { LIT (281474976710656.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (281474976710657.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (281474976710656.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (281474976710657.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "562949953421312.75", LIT (562949953421312.75), { LIT (562949953421312.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (562949953421313.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (562949953421312.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (562949953421313.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1125899906842624.75", LIT (1125899906842624.75), { LIT (1125899906842624.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1125899906842625.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1125899906842624.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1125899906842625.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-70368744177664.75", LIT (-70368744177664.75), { LIT (-70368744177665.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-70368744177665.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-70368744177664.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-70368744177664.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-140737488355328.75", LIT (-140737488355328.75), { LIT (-140737488355329.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-140737488355329.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-140737488355328.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-140737488355328.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-281474976710656.75", LIT (-281474976710656.75), { LIT (-281474976710657.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-281474976710657.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-281474976710656.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-281474976710656.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-562949953421312.75", LIT (-562949953421312.75), { LIT (-562949953421313.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-562949953421313.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-562949953421312.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-562949953421312.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-1125899906842624.75", LIT (-1125899906842624.75), { LIT (-1125899906842625.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1125899906842625.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1125899906842624.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1125899906842624.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
#endif
#if MANT_DIG >= 64
    /* The result can only be represented in long double.  */
    { "4503599627370495.5", LIT (4503599627370495.5), { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370496.25", LIT (4503599627370496.25), { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370496.5", LIT (4503599627370496.5), { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370496.75", LIT (4503599627370496.75), { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370497.5", LIT (4503599627370497.5), { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# if MANT_DIG > 100
    { "1024.5000000000001", LIT (1024.5000000000001), { LIT (1024.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1025.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1024.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1025.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1025.5000000000001", LIT (1025.5000000000001), { LIT (1025.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1026.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1025.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1026.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-1024.5000000000001", LIT (-1024.5000000000001), { LIT (-1025.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1025.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1024.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1024.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-1025.5000000000001", LIT (-1025.5000000000001), { LIT (-1026.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1026.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1025.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1025.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370494.5000000000001", LIT (4503599627370494.5000000000001), { LIT (4503599627370494.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370494.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370495.5000000000001", LIT (4503599627370495.5000000000001), { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "4503599627370496.5000000000001", LIT (4503599627370496.5000000000001), { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# endif
    { "-4503599627370495.5", LIT (-4503599627370495.5), { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370496.25", LIT (-4503599627370496.25), { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370496.5", LIT (-4503599627370496.5), { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370496.75", LIT (-4503599627370496.75), { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370497.5", LIT (-4503599627370497.5), { LIT (-4503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# if MANT_DIG > 100
    { "-4503599627370494.5000000000001", LIT (-4503599627370494.5000000000001), { LIT (-4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370494.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370494.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370495.5000000000001", LIT (-4503599627370495.5000000000001), { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370495.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4503599627370496.5000000000001", LIT (-4503599627370496.5000000000001), { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370497.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-4503599627370496.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "9007199254740991.0000000000001", LIT (9007199254740991.0000000000001), { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740992.0000000000001", LIT (9007199254740992.0000000000001), { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740993.0000000000001", LIT (9007199254740993.0000000000001), { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740991.5000000000001", LIT (9007199254740991.5000000000001), { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740992.5000000000001", LIT (9007199254740992.5000000000001), { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740993.5000000000001", LIT (9007199254740993.5000000000001), { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "-9007199254740991.0000000000001", LIT (-9007199254740991.0000000000001), { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740992.0000000000001", LIT (-9007199254740992.0000000000001), { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740993.0000000000001", LIT (-9007199254740993.0000000000001), { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740991.5000000000001", LIT (-9007199254740991.5000000000001), { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740992.5000000000001", LIT (-9007199254740992.5000000000001), { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740993.5000000000001", LIT (-9007199254740993.5000000000001), { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# endif

    { "9007199254740991.5", LIT (9007199254740991.5), { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740992.25", LIT (9007199254740992.25), { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740992.5", LIT (9007199254740992.5), { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740992.75", LIT (9007199254740992.75), { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9007199254740993.5", LIT (9007199254740993.5), { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "-9007199254740991.5", LIT (-9007199254740991.5), { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740991.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740992.25", LIT (-9007199254740992.25), { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740992.5", LIT (-9007199254740992.5), { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740992.75", LIT (-9007199254740992.75), { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740992.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9007199254740993.5", LIT (-9007199254740993.5), { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740994.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-9007199254740993.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "72057594037927935.5", LIT (72057594037927935.5), { LIT (72057594037927935.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927935.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "72057594037927936.25", LIT (72057594037927936.25), { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "72057594037927936.5", LIT (72057594037927936.5), { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "72057594037927936.75", LIT (72057594037927936.75), { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "72057594037927937.5", LIT (72057594037927937.5), { LIT (72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927938.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (72057594037927938.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "-72057594037927935.5", LIT (-72057594037927935.5), { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927935.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927935.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-72057594037927936.25", LIT (-72057594037927936.25), { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-72057594037927936.5", LIT (-72057594037927936.5), { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-72057594037927936.75", LIT (-72057594037927936.75), { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927936.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-72057594037927937.5", LIT (-72057594037927937.5), { LIT (-72057594037927938.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927938.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-72057594037927937.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

# if MANT_DIG > 100
    { "10141204801825835211973625643007.5", LIT (10141204801825835211973625643007.5), { LIT (10141204801825835211973625643007.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643007.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "10141204801825835211973625643008.25", LIT (10141204801825835211973625643008.25), { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643009.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "10141204801825835211973625643008.5", LIT (10141204801825835211973625643008.5), { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643009.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "10141204801825835211973625643008.75", LIT (10141204801825835211973625643008.75), { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643009.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643008.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643009.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "10141204801825835211973625643009.5", LIT (10141204801825835211973625643009.5), { LIT (10141204801825835211973625643009.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643010.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643009.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (10141204801825835211973625643010.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# endif

    /* Check cases where first double is a exact integer higher than
       2^52 and the precision is determined by second long double for
       IBM long double.  */
    { "34503599627370498.515625", LIT (34503599627370498.515625), { LIT (34503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (34503599627370499.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (34503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (34503599627370499.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-34503599627370498.515625", LIT (-34503599627370498.515625), { LIT (-34503599627370499.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-34503599627370499.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-34503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-34503599627370498.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# if MANT_DIG >= 106
    { "1192568192774434123539907640624.484375", LIT (1192568192774434123539907640624.484375), { LIT (1192568192774434123539907640624.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1192568192774434123539907640624.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1192568192774434123539907640624.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (1192568192774434123539907640625.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-1192568192774434123539907640624.484375", LIT (-1192568192774434123539907640624.484375), { LIT (-1192568192774434123539907640625.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1192568192774434123539907640624.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1192568192774434123539907640624.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-1192568192774434123539907640624.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
# endif
#endif

#if !TEST_COND_binary32
    { "-8.98847e+307", LIT (-8.98847e+307), { LIT (-8.98847e+307), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-8.98847e+307), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-8.98847e+307), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-8.98847e+307), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-4.45015e-308", LIT (-4.45015e-308), { LIT (-1.0), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
#endif
  };

static void
nearbyint_test (void)
{
  ALL_RM_TEST (nearbyint, 1, nearbyint_test_data, RUN_TEST_LOOP_f_f, END);
}

static void
do_test (void)
{
  nearbyint_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */
