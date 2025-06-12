#include "cmn/thread_test.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace threadtest {
void Hello() {
  std::cout << "Hello from ns:thread_test, func: Hello\n";
  std::thread::id this_id = std::this_thread::get_id();
  std::cout << "thread id is " << this_id << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(5));
}
}  // namespace threadtest