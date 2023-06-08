# Palindromic Prime Generator

This repository contains a C++ program that generates and tests large palindromic numbers for primality. The program uses the Boost library's multiprecision and Miller-Rabin modules to handle and operate on large numbers that are beyond the range of built-in C++ types.

## Program Overview

The program consists of three main functions:

1. `main()`: The main function where the program starts. It initializes a large number `lim` and then iterates from `lim - 1000` to `lim`. For each number `a` in this range, it iterates through the digits 0 to 9. For each digit `b`, it makes a palindrome from `a` and `b` and checks if this palindrome is a prime number. If it is, it prints the number.

2. `isPrime()`: This function uses the Miller-Rabin primality test from the Boost library to check if a number is prime. It takes a number `a` and a number `n` of iterations for the test. It returns `true` if `a` is prime and `false` otherwise.

3. `makePalindrome()`: This function takes a number `i` and a digit `n`, and modifies `i` to be a palindrome made from `i`, `n`, and the reverse of `i`. It first converts `i` to a string and reverses it. It then concatenates `i`, `n`, and the reversed string to form a palindrome, and updates `i` to this new number.

## Dependencies

The program requires the Boost library. You can install it on Ubuntu with:

```bash
sudo apt-get install libboost-all-dev
```

## Compilation

You can compile the program with g++:

```bash
g++ -o palindrome_prime main.cpp -lboost_system -lboost_filesystem
```

## Usage

After compilation, you can run the program with:

```bash
./palindrome_prime
```

The program will print the palindromic prime numbers it finds.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
