#include <iostream>
#include <thread>
#include <vector>

void DoSomethingBad(){
  while (true)
  {     
    std::cout<<1/(rand()%12)<<std::endl;
    /* code */
  }
}

int main(){
  //这段代码 std::thread::hardware_concurrency() 是 C++ 标准库中的一个函数，用于获取当前平台支持的硬件线程数（也就是 CPU 核心数）。
  unsigned int num_thread = std::thread::hardware_concurrency();
  //这段代码定义了一个名为 threads 的 std::vector 对象，它的模板参数是 std::thread，也就是说这个 vector 存储的元素是 std::thread 对象。
  //std::vector 是 C++ 标准库中的一个容器，提供了动态数组的功能，可以动态增加和删除元素。而 std::thread 则是一个线程对象，它提供了创建和管理线程的接口。
  // 因此，这个代码定义了一个可以存储多个线程的容器对象。可以通过 threads 向其中添加多个线程，以便进行并发操作。例如：
  std::vector<std::thread> threads;
  std::cout<<"running with"<<num_thread<<"threads."<<std::endl;

  // 创建线程的方式：
  // 1. 首先需要定义一个函数或函数对象，作为新线程的切入点
  for (int i=0;i<num_thread;++i)
    threads.push_back(std::thread(DoSomethingBad));

  // 这段代码使用了 C++11 中的范围 for 循环，遍历了 threads 向量中的每一个 std::thread 对象，并依次调用其 join() 方法，等待所有线程执行完毕。
  // auto && 是 C++11 引入的新特性之一，它被称为“万能引用”，可以自动推导出迭代器类型并支持任意类型的值，而不需要显式指定类型。
  // 因此，这段代码可以简化传统的使用迭代器的方式：
  for (auto && th : threads)th.join();
  return 0;
}