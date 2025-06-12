#include <iostream>
#include <thread>

#include "cmn/thread_test.h"

int main(int argc, char const *argv[]) {
  /*
   * 一、std::thread构造方式
   */

  // 1. 默认构造 - 创建非活动线程对象
  // 注意: 这种线程对象不代表任何执行线程
  // joinable() == false

  // 2. 从自由函数构造
  // 语法: std::thread(函数指针, 参数...)
  // 线程立即开始执行

  // 3. 从成员函数构造
  // 语法: std::thread(&类名::成员函数, 对象指针, 参数...)

  // 4. 从静态成员函数构造
  // 与自由函数用法相同

  // 5. 从lambda表达式构造
  // 适合简短的一次性任务

  /*
   * 二、析构处理
   *
   * 重要规则:
   * 1. 在std::thread对象析构前，必须确保:
   *    - 已经调用join()等待线程结束，或
   *    - 已经调用detach()分离线程
   * 2. 如果thread对象析构时仍为joinable状态(即关联活动线程)，
   *    程序会调用std::terminate()终止
   */
  std::thread t1;
  std::cout << "t1's thread id is " << t1.get_id() << std::endl;
  std::thread t2(threadtest::Hello);
  std::cout << "t2's thread id is " << t2.get_id() << std::endl;
  // ===================================================================
  // joinable() 详解
  // ===================================================================
  //
  // joinable() 是 std::thread 的一个重要方法，用于判断线程对象是否可以调用
  // join() 或 detach()。
  //
  // 返回 true 的情况：
  //   1. 线程是通过构造函数绑定了可调用对象创建的（如 `std::thread t(func)`）。
  //   2. 线程尚未被 join() 或 detach() 过。
  //
  // 返回 false 的情况：
  //   1. 线程是默认构造的（如 `std::thread t;`，不代表任何执行线程）。
  //   2. 线程已经被 join() 或 detach() 过（调用后线程对象不再关联执行线程）。
  //   3. 线程已被移动（资源转移到其他线程对象，原对象不再关联线程）。
  //
  // 为什么需要 joinable()？
  //   - 防止对同一线程多次调用 join() 或 detach()，否则会触发 std::terminate。
  //   - 明确线程状态，避免操作无效的线程对象。
  //
  // 正确用法：
  //   if (t.joinable()) {  // 检查是否可以 join/detach
  //       t.join();         // 等待线程结束（或 t.detach() 分离线程）
  //   }
  // ===================================================================
  if (t1.joinable()) {
    t1.join();
  }
  if (t2.joinable()) {
    t2.join();
  }
  return 0;
}
