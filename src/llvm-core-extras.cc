#include <llvm-c/Core.h>
#include <llvm/IR/BasicBlock.h>

using namespace llvm;

LLVMValueRef LLVMGetFirstInsertionPt(LLVMBasicBlockRef BB) {
  BasicBlock *Block = unwrap(BB);
  BasicBlock::iterator I = Block->getFirstInsertionPt();
  if (I == Block->end())
    return nullptr;
  return wrap(&*I);
}
