#include <iostream>

void someFunction() {
  std::cout << "Hello from someFunction!" << std::endl;
}

int main() {
  // Reinterpret function pointer to a different type
  void* funcPtrAsVoid = reinterpret_cast<void*>(someFunction);

  // Reinterpret back to the original function pointer type
  void (*newFuncPtr)() = reinterpret_cast<void (*)()>(funcPtrAsVoid);

  // Call the function through the reinterpreted pointer
  newFuncPtr();

  return 0;
}
