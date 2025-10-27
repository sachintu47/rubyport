/* -----------------------------------------------------------------*-C-*-
   ffitarget.h - Copyright (c) 2012  Anthony Green
                 Copyright (c) 1996-2003  Red Hat, Inc.
                 Copyright IBM Corp. 2021
   Target configuration macros for S390.

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   ``Software''), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED ``AS IS'', WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.

   ----------------------------------------------------------------------- */

#ifndef LIBFFI_TARGET_H
#define LIBFFI_TARGET_H


#ifndef LIBFFI_H
#error "Please do not include ffitarget.h directly into your source.  Use ffi.h instead."
#endif

#if defined (__s390x__)
#ifndef S390X
#define S390X
#endif
#endif

/* ---- System specific configurations ----------------------------------- */

#ifndef LIBFFI_ASM
typedef unsigned long          ffi_arg;
typedef signed long            ffi_sarg;

typedef enum ffi_abi {
  FFI_FIRST_ABI = 0,
  FFI_SYSV,
  FFI_LAST_ABI,
  FFI_DEFAULT_ABI = FFI_SYSV
} ffi_abi;
#endif

#define FFI_TARGET_SPECIFIC_STACK_SPACE_ALLOCATION
#define FFI_TARGET_HAS_COMPLEX_TYPE

/* ---- Definitions for closures ----------------------------------------- */

#define FFI_CLOSURES 1
#ifdef S390X
#define FFI_TRAMPOLINE_SIZE 64
#else
#define FFI_TRAMPOLINE_SIZE 64
#endif
#define FFI_NATIVE_RAW_API 0


/* If these change, update src/mips/ffitarget.h. */
/**
#define FFI_TYPE_VOID       0
#define FFI_TYPE_INT        1
#define FFI_TYPE_FLOAT      2
#define FFI_TYPE_DOUBLE     3
#if @HAVE_LONG_DOUBLE@
#define FFI_TYPE_LONGDOUBLE 4
#else
#define FFI_TYPE_LONGDOUBLE FFI_TYPE_DOUBLE
#endif
#define FFI_TYPE_UINT8      5
#define FFI_TYPE_SINT8      6
#define FFI_TYPE_UINT16     7
#define FFI_TYPE_SINT16     8
#define FFI_TYPE_UINT32     9
#define FFI_TYPE_SINT32     10
#define FFI_TYPE_UINT64     11
#define FFI_TYPE_SINT64     12
#define FFI_TYPE_STRUCT     13
#define FFI_TYPE_POINTER    14
#define FFI_TYPE_COMPLEX    15
#define FFI_TYPE_STRUCT_FF  16
#define FFI_TYPE_STRUCT_DD  17
**/

#define FFI_TYPE_STRUCT_FF  16
#define FFI_TYPE_STRUCT_DD  17

// HACK ALERT!!! (maybe fix this?)
#ifdef FFI_TYPE_LAST
#undef FFI_TYPE_LAST
/* This should always refer to the last type code (for sanity checks) */
#define FFI_TYPE_LAST       FFI_TYPE_STRUCT_DD
#endif

/* struct data to save registers */
struct ffi_reg_data {
  long* gpr[16];
  double fpr[7];
};

// #define FFI_EXTRA_CIF_FIELDS struct ffi_reg_data reg

#endif

