#include <iostream>
#include "Wrapper.h"
#include "LOAD_libOperatorManagerWrapper.h"

int main(){
  Wrapper* instance = new Wrapper();
  instance->useOperator();
  instance->useManager();

  delete instance;

  std::cout << "apparently it works" << std::endl;
  system("PAUSE");
  return 0;
}