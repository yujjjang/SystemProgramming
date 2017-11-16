/* Test logb.
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

static const struct test_f_f_data logb_test_data[] =
  {
    { "inf", plus_infty, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf", minus_infty, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { plus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    /* Bug 6793: errno setting may be missing.  */
    { "0", 0, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION } },

    { "-0", minus_zero, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION }, { minus_infty, NON_FINITE|NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION } },
    { "qNaN", qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN", -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN", snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },
    { "-sNaN", -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|NO_INEXACT_EXCEPTION|INVALID_EXCEPTION } },

    { "1", 1, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "lit_e", lit_e, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1024", 1024, { 10, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 10, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 10, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 10, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-2000", -2000, { 10, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 10, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 10, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 10, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "min_subnorm_value", min_subnorm_value, { MIN_EXP-MANT_DIG, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-MANT_DIG, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-MANT_DIG, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-MANT_DIG, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-min_subnorm_value", -min_subnorm_value, { MIN_EXP-MANT_DIG, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-MANT_DIG, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-MANT_DIG, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-MANT_DIG, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "min_value", min_value, { MIN_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-min_value", -min_value, { MIN_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MIN_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "max_value", max_value, { MAX_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MAX_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MAX_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MAX_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-max_value", -max_value, { MAX_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MAX_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MAX_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { MAX_EXP-1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    { "0x0.1p-127", LIT (0x0.1p-127), { -131, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -131, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -131, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -131, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x0.01p-127", LIT (0x0.01p-127), { -135, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -135, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -135, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -135, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x0.011p-127", LIT (0x0.011p-127), { -135, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -135, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -135, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -135, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
#if !TEST_COND_binary32
    { "0x0.8p-1022", LIT (0x0.8p-1022), { -1023, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1023, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1023, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1023, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x0.1p-1022", LIT (0x0.1p-1022), { -1026, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1026, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1026, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1026, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x0.00111p-1022", LIT (0x0.00111p-1022), { -1034, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1034, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1034, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1034, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x0.00001p-1022", LIT (0x0.00001p-1022), { -1042, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1042, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1042, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1042, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x0.000011p-1022", LIT (0x0.000011p-1022), { -1042, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1042, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1042, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1042, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x0.0000000000001p-1022", LIT (0x0.0000000000001p-1022), { -1074, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1074, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1074, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -1074, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
#endif
#if MIN_EXP - MANT_DIG <= -16400
    { "0x1p-16400", LIT (0x1p-16400), { -16400, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -16400, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -16400, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -16400, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0x.00000000001p-16382", LIT (0x.00000000001p-16382), { -16426, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -16426, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -16426, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { -16426, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
#endif

#if MANT_DIG >= 57
    { "0x1.ffffffffffffffp1", LIT (0x1.ffffffffffffffp1), { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0x1.ffffffffffffffp1", LIT (-0x1.ffffffffffffffp1), { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
#endif
  };

static void
logb_test (void)
{
  ALL_RM_TEST (logb, 1, logb_test_data, RUN_TEST_LOOP_f_f, END);
}

static void
do_test (void)
{
  logb_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */
