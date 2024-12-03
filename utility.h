#include <algorithm>
#include <concepts>
#include <iterator>
#include <range/v3/algorithm/fold_right.hpp>
#include <range/v3/all.hpp>
#include <range/v3/view/concat.hpp>
#include <range/v3/view/for_each.hpp>
#include <range/v3/view/subrange.hpp>
#include <type_traits>

template <typename Func, typename Iter>
  requires(
      std::totally_ordered<std::invoke_result_t<Func, std::iter_value_t<Iter>>>)
constexpr auto minWith(Iter begin, Iter end, Func func)
    -> std::iter_value_t<Iter> {
  return *std::min_element(begin, end,
                           [&](auto a, auto b) { return func(a) < func(b); });
}

template <typename Func, std::input_iterator Iter>
constexpr auto foldr1(Func f, Iter first, Iter last) {
  return ranges::fold_right_last(ranges::make_subrange(first, last), f).value();
}

constexpr auto foldr(auto f, auto init, auto first, auto last) {
  return ranges::fold_right(ranges::make_subrange(first, last), init, f);
}

constexpr auto foldr(auto f, auto init, auto &&range) {
  return ranges::fold_right(range, init, f);
}

constexpr auto concatMap(auto f, auto &&range) {
  return range |
         ranges::views::for_each([&f](const auto &elem) { return f(elem); });
}

// constexpr auto concatMap
