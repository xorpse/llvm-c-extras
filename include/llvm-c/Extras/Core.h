#ifndef LLVM_C_EXTRAS_CORE_H
#define LLVM_C_EXTRAS_CORE_H

#include <llvm-c/ExternC.h>
#include <llvm-c/Types.h>

LLVM_C_EXTERN_C_BEGIN

LLVMValueRef LLVMGetFirstInsertionPt(LLVMBasicBlockRef BB);

LLVM_C_EXTERN_C_END

#endif
