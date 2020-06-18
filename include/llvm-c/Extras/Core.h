#ifndef LLVM_C_EXTRAS_CORE_H
#define LLVM_C_EXTRAS_CORE_H

#include <llvm-c/ExternC.h>
#include <llvm-c/Types.h>

LLVM_C_EXTERN_C_BEGIN

typedef enum {
  LLVMFastMathFlagsNone = 0,
  LLVMFastMathFlagsAllowReassoc = (1 << 0),
  LLVMFastMathFlagsNoNaNs = (1 << 1),
  LLVMFastMathFlagsNoInfs = (1 << 2),
  LLVMFastMathFlagsNoSignedZeros = (1 << 3),
  LLVMFastMathFlagsAllowReciprocal = (1 << 4),
  LLVMFastMathFlagsAllowContract = (1 << 5),
  LLVMFastMathFlagsApproxFunc = (1 << 6),
} LLVMFastMathFlags;

LLVMValueRef LLVMGetFirstInsertionPt(LLVMBasicBlockRef BB);

LLVMBool LLVMHasNoInfs(LLVMValueRef Instr);
LLVMBool LLVMHasNoNaNs(LLVMValueRef Instr);
LLVMBool LLVMHasNoSignedWrap(LLVMValueRef Instr);
LLVMBool LLVMHasNoSignedZeros(LLVMValueRef Instr);
LLVMBool LLVMHasNoUnsignedWrap(LLVMValueRef Instr);
LLVMBool LLVMIsExact(LLVMValueRef Instr);
LLVMBool LLVMIsFast(LLVMValueRef Instr);
LLVMFastMathFlags LLVMGetFastMathFlags(LLVMValueRef Instr);

LLVM_C_EXTERN_C_END

#endif
