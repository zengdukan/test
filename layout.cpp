#include <cstdint>
#include <tuple>
#include <map>
#include <vector>
#include <cmath>
#include <stdint.h>
#include <assert.h>

static void calcLayout(uint32_t number, uint32_t &row, uint32_t &col) {
  static std::map<uint32_t, std::tuple<uint32_t, uint32_t>> default_layout = {
      {1, {1, 1}},  {2, {1, 2}},  {3, {2, 2}},  {4, {2, 2}},
      {5, {2, 3}},  {6, {2, 3}},  {7, {3, 3}},  {8, {3, 3}},
      {9, {3, 3}},  {10, {3, 4}}, {11, {3, 4}}, {12, {3, 4}},
      {13, {4, 4}}, {14, {4, 4}}, {15, {4, 4}}, {16, {4, 4}}};
  if (default_layout.find(number) != default_layout.end()) {
    row = std::get<0>(default_layout[number]);
    col = std::get<1>(default_layout[number]);
    return;
  }

  // > 16
  row = std::ceil(std::sqrt(number));
  col = row;
}

static void calcLayout1(uint32_t number, uint32_t &row, uint32_t &col) {
  static std::map<uint32_t, std::vector<uint32_t>> default_layout = {
      {1, {1, 1}},  {2, {1, 2}},  {3, {2, 2}},  {4, {2, 2}},
      {5, {2, 3}},  {6, {2, 3}},  {7, {3, 3}},  {8, {3, 3}},
      {9, {3, 3}},  {10, {3, 4}}, {11, {3, 4}}, {12, {3, 4}},
      {13, {4, 4}}, {14, {4, 4}}, {15, {4, 4}}, {16, {4, 4}}};
  if (default_layout.find(number) != default_layout.end()) {
    row = default_layout[number][0];
    col = default_layout[number][1];
    return;
  }

  // > 16
  row = std::ceil(std::sqrt(number));
  col = row;
}

int main(int argc, char* argv[])
{
    uint32_t row = 0, col = 0;
    uint32_t row1 = 0, col1 = 0;

    for (uint32_t i = 1; i <= 16; i++)
    {
        calcLayout(i, row, col);
        calcLayout(i, row1, col1);

        assert(row == row1);
        assert(col == col1);
    }
    return 0;
}