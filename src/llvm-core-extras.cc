#include <llvm-c/Core.h>
#include <llvm-c/Extras/Core.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Operator.h>

using namespace llvm;

LLVMValueRef LLVMGetFirstInsertionPt(LLVMBasicBlockRef BB) {
  BasicBlock *Block = unwrap(BB);
  BasicBlock::iterator I = Block->getFirstInsertionPt();
  if (I == Block->end())
    return nullptr;
  return wrap(&*I);
}

LLVMBool LLVMHasNoInfs(LLVMValueRef Instr) {
  Instruction *I = unwrap<Instruction>(Instr);
  return I->hasNoInfs();
}

LLVMBool LLVMHasNoNaNs(LLVMValueRef Instr) {
  Instruction *I = unwrap<Instruction>(Instr);
  return I->hasNoNaNs();
}

LLVMBool LLVMHasNoSignedWrap(LLVMValueRef Instr) {
  Instruction *I = unwrap<Instruction>(Instr);
  return I->hasNoSignedWrap();
}

LLVMBool LLVMHasNoSignedZeros(LLVMValueRef Instr) {
  Instruction *I = unwrap<Instruction>(Instr);
  return I->hasNoSignedZeros();
}

LLVMBool LLVMHasNoUnsignedWrap(LLVMValueRef Instr) {
  Instruction *I = unwrap<Instruction>(Instr);
  return I->hasNoUnsignedWrap();
}

LLVMBool LLVMIsExact(LLVMValueRef Instr) {
  Instruction *I = unwrap<Instruction>(Instr);
  return I->isExact();
}

LLVMBool LLVMIsFast(LLVMValueRef Instr) {
  Instruction *I = unwrap<Instruction>(Instr);
  return I->isFast();
}

LLVMFastMathFlags LLVMGetFastMathFlags(LLVMValueRef Instr) {
  Instruction *I = unwrap<Instruction>(Instr);
  FastMathFlags FMF = I->getFastMathFlags();
  return static_cast<LLVMFastMathFlags>(
    (FMF.allowContract() ? LLVMFastMathFlagsAllowReassoc : LLVMFastMathFlagsNone) |
    (FMF.noNaNs() ? LLVMFastMathFlagsNoNaNs : LLVMFastMathFlagsNone) |
    (FMF.noInfs() ? LLVMFastMathFlagsNoInfs : LLVMFastMathFlagsNone) |
    (FMF.noSignedZeros() ? LLVMFastMathFlagsNoSignedZeros : LLVMFastMathFlagsNone) |
    (FMF.allowReciprocal() ? LLVMFastMathFlagsAllowReciprocal : LLVMFastMathFlagsNone) |
    (FMF.allowContract() ? LLVMFastMathFlagsAllowContract : LLVMFastMathFlagsNone) |
    (FMF.approxFunc() ? LLVMFastMathFlagsApproxFunc : LLVMFastMathFlagsNone));
}
