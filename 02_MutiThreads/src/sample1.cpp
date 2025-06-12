#include <iostream>
#include <thread>  // 提供 C++11 标准线程库的核心功能。

// 定义线程要执行的函数
void Hello() { std::cout << "Hello from Thread!\n"; }

int main(int argc, char const *argv[]) {
  // 作用：创建并启动线程
  std::thread thread(Hello);
  // 关键点：
  // 1、std::thread 的构造函数接受一个 可调用对象（这里是函数 Hello）
  // 2、线程在构造时 立即开始执行
  // 3、如果 Hello 带参数，需在构造函数中传递（如 std::thread thread(Hello,
  // arg1, arg2)）。

  // 等待线程完成
  // 作用：阻塞当前线程（这里是主线程），直到 thread 线程执行完毕
  if (thread.joinable()) {
    thread.join();
  }
  // 关键点：
  // 1、必须调用 join() 或 detach()，否则程序终止时 std::thread 析构会调用
  // std::terminate 导致程序崩溃
  //    当一个 std::thread
  //    对象析构时，它会检查自己是否还"关联"着一个活跃的线程（即线程是否还在运行）
  //    如果仍然关联着活跃线程（既没有 join() 也没有 detach()），则调用
  //    std::terminate() 终止整个程序
  // 2、join()：等待线程结束，并回收资源。
  // 3、detach()：分离线程，使其在后台独立运行（失去控制权，慎用！）

  // 主线程执行其他任务
  std::cout << "Hello from main!\n";
  // 立即执行一次lamda表达式
  []() { std::cout << "Hello from lamda\n"; }();
  return 0;
}
