/* Test cos.
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

static const struct test_f_f_data cos_test_data[] =
  {
    { "inf", plus_infty, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM } },
    { "-inf", minus_infty, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, NON_FINITE|INVALID_EXCEPTION|ERRNO_EDOM } },
    { "qNaN", qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN", -qnan_value, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NON_FINITE|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN", snan_value, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION } },
    { "-sNaN", -snan_value, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, NON_FINITE|TEST_SNAN|INVALID_EXCEPTION } },

#if (TEST_COND_binary128)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (0x8.7e0ea4db2f488671c85df720896p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f488671c85df7208968p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f488671c85df720896p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f488671c85df7208968p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fc00ece4f02f278ade6ad9e89p+0", LIT (-0x1.921fc00ece4f02f278ade6ad9e89p+0), { LIT (-0xa.ca8b7d7e881db0d49193e9ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e9ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e9ab43b8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e9ab43b8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fc00ece4f02f278ade6ad9e8ap+0", LIT (-0x1.921fc00ece4f02f278ade6ad9e8ap+0), { LIT (-0xa.ca8b7d7e881db0d49193eaab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193eaab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193eaab43b8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193eaab43b8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fc00ece4f02f278ade6ad9e8p+0", LIT (-0x1.921fc00ece4f02f278ade6ad9e8p+0), { LIT (-0xa.ca8b7d7e881db0d49193e0ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab43b8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab43b8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fc00ece4f02f278ade6ad9fp+0", LIT (-0x1.921fc00ece4f02f278ade6ad9fp+0), { LIT (-0xa.ca8b7d7e881db0d4919460ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab43b8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab43b8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fc00ece4f02f2p+0", LIT (-0x1.921fc00ece4f02f2p+0), { LIT (-0xa.ca8b7d7e87a502ede3f57c1dce18p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1dce1p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1dce1p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1dce1p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fc00ece4f02f4p+0", LIT (-0x1.921fc00ece4f02f4p+0), { LIT (-0xa.ca8b7d7e89a502ede3f507aaa7d8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa7d8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa7dp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa7dp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fc00ece4f1p+0", LIT (-0x1.921fc00ece4f1p+0), { LIT (-0xa.ca8b7d8b95a502ede0fd607f3948p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f394p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f394p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f394p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fc00ece4fp+0", LIT (-0x1.921fc00ece4fp+0), { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11c3p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11c28p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11c28p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11c28p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fc2p+0", LIT (-0x1.921fc2p+0), { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460a12p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460a12p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460a118p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460a118p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fcp+0", LIT (-0x1.921fcp+0), { LIT (-0xa.bbbd2e7b95a85c638e746a5f4f68p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f4f6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f4f6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f4f6p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xf.fb701e22987fbe68852ee2bc897p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc897p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc897p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc8978p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { LIT (-0x1.febbf9949ecc133623bb8c8c5a28p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc133623bb8c8c5a27p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc133623bb8c8c5a27p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc133623bb8c8c5a27p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16448", LIT (-0x4p-16448), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16496", LIT (-0x4p-16496), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0xf.fff31767d5ba9e038d934070f138p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070f138p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070f13p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070f13p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { LIT (-0x5.b773d971a848e75c230605526978p-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c230605526978p-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c230605526974p-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c230605526974p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffffffffffffff8p+16380", LIT (-0xf.fffffffffffffffffffffffffff8p+16380), { LIT (-0x4.e6dc95fb529bc365f472e4fbc1f8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.e6dc95fb529bc365f472e4fbc1f8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.e6dc95fb529bc365f472e4fbc1f4p-4), ERRNO_UNCHANGED }, { LIT (-0x4.e6dc95fb529bc365f472e4fbc1f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0x2.002ef4018753d50b7a7f6bc3f5bap-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d50b7a7f6bc3f5bap-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d50b7a7f6bc3f5b8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d50b7a7f6bc3f5b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fb2f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.000000cf4a2a2p+0", LIT (0x1.000000cf4a2a2p+0), { LIT (0x8.a513fcf3a90ec00000037aea619p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ec00000037aea619p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ec00000037aea619p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ec00000037aea6198p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0000010b239a9p+0", LIT (0x1.0000010b239a9p+0), { LIT (0x8.a513f9cde04e4000000314b550fp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e4000000314b550f8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e4000000314b550fp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e4000000314b550f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.00000162a932bp+0", LIT (0x1.00000162a932bp+0), { LIT (0x8.a513f53385c5c0000002a6dfa3ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5c0000002a6dfa3ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5c0000002a6dfa3ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5c0000002a6dfa3e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.000002d452a1p+0", LIT (0x1.000002d452a1p+0), { LIT (0x8.a513e1c29116c0000003f8dd14b8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116c0000003f8dd14cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116c0000003f8dd14b8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116c0000003f8dd14cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x8.a513eced2ea575e738a147c82bd8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575e738a147c82bd8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575e738a147c82bd8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575e738a147c82bep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.000004p+0", LIT (0x1.000004p+0), { LIT (0x8.a513d1ffd9e28e629926fb8f7fb8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e629926fb8f7fcp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e629926fb8f7fb8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e629926fb8f7fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.000005bc7d86dp+0", LIT (0x1.000005bc7d86dp+0), { LIT (0x8.a513ba9f703d3ffffffcb9235418p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d3ffffffcb9235418p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d3ffffffcb9235418p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d3ffffffcb923542p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.000006p+0", LIT (0x1.000006p+0), { LIT (0x8.a513b71284fd128eb1ad47d820d8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd128eb1ad47d820ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd128eb1ad47d820d8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd128eb1ad47d820ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { LIT (0x8.000014f038b1ab0e902f68119158p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1ab0e902f6811916p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1ab0e902f68119158p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1ab0e902f6811916p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d73658465bb32e0f567ap+0", LIT (0x1.0c152382d73658465bb32e0f567ap+0), { LIT (0x8.0000000000000000000000000008p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000000000000000001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d73658465bb32e0f567bp+0", LIT (0x1.0c152382d73658465bb32e0f567bp+0), { LIT (0x7.fffffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d73658465bb32e0f568p+0", LIT (0x1.0c152382d73658465bb32e0f568p+0), { LIT (0x7.ffffffffffffffffffffffffffb8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffffffffffffffb8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffffffffffffffb8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffffffffffffffbcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d73658465bb32e0f56p+0", LIT (0x1.0c152382d73658465bb32e0f56p+0), { LIT (0x8.00000000000000000000000006ap-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000006a8p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000006ap-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000006a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d7365846p+0", LIT (0x1.0c152382d7365846p+0), { LIT (0x8.0000000000000004f6a1a27d7e4p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000004f6a1a27d7e48p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000004f6a1a27d7e4p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000004f6a1a27d7e48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d7365848p+0", LIT (0x1.0c152382d7365848p+0), { LIT (0x7.ffffffffffffffe94026ba253198p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffe94026ba25319cp-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffe94026ba253198p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffe94026ba25319cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d7365p+0", LIT (0x1.0c152382d7365p+0), { LIT (0x8.00000000000072a8d510c7c2a248p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072a8d510c7c2a25p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072a8d510c7c2a248p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072a8d510c7c2a25p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d7366p+0", LIT (0x1.0c152382d7366p+0), { LIT (0x7.ffffffffffff94f4fdce055d4ed4p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94f4fdce055d4ed4p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94f4fdce055d4ed4p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94f4fdce055d4ed8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { LIT (0x7.fffff939bdd18035537d20fef1bp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18035537d20fef1b4p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18035537d20fef1bp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18035537d20fef1b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.200144p+32", LIT (0x1.200144p+32), { LIT (0xf.bc96ca2c658abf5ace7b886a8fbp-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf5ace7b886a8fbp-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf5ace7b886a8fbp-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf5ace7b886a8fb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.200145a975ce6p+32", LIT (0x1.200145a975ce6p+32), { LIT (-0x6.568e7ed3dffcdfe227fd726840e8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfe227fd726840e4p-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfe227fd726840e4p-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfe227fd726840e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (-0xf.74fbd5498fe4c0c71bd9e4ef59e8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0c71bd9e4ef59e8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0c71bd9e4ef59ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0c71bd9e4ef59ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xd.a82832da19f9891d9762fa659ff8p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9891d9762fa659ff8p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9891d9762fa659ff8p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9891d9762fa65ap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { LIT (0xd.a82683a33cbebfffffffa2966878p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbebfffffffa2966878p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbebfffffffa2966878p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbebfffffffa296688p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xd.a8263394be6d0e58c1c35a8a3bap-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e58c1c35a8a3bap-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e58c1c35a8a3bap-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e58c1c35a8a3ba8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0x1.4442d18469893610281a0f9b0e8dp-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469893610281a0f9b0e8dp-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469893610281a0f9b0e8dp-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469893610281a0f9b0e8ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { LIT (0x1.898cc51701b839a252049c1114cfp-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a252049c1114dp-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a252049c1114cfp-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a252049c1114dp-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc517018p+0", LIT (0x1.921fb54442d18469898cc517018p+0), { LIT (0x3.839a252049c1114cf98e804177d4p-108), ERRNO_UNCHANGED }, { LIT (0x3.839a252049c1114cf98e804177d4p-108), ERRNO_UNCHANGED }, { LIT (0x3.839a252049c1114cf98e804177d4p-108), ERRNO_UNCHANGED }, { LIT (0x3.839a252049c1114cf98e804177d6p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc51701b8p+0", LIT (0x1.921fb54442d18469898cc51701b8p+0), { LIT (0x3.9a252049c1114cf98e804177d4c6p-116), ERRNO_UNCHANGED }, { LIT (0x3.9a252049c1114cf98e804177d4c8p-116), ERRNO_UNCHANGED }, { LIT (0x3.9a252049c1114cf98e804177d4c6p-116), ERRNO_UNCHANGED }, { LIT (0x3.9a252049c1114cf98e804177d4c8p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc51701b9p+0", LIT (0x1.921fb54442d18469898cc51701b9p+0), { LIT (-0xc.65dadfb63eeeb306717fbe882b4p-116), ERRNO_UNCHANGED }, { LIT (-0xc.65dadfb63eeeb306717fbe882b38p-116), ERRNO_UNCHANGED }, { LIT (-0xc.65dadfb63eeeb306717fbe882b38p-116), ERRNO_UNCHANGED }, { LIT (-0xc.65dadfb63eeeb306717fbe882b38p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc51702p+0", LIT (0x1.921fb54442d18469898cc51702p+0), { LIT (-0x4.7c65dadfb63eeeb306717fbe882cp-108), ERRNO_UNCHANGED }, { LIT (-0x4.7c65dadfb63eeeb306717fbe882cp-108), ERRNO_UNCHANGED }, { LIT (-0x4.7c65dadfb63eeeb306717fbe8828p-108), ERRNO_UNCHANGED }, { LIT (-0x4.7c65dadfb63eeeb306717fbe8828p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { LIT (-0x7.6733ae8fe47c65dadfb63eeeb308p-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65dadfb63eeeb308p-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65dadfb63eeeb304p-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65dadfb63eeeb304p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { LIT (0x4.69898cc51701b839a252049c1104p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b839a252049c1108p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b839a252049c1104p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b839a252049c1108p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { LIT (-0xb.9676733ae8fe47c65dadfb63ede8p-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47c65dadfb63ede8p-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47c65dadfb63edep-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47c65dadfb63edep-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (-0xb.bbd2e7b96766266f1d18f3ead018p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766266f1d18f3ead01p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766266f1d18f3ead01p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766266f1d18f3ead01p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fc00ece4f02f278ade6ad9e89p+0", LIT (0x1.921fc00ece4f02f278ade6ad9e89p+0), { LIT (-0xa.ca8b7d7e881db0d49193e9ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e9ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e9ab43b8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e9ab43b8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fc00ece4f02f278ade6ad9e8ap+0", LIT (0x1.921fc00ece4f02f278ade6ad9e8ap+0), { LIT (-0xa.ca8b7d7e881db0d49193eaab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193eaab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193eaab43b8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193eaab43b8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fc00ece4f02f278ade6ad9e8p+0", LIT (0x1.921fc00ece4f02f278ade6ad9e8p+0), { LIT (-0xa.ca8b7d7e881db0d49193e0ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab43b8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab43b8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fc00ece4f02f278ade6ad9fp+0", LIT (0x1.921fc00ece4f02f278ade6ad9fp+0), { LIT (-0xa.ca8b7d7e881db0d4919460ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab43cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab43b8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab43b8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fc00ece4f02f2p+0", LIT (0x1.921fc00ece4f02f2p+0), { LIT (-0xa.ca8b7d7e87a502ede3f57c1dce18p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1dce1p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1dce1p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1dce1p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fc00ece4f02f4p+0", LIT (0x1.921fc00ece4f02f4p+0), { LIT (-0xa.ca8b7d7e89a502ede3f507aaa7d8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa7d8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa7dp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa7dp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fc00ece4f1p+0", LIT (0x1.921fc00ece4f1p+0), { LIT (-0xa.ca8b7d8b95a502ede0fd607f3948p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f394p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f394p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f394p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fc00ece4fp+0", LIT (0x1.921fc00ece4fp+0), { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11c3p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11c28p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11c28p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11c28p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fc2p+0", LIT (0x1.921fc2p+0), { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460a12p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460a12p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460a118p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460a118p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fcp+0", LIT (0x1.921fcp+0), { LIT (-0xa.bbbd2e7b95a85c638e746a5f4f68p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f4f6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f4f6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f4f6p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x8.a51407da8345c91c2466d9768718p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c91c2466d9768718p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c91c2466d9768718p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c91c2466d976872p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+120", LIT (0x1p+120), { LIT (-0xe.d06685b36c66c4cf35c11f6519p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4cf35c11f6519p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4cf35c11f6518f8p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4cf35c11f6518f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0x2.a62ba8824e5bcb065f5f3b8e4f58p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb065f5f3b8e4f58p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb065f5f3b8e4f56p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb065f5f3b8e4f56p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffffff80000000000aaaaaaa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff80000000000aaaaaaa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff80000000000aaaaaaa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff80000000000aaaaaabp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffff800000008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.182a44p+0", LIT (0x2.182a44p+0), { LIT (-0x7.ffffd61f8e65dc9a1c1408dd99b4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc9a1c1408dd99bp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc9a1c1408dd99bp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc9a1c1408dd99bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.182a4705ae6cap+0", LIT (0x2.182a4705ae6cap+0), { LIT (-0x7.ffffffffffff1aae55de707ab4f8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1aae55de707ab4f4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1aae55de707ab4f4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1aae55de707ab4f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.182a4705ae6cb08cb7665c1eacf4p+0", LIT (0x2.182a4705ae6cb08cb7665c1eacf4p+0), { LIT (-0x7.ffffffffffffffffffffffffffecp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffffffffffffffffe8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffffffffffffffffe8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffffffffffffffffe8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.182a4705ae6cb08cb7665c1eacf6p+0", LIT (0x2.182a4705ae6cb08cb7665c1eacf6p+0), { LIT (-0x8.0000000000000000000000000008p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000000000000000000008p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.182a4705ae6cb08cb7665c1eacp+0", LIT (0x2.182a4705ae6cb08cb7665c1eacp+0), { LIT (-0x7.fffffffffffffffffffffffff2b8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffff2b4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffff2b4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffff2b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.182a4705ae6cb08cb7665c1eadp+0", LIT (0x2.182a4705ae6cb08cb7665c1eadp+0), { LIT (-0x8.000000000000000000000000009p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000000000000000009p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000000000000000000088p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000000000000000000088p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.182a4705ae6cb08cp+0", LIT (0x2.182a4705ae6cb08cp+0), { LIT (-0x7.fffffffffffffff612bcbb050378p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff612bcbb050374p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff612bcbb050374p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff612bcbb050374p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.182a4705ae6cb09p+0", LIT (0x2.182a4705ae6cb09p+0), { LIT (-0x8.000000000000002d7fb28bb59cdp-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000002d7fb28bb59cc8p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000002d7fb28bb59cc8p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000002d7fb28bb59cc8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.182a4705ae6ccp+0", LIT (0x2.182a4705ae6ccp+0), { LIT (-0x8.000000000000d6160463f5455ccp-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d6160463f5455ccp-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d6160463f5455cb8p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d6160463f5455cb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.182a48p+0", LIT (0x2.182a48p+0), { LIT (-0x8.00000d8c84574300c524d804275p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c84574300c524d8042748p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c84574300c524d8042748p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c84574300c524d8042748p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { LIT (0x8.5f167780e479c9a5c86ffce76148p-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9a5c86ffce7615p-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9a5c86ffce76148p-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9a5c86ffce7615p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (0xf.431dd7a36cf37de5c74544f6b438p-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37de5c74544f6b438p-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37de5c74544f6b438p-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37de5c74544f6b44p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (0xa.dd6f6bacd20654c1404f52cde16p-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654c1404f52cde16p-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654c1404f52cde16p-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654c1404f52cde168p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+0", LIT (0x2p+0), { LIT (-0x6.a88995d4dc81290ccbe2b2edcac4p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc81290ccbe2b2edcac4p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc81290ccbe2b2edcacp-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc81290ccbe2b2edcacp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+64", LIT (0x2p+64), { LIT (0xf.fb701e22987fbe68852ee2bc897p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc897p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc897p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc8978p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffffffe00000000aaaaaaaa93e9p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe00000000aaaaaaaa93e9p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe00000000aaaaaaaa93e9p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe00000000aaaaaaaa93e98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.ffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffe00000000008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.ffffffffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffffe8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (-0xf.dfe6f2169e24f276e8027d91ba9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f276e8027d91ba9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f276e8027d91ba88p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f276e8027d91ba88p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3p+0", LIT (0x3p+0), { LIT (-0xf.d7025f42f2e9307dff82fdf6a708p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9307dff82fdf6a708p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9307dff82fdf6a7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9307dff82fdf6a7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0xf.dfe902135fc1c18492e869a3f8bp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18492e869a3f8a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18492e869a3f8a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18492e869a3f8a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xa.7553036d926062336d0e16e3dd58p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d926062336d0e16e3dd5p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d926062336d0e16e3dd5p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d926062336d0e16e3dd5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p+48", LIT (0x4p+48), { LIT (0xd.e3b88804f00552d6baba709471d8p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552d6baba709471d8p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552d6baba709471d8p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552d6baba709471ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.ffff800000aaaaaa4fa4fa69a698p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaaaa4fa4fa69a698p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaaaa4fa4fa69a698p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaaaa4fa4fa69a6ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448", LIT (0x4p-16448), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496", LIT (0x4p-16496), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff80000000000008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.ffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffff8008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x4.89e15c1ad2b654f99f75a35ee5f8p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b654f99f75a35ee5fcp-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b654f99f75a35ee5f8p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b654f99f75a35ee5fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.5cdb84bc117abd74f1e700074a9p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd74f1e700074a98p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd74f1e700074a9p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd74f1e700074a98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xc.0ffbcf6c900baafbd68c5a99d548p-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900baafbd68c5a99d55p-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900baafbd68c5a99d548p-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900baafbd68c5a99d55p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+0", LIT (0x8p+0), { LIT (-0x2.53f7d7ec65f271ec91f976afbdcep-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ec91f976afbdcep-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ec91f976afbdccp-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ec91f976afbdccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+1020", LIT (0x8p+1020), { LIT (-0xd.38cf9361195f50b10fac29dd9038p-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50b10fac29dd9038p-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50b10fac29dd903p-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50b10fac29dd903p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+124", LIT (0x8p+124), { LIT (0xc.82b8ec98b5e62fcf0b09fd10eb28p-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fcf0b09fd10eb3p-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fcf0b09fd10eb28p-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fcf0b09fd10eb3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+16380", LIT (0x8p+16380), { LIT (0xe.bcc2fc82ae39ebf8da5d687bf358p-4), ERRNO_UNCHANGED }, { LIT (0xe.bcc2fc82ae39ebf8da5d687bf36p-4), ERRNO_UNCHANGED }, { LIT (0xe.bcc2fc82ae39ebf8da5d687bf358p-4), ERRNO_UNCHANGED }, { LIT (0xe.bcc2fc82ae39ebf8da5d687bf36p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffffffffffe0000000000000aa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffe0000000000000aa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffe0000000000000aa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffe0000000000000abp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.fffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffe000008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.fe000aaa93e9589576da4ec9494p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9589576da4ec94948p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9589576da4ec9494p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9589576da4ec94948p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-972", LIT (0x8p-972), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x9p+0", LIT (0x9p+0), { LIT (-0xe.93fd53530cb5b8268bb2e8949abp-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b8268bb2e8949aa8p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b8268bb2e8949aa8p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b8268bb2e8949aa8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xa.217bap+12", LIT (0xa.217bap+12), { LIT (0x2.8f31660ce5e42c0544355e8e3d04p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c0544355e8e3d04p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c0544355e8e3d04p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c0544355e8e3d06p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xap+0", LIT (0xap+0), { LIT (-0xd.6cd64486358f904f7e2a0b9994e8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f904f7e2a0b9994e8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f904f7e2a0b9994ep-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f904f7e2a0b9994ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a663c8p-4", LIT (0xc.d4966d92d17082980965c1a663c8p-4), { LIT (0xb.201e79450884be22c53e47ed16d8p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed16d8p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed16d8p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed16ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a663cp-4", LIT (0xc.d4966d92d17082980965c1a663cp-4), { LIT (0xb.201e79450884be22c53e47ed16ep-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed16ep-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed16ep-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed16e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a664p-4", LIT (0xc.d4966d92d17082980965c1a664p-4), { LIT (0xb.201e79450884be22c53e47ed16bp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed16bp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed16bp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed16b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a66p-4", LIT (0xc.d4966d92d17082980965c1a66p-4), { LIT (0xb.201e79450884be22c53e47ed199p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed199p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed199p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed1998p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { LIT (0xb.201e79450884be288bda3ee0dd18p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be288bda3ee0dd18p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be288bda3ee0dd18p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be288bda3ee0dd2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { LIT (0xb.201e79450884be1d0c24406973ap-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be1d0c24406973ap-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be1d0c24406973ap-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be1d0c24406973a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { LIT (0xb.201e79450884c00000000000c17p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884c00000000000c178p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884c00000000000c17p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884c00000000000c178p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { LIT (0xb.201e794508846402500c44b4f8ep-4), ERRNO_UNCHANGED }, { LIT (0xb.201e794508846402500c44b4f8e8p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e794508846402500c44b4f8ep-4), ERRNO_UNCHANGED }, { LIT (0xb.201e794508846402500c44b4f8e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.201e83065041456a084c70f5a12p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041456a084c70f5a128p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041456a084c70f5a12p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041456a084c70f5a128p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.201e77869a46ae20ce545c5c67p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae20ce545c5c67p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae20ce545c5c67p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae20ce545c5c6708p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xb.b4ff632a908f73ec151839cb9d98p-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73ec151839cb9d98p-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73ec151839cb9d98p-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73ec151839cb9dap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { LIT (0x1.ff01000c9ae73630add558c936b4p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae73630add558c936b5p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae73630add558c936b4p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae73630add558c936b5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0xe.26f8af8333f9270e9c3e9f64f938p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9270e9c3e9f64f94p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9270e9c3e9f64f938p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9270e9c3e9f64f94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (-0xa.07bd3ab53ab9710f3445538de8fp-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab9710f3445538de8fp-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab9710f3445538de8e8p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab9710f3445538de8e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0xd.b7f5359babdb66be8d0cd3e293fp-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66be8d0cd3e293e8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66be8d0cd3e293e8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66be8d0cd3e293e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xf.fb2a030c5ae20bdfe29fda198eap-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bdfe29fda198eap-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bdfe29fda198eap-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bdfe29fda198ea8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (-0xf.fff31767d5ba9e038d934070f138p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070f138p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070f13p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070f13p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (-0x5.b773d971a848e75c230605526978p-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c230605526978p-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c230605526974p-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c230605526974p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffffffffffffff8p+16380", LIT (0xf.fffffffffffffffffffffffffff8p+16380), { LIT (-0x4.e6dc95fb529bc365f472e4fbc1f8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.e6dc95fb529bc365f472e4fbc1f8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.e6dc95fb529bc365f472e4fbc1f4p-4), ERRNO_UNCHANGED }, { LIT (-0x4.e6dc95fb529bc365f472e4fbc1f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (-0x2.002ef4018753d50b7a7f6bc3f5bap-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d50b7a7f6bc3f5bap-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d50b7a7f6bc3f5b8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d50b7a7f6bc3f5b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fb2f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (0x8.7e0eap-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0eap-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0eap-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ebp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.921fc2p+0", LIT (-0x1.921fc2p+0), { LIT (-0xc.bbbd3p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd3p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.921fcp+0", LIT (-0x1.921fcp+0), { LIT (-0xa.bbbd3p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd3p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xf.fb701p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb702p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb702p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0xd.a5f96p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f96p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f96p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f97p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x8.a513ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.000004p+0", LIT (0x1.000004p+0), { LIT (0x8.a513dp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513dp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513dp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.000006p+0", LIT (0x1.000006p+0), { LIT (0x8.a513bp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513bp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513bp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { LIT (0x8.00001p-4), ERRNO_UNCHANGED }, { LIT (0x8.00001p-4), ERRNO_UNCHANGED }, { LIT (0x8.00001p-4), ERRNO_UNCHANGED }, { LIT (0x8.00002p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { LIT (0x7.fffff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.200144p+32", LIT (0x1.200144p+32), { LIT (0xf.bc96cp-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96dp-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96cp-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (-0xf.74fbep-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xd.a8283p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8283p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8283p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8284p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xd.a8263p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8264p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0x1.4442dp-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d2p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442dp-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d2p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (-0xb.bbd2fp-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2ep-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2ep-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2ep-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.921fc2p+0", LIT (0x1.921fc2p+0), { LIT (-0xc.bbbd3p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd3p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.921fcp+0", LIT (0x1.921fcp+0), { LIT (-0xa.bbbd3p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd3p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x8.a514p-4), ERRNO_UNCHANGED }, { LIT (0x8.a514p-4), ERRNO_UNCHANGED }, { LIT (0x8.a514p-4), ERRNO_UNCHANGED }, { LIT (0x8.a5141p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+120", LIT (0x1p+120), { LIT (-0xe.d0669p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d0668p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d0668p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d0668p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0x2.a62bacp-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.182a44p+0", LIT (0x2.182a44p+0), { LIT (-0x7.ffffd8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffdp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.182a48p+0", LIT (0x2.182a48p+0), { LIT (-0x8.00001p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00001p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (0xf.431ddp-4), ERRNO_UNCHANGED }, { LIT (0xf.431ddp-4), ERRNO_UNCHANGED }, { LIT (0xf.431ddp-4), ERRNO_UNCHANGED }, { LIT (0xf.431dep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (0xa.dd6f6p-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f7p-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6p-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+0", LIT (0x2p+0), { LIT (-0x6.a88998p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88998p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a8899p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a8899p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+64", LIT (0x2p+64), { LIT (0xf.fb701p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb702p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb702p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (-0xf.dfe7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3p+0", LIT (0x3p+0), { LIT (-0xf.d7026p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7026p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0xf.dfe91p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xa.75531p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p+48", LIT (0x4p+48), { LIT (0xd.e3b88p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b89p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b89p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.ffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x4.89e158p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e16p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e158p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e16p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.5cdb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xc.0ffbcp-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbdp-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcp-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p+0", LIT (0x8p+0), { LIT (-0x2.53f7d8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d4p-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p+124", LIT (0x8p+124), { LIT (0xc.82b8ep-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8fp-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ep-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.fep-4), ERRNO_UNCHANGED }, { LIT (0xf.fe001p-4), ERRNO_UNCHANGED }, { LIT (0xf.fep-4), ERRNO_UNCHANGED }, { LIT (0xf.fe001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x9p+0", LIT (0x9p+0), { LIT (-0xe.93fd6p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd5p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd5p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xa.217bap+12", LIT (0xa.217bap+12), { LIT (0x2.8f3164p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f3168p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f3164p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f3168p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xap+0", LIT (0xap+0), { LIT (-0xd.6cd65p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.201e8p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e8p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e8p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.201e7p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e7p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e7p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xb.b4ff6p-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff6p-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff6p-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0xe.26f8ap-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8bp-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8ap-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (-0xa.07bd4p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd4p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0xd.b7f54p-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f53p-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f53p-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f53p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xf.fb2ap-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2ap-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2ap-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xd.a5f96p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f96p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f96p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f97p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (0x8.7e0ea4db2f488p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f488p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f488p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f49p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.921fc00ece4f1p+0", LIT (-0x1.921fc00ece4f1p+0), { LIT (-0xa.ca8b7d8b95a58p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a5p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.921fc00ece4fp+0", LIT (-0x1.921fc00ece4fp+0), { LIT (-0xa.ca8b7d7b95a58p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a5p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.921fc2p+0", LIT (-0x1.921fc2p+0), { LIT (-0xc.bbbd2e7b951e8p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e8p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951ep-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.921fcp+0", LIT (-0x1.921fcp+0), { LIT (-0xa.bbbd2e7b95a88p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a88p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xf.fb701e22987f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22988p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { LIT (-0x1.febbf9949ecc2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc1p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc1p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0xf.fff31767d5bbp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0xd.a5f963cdefe68p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe7p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe68p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.000000cf4a2a2p+0", LIT (0x1.000000cf4a2a2p+0), { LIT (0x8.a513fcf3a90e8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90fp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90e8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0000010b239a9p+0", LIT (0x1.0000010b239a9p+0), { LIT (0x8.a513f9cde04ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.00000162a932bp+0", LIT (0x1.00000162a932bp+0), { LIT (0x8.a513f53385c58p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c6p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c58p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.000002d452a1p+0", LIT (0x1.000002d452a1p+0), { LIT (0x8.a513e1c291168p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29117p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c291168p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29117p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x8.a513eced2ea5p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea58p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea5p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.000004p+0", LIT (0x1.000004p+0), { LIT (0x8.a513d1ffd9e28p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.000005bc7d86dp+0", LIT (0x1.000005bc7d86dp+0), { LIT (0x8.a513ba9f703dp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703dp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703dp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.000006p+0", LIT (0x1.000006p+0), { LIT (0x8.a513b71284fdp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fdp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fdp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { LIT (0x8.000014f038b18p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b18p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b18p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0c152382d7365p+0", LIT (0x1.0c152382d7365p+0), { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000008p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0c152382d7366p+0", LIT (0x1.0c152382d7366p+0), { LIT (0x7.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { LIT (0x7.fffff939bdd18p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd1cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.200144p+32", LIT (0x1.200144p+32), { LIT (0xf.bc96ca2c658a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.200145a975ce6p+32", LIT (0x1.200145a975ce6p+32), { LIT (-0x6.568e7ed3dffdp-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffccp-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffccp-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (-0xf.74fbd5498fe5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe48p-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xd.a82832da19f98p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f98p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f98p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19fap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { LIT (0xd.a82683a33cbe8p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbe8p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbe8p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbfp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xd.a8263394be6dp-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6dp-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6dp-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0x1.4442d18469893p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469893p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469893p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469894p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { LIT (0x4.69898cc517018p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701cp-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc517018p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701cp-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { LIT (-0xb.9676733ae8fe8p-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe8p-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fep-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fep-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (-0xb.bbd2e7b967668p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fc00ece4f1p+0", LIT (0x1.921fc00ece4f1p+0), { LIT (-0xa.ca8b7d8b95a58p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a5p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fc00ece4fp+0", LIT (0x1.921fc00ece4fp+0), { LIT (-0xa.ca8b7d7b95a58p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a5p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fc2p+0", LIT (0x1.921fc2p+0), { LIT (-0xc.bbbd2e7b951e8p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e8p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951ep-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fcp+0", LIT (0x1.921fcp+0), { LIT (-0xa.bbbd2e7b95a88p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a88p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x8.a51407da83458p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8346p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da83458p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8346p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+120", LIT (0x1p+120), { LIT (-0xe.d06685b36c67p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c67p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c668p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c668p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0x2.a62ba8824e5bep-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcp-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcp-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff8008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.182a44p+0", LIT (0x2.182a44p+0), { LIT (-0x7.ffffd61f8e66p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65cp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65cp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.182a4705ae6cap+0", LIT (0x2.182a4705ae6cap+0), { LIT (-0x7.ffffffffffff4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.182a4705ae6ccp+0", LIT (0x2.182a4705ae6ccp+0), { LIT (-0x8.000000000001p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000001p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000008p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.182a48p+0", LIT (0x2.182a48p+0), { LIT (-0x8.00000d8c84578p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c84578p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c8457p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c8457p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { LIT (0x8.5f167780e4798p-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e47ap-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e4798p-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e47ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (0xf.431dd7a36cf3p-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf38p-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf3p-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf38p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (0xa.dd6f6bacd206p-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd2068p-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd206p-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd2068p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+0", LIT (0x2p+0), { LIT (-0x6.a88995d4dc814p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc814p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc81p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc81p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+64", LIT (0x2p+64), { LIT (0xf.fb701e22987f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22988p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe000008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (-0xf.dfe6f2169e25p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e25p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e248p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e248p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3p+0", LIT (0x3p+0), { LIT (-0xf.d7025f42f2e98p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0xf.dfe902135fc2p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc2p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc18p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xa.7553036d92608p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d92608p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d926p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d926p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p+48", LIT (0x4p+48), { LIT (0xd.e3b88804f005p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f0058p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f005p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f0058p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.ffff800000aa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000abp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x4.89e15c1ad2b64p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b64p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b64p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.5cdb84bc117a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xc.0ffbcf6c900b8p-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900b8p-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900b8p-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+0", LIT (0x8p+0), { LIT (-0x2.53f7d7ec65f28p-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f28p-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f26p-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f26p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+1020", LIT (0x8p+1020), { LIT (-0xd.38cf9361195f8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195fp-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+124", LIT (0x8p+124), { LIT (0xc.82b8ec98b5e6p-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e6p-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e6p-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffe8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.fe000aaa93e9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e98p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-972", LIT (0x8p-972), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x9p+0", LIT (0x9p+0), { LIT (-0xe.93fd53530cb6p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb58p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb58p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xa.217bap+12", LIT (0xa.217bap+12), { LIT (0x2.8f31660ce5e42p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e44p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xap+0", LIT (0xap+0), { LIT (-0xd.6cd64486359p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { LIT (0xb.201e794508848p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450885p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e794508848p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450885p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { LIT (0xb.201e79450884p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e794508848p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e794508848p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.201e83065041p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e830650418p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e830650418p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.201e77869a468p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a468p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a468p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a47p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xb.b4ff632a908fp-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908fp-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { LIT (0x1.ff01000c9ae73p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae73p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae73p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae74p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0xe.26f8af8333f9p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (-0xa.07bd3ab53ab98p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab98p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab9p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0xd.b7f5359babdb8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdbp-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xf.fb2a030c5ae2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (-0xf.fff31767d5bbp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xd.a5f963cdefe68p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe7p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe68p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (0x8.7e0ea4db2f488671c85df72088p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f488671c85df72088p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f488671c85df72088p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f488671c85df7208cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fc00ece4f02f278ade6ad9e8p+0", LIT (-0x1.921fc00ece4f02f278ade6ad9e8p+0), { LIT (-0xa.ca8b7d7e881db0d49193e0ab44p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab44p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab4p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab4p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fc00ece4f02f278ade6ad9fp+0", LIT (-0x1.921fc00ece4f02f278ade6ad9fp+0), { LIT (-0xa.ca8b7d7e881db0d4919460ab44p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab44p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab4p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab4p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fc00ece4f02f2p+0", LIT (-0x1.921fc00ece4f02f2p+0), { LIT (-0xa.ca8b7d7e87a502ede3f57c1ddp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1ddp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1dccp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1dccp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fc00ece4f02f4p+0", LIT (-0x1.921fc00ece4f02f4p+0), { LIT (-0xa.ca8b7d7e89a502ede3f507aaa8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa4p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa4p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fc00ece4f1p+0", LIT (-0x1.921fc00ece4f1p+0), { LIT (-0xa.ca8b7d8b95a502ede0fd607f3cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f38p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f38p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f38p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fc00ece4fp+0", LIT (-0x1.921fc00ece4fp+0), { LIT (-0xa.ca8b7d7b95a502ede4a0f9b12p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11cp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fc2p+0", LIT (-0x1.921fc2p+0), { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460a4p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460ap-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460ap-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460ap-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fcp+0", LIT (-0x1.921fcp+0), { LIT (-0xa.bbbd2e7b95a85c638e746a5f5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f4cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f4cp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xf.fb701e22987fbe68852ee2bc88p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc88p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc88p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc8cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { LIT (-0x1.febbf9949ecc133623bb8c8c5a8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc133623bb8c8c5ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc133623bb8c8c5ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc133623bb8c8c5ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0xf.fff31767d5ba9e038d934070f4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { LIT (-0x5.b773d971a848e75c230605526ap-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c230605526ap-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c2306055268p-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c2306055268p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0xd.a5f963cdefe6d529f6b6009fbp-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fb4p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fbp-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fb4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.000000cf4a2a2p+0", LIT (0x1.000000cf4a2a2p+0), { LIT (0x8.a513fcf3a90ec00000037aea6p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ec00000037aea6p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ec00000037aea6p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ec00000037aea64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0000010b239a9p+0", LIT (0x1.0000010b239a9p+0), { LIT (0x8.a513f9cde04e4000000314b55p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e4000000314b55p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e4000000314b55p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e4000000314b554p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.00000162a932bp+0", LIT (0x1.00000162a932bp+0), { LIT (0x8.a513f53385c5c0000002a6dfap-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5c0000002a6dfa4p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5c0000002a6dfap-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5c0000002a6dfa4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.000002d452a1p+0", LIT (0x1.000002d452a1p+0), { LIT (0x8.a513e1c29116c0000003f8dd14p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116c0000003f8dd14p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116c0000003f8dd14p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116c0000003f8dd18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x8.a513eced2ea575e738a147c828p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575e738a147c82cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575e738a147c828p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575e738a147c82cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.000004p+0", LIT (0x1.000004p+0), { LIT (0x8.a513d1ffd9e28e629926fb8f7cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e629926fb8f8p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e629926fb8f7cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e629926fb8f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.000005bc7d86dp+0", LIT (0x1.000005bc7d86dp+0), { LIT (0x8.a513ba9f703d3ffffffcb92354p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d3ffffffcb92354p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d3ffffffcb92354p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d3ffffffcb92358p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.000006p+0", LIT (0x1.000006p+0), { LIT (0x8.a513b71284fd128eb1ad47d82p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd128eb1ad47d82p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd128eb1ad47d82p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd128eb1ad47d824p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { LIT (0x8.000014f038b1ab0e902f68119p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1ab0e902f68119p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1ab0e902f68119p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1ab0e902f681194p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d73658465bb32e0f568p+0", LIT (0x1.0c152382d73658465bb32e0f568p+0), { LIT (0x7.fffffffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d73658465bb32e0f56p+0", LIT (0x1.0c152382d73658465bb32e0f56p+0), { LIT (0x8.00000000000000000000000004p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000008p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000004p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d7365846p+0", LIT (0x1.0c152382d7365846p+0), { LIT (0x8.0000000000000004f6a1a27d7cp-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000004f6a1a27d8p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000004f6a1a27d7cp-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000004f6a1a27d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d7365848p+0", LIT (0x1.0c152382d7365848p+0), { LIT (0x7.ffffffffffffffe94026ba253p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffe94026ba2532p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffe94026ba253p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffe94026ba2532p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d7365p+0", LIT (0x1.0c152382d7365p+0), { LIT (0x8.00000000000072a8d510c7c2ap-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072a8d510c7c2a4p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072a8d510c7c2ap-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072a8d510c7c2a4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d7366p+0", LIT (0x1.0c152382d7366p+0), { LIT (0x7.ffffffffffff94f4fdce055d4ep-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94f4fdce055d4ep-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94f4fdce055d4ep-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94f4fdce055d5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { LIT (0x7.fffff939bdd18035537d20fefp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18035537d20fef2p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18035537d20fefp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18035537d20fef2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.200144p+32", LIT (0x1.200144p+32), { LIT (0xf.bc96ca2c658abf5ace7b886a8cp-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf5ace7b886a9p-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf5ace7b886a8cp-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf5ace7b886a9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.200145a975ce6p+32", LIT (0x1.200145a975ce6p+32), { LIT (-0x6.568e7ed3dffcdfe227fd726842p-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfe227fd72684p-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfe227fd72684p-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfe227fd72684p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (-0xf.74fbd5498fe4c0c71bd9e4ef5cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0c71bd9e4ef58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0c71bd9e4ef58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0c71bd9e4ef58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xd.a82832da19f9891d9762fa659cp-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9891d9762fa65ap-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9891d9762fa659cp-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9891d9762fa65ap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { LIT (0xd.a82683a33cbebfffffffa29668p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbebfffffffa29668p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbebfffffffa29668p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbebfffffffa2966cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xd.a8263394be6d0e58c1c35a8a38p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e58c1c35a8a3cp-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e58c1c35a8a38p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e58c1c35a8a3cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0x1.4442d18469893610281a0f9b0e8p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469893610281a0f9b0e8p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469893610281a0f9b0e8p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469893610281a0f9b0fp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { LIT (0x1.898cc51701b839a252049c11148p-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a252049c1115p-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a252049c11148p-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a252049c1115p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18469898cc517018p+0", LIT (0x1.921fb54442d18469898cc517018p+0), { LIT (0x3.839a252049c1114cf98e804177p-108), ERRNO_UNCHANGED }, { LIT (0x3.839a252049c1114cf98e804178p-108), ERRNO_UNCHANGED }, { LIT (0x3.839a252049c1114cf98e804177p-108), ERRNO_UNCHANGED }, { LIT (0x3.839a252049c1114cf98e804178p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18469898cc51702p+0", LIT (0x1.921fb54442d18469898cc51702p+0), { LIT (-0x4.7c65dadfb63eeeb306717fbe8ap-108), ERRNO_UNCHANGED }, { LIT (-0x4.7c65dadfb63eeeb306717fbe88p-108), ERRNO_UNCHANGED }, { LIT (-0x4.7c65dadfb63eeeb306717fbe88p-108), ERRNO_UNCHANGED }, { LIT (-0x4.7c65dadfb63eeeb306717fbe88p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { LIT (-0x7.6733ae8fe47c65dadfb63eeeb4p-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65dadfb63eeeb4p-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65dadfb63eeeb2p-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65dadfb63eeeb2p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { LIT (0x4.69898cc51701b839a252049c1p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b839a252049c12p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b839a252049c1p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b839a252049c12p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { LIT (-0xb.9676733ae8fe47c65dadfb63fp-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47c65dadfb63ecp-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47c65dadfb63ecp-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47c65dadfb63ecp-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (-0xb.bbd2e7b96766266f1d18f3ead4p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766266f1d18f3eadp-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766266f1d18f3eadp-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766266f1d18f3eadp-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fc00ece4f02f278ade6ad9e8p+0", LIT (0x1.921fc00ece4f02f278ade6ad9e8p+0), { LIT (-0xa.ca8b7d7e881db0d49193e0ab44p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab44p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab4p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d49193e0ab4p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fc00ece4f02f278ade6ad9fp+0", LIT (0x1.921fc00ece4f02f278ade6ad9fp+0), { LIT (-0xa.ca8b7d7e881db0d4919460ab44p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab44p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab4p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e881db0d4919460ab4p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fc00ece4f02f2p+0", LIT (0x1.921fc00ece4f02f2p+0), { LIT (-0xa.ca8b7d7e87a502ede3f57c1ddp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1ddp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1dccp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ede3f57c1dccp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fc00ece4f02f4p+0", LIT (0x1.921fc00ece4f02f4p+0), { LIT (-0xa.ca8b7d7e89a502ede3f507aaa8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa8p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa4p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ede3f507aaa4p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fc00ece4f1p+0", LIT (0x1.921fc00ece4f1p+0), { LIT (-0xa.ca8b7d8b95a502ede0fd607f3cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f38p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f38p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ede0fd607f38p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fc00ece4fp+0", LIT (0x1.921fc00ece4fp+0), { LIT (-0xa.ca8b7d7b95a502ede4a0f9b12p-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ede4a0f9b11cp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fc2p+0", LIT (0x1.921fc2p+0), { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460a4p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460ap-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460ap-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1e4cc9f460ap-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fcp+0", LIT (0x1.921fcp+0), { LIT (-0xa.bbbd2e7b95a85c638e746a5f5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f5p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f4cp-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c638e746a5f4cp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x8.a51407da8345c91c2466d97684p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c91c2466d97688p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c91c2466d97684p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c91c2466d97688p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+120", LIT (0x1p+120), { LIT (-0xe.d06685b36c66c4cf35c11f651cp-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4cf35c11f6518p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4cf35c11f6518p-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4cf35c11f6518p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0x2.a62ba8824e5bcb065f5f3b8e5p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb065f5f3b8e4fp-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb065f5f3b8e4fp-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb065f5f3b8e4fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffffff80000000000aaaaa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff80000000000aaaaacp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff80000000000aaaaa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff80000000000aaaaacp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffff8000004p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.182a44p+0", LIT (0x2.182a44p+0), { LIT (-0x7.ffffd61f8e65dc9a1c1408dd9ap-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc9a1c1408dd9ap-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc9a1c1408dd98p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc9a1c1408dd98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.182a4705ae6cap+0", LIT (0x2.182a4705ae6cap+0), { LIT (-0x7.ffffffffffff1aae55de707ab6p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1aae55de707ab4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1aae55de707ab4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1aae55de707ab4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.182a4705ae6cb08cb7665c1eacp+0", LIT (0x2.182a4705ae6cb08cb7665c1eacp+0), { LIT (-0x7.fffffffffffffffffffffffff4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffff2p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffff2p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffff2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.182a4705ae6cb08cb7665c1eadp+0", LIT (0x2.182a4705ae6cb08cb7665c1eadp+0), { LIT (-0x8.00000000000000000000000004p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.182a4705ae6cb08cp+0", LIT (0x2.182a4705ae6cb08cp+0), { LIT (-0x7.fffffffffffffff612bcbb0504p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff612bcbb0504p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff612bcbb0502p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff612bcbb0502p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.182a4705ae6cb09p+0", LIT (0x2.182a4705ae6cb09p+0), { LIT (-0x8.000000000000002d7fb28bb5ap-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000002d7fb28bb59cp-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000002d7fb28bb59cp-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000002d7fb28bb59cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.182a4705ae6ccp+0", LIT (0x2.182a4705ae6ccp+0), { LIT (-0x8.000000000000d6160463f5456p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d6160463f5455cp-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d6160463f5455cp-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d6160463f5455cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.182a48p+0", LIT (0x2.182a48p+0), { LIT (-0x8.00000d8c84574300c524d80428p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c84574300c524d80428p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c84574300c524d80424p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c84574300c524d80424p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { LIT (0x8.5f167780e479c9a5c86ffce76p-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9a5c86ffce76p-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9a5c86ffce76p-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9a5c86ffce764p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (0xf.431dd7a36cf37de5c74544f6b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37de5c74544f6b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37de5c74544f6b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37de5c74544f6b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (0xa.dd6f6bacd20654c1404f52cdep-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654c1404f52cdep-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654c1404f52cdep-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654c1404f52cde4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+0", LIT (0x2p+0), { LIT (-0x6.a88995d4dc81290ccbe2b2edccp-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc81290ccbe2b2edcap-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc81290ccbe2b2edcap-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc81290ccbe2b2edcap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+64", LIT (0x2p+64), { LIT (0xf.fb701e22987fbe68852ee2bc88p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc88p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc88p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe68852ee2bc8cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffffffe00000000aaaaaaaa93cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe00000000aaaaaaaa94p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe00000000aaaaaaaa93cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe00000000aaaaaaaa94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.ffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffe000000004p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (-0xf.dfe6f2169e24f276e8027d91bcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f276e8027d91bcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f276e8027d91b8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f276e8027d91b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3p+0", LIT (0x3p+0), { LIT (-0xf.d7025f42f2e9307dff82fdf6a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9307dff82fdf6a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9307dff82fdf6a4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9307dff82fdf6a4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0xf.dfe902135fc1c18492e869a3fcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18492e869a3f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18492e869a3f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18492e869a3f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xa.7553036d926062336d0e16e3ep-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d926062336d0e16e3dcp-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d926062336d0e16e3dcp-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d926062336d0e16e3dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p+48", LIT (0x4p+48), { LIT (0xd.e3b88804f00552d6baba70947p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552d6baba70947p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552d6baba70947p-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552d6baba709474p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.ffff800000aaaaaa4fa4fa69a4p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaaaa4fa4fa69a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaaaa4fa4fa69a4p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaaaa4fa4fa69a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff800000000004p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.ffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffff84p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x4.89e15c1ad2b654f99f75a35ee4p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b654f99f75a35ee6p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b654f99f75a35ee4p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b654f99f75a35ee6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.5cdb84bc117abd74f1e7000748p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd74f1e700074cp-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd74f1e7000748p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd74f1e700074cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xc.0ffbcf6c900baafbd68c5a99d4p-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900baafbd68c5a99d4p-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900baafbd68c5a99d4p-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900baafbd68c5a99d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+0", LIT (0x8p+0), { LIT (-0x2.53f7d7ec65f271ec91f976afbep-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ec91f976afbep-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ec91f976afbdp-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ec91f976afbdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+1020", LIT (0x8p+1020), { LIT (-0xd.38cf9361195f50b10fac29dd94p-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50b10fac29dd9p-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50b10fac29dd9p-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50b10fac29dd9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+124", LIT (0x8p+124), { LIT (0xc.82b8ec98b5e62fcf0b09fd10e8p-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fcf0b09fd10ecp-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fcf0b09fd10e8p-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fcf0b09fd10ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffffffffffe00000000000008p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffe0000000000000cp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffe00000000000008p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffe0000000000000cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.fffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffe0004p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.fe000aaa93e9589576da4ec948p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9589576da4ec948p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9589576da4ec948p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9589576da4ec94cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-972", LIT (0x8p-972), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x9p+0", LIT (0x9p+0), { LIT (-0xe.93fd53530cb5b8268bb2e8949cp-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b8268bb2e8949cp-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b8268bb2e89498p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b8268bb2e89498p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xa.217bap+12", LIT (0xa.217bap+12), { LIT (0x2.8f31660ce5e42c0544355e8e3dp-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c0544355e8e3dp-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c0544355e8e3dp-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c0544355e8e3ep-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xap+0", LIT (0xap+0), { LIT (-0xd.6cd64486358f904f7e2a0b9998p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f904f7e2a0b9994p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f904f7e2a0b9994p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f904f7e2a0b9994p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d17082980965c1a664p-4", LIT (0xc.d4966d92d17082980965c1a664p-4), { LIT (0xb.201e79450884be22c53e47ed14p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed18p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed14p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d17082980965c1a66p-4", LIT (0xc.d4966d92d17082980965c1a66p-4), { LIT (0xb.201e79450884be22c53e47ed18p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed18p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed18p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be22c53e47ed1cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { LIT (0xb.201e79450884be288bda3ee0dcp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be288bda3ee0dcp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be288bda3ee0dcp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be288bda3ee0ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { LIT (0xb.201e79450884be1d0c2440697p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be1d0c24406974p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be1d0c2440697p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be1d0c24406974p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { LIT (0xb.201e79450884c00000000000cp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884c00000000000cp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884c00000000000cp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884c00000000000c4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { LIT (0xb.201e794508846402500c44b4f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e794508846402500c44b4f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e794508846402500c44b4f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e794508846402500c44b4fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.201e83065041456a084c70f5ap-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041456a084c70f5ap-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041456a084c70f5ap-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041456a084c70f5a4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.201e77869a46ae20ce545c5c64p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae20ce545c5c68p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae20ce545c5c64p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae20ce545c5c68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xb.b4ff632a908f73ec151839cb9cp-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73ec151839cb9cp-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73ec151839cb9cp-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73ec151839cbap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { LIT (0x1.ff01000c9ae73630add558c9368p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae73630add558c9368p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae73630add558c9368p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae73630add558c937p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0xe.26f8af8333f9270e9c3e9f64f8p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9270e9c3e9f64f8p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9270e9c3e9f64f8p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9270e9c3e9f64fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (-0xa.07bd3ab53ab9710f3445538decp-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab9710f3445538de8p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab9710f3445538de8p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab9710f3445538de8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0xd.b7f5359babdb66be8d0cd3e294p-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66be8d0cd3e294p-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66be8d0cd3e29p-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66be8d0cd3e29p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xf.fb2a030c5ae20bdfe29fda198cp-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bdfe29fda199p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bdfe29fda198cp-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bdfe29fda199p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (-0xf.fff31767d5ba9e038d934070f4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9e038d934070fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (-0x5.b773d971a848e75c230605526ap-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c230605526ap-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c2306055268p-4), ERRNO_UNCHANGED }, { LIT (-0x5.b773d971a848e75c2306055268p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xd.a5f963cdefe6d529f6b6009fbp-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fb4p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fbp-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d529f6b6009fb4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (0x8.7e0ea4db2f48867p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f48867p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f48867p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f48868p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fc00ece4f02f2p+0", LIT (-0x1.921fc00ece4f02f2p+0), { LIT (-0xa.ca8b7d7e87a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fc00ece4f02f4p+0", LIT (-0x1.921fc00ece4f02f4p+0), { LIT (-0xa.ca8b7d7e89a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fc00ece4f1p+0", LIT (-0x1.921fc00ece4f1p+0), { LIT (-0xa.ca8b7d8b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fc00ece4fp+0", LIT (-0x1.921fc00ece4fp+0), { LIT (-0xa.ca8b7d7b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fc2p+0", LIT (-0x1.921fc2p+0), { LIT (-0xc.bbbd2e7b951e5b2p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b2p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fcp+0", LIT (-0x1.921fcp+0), { LIT (-0xa.bbbd2e7b95a85c7p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xf.fb701e22987fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { LIT (-0x1.febbf9949ecc1338p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc1336p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc1336p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc1336p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0xf.fff31767d5ba9e1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0x2.002ef4018753d50cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d50cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d508p-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d508p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0xd.a5f963cdefe6d52p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d53p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d52p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d53p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.000000cf4a2a2p+0", LIT (0x1.000000cf4a2a2p+0), { LIT (0x8.a513fcf3a90ecp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ecp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ecp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ec01p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0000010b239a9p+0", LIT (0x1.0000010b239a9p+0), { LIT (0x8.a513f9cde04e4p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e4p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e4p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e401p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.00000162a932bp+0", LIT (0x1.00000162a932bp+0), { LIT (0x8.a513f53385c5cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5c01p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.000002d452a1p+0", LIT (0x1.000002d452a1p+0), { LIT (0x8.a513e1c29116cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116c01p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x8.a513eced2ea575ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.000004p+0", LIT (0x1.000004p+0), { LIT (0x8.a513d1ffd9e28e6p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e6p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e6p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.000005bc7d86dp+0", LIT (0x1.000005bc7d86dp+0), { LIT (0x8.a513ba9f703d3ffp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d4p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d3ffp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.000006p+0", LIT (0x1.000006p+0), { LIT (0x8.a513b71284fd128p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd129p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd128p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd129p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { LIT (0x8.000014f038b1abp-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1ab1p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1abp-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1ab1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c152382d7365846p+0", LIT (0x1.0c152382d7365846p+0), { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c152382d7365848p+0", LIT (0x1.0c152382d7365848p+0), { LIT (0x7.ffffffffffffffe8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffe8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffe8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c152382d7365p+0", LIT (0x1.0c152382d7365p+0), { LIT (0x8.00000000000072ap-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072bp-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072ap-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c152382d7366p+0", LIT (0x1.0c152382d7366p+0), { LIT (0x7.ffffffffffff94fp-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94f8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94fp-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { LIT (0x7.fffff939bdd1803p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18038p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd1803p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18038p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.200144p+32", LIT (0x1.200144p+32), { LIT (0xf.bc96ca2c658abf5p-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf6p-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf5p-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.200145a975ce6p+32", LIT (0x1.200145a975ce6p+32), { LIT (-0x6.568e7ed3dffcdfe8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfep-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfep-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (-0xf.74fbd5498fe4c0dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xd.a82832da19f9891p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9892p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9891p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9892p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { LIT (0xd.a82683a33cbebffp-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbecp-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbebffp-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbecp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xd.a8263394be6d0e5p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e6p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e5p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0x1.4442d1846989361p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d1846989361p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d1846989361p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469893612p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { LIT (0x1.898cc51701b839a2p-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a2p-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a2p-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a4p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { LIT (-0x7.6733ae8fe47c65ep-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65d8p-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65d8p-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65d8p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { LIT (0x4.69898cc51701b838p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b838p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b838p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b84p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { LIT (-0xb.9676733ae8fe47dp-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47cp-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47cp-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47cp-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (-0xb.bbd2e7b96766267p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766267p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766266p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766266p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fc00ece4f02f2p+0", LIT (0x1.921fc00ece4f02f2p+0), { LIT (-0xa.ca8b7d7e87a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fc00ece4f02f4p+0", LIT (0x1.921fc00ece4f02f4p+0), { LIT (-0xa.ca8b7d7e89a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fc00ece4f1p+0", LIT (0x1.921fc00ece4f1p+0), { LIT (-0xa.ca8b7d8b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fc00ece4fp+0", LIT (0x1.921fc00ece4fp+0), { LIT (-0xa.ca8b7d7b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fc2p+0", LIT (0x1.921fc2p+0), { LIT (-0xc.bbbd2e7b951e5b2p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b2p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fcp+0", LIT (0x1.921fcp+0), { LIT (-0xa.bbbd2e7b95a85c7p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x8.a51407da8345c91p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c92p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c91p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c92p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+120", LIT (0x1p+120), { LIT (-0xe.d06685b36c66c4dp-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4dp-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4cp-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0x2.a62ba8824e5bcb08p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb08p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb04p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb04p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff800001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.182a44p+0", LIT (0x2.182a44p+0), { LIT (-0x7.ffffd61f8e65dcap-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc98p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc98p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.182a4705ae6cap+0", LIT (0x2.182a4705ae6cap+0), { LIT (-0x7.ffffffffffff1abp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1abp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1aa8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1aa8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.182a4705ae6cb08cp+0", LIT (0x2.182a4705ae6cb08cp+0), { LIT (-0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.182a4705ae6cb09p+0", LIT (0x2.182a4705ae6cb09p+0), { LIT (-0x8.000000000000003p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000003p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000002p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000002p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.182a4705ae6ccp+0", LIT (0x2.182a4705ae6ccp+0), { LIT (-0x8.000000000000d62p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d61p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d61p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.182a48p+0", LIT (0x2.182a48p+0), { LIT (-0x8.00000d8c8457431p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c845743p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c845743p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c845743p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { LIT (0x8.5f167780e479c9ap-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9ap-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9ap-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (0xf.431dd7a36cf37dep-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37dep-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37dep-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37dfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (0xa.dd6f6bacd20654cp-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654cp-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654cp-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+0", LIT (0x2p+0), { LIT (-0x6.a88995d4dc81291p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc81291p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc812908p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc812908p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+64", LIT (0x2p+64), { LIT (0xf.fb701e22987fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe00000001p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe00000001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (-0xf.dfe6f2169e24f28p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f27p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f27p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f27p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3p+0", LIT (0x3p+0), { LIT (-0xf.d7025f42f2e9308p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9308p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9307p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9307p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0xf.dfe902135fc1c19p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xa.7553036d9260624p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d9260623p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d9260623p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d9260623p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p+48", LIT (0x4p+48), { LIT (0xd.e3b88804f00552dp-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552dp-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552dp-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.ffff800000aaaaap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaabp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaaap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaabp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x4.89e15c1ad2b654f8p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b654f8p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b654f8p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b655p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.5cdb84bc117abd7p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd7p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd7p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xc.0ffbcf6c900baafp-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900babp-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900baafp-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900babp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+0", LIT (0x8p+0), { LIT (-0x2.53f7d7ec65f271fp-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ecp-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ecp-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+1020", LIT (0x8p+1020), { LIT (-0xd.38cf9361195f50cp-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50bp-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50bp-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+124", LIT (0x8p+124), { LIT (0xc.82b8ec98b5e62fcp-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fdp-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fcp-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+16380", LIT (0x8p+16380), { LIT (0xe.bcc2fc82ae39ebfp-4), ERRNO_UNCHANGED }, { LIT (0xe.bcc2fc82ae39ecp-4), ERRNO_UNCHANGED }, { LIT (0xe.bcc2fc82ae39ebfp-4), ERRNO_UNCHANGED }, { LIT (0xe.bcc2fc82ae39ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffe001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.fe000aaa93e9589p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9589p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9589p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e958ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-972", LIT (0x8p-972), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x9p+0", LIT (0x9p+0), { LIT (-0xe.93fd53530cb5b83p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b82p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b82p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b82p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xa.217bap+12", LIT (0xa.217bap+12), { LIT (0x2.8f31660ce5e42c04p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c04p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c04p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c08p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xap+0", LIT (0xap+0), { LIT (-0xd.6cd64486358f905p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f905p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f904p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f904p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { LIT (0xb.201e79450884be2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be3p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { LIT (0xb.201e79450884be1p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be1p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { LIT (0xb.201e79450884cp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884cp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884cp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884c01p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { LIT (0xb.201e7945088464p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e7945088464p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e7945088464p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884641p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.201e83065041456p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041457p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041456p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041457p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.201e77869a46ae2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xb.b4ff632a908f73ep-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73fp-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73ep-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { LIT (0x1.ff01000c9ae7363p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae7363p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae7363p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae73632p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0xe.26f8af8333f927p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9271p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f927p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9271p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (-0xa.07bd3ab53ab9711p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab9711p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab971p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab971p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0xd.b7f5359babdb66cp-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66cp-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66bp-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xf.fb2a030c5ae20bdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bep-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (-0xf.fff31767d5ba9e1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (-0x2.002ef4018753d50cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d50cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d508p-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d508p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xd.a5f963cdefe6d52p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d53p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d52p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d53p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (0x8.7e0ea4db2f48867p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f48867p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f48867p-4), ERRNO_UNCHANGED }, { LIT (0x8.7e0ea4db2f48868p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fc00ece4f02f2p+0", LIT (-0x1.921fc00ece4f02f2p+0), { LIT (-0xa.ca8b7d7e87a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fc00ece4f02f4p+0", LIT (-0x1.921fc00ece4f02f4p+0), { LIT (-0xa.ca8b7d7e89a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fc00ece4f1p+0", LIT (-0x1.921fc00ece4f1p+0), { LIT (-0xa.ca8b7d8b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fc00ece4fp+0", LIT (-0x1.921fc00ece4fp+0), { LIT (-0xa.ca8b7d7b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fc2p+0", LIT (-0x1.921fc2p+0), { LIT (-0xc.bbbd2e7b951e5b2p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b2p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fcp+0", LIT (-0x1.921fcp+0), { LIT (-0xa.bbbd2e7b95a85c7p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xf.fb701e22987fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { LIT (-0x1.febbf9949ecc1338p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc1336p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc1336p-4), ERRNO_UNCHANGED }, { LIT (-0x1.febbf9949ecc1336p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16448", LIT (-0x4p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0xf.fff31767d5ba9e1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0x2.002ef4018753d50cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d50cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d508p-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d508p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0xd.a5f963cdefe6d52p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d53p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d52p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d53p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.000000cf4a2a2p+0", LIT (0x1.000000cf4a2a2p+0), { LIT (0x8.a513fcf3a90ecp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ecp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ecp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513fcf3a90ec01p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0000010b239a9p+0", LIT (0x1.0000010b239a9p+0), { LIT (0x8.a513f9cde04e4p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e4p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e4p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f9cde04e401p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.00000162a932bp+0", LIT (0x1.00000162a932bp+0), { LIT (0x8.a513f53385c5cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513f53385c5c01p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.000002d452a1p+0", LIT (0x1.000002d452a1p+0), { LIT (0x8.a513e1c29116cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116cp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513e1c29116c01p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x8.a513eced2ea575ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575ep-4), ERRNO_UNCHANGED }, { LIT (0x8.a513eced2ea575fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.000004p+0", LIT (0x1.000004p+0), { LIT (0x8.a513d1ffd9e28e6p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e6p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e6p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513d1ffd9e28e7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.000005bc7d86dp+0", LIT (0x1.000005bc7d86dp+0), { LIT (0x8.a513ba9f703d3ffp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d4p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d3ffp-4), ERRNO_UNCHANGED }, { LIT (0x8.a513ba9f703d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.000006p+0", LIT (0x1.000006p+0), { LIT (0x8.a513b71284fd128p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd129p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd128p-4), ERRNO_UNCHANGED }, { LIT (0x8.a513b71284fd129p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { LIT (0x8.000014f038b1abp-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1ab1p-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1abp-4), ERRNO_UNCHANGED }, { LIT (0x8.000014f038b1ab1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c152382d7365846p+0", LIT (0x1.0c152382d7365846p+0), { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c152382d7365848p+0", LIT (0x1.0c152382d7365848p+0), { LIT (0x7.ffffffffffffffe8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffe8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffe8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c152382d7365p+0", LIT (0x1.0c152382d7365p+0), { LIT (0x8.00000000000072ap-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072bp-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072ap-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000072bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c152382d7366p+0", LIT (0x1.0c152382d7366p+0), { LIT (0x7.ffffffffffff94fp-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94f8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94fp-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff94f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { LIT (0x7.fffff939bdd1803p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18038p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd1803p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff939bdd18038p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.200144p+32", LIT (0x1.200144p+32), { LIT (0xf.bc96ca2c658abf5p-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf6p-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf5p-4), ERRNO_UNCHANGED }, { LIT (0xf.bc96ca2c658abf6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.200145a975ce6p+32", LIT (0x1.200145a975ce6p+32), { LIT (-0x6.568e7ed3dffcdfe8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfep-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfep-4), ERRNO_UNCHANGED }, { LIT (-0x6.568e7ed3dffcdfep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (-0xf.74fbd5498fe4c0dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.74fbd5498fe4c0cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xd.a82832da19f9891p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9892p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9891p-8), ERRNO_UNCHANGED }, { LIT (0xd.a82832da19f9892p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { LIT (0xd.a82683a33cbebffp-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbecp-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbebffp-8), ERRNO_UNCHANGED }, { LIT (0xd.a82683a33cbecp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xd.a8263394be6d0e5p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e6p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e5p-8), ERRNO_UNCHANGED }, { LIT (0xd.a8263394be6d0e6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0x1.4442d1846989361p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d1846989361p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d1846989361p-24), ERRNO_UNCHANGED }, { LIT (0x1.4442d18469893612p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { LIT (0x1.898cc51701b839a2p-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a2p-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a2p-64), ERRNO_UNCHANGED }, { LIT (0x1.898cc51701b839a4p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { LIT (-0x7.6733ae8fe47c65ep-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65d8p-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65d8p-68), ERRNO_UNCHANGED }, { LIT (-0x7.6733ae8fe47c65d8p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { LIT (0x4.69898cc51701b838p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b838p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b838p-56), ERRNO_UNCHANGED }, { LIT (0x4.69898cc51701b84p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { LIT (-0xb.9676733ae8fe47dp-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47cp-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47cp-56), ERRNO_UNCHANGED }, { LIT (-0xb.9676733ae8fe47cp-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (-0xb.bbd2e7b96766267p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766267p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766266p-28), ERRNO_UNCHANGED }, { LIT (-0xb.bbd2e7b96766266p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fc00ece4f02f2p+0", LIT (0x1.921fc00ece4f02f2p+0), { LIT (-0xa.ca8b7d7e87a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e87a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fc00ece4f02f4p+0", LIT (0x1.921fc00ece4f02f4p+0), { LIT (-0xa.ca8b7d7e89a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7e89a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fc00ece4f1p+0", LIT (0x1.921fc00ece4f1p+0), { LIT (-0xa.ca8b7d8b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d8b95a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fc00ece4fp+0", LIT (0x1.921fc00ece4fp+0), { LIT (-0xa.ca8b7d7b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502fp-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ep-24), ERRNO_UNCHANGED }, { LIT (-0xa.ca8b7d7b95a502ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fc2p+0", LIT (0x1.921fc2p+0), { LIT (-0xc.bbbd2e7b951e5b2p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b2p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1p-24), ERRNO_UNCHANGED }, { LIT (-0xc.bbbd2e7b951e5b1p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fcp+0", LIT (0x1.921fcp+0), { LIT (-0xa.bbbd2e7b95a85c7p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED }, { LIT (-0xa.bbbd2e7b95a85c6p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x8.a51407da8345c91p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c92p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c91p-4), ERRNO_UNCHANGED }, { LIT (0x8.a51407da8345c92p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+120", LIT (0x1p+120), { LIT (-0xe.d06685b36c66c4dp-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4dp-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4cp-4), ERRNO_UNCHANGED }, { LIT (-0xe.d06685b36c66c4cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0x2.a62ba8824e5bcb08p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb08p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb04p-4), ERRNO_UNCHANGED }, { LIT (-0x2.a62ba8824e5bcb04p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffff800001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.182a44p+0", LIT (0x2.182a44p+0), { LIT (-0x7.ffffd61f8e65dcap-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc98p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc98p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffd61f8e65dc98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.182a4705ae6cap+0", LIT (0x2.182a4705ae6cap+0), { LIT (-0x7.ffffffffffff1abp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1abp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1aa8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffff1aa8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.182a4705ae6cb08cp+0", LIT (0x2.182a4705ae6cb08cp+0), { LIT (-0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.182a4705ae6cb09p+0", LIT (0x2.182a4705ae6cb09p+0), { LIT (-0x8.000000000000003p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000003p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000002p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000002p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.182a4705ae6ccp+0", LIT (0x2.182a4705ae6ccp+0), { LIT (-0x8.000000000000d62p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d61p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d61p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000d61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.182a48p+0", LIT (0x2.182a48p+0), { LIT (-0x8.00000d8c8457431p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c845743p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c845743p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000d8c845743p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { LIT (0x8.5f167780e479c9ap-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9ap-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9ap-4), ERRNO_UNCHANGED }, { LIT (0x8.5f167780e479c9bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (0xf.431dd7a36cf37dep-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37dep-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37dep-4), ERRNO_UNCHANGED }, { LIT (0xf.431dd7a36cf37dfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (0xa.dd6f6bacd20654cp-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654cp-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654cp-4), ERRNO_UNCHANGED }, { LIT (0xa.dd6f6bacd20654dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+0", LIT (0x2p+0), { LIT (-0x6.a88995d4dc81291p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc81291p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc812908p-4), ERRNO_UNCHANGED }, { LIT (-0x6.a88995d4dc812908p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+64", LIT (0x2p+64), { LIT (0xf.fb701e22987fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb701e22987fbe7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe00000001p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffe00000001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (-0xf.dfe6f2169e24f28p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f27p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f27p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe6f2169e24f27p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3p+0", LIT (0x3p+0), { LIT (-0xf.d7025f42f2e9308p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9308p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9307p-4), ERRNO_UNCHANGED }, { LIT (-0xf.d7025f42f2e9307p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0xf.dfe902135fc1c19p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfe902135fc1c18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xa.7553036d9260624p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d9260623p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d9260623p-4), ERRNO_UNCHANGED }, { LIT (-0xa.7553036d9260623p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p+48", LIT (0x4p+48), { LIT (0xd.e3b88804f00552dp-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552dp-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552dp-4), ERRNO_UNCHANGED }, { LIT (0xd.e3b88804f00552ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.ffff800000aaaaap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaabp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaaap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffff800000aaaabp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448", LIT (0x4p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffff9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x4.89e15c1ad2b654f8p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b654f8p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b654f8p-4), ERRNO_UNCHANGED }, { LIT (0x4.89e15c1ad2b655p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.5cdb84bc117abd7p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd7p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd7p-4), ERRNO_UNCHANGED }, { LIT (0xf.5cdb84bc117abd8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xc.0ffbcf6c900baafp-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900babp-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900baafp-4), ERRNO_UNCHANGED }, { LIT (0xc.0ffbcf6c900babp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+0", LIT (0x8p+0), { LIT (-0x2.53f7d7ec65f271fp-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ecp-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ecp-4), ERRNO_UNCHANGED }, { LIT (-0x2.53f7d7ec65f271ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+1020", LIT (0x8p+1020), { LIT (-0xd.38cf9361195f50cp-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50bp-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50bp-4), ERRNO_UNCHANGED }, { LIT (-0xd.38cf9361195f50bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+124", LIT (0x8p+124), { LIT (0xc.82b8ec98b5e62fcp-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fdp-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fcp-4), ERRNO_UNCHANGED }, { LIT (0xc.82b8ec98b5e62fdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+16380", LIT (0x8p+16380), { LIT (0xe.bcc2fc82ae39ebfp-4), ERRNO_UNCHANGED }, { LIT (0xe.bcc2fc82ae39ecp-4), ERRNO_UNCHANGED }, { LIT (0xe.bcc2fc82ae39ebfp-4), ERRNO_UNCHANGED }, { LIT (0xe.bcc2fc82ae39ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffe001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.fe000aaa93e9589p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9589p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e9589p-4), ERRNO_UNCHANGED }, { LIT (0xf.fe000aaa93e958ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-972", LIT (0x8p-972), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x9p+0", LIT (0x9p+0), { LIT (-0xe.93fd53530cb5b83p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b82p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b82p-4), ERRNO_UNCHANGED }, { LIT (-0xe.93fd53530cb5b82p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xa.217bap+12", LIT (0xa.217bap+12), { LIT (0x2.8f31660ce5e42c04p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c04p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c04p-20), ERRNO_UNCHANGED }, { LIT (0x2.8f31660ce5e42c08p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xap+0", LIT (0xap+0), { LIT (-0xd.6cd64486358f905p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f905p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f904p-4), ERRNO_UNCHANGED }, { LIT (-0xd.6cd64486358f904p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { LIT (0xb.201e79450884be2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be3p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { LIT (0xb.201e79450884be1p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be1p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884be2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { LIT (0xb.201e79450884cp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884cp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884cp-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884c01p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { LIT (0xb.201e7945088464p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e7945088464p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e7945088464p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e79450884641p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.201e83065041456p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041457p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041456p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e83065041457p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.201e77869a46ae2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae2p-4), ERRNO_UNCHANGED }, { LIT (0xb.201e77869a46ae3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xb.b4ff632a908f73ep-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73fp-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73ep-4), ERRNO_UNCHANGED }, { LIT (0xb.b4ff632a908f73fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { LIT (0x1.ff01000c9ae7363p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae7363p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae7363p-4), ERRNO_UNCHANGED }, { LIT (0x1.ff01000c9ae73632p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0xe.26f8af8333f927p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9271p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f927p-4), ERRNO_UNCHANGED }, { LIT (0xe.26f8af8333f9271p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (-0xa.07bd3ab53ab9711p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab9711p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab971p-4), ERRNO_UNCHANGED }, { LIT (-0xa.07bd3ab53ab971p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0xd.b7f5359babdb66cp-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66cp-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66bp-4), ERRNO_UNCHANGED }, { LIT (-0xd.b7f5359babdb66bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xf.fb2a030c5ae20bdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bep-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fb2a030c5ae20bep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (-0xf.fff31767d5ba9e1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31767d5ba9ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (-0x2.002ef4018753d50cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d50cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d508p-4), ERRNO_UNCHANGED }, { LIT (-0x2.002ef4018753d508p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xd.a5f963cdefe6d52p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d53p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d52p-4), ERRNO_UNCHANGED }, { LIT (0xd.a5f963cdefe6d53p-4), ERRNO_UNCHANGED } },
#endif
  };

static void
cos_test (void)
{
  ALL_RM_TEST (cos, 0, cos_test_data, RUN_TEST_LOOP_f_f, END);
}

static void
do_test (void)
{
  cos_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */