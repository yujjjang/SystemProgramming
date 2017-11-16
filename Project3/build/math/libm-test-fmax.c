/* Test fmax.
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

static const struct test_ff_f_data fmax_test_data[] =
  {
    { "0, 0", 0, 0, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0, -0", minus_zero, minus_zero, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, -0", 0, minus_zero, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN } },
    { "-0, 0", minus_zero, 0, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN } },
    { "min_subnorm_value, -min_subnorm_value", min_subnorm_value, -min_subnorm_value, { min_subnorm_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_subnorm_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_subnorm_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_subnorm_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-min_subnorm_value, min_subnorm_value", -min_subnorm_value, min_subnorm_value, { min_subnorm_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_subnorm_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_subnorm_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_subnorm_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "min_value, -min_value", min_value, -min_value, { min_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-min_value, min_value", -min_value, min_value, { min_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { min_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "max_value, -max_value", max_value, -max_value, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-max_value, max_value", -max_value, max_value, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { max_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9, 0", 9, 0, { 9, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, 9", 0, 9, { 9, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9, 0", -9, 0, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, -9", 0, -9, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "inf, 9", plus_infty, 9, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, inf", 0, plus_infty, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9, inf", -9, plus_infty, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "inf, -9", plus_infty, -9, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "-inf, 9", minus_infty, 9, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf, -9", minus_infty, -9, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9, -inf", 9, minus_infty, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9, -inf", -9, minus_infty, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "0, qNaN", 0, qnan_value, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, -qNaN", 0, -qnan_value, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0, qNaN", minus_zero, qnan_value, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0, -qNaN", minus_zero, -qnan_value, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9, qNaN", 9, qnan_value, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "9, -qNaN", 9, -qnan_value, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9, qNaN", -9, qnan_value, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-9, -qNaN", -9, -qnan_value, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, sNaN", 0, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "0, -sNaN", 0, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-0, sNaN", minus_zero, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-0, -sNaN", minus_zero, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "9, sNaN", 9, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "9, -sNaN", 9, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-9, sNaN", -9, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-9, -sNaN", -9, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, 0", qnan_value, 0, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, 0", -qnan_value, 0, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "qNaN, -0", qnan_value, minus_zero, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, -0", -qnan_value, minus_zero, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_zero, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "qNaN, 9", qnan_value, 9, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, 9", -qnan_value, 9, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "qNaN, -9", qnan_value, -9, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, -9", -qnan_value, -9, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -9, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN, 0", snan_value, 0, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, 0", -snan_value, 0, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, -0", snan_value, minus_zero, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, -0", -snan_value, minus_zero, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, 9", snan_value, 9, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, 9", -snan_value, 9, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, -9", snan_value, -9, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, -9", -snan_value, -9, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "inf, qNaN", plus_infty, qnan_value, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "inf, -qNaN", plus_infty, -qnan_value, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf, qNaN", minus_infty, qnan_value, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf, -qNaN", minus_infty, -qnan_value, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "inf, sNaN", plus_infty, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "inf, -sNaN", plus_infty, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-inf, sNaN", minus_infty, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-inf, -sNaN", minus_infty, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, inf", qnan_value, plus_infty, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, inf", -qnan_value, plus_infty, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "qNaN, -inf", qnan_value, minus_infty, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, -inf", -qnan_value, minus_infty, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN, inf", snan_value, plus_infty, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, inf", -snan_value, plus_infty, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, -inf", snan_value, minus_infty, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, -inf", -snan_value, minus_infty, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, qNaN", qnan_value, qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "qNaN, -qNaN", qnan_value, -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, qNaN", -qnan_value, qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN, -qNaN", -qnan_value, -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "qNaN, sNaN", qnan_value, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "qNaN, -sNaN", qnan_value, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-qNaN, sNaN", -qnan_value, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-qNaN, -sNaN", -qnan_value, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, qNaN", snan_value, qnan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, -qNaN", snan_value, -qnan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, qNaN", -snan_value, qnan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, -qNaN", -snan_value, -qnan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, sNaN", snan_value, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "sNaN, -sNaN", snan_value, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, sNaN", -snan_value, snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN, -sNaN", -snan_value, -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
  };

static void
fmax_test (void)
{
  ALL_RM_TEST (fmax, 1, fmax_test_data, RUN_TEST_LOOP_ff_f, END);
}

static void
do_test (void)
{
  fmax_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */
