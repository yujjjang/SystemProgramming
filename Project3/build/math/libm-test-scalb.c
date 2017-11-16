/* Test scalb.
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

static const struct test_ff_f_data scalb_test_data[] =
  {
#if !TEST_FLOATN
    /* Results in this case are unspecified by POSIX, so, for an
       otherwise fully-determined function, spurious "inexact"
       exceptions are OK.  */
    { "2.0, 0.5", LIT (2.0), LIT (0.5), { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM } },
    { "3.0, -2.5", LIT (3.0), LIT (-2.5), { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM } },

    { "0, qNaN", 0, qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, -qNaN", 0, -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1, qNaN", 1, qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1, -qNaN", 1, -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, sNaN", 0, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "0, -sNaN", 0, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "1, sNaN", 1, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "1, -sNaN", 1, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },

    { "1, 0", 1, 0, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-1, 0", -1, 0, { -1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "0, inf", 0, plus_infty, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM } },
    { "-0, inf", minus_zero, plus_infty, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM } },

    { "0, 2", 0, 2, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0, -4", minus_zero, -4, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, 0", 0, 0, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0, 0", minus_zero, 0, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, -1", 0, -1, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0, -10", minus_zero, -10, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, -inf", 0, minus_infty, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0, -inf", minus_zero, minus_infty, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "inf, -1", plus_infty, -1, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf, -10", minus_infty, -10, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "inf, 0", plus_infty, 0, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf, 0", minus_infty, 0, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "inf, 2", plus_infty, 2, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf, 100", minus_infty, 100, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "0.1, -inf", LIT (0.1), minus_infty, { LIT (0.0), NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (0.0), NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0.1, -inf", LIT (-0.1), minus_infty, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "1, inf", 1, plus_infty, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-1, inf", -1, plus_infty, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "inf, inf", plus_infty, plus_infty, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf, inf", minus_infty, plus_infty, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "inf, -inf", plus_infty, minus_infty, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM } },
    { "-inf, -inf", minus_infty, minus_infty, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM } },

    { "qNaN, 1", qnan_value, 1, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, 1", -qnan_value, 1, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN, 1", snan_value, 1, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, 1", -snan_value, 1, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "1, qNaN", 1, qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1, -qNaN", 1, -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1, sNaN", 1, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "1, -sNaN", 1, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, 0.5", qnan_value, LIT (0.5), { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, 0.5", -qnan_value, LIT (0.5), { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN, 0.5", snan_value, LIT (0.5), { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, 0.5", -snan_value, LIT (0.5), { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "0.5, qNaN", LIT (0.5), qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0.5, -qNaN", LIT (0.5), -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0.5, sNaN", LIT (0.5), snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "0.5, -sNaN", LIT (0.5), -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, 0", qnan_value, 0, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, 0", -qnan_value, 0, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN, 0", snan_value, 0, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, 0", -snan_value, 0, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "0, qNaN", 0, qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, -qNaN", 0, -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, sNaN", 0, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "0, -sNaN", 0, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, inf", qnan_value, plus_infty, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, inf", -qnan_value, plus_infty, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN, inf", snan_value, plus_infty, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, inf", -snan_value, plus_infty, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "inf, qNaN", plus_infty, qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "inf, -qNaN", plus_infty, -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "inf, sNaN", plus_infty, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "inf, -sNaN", plus_infty, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, -inf", qnan_value, minus_infty, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, -inf", -qnan_value, minus_infty, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN, -inf", snan_value, minus_infty, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, -inf", -snan_value, minus_infty, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-inf, qNaN", minus_infty, qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf, -qNaN", minus_infty, -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf, sNaN", minus_infty, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-inf, -sNaN", minus_infty, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, qNaN", qnan_value, qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "qNaN, -qNaN", qnan_value, -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, qNaN", -qnan_value, qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, -qNaN", -qnan_value, -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN, qNaN", snan_value, qnan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, -qNaN", snan_value, -qnan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, qNaN", -snan_value, qnan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, -qNaN", -snan_value, -qnan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, sNaN", qnan_value, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, -sNaN", qnan_value, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-qNaN, sNaN", -qnan_value, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-qNaN, -sNaN", -qnan_value, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, sNaN", snan_value, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, -sNaN", snan_value, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, sNaN", -snan_value, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, -sNaN", -snan_value, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },

    { "max_value, max_value", max_value, max_value, { max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { plus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|0 }, { max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { plus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|XFAIL_IBM128_LIBGCC } },
    { "max_value, -max_value", max_value, -max_value, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { min_subnorm_value, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|0 } },
    { "1, max_value", 1, max_value, { max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { plus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|0 }, { max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { plus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|XFAIL_IBM128_LIBGCC } },
    { "1, -max_value", 1, -max_value, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { min_subnorm_value, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|0 } },
    { "min_value, max_value", min_value, max_value, { max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { plus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|0 }, { max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { plus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|XFAIL_IBM128_LIBGCC } },
    { "min_value, -max_value", min_value, -max_value, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { min_subnorm_value, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|0 } },
    { "min_subnorm_value, max_value", min_subnorm_value, max_value, { max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { plus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|0 }, { max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { plus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|XFAIL_IBM128_LIBGCC } },
    { "min_subnorm_value, -max_value", min_subnorm_value, -max_value, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { plus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { min_subnorm_value, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|0 } },
    { "-max_value, max_value", -max_value, max_value, { minus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|XFAIL_IBM128_LIBGCC }, { minus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|0 }, { -max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { -max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC } },
    { "-max_value, -max_value", -max_value, -max_value, { -min_subnorm_value, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|0 }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE } },
    { "-1, max_value", -1, max_value, { minus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|XFAIL_IBM128_LIBGCC }, { minus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|0 }, { -max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { -max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC } },
    { "-1, -max_value", -1, -max_value, { -min_subnorm_value, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|0 }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE } },
    { "-min_value, max_value", -min_value, max_value, { minus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|XFAIL_IBM128_LIBGCC }, { minus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|0 }, { -max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { -max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC } },
    { "-min_value, -max_value", -min_value, -max_value, { -min_subnorm_value, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|0 }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE } },
    { "-min_subnorm_value, max_value", -min_subnorm_value, max_value, { minus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|XFAIL_IBM128_LIBGCC }, { minus_infty, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|ERRNO_ERANGE|0 }, { -max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC }, { -max_value, INEXACT_EXCEPTION|OVERFLOW_EXCEPTION|0|XFAIL_IBM128_LIBGCC } },
    { "-min_subnorm_value, -max_value", -min_subnorm_value, -max_value, { -min_subnorm_value, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|0 }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE }, { minus_zero, INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION|ERRNO_ERANGE } },

    { "0.8, 4", LIT (0.8), 4, { LIT (12.8), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (12.8), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (12.8), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (12.8), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0.854375, 5", LIT (-0.854375), 5, { LIT (-27.34), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-27.34), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-27.34), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { LIT (-27.34), NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
#endif
  };

static void
scalb_test (void)
{
#if !TEST_FLOATN
  ALL_RM_TEST (scalb, 1, scalb_test_data, RUN_TEST_LOOP_ff_f, END);
#endif
}

static void
do_test (void)
{
  scalb_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */