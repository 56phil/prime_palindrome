/*
 This C++ program uses the Boost library to generate and test large palindromic
numbers for primality.

Here's a summary of what each function does:

1. `main()`: This is the main function where the program starts. It initializes
a large number `lim` and then iterates from `lim - 1000` to `lim`. For each
number `a` in this range, it iterates through the digits 0 to 9. For each digit
`b`, it makes a palindrome from `a` and `b` and checks if this palindrome is a
prime number. If it is, it prints the number.

2. `isPrime()`: This function uses the Miller-Rabin primality test from the
Boost library to check if a number is prime. It takes a number `a` and a number
`n` of iterations for the test. It returns `true` if `a` is prime and `false`
otherwise.

3. `makePalindrome()`: This function takes a number `i` and a digit `n`, and
modifies `i` to be a palindrome made from `i`, `n`, and the reverse of `i`. It
first converts `i` to a string and reverses it. It then concatenates `i`, `n`,
and the reversed string to form a palindrome, and updates `i` to this new
number.

The program uses the Boost library's multiprecision and Miller-Rabin modules to
handle and operate on large numbers that are beyond the range of built-in C++
types. The Miller-Rabin test is a probabilistic algorithm for determining if a
given number is prime.
 */

#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <iostream>
#include <string>

using boost::multiprecision::cpp_int;

bool isPrime(const cpp_int &, const int);
void group(const cpp_int &, std::string &);
void makePalindrome(cpp_int &, int n);

int main() {
  cpp_int lim(
      "987654321012345678909876543210123456789876543212345678900000000");
  for (cpp_int a(lim - 1000); a < lim; a++) {
    for (int b(0); b <= 9; b++) {
      cpp_int p(a);
      makePalindrome(p, b);
      if (isPrime(p, 19)) {
        std::cout << p << '\n';
      }
    }
  }

  return 0;
}

bool isPrime(const cpp_int &a, const int n) {
  return boost::multiprecision::miller_rabin_test(a, n);
}

void makePalindrome(cpp_int &i, const int n) {
  std::string rev = i.str();
  char c(n | 0x30);
  std::reverse(rev.begin(), rev.end());
  cpp_int p(i.str() + c + rev);
  i = p;
}
