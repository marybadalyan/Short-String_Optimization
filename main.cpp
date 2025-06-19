#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;



void test_short_strings(size_t count) {
    vector<string> vec;
    vec.reserve(count);

    auto start = high_resolution_clock::now();

    for (size_t i = 0; i < count; ++i) 
        vec.emplace_back("shortshortshort"); // <15 chars 

    auto end = high_resolution_clock::now();
    cout << "SSO strings took: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}


void test_long_strings(size_t count) {
    vector<string> vec;
    vec.reserve(count);

    auto start = high_resolution_clock::now();

    for (size_t i = 0; i < count; ++i)
        vec.emplace_back("shortshortshort+1"); // > 15 chars

    auto end = high_resolution_clock::now();
    cout << "Long strings took: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}




int main() {
    size_t n = 1'000'000;



    std::string s = "Hi";
    // to make sure sso is enabled we can check if the actual string address 
    // is the same as the str objects adress if tey are withig 64 bytes of each other
    // then SSO is in effect, otherwise it is not.
    
    const void* str_ptr = static_cast<const void*>(s.c_str());
    const void* obj_ptr = static_cast<const void*>(&s);

    std::cout << "Object address:   " << obj_ptr << '\n';
    std::cout << "Data address:     " << str_ptr << '\n';

    ptrdiff_t diff = (char*)str_ptr - (char*)obj_ptr;

    if (std::abs(diff) < 64) {
        std::cout << "✅ SSO is in effect\n";
    } else {
        std::cout << "❌ SSO not in effect (heap used)\n";
    }


    test_short_strings(n);
    test_long_strings(n);


    std::cout << "Long string is 1 caracter longer than short string.\n";


    return 0;
}
