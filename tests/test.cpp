// Copyright 2020 Anastasiya Osipova anstasiyaosipova2001@gmail.com

#include <gtest/gtest.h>

TEST(Example, EmptyTest) {
    Exploration cache;
  cache.Direct();
  std::cout << cache;
  cache.Reverse();
  std::cout << cache;
  cache.Random();
  std::cout << cache;
    EXPECT_TRUE(true);
}
