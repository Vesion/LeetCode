#include <thread>
#include <mutex>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>

int main() {
{
  using clock = std::chrono::system_clock;
  std::cout << "is steady: " << clock::is_steady << std::endl;
  std::cout << "period: " << clock::period::num << " / " << clock::period::den << std::endl;
}

{
  using clock = std::chrono::steady_clock;
  std::cout << "is steady: " << clock::is_steady << std::endl;
  std::cout << "period: " << clock::period::num << " / " << clock::period::den << std::endl;
}

{
  using clock = std::chrono::high_resolution_clock;
  std::cout << "is steady: " << clock::is_steady << std::endl;
  std::cout << "period: " << clock::period::num << " / " << clock::period::den << std::endl;
}

}