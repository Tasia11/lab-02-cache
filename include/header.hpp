// Copyright 2020 Anastasiya Osipova anstasiyaosipova2001@gmail.com

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class Exploration {
 public:
  Exploration();
  void Direct();
  void Reverse();
  void Random();
  friend std::ostream& operator<<(std::ostream& out,
                                  const Exploration& c);

 private:
  std::string travel_variant;
  const std::vector<size_t> cache_size = {64 * 1024, 256 * 1024, 3072 * 1024};
  std::vector<size_t> buffer;
  std::vector<double> time;
};

#endif  // INCLUDE_HEADER_HPP_

