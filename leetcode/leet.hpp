#include <algorithm>
#include <array>
#include <deque>
#include <exception>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#pragma once
// Heavily inspired by (actually copied from):
// https://www.scs.stanford.edu/~dm/blog/va-opt.html

#define PARENS ()

#define EXPAND(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__

/**
 * @brief Macro that applies `macro` on all arguments.
 *
 * @example:
 * ```cpp
 * #define MK_STRUCT(name) struct name {};
 # FOR_EACH(MK_STRUCT, S1, S2, S3)
 * ```
 * expands to:
 * ```cpp
 * struct S1 {};
 * struct S2 {};
 * struct S3 {};
 * ```
 */
#define FOR_EACH(macro, ...)                                                   \
  __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...)                                        \
  macro(a1) __VA_OPT__(FOR_EACH_AGAIN PARENS(macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER

/**
 * @brief For each macro, but gives the called macro an `arg` argument +
 * iterates over the rest.
 */
#define FOR_EACH_ARG(macro, arg, ...)                                          \
  __VA_OPT__(EXPAND(FOR_EACH_HELPER_ARG(macro, arg, __VA_ARGS__)))
#define FOR_EACH_HELPER_ARG(macro, arg, a1, ...)                               \
  macro(arg, a1) __VA_OPT__(FOR_EACH_AGAIN_ARG PARENS(macro, arg, __VA_ARGS__))
#define FOR_EACH_AGAIN_ARG() FOR_EACH_HELPER_ARG

/**
 * @brief For each macro, but gives the called macro `arg0` and `arg1` arguments
 * + iterates over the rest.
 */
#define FOR_EACH_2ARG(macro, arg0, arg1, ...)                                  \
  __VA_OPT__(EXPAND(FOR_EACH_HELPER_2ARG(macro, arg0, arg1, __VA_ARGS__)))
#define FOR_EACH_HELPER_2ARG(macro, arg0, arg1, a1, ...)                       \
  macro(arg0, arg1, a1)                                                        \
      __VA_OPT__(FOR_EACH_AGAIN_2ARG PARENS(macro, arg0, arg1, __VA_ARGS__))
#define FOR_EACH_AGAIN_2ARG() FOR_EACH_HELPER_2ARG

namespace detail {
template <class T>
  requires(std::is_floating_point_v<T> || std::is_integral_v<T>)
inline void strConcat(std::string &out, T v) {
  out.append(std::to_string(v));
}

inline void strConcat(std::string &out, bool v) {
  out.append(v ? "true" : "false");
}

inline void strConcat(std::string &out, const char *v) {
  if (v == nullptr)
    throw std::domain_error("strConcat called with nullptr");
  out.append(std::string(v));
}

template <typename U, typename V>
  requires(std::is_trivially_copyable_v<U> && std::is_trivially_copyable_v<V>)
inline void strConcat(std::string &out, std::pair<U, V> pair) {
  out += "<";
  strConcat(out, pair.first);
  out += ", ";
  strConcat(out, pair.second);
  out += ">";
}
} // namespace detail

template <typename... T> std::string strConcat(T &&...elements) {
  std::string out;
  (detail::strConcat(out, std::forward<T>(elements)), ...);
  return out;
}

/**
 * Replaces all occurrences of `from` with `to`.
 * @param str The source string.
 * @param from The pattern to be erased.
 * @param to The pattern to be put instead of `from`.
 */
constexpr void strReplaceAll(std::string &str, const std::string &from,
                             const std::string &to) {
  // Thanks to: https://stackoverflow.com/a/3418285.
  if (from.empty())
    return;
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // In case 'to' contains 'from', like replacing
                              // 'x' with 'yx'
  }
}

/**
 * Splits a string by a delimiter.
 * @param str The string to split.
 * @param delimiter A string, that is used to separate the substrings.
 * @return A vector of separated strings.
 */
constexpr std::vector<std::string> strSplit(const std::string_view str,
                                            const std::string &delimiter) {
  std::vector<std::string> result;
  size_t end_pos = 0;
  size_t start_pos = 0;
  while ((end_pos = str.find(delimiter, start_pos)) != std::string::npos) {
    result.emplace_back(str.substr(start_pos, end_pos - start_pos));
    start_pos = end_pos + delimiter.length();
  }
  result.emplace_back(str.substr(start_pos));
  return result;
}

#define CALL_TEST(curr)                                                        \
  test_##curr(test_context);                                                   \
  if constexpr (curr + 1 < _test_count) {                                      \
    CALL_TESTS(curr + 1)                                                       \
  };

#define ASSERT_EQUAL(expected, actual)                                         \
  if ((expected) != (actual)) {                                                \
    throw std::logic_error(strConcat(                                          \
        "At ", __func__, " values not equal:\n\t\tIn line ", __LINE__, ": ",   \
        #expected, " != ", #actual, "(", expected, "!=", actual, ")"));         \
  }

int test_counter = 0;
std::function<void()> tests[1000]{};

int main() {
  for (int i = 0; i < test_counter; i++) {
    tests[i]();
  }
  std::cout << "All " << test_counter << " tests passed!";
}

#define TESTS() void tests(std::vector<std::function<void()>> vec)
#define TEST(num)                                                              \
  void test_##num();                                                           \
  auto _lol_##num = tests[test_counter++] = test_##num;                        \
  void test_##num()
