#include <cstdlib>
#include <unordered_map>
#include <vector>

void test_map_latency() {
  std::unordered_map<std::string, size_t> m;

  PROFILE_START("map total");
  
    PROFILE_START("map insert 10");
      for (size_t i = 0; i < 10; ++i) {
        m.emplace(std::to_string(i), i);
      }
      PROFILE_STOP("map insert 10");
  
    PROFILE_ONCE("map erase 10",
      for (size_t i = 0; i < 10; ++i) { 
        m.erase(std::to_string(i)); 
      }
    );
  PROFILE_STOP("map total");
}


int main() {

  PROFILE_RUN_ALL(1000, 100, 
    test_map_latency();
  );

  
  PROFILE_RUN("rand test", 1000, 100, 
    std::srand(__loop); 
    std::rand();
  );

  std::vector<std::string> v;
  for (int loops = 0; loops < 1100; ++loops) {
    PROFILE_START("vec total");
      PROFILE_START("vec insert 10");
        for (size_t i = 0; i < 10; ++i) {
          v.emplace_back(std::to_string(i));
        }
      PROFILE_STOP("vec insert 10");
      
      PROFILE_ONCE("vec erase 10",
        for (size_t i = 0; i < 10; ++i) { 
          v.erase(v.begin()); 
        }
      );
    PROFILE_STOP("vec total");

    if (loops < 1000) {
      PROFILE_CLEAR("vec total");
      PROFILE_CLEAR("vec insert 10");
      PROFILE_CLEAR("vec erase 10");
    }
  }
  
 
  const auto [min, avg, max] = profile::get_latency(20, 10, sqrt, 3.14);
  std::cout << "Sqrt latency usec:" << std::endl;
  std::cout << "Min: " << min / 1000 << std::endl;
  std::cout << "Avg: " << avg / 1000 <<std::endl;
  std::cout << "Max: " << max / 1000 <<std::endl;

  return 0;
}
