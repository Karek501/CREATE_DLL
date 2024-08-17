#include <iostream>
#include <windows.h>

// Defining funtion pointers
typedef void* (*CreateWrapper)();
typedef void (*UseOperator)(void*);
typedef void (*UseManager)(void*);
typedef void (*DeleteWrapper)(void*);

int main(){
  // Load the DLL
  HMODULE dllHandle = LoadLibrary("libOperatorManagerWrapper.dll");
  if (!dllHandle) {
      std::cerr << "Failed to load DLL." << std::endl;
      return 1;
  }

  // Store function definitions into our function prototypes
  CreateWrapper createWrapper = reinterpret_cast<CreateWrapper>(GetProcAddress(dllHandle, "createWrapper"));
  UseOperator useOperator = reinterpret_cast<UseOperator>(GetProcAddress(dllHandle, "useOperator"));
  UseManager useManager = reinterpret_cast<UseManager>(GetProcAddress(dllHandle, "useManager"));
  DeleteWrapper deleteWrapper = reinterpret_cast<DeleteWrapper>(GetProcAddress(dllHandle, "deleteWrapper"));

  // Stop execution if we can not get functions from the dll
  if(!createWrapper || !useOperator || !useManager || !deleteWrapper){
    std::cerr << "Failed to get function pointers." << std::endl;
    FreeLibrary(dllHandle);
    return 1;
  }

  void* instance = createWrapper();
  useOperator(instance);
  useManager(instance);
  deleteWrapper(instance);

  // Clean up
  FreeLibrary(dllHandle);

  return 0;
}