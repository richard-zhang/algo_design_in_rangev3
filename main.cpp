#include "utility.h"
#include <vector>
#include <array>
#include <iostream>

int main()
{
    const std::array<int, 5> arr = {5,4,3,2,9};
    std::cout << foldr1(std::plus{}, arr.begin(), arr.end()) << std::endl;
    std::cout << foldr(std::plus{}, 0, arr.begin(), arr.end()) << std::endl;

    auto range = ranges::views::iota(1, 11) 
        | ranges::views::transform([](int n) { return n * n; });

    // Directly convert the range to a vector
    std::vector<int> vec = ranges::to<std::vector<int>>(range);
    // auto r2 = ranges::views::all({1, 2, 3, 5});

    std::cout << concatMap([](int x){return ranges::views::iota(1, x);}, std::vector<int>{5,4,8,9,1}) << std::endl;

    auto hello = concatMap([](int a){return std::vector<int>{a, a};}, ranges::views::all(arr));
    std::cout << hello << std::endl;
    
    auto i = ranges::empty_view<std::string>{};
    std::vector<std::string> his_face{"this", "is", "his", "face"};
    std::vector<std::string> another_mess{"another", "fine", "mess"};
    auto a = std::vector<std::string>{"hel"};
    auto i2 = ranges::views::concat(ranges::views::all(a), i);
    return 0;
}