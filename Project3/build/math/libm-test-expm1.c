/* Test expm1.
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

static const struct test_f_f_data expm1_test_data[] =
  {
    { "inf", plus_infty, { plus_infty, NON_FINITE|ERRNO_UNCHANGED|NO_TEST_INLINE }, { plus_infty, NON_FINITE|ERRNO_UNCHANGED|NO_TEST_INLINE }, { plus_infty, NON_FINITE|ERRNO_UNCHANGED|NO_TEST_INLINE }, { plus_infty, NON_FINITE|ERRNO_UNCHANGED|NO_TEST_INLINE } },
    { "-inf", minus_infty, { -1, NON_FINITE|ERRNO_UNCHANGED|NO_TEST_INLINE }, { -1, NON_FINITE|ERRNO_UNCHANGED|NO_TEST_INLINE }, { -1, NON_FINITE|ERRNO_UNCHANGED|NO_TEST_INLINE }, { -1, NON_FINITE|ERRNO_UNCHANGED|NO_TEST_INLINE } },
    { "qNaN", qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN", -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN", snan_value, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION } },
    { "-sNaN", -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION } },

#if (TEST_COND_binary128)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.1p+4", LIT (-0x1.1p+4), { LIT (-0xf.fffff4e30e7452cbb1a1331e22b8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452cbb1a1331e22bp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452cbb1a1331e22bp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452cbb1a1331e22bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.2p+4", LIT (-0x1.2p+4), { LIT (-0xf.fffffbe9675ce59817cddee3aa18p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce59817cddee3aa18p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce59817cddee3aa1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce59817cddee3aa1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.86ap+16", LIT (-0x1.86ap+16), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+4", LIT (-0x1p+4), { LIT (-0xf.ffffe1caa445117a35259a08c0dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445117a35259a08c0dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445117a35259a08c0c8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445117a35259a08c0c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p-100", LIT (-0x1p-100), { LIT (-0xf.ffffffffffffffffffffffff8008p-104), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffff8p-104), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffff8p-104), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffff8p-104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p-10000", LIT (-0x1p-10000), { LIT (-0x1p-10000), ERRNO_UNCHANGED }, { LIT (-0x1p-10000), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-10004), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-10004), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p-20", LIT (-0x1p-20), { LIT (-0xf.ffff800002aaaaa00000222221c8p-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaa00000222221c8p-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaa00000222221cp-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaa00000222221cp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p-32", LIT (-0x1p-32), { LIT (-0xf.fffffff800000002aaaaaaaa0008p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff800000002aaaaaaaap-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff800000002aaaaaaaap-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff800000002aaaaaaaap-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p-600", LIT (-0x1p-600), { LIT (-0x1p-600), ERRNO_UNCHANGED }, { LIT (-0x1p-600), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-604), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-604), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p-64", LIT (-0x1p-64), { LIT (-0xf.fffffffffffffff8000000000008p-68), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff8p-68), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff8p-68), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff8p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.4p+4", LIT (-0x2.4p+4), { LIT (-0xf.fffffffffffef493c50221f9c8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef493c50221f9c7f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef493c50221f9c7f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef493c50221f9c7f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.5p+4", LIT (-0x2.5p+4), { LIT (-0xf.ffffffffffff9d9ee380d67eac08p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9d9ee380d67eac08p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9d9ee380d67eacp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9d9ee380d67eacp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.6p+4", LIT (-0x2.6p+4), { LIT (-0xf.ffffffffffffdbceea52a399f9e8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbceea52a399f9e8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbceea52a399f9ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbceea52a399f9ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.71p+12", LIT (-0x2.71p+12), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.cp+4", LIT (-0x2.cp+4), { LIT (-0xf.ffffffffffffffe908be21e8b718p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffe908be21e8b718p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffe908be21e8b71p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffe908be21e8b71p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0xf.fffffffffffffff78d2461700568p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff78d246170056p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff78d246170056p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff78d246170056p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.ep+4", LIT (-0x2.ep+4), { LIT (-0xf.fffffffffffffffce4543c89ec58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffce4543c89ec5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffce4543c89ec5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffce4543c89ec5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.e8p+8", LIT (-0x3.e8p+8), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.9p+4", LIT (-0x4.9p+4), { LIT (-0xf.fffffffffffffffffffffffff998p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffff99p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffff99p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffff99p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.ap+4", LIT (-0x4.ap+4), { LIT (-0xf.fffffffffffffffffffffffffda8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffdap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffdap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffdap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.bp+4", LIT (-0x4.bp+4), { LIT (-0xf.ffffffffffffffffffffffffff28p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffffff2p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffffff2p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffffff2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.ep+4", LIT (-0x4.ep+4), { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.fp+4", LIT (-0x4.fp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-12", LIT (-0x4p-12), { LIT (-0x3.ff800aaa0008882d861847853134p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882d861847853132p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882d861847853132p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882d861847853132p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16448", LIT (-0x4p-16448), { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x3.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x3.fffffffffffcp-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16496", LIT (-0x4p-16496), { LIT (-0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-4", LIT (-0x4p-4), { LIT (-0x3.8a0830a9befa8bcbea343629c972p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bcbea343629c97p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bcbea343629c97p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bcbea343629c97p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-52", LIT (-0x4p-52), { LIT (-0x3.ffffffffffff8000000000000aacp-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8000000000000aaap-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8000000000000aaap-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8000000000000aaap-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x5p+4", LIT (-0x5p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x6.4p+4", LIT (-0x6.4p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7.d6c508p+0", LIT (-0x7.d6c508p+0), { LIT (-0xf.fe62c59d9de7d6168bf8c31a7168p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d6168bf8c31a716p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d6168bf8c31a716p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d6168bf8c31a716p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7.d6c50b469d404p+0", LIT (-0x7.d6c50b469d404p+0), { LIT (-0xf.fe62c5a2e792bffeb1e98cc705d8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792bffeb1e98cc705dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792bffeb1e98cc705dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792bffeb1e98cc705dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7.d6c51p+0", LIT (-0x7.d6c51p+0), { LIT (-0xf.fe62c5aa87bab580018589d526p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab580018589d526p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab580018589d525f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab580018589d525f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x7.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x7.fffffffffffcp-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-32", LIT (-0x8p-32), { LIT (-0x7.ffffffe000000055555554aaaaacp-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe000000055555554aaaaacp-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe000000055555554aaaaa8p-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe000000055555554aaaaa8p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.ffd0650c953706cac749b7155edp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706cac749b7155edp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706cac749b7155ec8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706cac749b7155ec8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffffffffffffff8p+16380", LIT (-0xf.fffffffffffffffffffffffffff8p+16380), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0x1.ceb088a68e80402189797f9599cbp+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e80402189797f9599ccp+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e80402189797f9599cbp+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e80402189797f9599ccp+28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.86ap+16", LIT (0x1.86ap+16), { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary128)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0x1.0c3d3920862c88aafb2ae72d6857p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88aafb2ae72d6857p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88aafb2ae72d6857p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88aafb2ae72d6858p+36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0x9.b823857613764f43e201f73a5428p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f43e201f73a543p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f43e201f73a5428p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f43e201f73a543p+40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.f4p+8", LIT (0x1.f4p+8), { LIT (0x2.8b74553efc87128fd5d1b2c1ea3ap+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87128fd5d1b2c1ea3ap+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87128fd5d1b2c1ea3ap+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87128fd5d1b2c1ea3cp+720), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x1.b7e151628aed2a6abf7158809cf4p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6abf7158809cf5p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6abf7158809cf4p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6abf7158809cf5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-100", LIT (0x1p-100), { LIT (0x1.00000000000000000000000008p-100), ERRNO_UNCHANGED }, { LIT (0x1.00000000000000000000000008p-100), ERRNO_UNCHANGED }, { LIT (0x1.00000000000000000000000008p-100), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000801p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p-10000), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-20", LIT (0x1p-20), { LIT (0x1.00000800002aaaab55555777777dp-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaab55555777777dp-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaab55555777777dp-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaab55555777777ep-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-32", LIT (0x1p-32), { LIT (0x1.00000000800000002aaaaaaab555p-32), ERRNO_UNCHANGED }, { LIT (0x1.00000000800000002aaaaaaab555p-32), ERRNO_UNCHANGED }, { LIT (0x1.00000000800000002aaaaaaab555p-32), ERRNO_UNCHANGED }, { LIT (0x1.00000000800000002aaaaaaab556p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-600", LIT (0x1p-600), { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p-600), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-64", LIT (0x1p-64), { LIT (0x1.00000000000000008p-64), ERRNO_UNCHANGED }, { LIT (0x1.00000000000000008p-64), ERRNO_UNCHANGED }, { LIT (0x1.00000000000000008p-64), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000800000000001p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0x5.a278886f2355ba66b452ea7226f4p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba66b452ea7226f4p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba66b452ea7226f4p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba66b452ea7226f8p+48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0x3.4441a72f2e5d50686c20e8b55b3ap+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d50686c20e8b55b3cp+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d50686c20e8b55b3ap+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d50686c20e8b55b3cp+56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.c5c4p+12", LIT (0x2.c5c4p+12), { LIT (0xc.2c2b72bac3ba40c9d77771f196c8p+16380), ERRNO_UNCHANGED }, { LIT (0xc.2c2b72bac3ba40c9d77771f196dp+16380), ERRNO_UNCHANGED }, { LIT (0xc.2c2b72bac3ba40c9d77771f196c8p+16380), ERRNO_UNCHANGED }, { LIT (0xc.2c2b72bac3ba40c9d77771f196dp+16380), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x6.63992e35376b730ce8ee881ada28p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b730ce8ee881ada2cp+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b730ce8ee881ada28p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b730ce8ee881ada2cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.0000000000000000000000000004p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0x1.19103e4080b45664d6740cf8c5d8p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45664d6740cf8c5d9p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45664d6740cf8c5d8p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45664d6740cf8c5d9p+72), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.735f48p-4", LIT (0x3.735f48p-4), { LIT (0x3.d9dceda6a6b41355e2e68cfbebc8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41355e2e68cfbebcap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41355e2e68cfbebc8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41355e2e68cfbebcap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.735f497c4e674p-4", LIT (0x3.735f497c4e674p-4), { LIT (0x3.d9dcef7e7e39645fb77dffbba9aap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39645fb77dffbba9aap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39645fb77dffbba9aap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39645fb77dffbba9acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.735f497c4e67535cp-4", LIT (0x3.735f497c4e67535cp-4), { LIT (0x3.d9dcef7e7e397c649290c708e3aap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c649290c708e3aap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c649290c708e3aap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c649290c708e3acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.735f497c4e676p-4", LIT (0x3.735f497c4e676p-4), { LIT (0x3.d9dcef7e7e398c13715cfcb81c9ap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c13715cfcb81c9ap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c13715cfcb81c9ap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c13715cfcb81c9cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.735f4cp-4", LIT (0x3.735f4cp-4), { LIT (0x3.d9dcf29d1df01bce7765d392e548p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bce7765d392e54ap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bce7765d392e548p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bce7765d392e54ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.cp+4", LIT (0x3.cp+4), { LIT (0x5.e76f27714f19924caf2a5508189p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19924caf2a55081894p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19924caf2a5508189p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19924caf2a55081894p+84), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.315e5bf6fb105f2d4bdfc53744c3p+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2d4bdfc53744c4p+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2d4bdfc53744c3p+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2d4bdfc53744c4p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000028p-16384", LIT (0x4.0000000000000028p-16384), { LIT (0x4.0000000000000028p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000028p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000028p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000028000000000004p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.6p+4", LIT (0x4.6p+4), { LIT (0x1.fbfd219c43b04730797e2bfeb1cep+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b04730797e2bfeb1cfp+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b04730797e2bfeb1cep+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b04730797e2bfeb1cfp+100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.857de8p+4", LIT (0x4.857de8p+4), { LIT (0x1.4aaa8e05bcf71097ff88abf1c0adp+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71097ff88abf1c0adp+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71097ff88abf1c0adp+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71097ff88abf1c0aep+104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x3.599205c4e74b0cf1ada77fb727b6p+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cf1ada77fb727b8p+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cf1ada77fb727b6p+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cf1ada77fb727b8p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000000004p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000000004p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x4.00800aab555dde38e6ce86e92778p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde38e6ce86e9277cp-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde38e6ce86e92778p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde38e6ce86e9277cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000000004p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4.0000000000000000000000000004p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448", LIT (0x4p-16448), { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4.000000000004p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496", LIT (0x4p-16496), { LIT (0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-4", LIT (0x4p-4), { LIT (0x4.8b5e3c3e81866767bc3b69baabe4p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81866767bc3b69baabe4p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81866767bc3b69baabe4p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81866767bc3b69baabe8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x4.0000000000008000000000000aa8p-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008000000000000aacp-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008000000000000aa8p-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008000000000000aacp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.ap+4", LIT (0x5.ap+4), { LIT (0x3.96211ff7d82c792f823b2ba3a164p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c792f823b2ba3a166p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c792f823b2ba3a164p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c792f823b2ba3a166p+128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.dfeb68p-4", LIT (0x5.dfeb68p-4), { LIT (0x7.19267f117e20e3b9a8b8bdf57f7p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3b9a8b8bdf57f74p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3b9a8b8bdf57f7p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3b9a8b8bdf57f74p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fb8dc64e91a74p-4", LIT (0x5.fb8dc64e91a74p-4), { LIT (0x7.412dde3318f344bc6f6cd00f8ed8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344bc6f6cd00f8ed8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344bc6f6cd00f8ed8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344bc6f6cd00f8edcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fb8dc8p-4", LIT (0x5.fb8dc8p-4), { LIT (0x7.412de0a90d3dcc39dc4e01aef3b4p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc39dc4e01aef3b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc39dc4e01aef3b4p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc39dc4e01aef3b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fb8dcp-4", LIT (0x5.fb8dcp-4), { LIT (0x7.412dd50876505fd8f901001e9238p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fd8f901001e9238p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fd8f901001e9238p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fd8f901001e923cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x9.369c4cb819c78fb37d56c91ad5fp+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fb37d56c91ad5fp+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fb37d56c91ad5fp+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fb37d56c91ad5f8p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5p+4", LIT (0x5p+4), { LIT (0xa.abbcdcc279f59e45281da547124p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e45281da547124p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e45281da547124p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e45281da5471248p+112), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.1b4d318238d48p-4", LIT (0x6.1b4d318238d48p-4), { LIT (0x7.6f8042a9af77fc11bbb323d011ep-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc11bbb323d011ep-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc11bbb323d011ep-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc11bbb323d011e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.1b4d318238d4a2a8p-4", LIT (0x6.1b4d318238d4a2a8p-4), { LIT (0x7.6f8042a9af782ed4bf03885aa378p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782ed4bf03885aa37cp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782ed4bf03885aa378p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782ed4bf03885aa37cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.1b4d318238d4cp-4", LIT (0x6.1b4d318238d4cp-4), { LIT (0x7.6f8042a9af7859cfbcbdca8df28cp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859cfbcbdca8df28cp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859cfbcbdca8df28cp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859cfbcbdca8df29p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.1b4d38p-4", LIT (0x6.1b4d38p-4), { LIT (0x7.6f804c2bba6774a43c5c34a96fcp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774a43c5c34a96fcp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774a43c5c34a96fcp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774a43c5c34a96fc4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.1b4d3p-4", LIT (0x6.1b4d3p-4), { LIT (0x7.6f804073fa444cb711aa5c815444p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cb711aa5c815448p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cb711aa5c815444p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cb711aa5c815448p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.289a78p-4", LIT (0x6.289a78p-4), { LIT (0x7.8304264e39d2cffd272b76863fa8p-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2cffd272b76863fa8p-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2cffd272b76863fa8p-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2cffd272b76863facp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x1.3494a9b171bf4acc225093322428p+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4acc225093322428p+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4acc225093322428p+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4acc225093322429p+144), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.660247486aed8p-4", LIT (0x6.660247486aed8p-4), { LIT (0x7.ddee37ace0525de2e3d415373edp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525de2e3d415373edp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525de2e3d415373edp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525de2e3d415373ed4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.660248p-4", LIT (0x6.660248p-4), { LIT (0x7.ddee38beb90553d11ec1beb27a08p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553d11ec1beb27a08p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553d11ec1beb27a08p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553d11ec1beb27a0cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.66024p-4", LIT (0x6.66024p-4), { LIT (0x7.ddee2ccfc1ebf03262b062f7fa3cp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf03262b062f7fa4p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf03262b062f7fa3cp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf03262b062f7fa4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.fp+4", LIT (0x7.fp+4), { LIT (0x9.552183749160e8b702888dad9508p+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8b702888dad951p+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8b702888dad9508p+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8b702888dad951p+180), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8.000000000004p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-32", LIT (0x8p-32), { LIT (0x8.0000002000000055555556p-32), ERRNO_UNCHANGED }, { LIT (0x8.0000002000000055555556p-32), ERRNO_UNCHANGED }, { LIT (0x8.0000002000000055555556p-32), ERRNO_UNCHANGED }, { LIT (0x8.0000002000000055555556000008p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xap+0", LIT (0xap+0), { LIT (0x5.609773e54157e7c1faa3015b44dp+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7c1faa3015b44d4p+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7c1faa3015b44dp+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7c1faa3015b44d4p+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x1.1df3b68cfb9ef7a986addc7dcee2p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7a986addc7dcee2p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7a986addc7dcee2p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7a986addc7dcee3p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.4152ac57cd1e8p-60", LIT (0xe.4152ac57cd1e8p-60), { LIT (0xe.4152ac57cd1e8659adaf7e8f0e28p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e8659adaf7e8f0e28p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e8659adaf7e8f0e28p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e8659adaf7e8f0e3p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.4152ac57cd1ea7ap-60", LIT (0xe.4152ac57cd1ea7ap-60), { LIT (0xe.4152ac57cd1eadf9adaf7e8f0e48p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eadf9adaf7e8f0e5p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eadf9adaf7e8f0e48p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eadf9adaf7e8f0e5p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.4152ac57cd1fp-60", LIT (0xe.4152ac57cd1fp-60), { LIT (0xe.4152ac57cd1f0659adaf7e8f0e98p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f0659adaf7e8f0e98p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f0659adaf7e8f0e98p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f0659adaf7e8f0eap-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.4152ap-60", LIT (0xe.4152ap-60), { LIT (0xe.4152a00000000659ada47f572p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a00000000659ada47f572p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a00000000659ada47f572p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a00000000659ada47f572008p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.4152bp-60", LIT (0xe.4152bp-60), { LIT (0xe.4152b00000000659adb2c0a9c8p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b00000000659adb2c0a9c8p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b00000000659adb2c0a9c8p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b00000000659adb2c0a9c808p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffffffffffffff8p+16380", LIT (0xf.fffffffffffffffffffffffffff8p+16380), { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffffffffffffff8p+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary128)
    { "0xfp+0", LIT (0xfp+0), { LIT (0x3.1e1985f5a550dde2e5fe372cd4bp+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550dde2e5fe372cd4b2p+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550dde2e5fe372cd4bp+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550dde2e5fe372cd4b2p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.1p+4", LIT (-0x1.1p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.2p+4", LIT (-0x1.2p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.86ap+16", LIT (-0x1.86ap+16), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1p+4", LIT (-0x1p+4), { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffep-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffep-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1p-100", LIT (-0x1p-100), { LIT (-0x1p-100), ERRNO_UNCHANGED }, { LIT (-0x1p-100), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-104), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1p-20", LIT (-0x1p-20), { LIT (-0xf.ffff9p-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff8p-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff8p-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1p-32", LIT (-0x1p-32), { LIT (-0x1p-32), ERRNO_UNCHANGED }, { LIT (-0x1p-32), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1p-64", LIT (-0x1p-64), { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-68), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.4p+4", LIT (-0x2.4p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.5p+4", LIT (-0x2.5p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.6p+4", LIT (-0x2.6p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.71p+12", LIT (-0x2.71p+12), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.cp+4", LIT (-0x2.cp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.ep+4", LIT (-0x2.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x3.e8p+8", LIT (-0x3.e8p+8), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.9p+4", LIT (-0x4.9p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.ap+4", LIT (-0x4.ap+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.bp+4", LIT (-0x4.bp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.ep+4", LIT (-0x4.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.fp+4", LIT (-0x4.fp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p-12", LIT (-0x4p-12), { LIT (-0x3.ff800cp-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800cp-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff8008p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff8008p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffff8p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffff8p-128), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p-4", LIT (-0x4p-4), { LIT (-0x3.8a0834p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a083p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a083p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a083p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p-52", LIT (-0x4p-52), { LIT (-0x4p-52), ERRNO_UNCHANGED }, { LIT (-0x4p-52), ERRNO_UNCHANGED }, { LIT (-0x3.fffffcp-52), ERRNO_UNCHANGED }, { LIT (-0x3.fffffcp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x5p+4", LIT (-0x5p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x6.4p+4", LIT (-0x6.4p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x7.d6c508p+0", LIT (-0x7.d6c508p+0), { LIT (-0xf.fe62dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x7.d6c51p+0", LIT (-0x7.d6c51p+0), { LIT (-0xf.fe62dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-32", LIT (-0x8p-32), { LIT (-0x8p-32), ERRNO_UNCHANGED }, { LIT (-0x8p-32), ERRNO_UNCHANGED }, { LIT (-0x7.fffff8p-32), ERRNO_UNCHANGED }, { LIT (-0x7.fffff8p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.ffd07p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd06p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd06p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd06p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0x1.ceb088p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb08ap+28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.86ap+16", LIT (0x1.86ap+16), { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary32)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0x1.0c3d38p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3ap+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d38p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3ap+36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0x9.b8238p+40), ERRNO_UNCHANGED }, { LIT (0x9.b8238p+40), ERRNO_UNCHANGED }, { LIT (0x9.b8238p+40), ERRNO_UNCHANGED }, { LIT (0x9.b8239p+40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.f4p+8", LIT (0x1.f4p+8), { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x1.b7e15p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e152p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e15p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e152p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-100", LIT (0x1p-100), { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1.000002p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-20", LIT (0x1p-20), { LIT (0x1.000008p-20), ERRNO_UNCHANGED }, { LIT (0x1.000008p-20), ERRNO_UNCHANGED }, { LIT (0x1.000008p-20), ERRNO_UNCHANGED }, { LIT (0x1.00000ap-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-32", LIT (0x1p-32), { LIT (0x1p-32), ERRNO_UNCHANGED }, { LIT (0x1p-32), ERRNO_UNCHANGED }, { LIT (0x1p-32), ERRNO_UNCHANGED }, { LIT (0x1.000002p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-64", LIT (0x1p-64), { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1.000002p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0x5.a27888p+48), ERRNO_UNCHANGED }, { LIT (0x5.a27888p+48), ERRNO_UNCHANGED }, { LIT (0x5.a27888p+48), ERRNO_UNCHANGED }, { LIT (0x5.a2789p+48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0x3.4441a4p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a8p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a4p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a8p+56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.c5c4p+12", LIT (0x2.c5c4p+12), { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x6.639928p+0), ERRNO_UNCHANGED }, { LIT (0x6.63993p+0), ERRNO_UNCHANGED }, { LIT (0x6.639928p+0), ERRNO_UNCHANGED }, { LIT (0x6.63993p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0x1.19103ep+72), ERRNO_UNCHANGED }, { LIT (0x1.19103ep+72), ERRNO_UNCHANGED }, { LIT (0x1.19103ep+72), ERRNO_UNCHANGED }, { LIT (0x1.19104p+72), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.735f48p-4", LIT (0x3.735f48p-4), { LIT (0x3.d9dcecp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcecp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcecp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.735f4cp-4", LIT (0x3.735f4cp-4), { LIT (0x3.d9dcfp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf4p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcfp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.cp+4", LIT (0x3.cp+4), { LIT (0x5.e76f2p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f28p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f2p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f28p+84), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.315e5ap+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5cp+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5ap+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5cp+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.6p+4", LIT (0x4.6p+4), { LIT (0x1.fbfd2p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd22p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd2p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd22p+100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.857de8p+4", LIT (0x4.857de8p+4), { LIT (0x1.4aaa8ep+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8ep+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8ep+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa9p+104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x3.599204p+4), ERRNO_UNCHANGED }, { LIT (0x3.599204p+4), ERRNO_UNCHANGED }, { LIT (0x3.599204p+4), ERRNO_UNCHANGED }, { LIT (0x3.599208p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x4.008008p-12), ERRNO_UNCHANGED }, { LIT (0x4.008008p-12), ERRNO_UNCHANGED }, { LIT (0x4.008008p-12), ERRNO_UNCHANGED }, { LIT (0x4.00801p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4.000008p-128), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-4", LIT (0x4p-4), { LIT (0x4.8b5e38p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e4p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e38p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x4p-52), ERRNO_UNCHANGED }, { LIT (0x4p-52), ERRNO_UNCHANGED }, { LIT (0x4p-52), ERRNO_UNCHANGED }, { LIT (0x4.000008p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.ap+4", LIT (0x5.ap+4), { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary32)
    { "0x5.dfeb68p-4", LIT (0x5.dfeb68p-4), { LIT (0x7.192678p-4), ERRNO_UNCHANGED }, { LIT (0x7.19268p-4), ERRNO_UNCHANGED }, { LIT (0x7.192678p-4), ERRNO_UNCHANGED }, { LIT (0x7.19268p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.fb8dc8p-4", LIT (0x5.fb8dc8p-4), { LIT (0x7.412dep-4), ERRNO_UNCHANGED }, { LIT (0x7.412dep-4), ERRNO_UNCHANGED }, { LIT (0x7.412dep-4), ERRNO_UNCHANGED }, { LIT (0x7.412de8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.fb8dcp-4", LIT (0x5.fb8dcp-4), { LIT (0x7.412ddp-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412ddp-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x9.369c4p+4), ERRNO_UNCHANGED }, { LIT (0x9.369c5p+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4p+4), ERRNO_UNCHANGED }, { LIT (0x9.369c5p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5p+4", LIT (0x5p+4), { LIT (0xa.abbcdp+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcep+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdp+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcep+112), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6.1b4d38p-4", LIT (0x6.1b4d38p-4), { LIT (0x7.6f8048p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f805p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8048p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f805p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6.1b4d3p-4", LIT (0x6.1b4d3p-4), { LIT (0x7.6f804p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8048p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6.289a78p-4", LIT (0x6.289a78p-4), { LIT (0x7.83042p-4), ERRNO_UNCHANGED }, { LIT (0x7.830428p-4), ERRNO_UNCHANGED }, { LIT (0x7.83042p-4), ERRNO_UNCHANGED }, { LIT (0x7.830428p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary32)
    { "0x6.660248p-4", LIT (0x6.660248p-4), { LIT (0x7.ddee38p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6.66024p-4", LIT (0x6.66024p-4), { LIT (0x7.ddee28p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee3p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee28p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7.fp+4", LIT (0x7.fp+4), { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x1p-148), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-32", LIT (0x8p-32), { LIT (0x8p-32), ERRNO_UNCHANGED }, { LIT (0x8p-32), ERRNO_UNCHANGED }, { LIT (0x8p-32), ERRNO_UNCHANGED }, { LIT (0x8.00001p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xap+0", LIT (0xap+0), { LIT (0x5.60977p+12), ERRNO_UNCHANGED }, { LIT (0x5.60977p+12), ERRNO_UNCHANGED }, { LIT (0x5.60977p+12), ERRNO_UNCHANGED }, { LIT (0x5.609778p+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x1.1df3b6p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b6p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b6p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.4152ap-60", LIT (0xe.4152ap-60), { LIT (0xe.4152ap-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ap-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ap-60), ERRNO_UNCHANGED }, { LIT (0xe.4152bp-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.4152bp-60", LIT (0xe.4152bp-60), { LIT (0xe.4152bp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152bp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152bp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152cp-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffp+124), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary32)
    { "0xfp+0", LIT (0xfp+0), { LIT (0x3.1e1984p+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1984p+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1984p+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1988p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.1p+4", LIT (-0x1.1p+4), { LIT (-0xf.fffff4e30e748p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e748p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e74p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e74p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.2p+4", LIT (-0x1.2p+4), { LIT (-0xf.fffffbe9675dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675c8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.86ap+16", LIT (-0x1.86ap+16), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p+4", LIT (-0x1p+4), { LIT (-0xf.ffffe1caa4458p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p-100", LIT (-0x1p-100), { LIT (-0x1p-100), ERRNO_UNCHANGED }, { LIT (-0x1p-100), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-104), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p-20", LIT (-0x1p-20), { LIT (-0xf.ffff800002abp-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aa8p-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aa8p-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aa8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p-32", LIT (-0x1p-32), { LIT (-0xf.fffffff800008p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff8p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff8p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff8p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p-600", LIT (-0x1p-600), { LIT (-0x1p-600), ERRNO_UNCHANGED }, { LIT (-0x1p-600), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-604), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-604), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p-64", LIT (-0x1p-64), { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-68), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.4p+4", LIT (-0x2.4p+4), { LIT (-0xf.ffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffe8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffe8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.5p+4", LIT (-0x2.5p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.6p+4", LIT (-0x2.6p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.71p+12", LIT (-0x2.71p+12), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.cp+4", LIT (-0x2.cp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.ep+4", LIT (-0x2.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.e8p+8", LIT (-0x3.e8p+8), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.9p+4", LIT (-0x4.9p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.ap+4", LIT (-0x4.ap+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.bp+4", LIT (-0x4.bp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.ep+4", LIT (-0x4.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.fp+4", LIT (-0x4.fp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (-0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-12", LIT (-0x4p-12), { LIT (-0x3.ff800aaa0008ap-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa00088p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa00088p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa00088p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffep-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-4", LIT (-0x4p-4), { LIT (-0x3.8a0830a9befaap-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-52", LIT (-0x4p-52), { LIT (-0x3.ffffffffffffap-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8p-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8p-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x5p+4", LIT (-0x5p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x6.4p+4", LIT (-0x6.4p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7.d6c508p+0", LIT (-0x7.d6c508p+0), { LIT (-0xf.fe62c59d9de8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de78p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7.d6c50b469d404p+0", LIT (-0x7.d6c50b469d404p+0), { LIT (-0xf.fe62c5a2e793p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e7928p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e7928p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e7928p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7.d6c51p+0", LIT (-0x7.d6c51p+0), { LIT (-0xf.fe62c5aa87bbp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87ba8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87ba8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87ba8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-32", LIT (-0x8p-32), { LIT (-0x7.ffffffe000004p-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffep-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffep-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffep-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.ffd0650c95378p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c9537p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c9537p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c9537p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0x1.ceb088a68e804p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e804p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e804p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e805p+28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.86ap+16", LIT (0x1.86ap+16), { LIT (0xf.ffffffffffff8p+1020), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.ffffffffffff8p+1020), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary64)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0x1.0c3d3920862c8p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c9p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c8p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c9p+36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0x9.b82385761376p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613768p+40), ERRNO_UNCHANGED }, { LIT (0x9.b82385761376p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613768p+40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.f4p+8", LIT (0x1.f4p+8), { LIT (0x2.8b74553efc87p+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc872p+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87p+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc872p+720), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x1.b7e151628aed2p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed3p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed3p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-100", LIT (0x1p-100), { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-20", LIT (0x1p-20), { LIT (0x1.00000800002aap-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002abp-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aap-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002abp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-32", LIT (0x1p-32), { LIT (0x1.000000008p-32), ERRNO_UNCHANGED }, { LIT (0x1.000000008p-32), ERRNO_UNCHANGED }, { LIT (0x1.000000008p-32), ERRNO_UNCHANGED }, { LIT (0x1.0000000080001p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-600", LIT (0x1p-600), { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p-600), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-64", LIT (0x1p-64), { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0x5.a278886f23558p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355cp+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f23558p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355cp+48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0x3.4441a72f2e5d4p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d6p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d4p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d6p+56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.c5c4p+12", LIT (0x2.c5c4p+12), { LIT (0xf.ffffffffffff8p+1020), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.ffffffffffff8p+1020), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x6.63992e35376b4p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b8p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b4p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0x1.19103e4080b45p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b46p+72), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.735f48p-4", LIT (0x3.735f48p-4), { LIT (0x3.d9dceda6a6b4p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b42p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b4p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b42p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.735f497c4e674p-4", LIT (0x3.735f497c4e674p-4), { LIT (0x3.d9dcef7e7e396p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e396p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e396p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.735f497c4e676p-4", LIT (0x3.735f497c4e676p-4), { LIT (0x3.d9dcef7e7e398p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.735f4cp-4", LIT (0x3.735f4cp-4), { LIT (0x3.d9dcf29d1dfp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df02p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1dfp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df02p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.cp+4", LIT (0x3.cp+4), { LIT (0x5.e76f27714f198p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f198p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f198p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19cp+84), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.315e5bf6fb105p+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb106p+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105p+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb106p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.6p+4", LIT (0x4.6p+4), { LIT (0x1.fbfd219c43b04p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b04p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b04p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b05p+100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.857de8p+4", LIT (0x4.857de8p+4), { LIT (0x1.4aaa8e05bcf71p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf72p+104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x3.599205c4e74bp+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74bp+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74bp+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b2p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4.0000000000004p-1024), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x8p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x4.00800aab555dcp-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dcp-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dcp-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555ep-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4.0000000000004p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-4", LIT (0x4p-4), { LIT (0x4.8b5e3c3e81864p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81868p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81864p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81868p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x4.0000000000008p-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008p-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008p-52), ERRNO_UNCHANGED }, { LIT (0x4.000000000000cp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.ap+4", LIT (0x5.ap+4), { LIT (0x3.96211ff7d82c6p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c8p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c6p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c8p+128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.dfeb68p-4", LIT (0x5.dfeb68p-4), { LIT (0x7.19267f117e20cp-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e21p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20cp-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e21p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.fb8dc64e91a74p-4", LIT (0x5.fb8dc64e91a74p-4), { LIT (0x7.412dde3318f34p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f34p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f34p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f38p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.fb8dc8p-4", LIT (0x5.fb8dc8p-4), { LIT (0x7.412de0a90d3dcp-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcp-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcp-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.fb8dcp-4", LIT (0x5.fb8dcp-4), { LIT (0x7.412dd50876504p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876504p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876504p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876508p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x9.369c4cb819c78p+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78p+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78p+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c8p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5p+4", LIT (0x5p+4), { LIT (0xa.abbcdcc279f58p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f58p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f58p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f6p+112), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.1b4d318238d48p-4", LIT (0x6.1b4d318238d48p-4), { LIT (0x7.6f8042a9af77cp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af78p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77cp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.1b4d318238d4cp-4", LIT (0x6.1b4d318238d4cp-4), { LIT (0x7.6f8042a9af784p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af784p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af784p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af788p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.1b4d38p-4", LIT (0x6.1b4d38p-4), { LIT (0x7.6f804c2bba674p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba678p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba674p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba678p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.1b4d3p-4", LIT (0x6.1b4d3p-4), { LIT (0x7.6f804073fa444p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa448p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.289a78p-4", LIT (0x6.289a78p-4), { LIT (0x7.8304264e39d2cp-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2cp-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2cp-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x1.3494a9b171bf4p+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf5p+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4p+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf5p+144), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.660247486aed8p-4", LIT (0x6.660247486aed8p-4), { LIT (0x7.ddee37ace0524p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0524p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0524p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0528p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.660248p-4", LIT (0x6.660248p-4), { LIT (0x7.ddee38beb9054p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb9054p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb9054p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb9058p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.66024p-4", LIT (0x6.66024p-4), { LIT (0x7.ddee2ccfc1ebcp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ecp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebcp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7.fp+4", LIT (0x7.fp+4), { LIT (0x9.5521837491608p+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749161p+180), ERRNO_UNCHANGED }, { LIT (0x9.5521837491608p+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749161p+180), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8.0000000000008p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-32", LIT (0x8p-32), { LIT (0x8.0000002p-32), ERRNO_UNCHANGED }, { LIT (0x8.0000002p-32), ERRNO_UNCHANGED }, { LIT (0x8.0000002p-32), ERRNO_UNCHANGED }, { LIT (0x8.0000002000008p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000008p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xap+0", LIT (0xap+0), { LIT (0x5.609773e54157cp+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54158p+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157cp+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54158p+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x1.1df3b68cfb9efp+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9efp+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9efp+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9fp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.4152ac57cd1e8p-60", LIT (0xe.4152ac57cd1e8p-60), { LIT (0xe.4152ac57cd1e8p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e8p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e8p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1fp-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.4152ac57cd1fp-60", LIT (0xe.4152ac57cd1fp-60), { LIT (0xe.4152ac57cd1fp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1fp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1fp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f8p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.4152ap-60", LIT (0xe.4152ap-60), { LIT (0xe.4152ap-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ap-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ap-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a00000008p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.4152bp-60", LIT (0xe.4152bp-60), { LIT (0xe.4152bp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152bp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152bp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b00000008p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.ffffffffffff8p+1020), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.ffffffffffff8p+1020), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.ffffffffffff8p+1020), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.ffffffffffff8p+1020), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary64)
    { "0xfp+0", LIT (0xfp+0), { LIT (0x3.1e1985f5a550cp+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550ep+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550cp+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550ep+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.1p+4", LIT (-0x1.1p+4), { LIT (-0xf.fffff4e30e7452cbb1a1331e24p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452cbb1a1331e24p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452cbb1a1331e2p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452cbb1a1331e2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.2p+4", LIT (-0x1.2p+4), { LIT (-0xf.fffffbe9675ce59817cddee3acp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce59817cddee3acp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce59817cddee3a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce59817cddee3a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.86ap+16", LIT (-0x1.86ap+16), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p+4", LIT (-0x1p+4), { LIT (-0xf.ffffe1caa445117a35259a08c4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445117a35259a08cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445117a35259a08cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445117a35259a08cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p-100", LIT (-0x1p-100), { LIT (-0xf.ffffffffffffffffffffffff84p-104), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffff8p-104), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffff8p-104), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffff8p-104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p-20", LIT (-0x1p-20), { LIT (-0xf.ffff800002aaaaa00000222224p-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaa0000022222p-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaa0000022222p-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaa0000022222p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p-32", LIT (-0x1p-32), { LIT (-0xf.fffffff800000002aaaaaaaa04p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff800000002aaaaaaaap-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff800000002aaaaaaaap-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff800000002aaaaaaaap-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p-600", LIT (-0x1p-600), { LIT (-0x1p-600), ERRNO_UNCHANGED }, { LIT (-0x1p-600), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-604), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-604), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p-64", LIT (-0x1p-64), { LIT (-0xf.fffffffffffffff80000000004p-68), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff8p-68), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff8p-68), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff8p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.4p+4", LIT (-0x2.4p+4), { LIT (-0xf.fffffffffffef493c50221f9c8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef493c50221f9c8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef493c50221f9c4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef493c50221f9c4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.5p+4", LIT (-0x2.5p+4), { LIT (-0xf.ffffffffffff9d9ee380d67ebp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9d9ee380d67eacp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9d9ee380d67eacp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9d9ee380d67eacp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.6p+4", LIT (-0x2.6p+4), { LIT (-0xf.ffffffffffffdbceea52a399fcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbceea52a399f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbceea52a399f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbceea52a399f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.71p+12", LIT (-0x2.71p+12), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.cp+4", LIT (-0x2.cp+4), { LIT (-0xf.ffffffffffffffe908be21e8b8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffe908be21e8b8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffe908be21e8b4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffe908be21e8b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0xf.fffffffffffffff78d24617008p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff78d24617004p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff78d24617004p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff78d24617004p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.ep+4", LIT (-0x2.ep+4), { LIT (-0xf.fffffffffffffffce4543c89fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffce4543c89ecp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffce4543c89ecp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffce4543c89ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.e8p+8", LIT (-0x3.e8p+8), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.9p+4", LIT (-0x4.9p+4), { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.ap+4", LIT (-0x4.ap+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.bp+4", LIT (-0x4.bp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.ep+4", LIT (-0x4.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.fp+4", LIT (-0x4.fp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (-0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (-0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-12", LIT (-0x4p-12), { LIT (-0x3.ff800aaa0008882d8618478532p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882d8618478531p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882d8618478531p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882d8618478531p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-4", LIT (-0x4p-4), { LIT (-0x3.8a0830a9befa8bcbea343629cap-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bcbea343629c9p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bcbea343629c9p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bcbea343629c9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-52", LIT (-0x4p-52), { LIT (-0x3.ffffffffffff8000000000000bp-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8000000000000bp-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8000000000000ap-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8000000000000ap-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x5p+4", LIT (-0x5p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x6.4p+4", LIT (-0x6.4p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7.d6c508p+0", LIT (-0x7.d6c508p+0), { LIT (-0xf.fe62c59d9de7d6168bf8c31a74p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d6168bf8c31a7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d6168bf8c31a7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d6168bf8c31a7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7.d6c50b469d404p+0", LIT (-0x7.d6c50b469d404p+0), { LIT (-0xf.fe62c5a2e792bffeb1e98cc708p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792bffeb1e98cc704p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792bffeb1e98cc704p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792bffeb1e98cc704p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7.d6c51p+0", LIT (-0x7.d6c51p+0), { LIT (-0xf.fe62c5aa87bab580018589d528p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab580018589d524p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab580018589d524p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab580018589d524p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffep-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-32", LIT (-0x8p-32), { LIT (-0x7.ffffffe000000055555554aaacp-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe000000055555554aaaap-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe000000055555554aaaap-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe000000055555554aaaap-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x7.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x7.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_ibm128)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.ffd0650c953706cac749b7156p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706cac749b7156p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706cac749b7155cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706cac749b7155cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0x1.ceb088a68e80402189797f95998p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e80402189797f959ap+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e80402189797f95998p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e80402189797f959ap+28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.86ap+16", LIT (0x1.86ap+16), { LIT (0xf.ffffffffffffbffffffffffffcp+1020), NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.ffffffffffffbffffffffffffcp+1020), NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0x1.0c3d3920862c88aafb2ae72d68p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88aafb2ae72d688p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88aafb2ae72d68p+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88aafb2ae72d688p+36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0x9.b823857613764f43e201f73a54p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f43e201f73a54p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f43e201f73a54p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f43e201f73a58p+40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.f4p+8", LIT (0x1.f4p+8), { LIT (0x2.8b74553efc87128fd5d1b2c1eap+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87128fd5d1b2c1eap+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87128fd5d1b2c1eap+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87128fd5d1b2c1ebp+720), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x1.b7e151628aed2a6abf7158809c8p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6abf7158809dp+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6abf7158809c8p+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6abf7158809dp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-100", LIT (0x1p-100), { LIT (0x1.00000000000000000000000008p-100), ERRNO_UNCHANGED }, { LIT (0x1.00000000000000000000000008p-100), ERRNO_UNCHANGED }, { LIT (0x1.00000000000000000000000008p-100), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000088p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-20", LIT (0x1p-20), { LIT (0x1.00000800002aaaab5555577777p-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaab55555777778p-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaab5555577777p-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaab55555777778p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-32", LIT (0x1p-32), { LIT (0x1.00000000800000002aaaaaaab5p-32), ERRNO_UNCHANGED }, { LIT (0x1.00000000800000002aaaaaaab58p-32), ERRNO_UNCHANGED }, { LIT (0x1.00000000800000002aaaaaaab5p-32), ERRNO_UNCHANGED }, { LIT (0x1.00000000800000002aaaaaaab58p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-600", LIT (0x1p-600), { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p-600), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-64", LIT (0x1p-64), { LIT (0x1.00000000000000008p-64), ERRNO_UNCHANGED }, { LIT (0x1.00000000000000008p-64), ERRNO_UNCHANGED }, { LIT (0x1.00000000000000008p-64), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000080000000008p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0x5.a278886f2355ba66b452ea7226p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba66b452ea7226p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba66b452ea7226p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba66b452ea7228p+48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0x3.4441a72f2e5d50686c20e8b55bp+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d50686c20e8b55bp+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d50686c20e8b55bp+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d50686c20e8b55cp+56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.c5c4p+12", LIT (0x2.c5c4p+12), { LIT (0xf.ffffffffffffbffffffffffffcp+1020), NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.ffffffffffffbffffffffffffcp+1020), NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x6.63992e35376b730ce8ee881adap+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b730ce8ee881adap+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b730ce8ee881adap+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b730ce8ee881adcp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0x1.19103e4080b45664d6740cf8c58p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45664d6740cf8c6p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45664d6740cf8c58p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45664d6740cf8c6p+72), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.735f48p-4", LIT (0x3.735f48p-4), { LIT (0x3.d9dceda6a6b41355e2e68cfbebp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41355e2e68cfbecp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41355e2e68cfbebp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41355e2e68cfbecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.735f497c4e674p-4", LIT (0x3.735f497c4e674p-4), { LIT (0x3.d9dcef7e7e39645fb77dffbba9p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39645fb77dffbbaap-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39645fb77dffbba9p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39645fb77dffbbaap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.735f497c4e67535cp-4", LIT (0x3.735f497c4e67535cp-4), { LIT (0x3.d9dcef7e7e397c649290c708e3p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c649290c708e4p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c649290c708e3p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c649290c708e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.735f497c4e676p-4", LIT (0x3.735f497c4e676p-4), { LIT (0x3.d9dcef7e7e398c13715cfcb81cp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c13715cfcb81dp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c13715cfcb81cp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c13715cfcb81dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.735f4cp-4", LIT (0x3.735f4cp-4), { LIT (0x3.d9dcf29d1df01bce7765d392e5p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bce7765d392e5p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bce7765d392e5p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bce7765d392e6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.cp+4", LIT (0x3.cp+4), { LIT (0x5.e76f27714f19924caf2a550818p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19924caf2a550818p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19924caf2a550818p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19924caf2a55081ap+84), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.315e5bf6fb105f2d4bdfc537448p+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2d4bdfc53745p+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2d4bdfc537448p+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2d4bdfc53745p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.6p+4", LIT (0x4.6p+4), { LIT (0x1.fbfd219c43b04730797e2bfeb18p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b04730797e2bfeb2p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b04730797e2bfeb18p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b04730797e2bfeb2p+100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.857de8p+4", LIT (0x4.857de8p+4), { LIT (0x1.4aaa8e05bcf71097ff88abf1c08p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71097ff88abf1c08p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71097ff88abf1c08p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71097ff88abf1c1p+104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x3.599205c4e74b0cf1ada77fb727p+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cf1ada77fb728p+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cf1ada77fb727p+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cf1ada77fb728p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4.0000000000004p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x8p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x4.00800aab555dde38e6ce86e926p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde38e6ce86e928p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde38e6ce86e926p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde38e6ce86e928p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4.00000000000000000000000002p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-4", LIT (0x4p-4), { LIT (0x4.8b5e3c3e81866767bc3b69baaap-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81866767bc3b69baacp-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81866767bc3b69baaap-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81866767bc3b69baacp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x4.0000000000008000000000000ap-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008000000000000ap-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008000000000000ap-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008000000000000cp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.ap+4", LIT (0x5.ap+4), { LIT (0x3.96211ff7d82c792f823b2ba3a1p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c792f823b2ba3a1p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c792f823b2ba3a1p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c792f823b2ba3a2p+128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.dfeb68p-4", LIT (0x5.dfeb68p-4), { LIT (0x7.19267f117e20e3b9a8b8bdf57ep-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3b9a8b8bdf58p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3b9a8b8bdf57ep-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3b9a8b8bdf58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.fb8dc64e91a74p-4", LIT (0x5.fb8dc64e91a74p-4), { LIT (0x7.412dde3318f344bc6f6cd00f8ep-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344bc6f6cd00f8ep-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344bc6f6cd00f8ep-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344bc6f6cd00f9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.fb8dc8p-4", LIT (0x5.fb8dc8p-4), { LIT (0x7.412de0a90d3dcc39dc4e01aef2p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc39dc4e01aef4p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc39dc4e01aef2p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc39dc4e01aef4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.fb8dcp-4", LIT (0x5.fb8dcp-4), { LIT (0x7.412dd50876505fd8f901001e92p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fd8f901001e92p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fd8f901001e92p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fd8f901001e94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x9.369c4cb819c78fb37d56c91ad4p+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fb37d56c91ad4p+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fb37d56c91ad4p+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fb37d56c91ad8p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5p+4", LIT (0x5p+4), { LIT (0xa.abbcdcc279f59e45281da5471p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e45281da54714p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e45281da5471p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e45281da54714p+112), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.1b4d318238d48p-4", LIT (0x6.1b4d318238d48p-4), { LIT (0x7.6f8042a9af77fc11bbb323d01p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc11bbb323d012p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc11bbb323d01p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc11bbb323d012p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.1b4d318238d4a2a8p-4", LIT (0x6.1b4d318238d4a2a8p-4), { LIT (0x7.6f8042a9af782ed4bf03885aa2p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782ed4bf03885aa4p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782ed4bf03885aa2p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782ed4bf03885aa4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.1b4d318238d4cp-4", LIT (0x6.1b4d318238d4cp-4), { LIT (0x7.6f8042a9af7859cfbcbdca8df2p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859cfbcbdca8df2p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859cfbcbdca8df2p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859cfbcbdca8df4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.1b4d38p-4", LIT (0x6.1b4d38p-4), { LIT (0x7.6f804c2bba6774a43c5c34a96ep-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774a43c5c34a97p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774a43c5c34a96ep-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774a43c5c34a97p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.1b4d3p-4", LIT (0x6.1b4d3p-4), { LIT (0x7.6f804073fa444cb711aa5c8154p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cb711aa5c8154p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cb711aa5c8154p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cb711aa5c8156p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.289a78p-4", LIT (0x6.289a78p-4), { LIT (0x7.8304264e39d2cffd272b76863ep-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2cffd272b76864p-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2cffd272b76863ep-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2cffd272b76864p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x1.3494a9b171bf4acc2250933224p+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4acc2250933224p+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4acc2250933224p+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4acc22509332248p+144), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.660247486aed8p-4", LIT (0x6.660247486aed8p-4), { LIT (0x7.ddee37ace0525de2e3d415373ep-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525de2e3d415373ep-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525de2e3d415373ep-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525de2e3d415374p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.660248p-4", LIT (0x6.660248p-4), { LIT (0x7.ddee38beb90553d11ec1beb27ap-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553d11ec1beb27ap-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553d11ec1beb27ap-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553d11ec1beb27cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.66024p-4", LIT (0x6.66024p-4), { LIT (0x7.ddee2ccfc1ebf03262b062f7fap-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf03262b062f7fap-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf03262b062f7fap-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf03262b062f7fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.fp+4", LIT (0x7.fp+4), { LIT (0x9.552183749160e8b702888dad94p+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8b702888dad94p+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8b702888dad94p+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8b702888dad98p+180), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000004p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-32", LIT (0x8p-32), { LIT (0x8.0000002000000055555556p-32), ERRNO_UNCHANGED }, { LIT (0x8.0000002000000055555556p-32), ERRNO_UNCHANGED }, { LIT (0x8.0000002000000055555556p-32), ERRNO_UNCHANGED }, { LIT (0x8.00000020000000555555560004p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x8.00000000000000000000000004p-972), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_ibm128)
    { "0xap+0", LIT (0xap+0), { LIT (0x5.609773e54157e7c1faa3015b44p+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7c1faa3015b44p+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7c1faa3015b44p+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7c1faa3015b46p+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x1.1df3b68cfb9ef7a986addc7dce8p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7a986addc7dcfp+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7a986addc7dce8p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7a986addc7dcfp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.4152ac57cd1e8p-60", LIT (0xe.4152ac57cd1e8p-60), { LIT (0xe.4152ac57cd1e8659adaf7e8f0cp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e8659adaf7e8f1p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e8659adaf7e8f0cp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e8659adaf7e8f1p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.4152ac57cd1ea7ap-60", LIT (0xe.4152ac57cd1ea7ap-60), { LIT (0xe.4152ac57cd1eadf9adaf7e8f0cp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eadf9adaf7e8f1p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eadf9adaf7e8f0cp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eadf9adaf7e8f1p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.4152ac57cd1fp-60", LIT (0xe.4152ac57cd1fp-60), { LIT (0xe.4152ac57cd1f0659adaf7e8f0cp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f0659adaf7e8f1p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f0659adaf7e8f0cp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f0659adaf7e8f1p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.4152ap-60", LIT (0xe.4152ap-60), { LIT (0xe.4152a00000000659ada47f572p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a00000000659ada47f572p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a00000000659ada47f572p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a00000000659ada47f5724p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.4152bp-60", LIT (0xe.4152bp-60), { LIT (0xe.4152b00000000659adb2c0a9c8p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b00000000659adb2c0a9c8p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b00000000659adb2c0a9c8p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b00000000659adb2c0a9ccp-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.ffffffffffffbffffffffffffcp+1020), NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.ffffffffffffbffffffffffffcp+1020), NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xf.ffffffffffffbffffffffffffcp+1020), NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.ffffffffffffbffffffffffffcp+1020), NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.ffffffffffffbffffffffffffcp+1020), NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.ffffffffffffbffffffffffffcp+1020), NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_ibm128)
    { "0xfp+0", LIT (0xfp+0), { LIT (0x3.1e1985f5a550dde2e5fe372cd4p+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550dde2e5fe372cd5p+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550dde2e5fe372cd4p+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550dde2e5fe372cd5p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.1p+4", LIT (-0x1.1p+4), { LIT (-0xf.fffff4e30e7452dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.2p+4", LIT (-0x1.2p+4), { LIT (-0xf.fffffbe9675ce5ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce5ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce59p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce59p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.86ap+16", LIT (-0x1.86ap+16), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+4", LIT (-0x1p+4), { LIT (-0xf.ffffe1caa445118p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445118p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445117p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445117p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p-100", LIT (-0x1p-100), { LIT (-0x1p-100), ERRNO_UNCHANGED }, { LIT (-0x1p-100), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-104), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p-10000", LIT (-0x1p-10000), { LIT (-0x1p-10000), ERRNO_UNCHANGED }, { LIT (-0x1p-10000), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-10004), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-10004), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p-20", LIT (-0x1p-20), { LIT (-0xf.ffff800002aaaabp-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaap-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaap-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaap-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p-32", LIT (-0x1p-32), { LIT (-0xf.fffffff80000001p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff8p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff8p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff8p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p-600", LIT (-0x1p-600), { LIT (-0x1p-600), ERRNO_UNCHANGED }, { LIT (-0x1p-600), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-604), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-604), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p-64", LIT (-0x1p-64), { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-68), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.4p+4", LIT (-0x2.4p+4), { LIT (-0xf.fffffffffffef4ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef49p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef49p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef49p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.5p+4", LIT (-0x2.5p+4), { LIT (-0xf.ffffffffffff9dap-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9dap-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9d9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9d9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.6p+4", LIT (-0x2.6p+4), { LIT (-0xf.ffffffffffffdbdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.71p+12", LIT (-0x2.71p+12), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.cp+4", LIT (-0x2.cp+4), { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.ep+4", LIT (-0x2.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.e8p+8", LIT (-0x3.e8p+8), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.9p+4", LIT (-0x4.9p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.ap+4", LIT (-0x4.ap+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.bp+4", LIT (-0x4.bp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.ep+4", LIT (-0x4.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.fp+4", LIT (-0x4.fp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-12", LIT (-0x4p-12), { LIT (-0x3.ff800aaa0008883p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882cp-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882cp-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-4", LIT (-0x4p-4), { LIT (-0x3.8a0830a9befa8bccp-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bccp-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bc8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bc8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-52", LIT (-0x4p-52), { LIT (-0x3.ffffffffffff8004p-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8p-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8p-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x5p+4", LIT (-0x5p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x6.4p+4", LIT (-0x6.4p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7.d6c508p+0", LIT (-0x7.d6c508p+0), { LIT (-0xf.fe62c59d9de7d62p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d61p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d61p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7.d6c50b469d404p+0", LIT (-0x7.d6c50b469d404p+0), { LIT (-0xf.fe62c5a2e792cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792bffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792bffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7.d6c51p+0", LIT (-0x7.d6c51p+0), { LIT (-0xf.fe62c5aa87bab59p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-32", LIT (-0x8p-32), { LIT (-0x7.ffffffe000000058p-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe000000058p-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe00000005p-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe00000005p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.ffd0650c953706dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0x1.ceb088a68e80402p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e804022p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e80402p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e804022p+28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.86ap+16", LIT (0x1.86ap+16), { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_intel96)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0x1.0c3d3920862c88aap+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88aap+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88aap+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88acp+36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0x9.b823857613764f4p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f4p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f4p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f5p+40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.f4p+8", LIT (0x1.f4p+8), { LIT (0x2.8b74553efc87128cp+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87129p+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87128cp+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87129p+720), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x1.b7e151628aed2a6ap+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6ap+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6ap+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-100", LIT (0x1p-100), { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-10000), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-20", LIT (0x1p-20), { LIT (0x1.00000800002aaaaap-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaacp-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaaap-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaacp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-32", LIT (0x1p-32), { LIT (0x1.000000008p-32), ERRNO_UNCHANGED }, { LIT (0x1.000000008p-32), ERRNO_UNCHANGED }, { LIT (0x1.000000008p-32), ERRNO_UNCHANGED }, { LIT (0x1.0000000080000002p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-600", LIT (0x1p-600), { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-600), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-64", LIT (0x1p-64), { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0x5.a278886f2355ba6p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba68p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba6p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba68p+48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0x3.4441a72f2e5d5068p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d5068p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d5068p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d506cp+56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.c5c4p+12", LIT (0x2.c5c4p+12), { LIT (0xc.2c2b72bac3ba40cp+16380), ERRNO_UNCHANGED }, { LIT (0xc.2c2b72bac3ba40dp+16380), ERRNO_UNCHANGED }, { LIT (0xc.2c2b72bac3ba40cp+16380), ERRNO_UNCHANGED }, { LIT (0xc.2c2b72bac3ba40dp+16380), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x6.63992e35376b7308p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b731p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b7308p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b731p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.0000000000000008p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0x1.19103e4080b45664p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45664p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45664p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45666p+72), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.735f48p-4", LIT (0x3.735f48p-4), { LIT (0x3.d9dceda6a6b41354p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41354p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41354p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41358p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.735f497c4e674p-4", LIT (0x3.735f497c4e674p-4), { LIT (0x3.d9dcef7e7e39645cp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39646p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39645cp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39646p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.735f497c4e67535cp-4", LIT (0x3.735f497c4e67535cp-4), { LIT (0x3.d9dcef7e7e397c64p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c64p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c64p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.735f497c4e676p-4", LIT (0x3.735f497c4e676p-4), { LIT (0x3.d9dcef7e7e398c1p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c14p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c1p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c14p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.735f4cp-4", LIT (0x3.735f4cp-4), { LIT (0x3.d9dcf29d1df01bccp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bdp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bccp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.cp+4", LIT (0x3.cp+4), { LIT (0x5.e76f27714f199248p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19925p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f199248p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19925p+84), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.315e5bf6fb105f2cp+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2ep+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2cp+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2ep+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.0000000000000028p-16384", LIT (0x4.0000000000000028p-16384), { LIT (0x4.0000000000000028p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000028p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000028p-16384), ERRNO_UNCHANGED }, { LIT (0x4.000000000000003p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.6p+4", LIT (0x4.6p+4), { LIT (0x1.fbfd219c43b0473p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b0473p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b0473p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b04732p+100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.857de8p+4", LIT (0x4.857de8p+4), { LIT (0x1.4aaa8e05bcf71096p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71098p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71096p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71098p+104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x3.599205c4e74b0cfp+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cfp+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cfp+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cf4p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x4.00800aab555dde38p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde38p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde38p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde4p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4.0000000000000008p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-4", LIT (0x4p-4), { LIT (0x4.8b5e3c3e8186676p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81866768p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e8186676p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81866768p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x4.0000000000008p-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008p-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008p-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008008p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.ap+4", LIT (0x5.ap+4), { LIT (0x3.96211ff7d82c792cp+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c793p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c792cp+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c793p+128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.dfeb68p-4", LIT (0x5.dfeb68p-4), { LIT (0x7.19267f117e20e3b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.fb8dc64e91a74p-4", LIT (0x5.fb8dc64e91a74p-4), { LIT (0x7.412dde3318f344b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344cp-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.fb8dc8p-4", LIT (0x5.fb8dc8p-4), { LIT (0x7.412de0a90d3dcc38p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc38p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc38p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.fb8dcp-4", LIT (0x5.fb8dcp-4), { LIT (0x7.412dd50876505fd8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fd8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fd8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x9.369c4cb819c78fbp+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fbp+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fbp+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fcp+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5p+4", LIT (0x5p+4), { LIT (0xa.abbcdcc279f59e4p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e4p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e4p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e5p+112), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.1b4d318238d48p-4", LIT (0x6.1b4d318238d48p-4), { LIT (0x7.6f8042a9af77fc1p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc1p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc1p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.1b4d318238d4a2a8p-4", LIT (0x6.1b4d318238d4a2a8p-4), { LIT (0x7.6f8042a9af782edp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782ed8p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782edp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782ed8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.1b4d318238d4cp-4", LIT (0x6.1b4d318238d4cp-4), { LIT (0x7.6f8042a9af7859c8p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859dp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859c8p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.1b4d38p-4", LIT (0x6.1b4d38p-4), { LIT (0x7.6f804c2bba6774ap-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774ap-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.1b4d3p-4", LIT (0x6.1b4d3p-4), { LIT (0x7.6f804073fa444cbp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cb8p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cbp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.289a78p-4", LIT (0x6.289a78p-4), { LIT (0x7.8304264e39d2cff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2dp-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2cff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x1.3494a9b171bf4accp+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4accp+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4accp+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4acep+144), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.660247486aed8p-4", LIT (0x6.660247486aed8p-4), { LIT (0x7.ddee37ace0525dep-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525dep-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525dep-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525de8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.660248p-4", LIT (0x6.660248p-4), { LIT (0x7.ddee38beb90553dp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553dp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553dp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.66024p-4", LIT (0x6.66024p-4), { LIT (0x7.ddee2ccfc1ebf03p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf03p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf03p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf038p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.fp+4", LIT (0x7.fp+4), { LIT (0x9.552183749160e8bp+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8bp+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8bp+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8cp+180), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16444), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-32", LIT (0x8p-32), { LIT (0x8.000000200000005p-32), ERRNO_UNCHANGED }, { LIT (0x8.000000200000005p-32), ERRNO_UNCHANGED }, { LIT (0x8.000000200000005p-32), ERRNO_UNCHANGED }, { LIT (0x8.000000200000006p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xap+0", LIT (0xap+0), { LIT (0x5.609773e54157e7cp+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7cp+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7cp+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7c8p+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x1.1df3b68cfb9ef7a8p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7aap+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7a8p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7aap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.4152ac57cd1e8p-60", LIT (0xe.4152ac57cd1e8p-60), { LIT (0xe.4152ac57cd1e865p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e866p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e865p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e866p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.4152ac57cd1ea7ap-60", LIT (0xe.4152ac57cd1ea7ap-60), { LIT (0xe.4152ac57cd1eadfp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eaep-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eadfp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eaep-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.4152ac57cd1fp-60", LIT (0xe.4152ac57cd1fp-60), { LIT (0xe.4152ac57cd1f065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f066p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f066p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.4152ap-60", LIT (0xe.4152ap-60), { LIT (0xe.4152a0000000065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a0000000066p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a0000000065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a0000000066p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.4152bp-60", LIT (0xe.4152bp-60), { LIT (0xe.4152b0000000065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b0000000066p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b0000000065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b0000000066p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_intel96)
    { "0xfp+0", LIT (0xfp+0), { LIT (0x3.1e1985f5a550ddep+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550dde4p+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550ddep+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550dde4p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.1p+4", LIT (-0x1.1p+4), { LIT (-0xf.fffff4e30e7452dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff4e30e7452cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.2p+4", LIT (-0x1.2p+4), { LIT (-0xf.fffffbe9675ce5ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce5ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce59p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffbe9675ce59p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.86ap+16", LIT (-0x1.86ap+16), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+4", LIT (-0x1p+4), { LIT (-0xf.ffffe1caa445118p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445118p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445117p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffe1caa445117p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p-100", LIT (-0x1p-100), { LIT (-0x1p-100), ERRNO_UNCHANGED }, { LIT (-0x1p-100), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-104), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p-10000", LIT (-0x1p-10000), { LIT (-0x1p-10000), ERRNO_UNCHANGED }, { LIT (-0x1p-10000), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-10004), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-10004), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p-20", LIT (-0x1p-20), { LIT (-0xf.ffff800002aaaabp-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaap-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaap-24), ERRNO_UNCHANGED }, { LIT (-0xf.ffff800002aaaaap-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p-32", LIT (-0x1p-32), { LIT (-0xf.fffffff80000001p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff8p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff8p-36), ERRNO_UNCHANGED }, { LIT (-0xf.fffffff8p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p-600", LIT (-0x1p-600), { LIT (-0x1p-600), ERRNO_UNCHANGED }, { LIT (-0x1p-600), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-604), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-604), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p-64", LIT (-0x1p-64), { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-68), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.4p+4", LIT (-0x2.4p+4), { LIT (-0xf.fffffffffffef4ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef49p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef49p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffef49p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.5p+4", LIT (-0x2.5p+4), { LIT (-0xf.ffffffffffff9dap-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9dap-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9d9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff9d9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.6p+4", LIT (-0x2.6p+4), { LIT (-0xf.ffffffffffffdbdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffdbcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.71p+12", LIT (-0x2.71p+12), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.cp+4", LIT (-0x2.cp+4), { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.ep+4", LIT (-0x2.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.e8p+8", LIT (-0x3.e8p+8), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.9p+4", LIT (-0x4.9p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.ap+4", LIT (-0x4.ap+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.bp+4", LIT (-0x4.bp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.ep+4", LIT (-0x4.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.fp+4", LIT (-0x4.fp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-12", LIT (-0x4p-12), { LIT (-0x3.ff800aaa0008883p-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882cp-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882cp-12), ERRNO_UNCHANGED }, { LIT (-0x3.ff800aaa0008882cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (-0x4p-16384), ERRNO_UNCHANGED }, { LIT (-0x4p-16384), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-16384), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16448", LIT (-0x4p-16448), { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-4", LIT (-0x4p-4), { LIT (-0x3.8a0830a9befa8bccp-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bccp-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bc8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.8a0830a9befa8bc8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-52", LIT (-0x4p-52), { LIT (-0x3.ffffffffffff8004p-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8p-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8p-52), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffff8p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x5p+4", LIT (-0x5p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x6.4p+4", LIT (-0x6.4p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7.d6c508p+0", LIT (-0x7.d6c508p+0), { LIT (-0xf.fe62c59d9de7d62p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d61p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d61p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c59d9de7d61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7.d6c50b469d404p+0", LIT (-0x7.d6c50b469d404p+0), { LIT (-0xf.fe62c5a2e792cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792bffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5a2e792bffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7.d6c51p+0", LIT (-0x7.d6c51p+0), { LIT (-0xf.fe62c5aa87bab59p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fe62c5aa87bab58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-32", LIT (-0x8p-32), { LIT (-0x7.ffffffe000000058p-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe000000058p-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe00000005p-32), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffe00000005p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.ffd0650c953706dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffd0650c953706cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0x1.ceb088a68e80402p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e804022p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e80402p+28), ERRNO_UNCHANGED }, { LIT (0x1.ceb088a68e804022p+28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.86ap+16", LIT (0x1.86ap+16), { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0x1.0c3d3920862c88aap+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88aap+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88aap+36), ERRNO_UNCHANGED }, { LIT (0x1.0c3d3920862c88acp+36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0x9.b823857613764f4p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f4p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f4p+40), ERRNO_UNCHANGED }, { LIT (0x9.b823857613764f5p+40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.f4p+8", LIT (0x1.f4p+8), { LIT (0x2.8b74553efc87128cp+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87129p+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87128cp+720), ERRNO_UNCHANGED }, { LIT (0x2.8b74553efc87129p+720), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x1.b7e151628aed2a6ap+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6ap+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6ap+0), ERRNO_UNCHANGED }, { LIT (0x1.b7e151628aed2a6cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-100", LIT (0x1p-100), { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-10000), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-20", LIT (0x1p-20), { LIT (0x1.00000800002aaaaap-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaacp-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaaap-20), ERRNO_UNCHANGED }, { LIT (0x1.00000800002aaaacp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-32", LIT (0x1p-32), { LIT (0x1.000000008p-32), ERRNO_UNCHANGED }, { LIT (0x1.000000008p-32), ERRNO_UNCHANGED }, { LIT (0x1.000000008p-32), ERRNO_UNCHANGED }, { LIT (0x1.0000000080000002p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-600", LIT (0x1p-600), { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-600), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-64", LIT (0x1p-64), { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1p-64), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0x5.a278886f2355ba6p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba68p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba6p+48), ERRNO_UNCHANGED }, { LIT (0x5.a278886f2355ba68p+48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0x3.4441a72f2e5d5068p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d5068p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d5068p+56), ERRNO_UNCHANGED }, { LIT (0x3.4441a72f2e5d506cp+56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.c5c4p+12", LIT (0x2.c5c4p+12), { LIT (0xc.2c2b72bac3ba40cp+16380), ERRNO_UNCHANGED }, { LIT (0xc.2c2b72bac3ba40dp+16380), ERRNO_UNCHANGED }, { LIT (0xc.2c2b72bac3ba40cp+16380), ERRNO_UNCHANGED }, { LIT (0xc.2c2b72bac3ba40dp+16380), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x6.63992e35376b7308p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b731p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b7308p+0), ERRNO_UNCHANGED }, { LIT (0x6.63992e35376b731p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2.0000000000000004p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0x1.19103e4080b45664p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45664p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45664p+72), ERRNO_UNCHANGED }, { LIT (0x1.19103e4080b45666p+72), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.735f48p-4", LIT (0x3.735f48p-4), { LIT (0x3.d9dceda6a6b41354p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41354p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41354p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dceda6a6b41358p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.735f497c4e674p-4", LIT (0x3.735f497c4e674p-4), { LIT (0x3.d9dcef7e7e39645cp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39646p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39645cp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e39646p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.735f497c4e67535cp-4", LIT (0x3.735f497c4e67535cp-4), { LIT (0x3.d9dcef7e7e397c64p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c64p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c64p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e397c68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.735f497c4e676p-4", LIT (0x3.735f497c4e676p-4), { LIT (0x3.d9dcef7e7e398c1p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c14p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c1p-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcef7e7e398c14p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.735f4cp-4", LIT (0x3.735f4cp-4), { LIT (0x3.d9dcf29d1df01bccp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bdp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bccp-4), ERRNO_UNCHANGED }, { LIT (0x3.d9dcf29d1df01bdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.cp+4", LIT (0x3.cp+4), { LIT (0x5.e76f27714f199248p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19925p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f199248p+84), ERRNO_UNCHANGED }, { LIT (0x5.e76f27714f19925p+84), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.315e5bf6fb105f2cp+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2ep+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2cp+4), ERRNO_UNCHANGED }, { LIT (0x1.315e5bf6fb105f2ep+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.0000000000000028p-16384", LIT (0x4.0000000000000028p-16384), { LIT (0x4.0000000000000028p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000028p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000028p-16384), ERRNO_UNCHANGED }, { LIT (0x4.000000000000003p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.6p+4", LIT (0x4.6p+4), { LIT (0x1.fbfd219c43b0473p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b0473p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b0473p+100), ERRNO_UNCHANGED }, { LIT (0x1.fbfd219c43b04732p+100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.857de8p+4", LIT (0x4.857de8p+4), { LIT (0x1.4aaa8e05bcf71096p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71098p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71096p+104), ERRNO_UNCHANGED }, { LIT (0x1.4aaa8e05bcf71098p+104), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x3.599205c4e74b0cfp+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cfp+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cfp+4), ERRNO_UNCHANGED }, { LIT (0x3.599205c4e74b0cf4p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x4.00800aab555dde38p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde38p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde38p-12), ERRNO_UNCHANGED }, { LIT (0x4.00800aab555dde4p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0x4p-16384), ERRNO_UNCHANGED }, { LIT (0x4p-16384), ERRNO_UNCHANGED }, { LIT (0x4p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448", LIT (0x4p-16448), { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-4", LIT (0x4p-4), { LIT (0x4.8b5e3c3e8186676p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81866768p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e8186676p-4), ERRNO_UNCHANGED }, { LIT (0x4.8b5e3c3e81866768p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x4.0000000000008p-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008p-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008p-52), ERRNO_UNCHANGED }, { LIT (0x4.0000000000008008p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.ap+4", LIT (0x5.ap+4), { LIT (0x3.96211ff7d82c792cp+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c793p+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c792cp+128), ERRNO_UNCHANGED }, { LIT (0x3.96211ff7d82c793p+128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.dfeb68p-4", LIT (0x5.dfeb68p-4), { LIT (0x7.19267f117e20e3b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.19267f117e20e3cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.fb8dc64e91a74p-4", LIT (0x5.fb8dc64e91a74p-4), { LIT (0x7.412dde3318f344b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344cp-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dde3318f344cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.fb8dc8p-4", LIT (0x5.fb8dc8p-4), { LIT (0x7.412de0a90d3dcc38p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc38p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc38p-4), ERRNO_UNCHANGED }, { LIT (0x7.412de0a90d3dcc4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.fb8dcp-4", LIT (0x5.fb8dcp-4), { LIT (0x7.412dd50876505fd8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fd8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fd8p-4), ERRNO_UNCHANGED }, { LIT (0x7.412dd50876505fep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x9.369c4cb819c78fbp+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fbp+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fbp+4), ERRNO_UNCHANGED }, { LIT (0x9.369c4cb819c78fcp+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5p+4", LIT (0x5p+4), { LIT (0xa.abbcdcc279f59e4p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e4p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e4p+112), ERRNO_UNCHANGED }, { LIT (0xa.abbcdcc279f59e5p+112), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.1b4d318238d48p-4", LIT (0x6.1b4d318238d48p-4), { LIT (0x7.6f8042a9af77fc1p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc1p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc1p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af77fc18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.1b4d318238d4a2a8p-4", LIT (0x6.1b4d318238d4a2a8p-4), { LIT (0x7.6f8042a9af782edp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782ed8p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782edp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af782ed8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.1b4d318238d4cp-4", LIT (0x6.1b4d318238d4cp-4), { LIT (0x7.6f8042a9af7859c8p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859dp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859c8p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f8042a9af7859dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.1b4d38p-4", LIT (0x6.1b4d38p-4), { LIT (0x7.6f804c2bba6774ap-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774ap-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804c2bba6774a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.1b4d3p-4", LIT (0x6.1b4d3p-4), { LIT (0x7.6f804073fa444cbp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cb8p-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cbp-4), ERRNO_UNCHANGED }, { LIT (0x7.6f804073fa444cb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.289a78p-4", LIT (0x6.289a78p-4), { LIT (0x7.8304264e39d2cff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2dp-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2cff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.8304264e39d2dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x1.3494a9b171bf4accp+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4accp+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4accp+144), ERRNO_UNCHANGED }, { LIT (0x1.3494a9b171bf4acep+144), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.660247486aed8p-4", LIT (0x6.660247486aed8p-4), { LIT (0x7.ddee37ace0525dep-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525dep-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525dep-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee37ace0525de8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.660248p-4", LIT (0x6.660248p-4), { LIT (0x7.ddee38beb90553dp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553dp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553dp-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee38beb90553d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.66024p-4", LIT (0x6.66024p-4), { LIT (0x7.ddee2ccfc1ebf03p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf03p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf03p-4), ERRNO_UNCHANGED }, { LIT (0x7.ddee2ccfc1ebf038p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.fp+4", LIT (0x7.fp+4), { LIT (0x9.552183749160e8bp+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8bp+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8bp+180), ERRNO_UNCHANGED }, { LIT (0x9.552183749160e8cp+180), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0xcp-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-32", LIT (0x8p-32), { LIT (0x8.000000200000005p-32), ERRNO_UNCHANGED }, { LIT (0x8.000000200000005p-32), ERRNO_UNCHANGED }, { LIT (0x8.000000200000005p-32), ERRNO_UNCHANGED }, { LIT (0x8.000000200000006p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xap+0", LIT (0xap+0), { LIT (0x5.609773e54157e7cp+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7cp+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7cp+12), ERRNO_UNCHANGED }, { LIT (0x5.609773e54157e7c8p+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x1.1df3b68cfb9ef7a8p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7aap+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7a8p+0), ERRNO_UNCHANGED }, { LIT (0x1.1df3b68cfb9ef7aap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.4152ac57cd1e8p-60", LIT (0xe.4152ac57cd1e8p-60), { LIT (0xe.4152ac57cd1e865p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e866p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e865p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1e866p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.4152ac57cd1ea7ap-60", LIT (0xe.4152ac57cd1ea7ap-60), { LIT (0xe.4152ac57cd1eadfp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eaep-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eadfp-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1eaep-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.4152ac57cd1fp-60", LIT (0xe.4152ac57cd1fp-60), { LIT (0xe.4152ac57cd1f065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f066p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152ac57cd1f066p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.4152ap-60", LIT (0xe.4152ap-60), { LIT (0xe.4152a0000000065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a0000000066p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a0000000065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152a0000000066p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.4152bp-60", LIT (0xe.4152bp-60), { LIT (0xe.4152b0000000065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b0000000066p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b0000000065p-60), ERRNO_UNCHANGED }, { LIT (0xe.4152b0000000066p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0xf.fffffffffffffffp+16380), NON_FINITE|OVERFLOW_EXCEPTION }, { plus_infty, NON_FINITE|OVERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_m68k96)
    { "0xfp+0", LIT (0xfp+0), { LIT (0x3.1e1985f5a550ddep+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550dde4p+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550ddep+20), ERRNO_UNCHANGED }, { LIT (0x3.1e1985f5a550dde4p+20), ERRNO_UNCHANGED } },
#endif
  };

static void
expm1_test (void)
{
  ALL_RM_TEST (expm1, 0, expm1_test_data, RUN_TEST_LOOP_f_f, END);
}

static void
do_test (void)
{
  expm1_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */
