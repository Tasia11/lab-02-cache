// Copyright 2020 Anastasiya Osipova anstasiyaosipova2001@gmail.com

#include <header.hpp>
#include <algorithm>
#include <random>

Exploration::Exploration()
{
  for (size_t i = 1.0 / 2 * cache_size[0]; i < 3.0 / 2 * cache_size[2];
       i *= 2)
  {
    buffer.push_back(i);
  }
  buffer.push_back(3.0 / 2 * cache_size[2]);
}
void Exploration::Direct()
{
  travel_variant = "direct";
  int k;
  if (!time.empty())
  {
    time.clear();
  }
  for (const size_t& i : buffer)
  {
    int* arr = new int[i / 4];
    for (size_t j = 0; j < i / 4; j += 16)
    {
      k = arr[j];
    }
    clock_t start_travel = clock();
    for (size_t n = 0; n < 1000; ++n)
    {
      for (size_t j = 0; j < i / 4; j += 16)
      {
        k = arr[j];
      }
    }
    clock_t end_travel = clock();
    time.push_back(static_cast<double>(end_travel-start_travel)/CLOCKS_PER_SEC * 1000);
    delete[] arr;
    ++k;
  }
}

void Exploration::Reverse()
{
  travel_variant = "reverse";
  int k;
  if (!time.empty())
  {
    time.clear();
  }
  for (const size_t& i : buffer)
  {
    int* arr = new int[i / 4];
    for (size_t j = i / 4; j > 0; j -= 16)
    {
      k = arr[j - 1];
    }
    clock_t start_travel = clock();
    for (size_t n = 0; n < 1000; ++n)
    {
      for (size_t j = i / 4; j > 0; j -= 16)
      {
        k = arr[j - 1];
      }
    }
    clock_t end_travel = clock();
    time.push_back(static_cast<double>(end_travel-start_travel)/CLOCKS_PER_SEC * 1000);
    delete[] arr;
    ++k;
  }
}
void Exploration::Random()
{
  travel_variant = "random";
  int k;
  if (!time.empty())
  {
    time.clear();
  }
  for (const size_t& i : buffer)
  {
    std::vector<size_t> rand;
    int* arr = new int[i / 4];
    for (size_t j = 0; j < i / 4; j += 16)
    {
      k = arr[j];
      rand.push_back(j);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(rand.begin(), rand.end(), gen);
    clock_t start_travel = clock();
    for (size_t n = 0; n < 1000; ++n)
    {
      for (const auto& index : rand)
      {
        k = arr[index];
      }
    }
    clock_t end_travel = clock();
    time.push_back(static_cast<double>(end_travel-start_travel)/CLOCKS_PER_SEC * 1000);
    delete[] arr;
    ++k;
  }
}
std::ostream& operator<<(std::ostream& out, const Exploration& c)
{
  out << "investigation:\n"
      << "  travel_variant: " << c.travel_variant << "\n"
      << "  experiments:\n";
  for (size_t i = 0; i < c.buffer.size(); ++i) {
    out << "- experiment: \n";
    out << "      number: " << i + 1 << "\n";
    out << "      input_data:\n";
    out << "        buffer_size: " << c.buffer[i] / 1024 << "KB\n";
    out << "      results:\n";
    out << "        duration: " << c.time[i] << "ms\n";
  }
  return out;
}
