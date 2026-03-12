# C++ Modules 

> Ten progressive C++ modules covering the full transition from C to modern OOP — implemented from scratch without the STL until the final modules explicitly require it.

![language](https://img.shields.io/badge/language-C%2B%2B98-blue)

---

## Table of Contents

- [Overview](#overview)
- [Module Breakdown](#module-breakdown)
- [Notable Implementations](#notable-implementations)
- [Key C++ Concepts Practised](#key-c-concepts-practised)
- [Getting Started](#getting-started)
- [Scale](#scale)
- [Engineering Notes](#engineering-notes)

---

## Overview

This repository is a structured progression through C++ as a language and object-oriented systems design as a discipline. Each module introduces a specific set of language features and requires implementing non-trivial programs that exercise those features under strict constraints — no `using namespace std`, no C-style casts after cpp6, Orthodox Canonical Form enforced on every class.

The constraint that matters most from an engineering perspective: **the STL is forbidden until cpp8**. Every data structure, algorithm, and utility implemented before that point is built manually, which forces a genuine understanding of the mechanics rather than interface usage.

---

## Module Breakdown

| Module | Core topic | Key exercise |
|---|---|---|
| **cpp0** | Namespaces, classes, streams, `const`, `static` | `PhoneBook` — class-based contact store with formatted I/O |
| **cpp1** | `new`/`delete`, references, pointers-to-members | Memory allocation patterns; reference vs pointer semantics |
| **cpp2** | Operator overloading, Orthodox Canonical Form | `Fixed` — Q8 fixed-point arithmetic with full operator set |
| **cpp3** | Inheritance, constructor/destructor chaining | `ClapTrap → ScavTrap → FragTrap` — multi-level hierarchy |
| **cpp4** | Subtype polymorphism, abstract classes, interfaces | `Animal` hierarchy with pure virtual methods; deep vs shallow copy |
| **cpp5** | Exception handling, nested exception classes | `Bureaucrat` / `AForm` hierarchy with grade-gated `try`/`catch` |
| **cpp6** | C++ casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`) | `ScalarConverter` — runtime type detection and explicit conversion |
| **cpp7** | Function templates, template specialisation | `swap`, `min`, `max`; `iter` — generic array walker with function pointer |
| **cpp8** | Templated containers, iterators, STL algorithms | `Span` — capacity-bounded integer container with `shortestSpan`/`longestSpan` |
| **cpp9** | Full STL (`map`, `stack`, `vector`, `deque`) | Bitcoin exchange, RPN evaluator, Ford-Johnson sort |

---

## Notable Implementations

### Fixed-Point Arithmetic — cpp2

`Fixed` implements a Q8 fixed-point number using a raw `int` with an 8-bit fractional part. Conversions to/from `int` and `float` use bitshift arithmetic (`num >> fractional_bits`, `num * (1 << fractional_bits)`). The full Orthodox Canonical Form is implemented alongside a complete arithmetic and comparison operator set, making `Fixed` usable in expressions like a primitive type.

### ScalarConverter — cpp6

A non-instantiable utility class (private constructor) that detects the scalar type of a string literal at runtime — `char`, `int`, `float`, or `double` — and converts it to all four types using C++ explicit casts. Handles edge cases: non-displayable chars, pseudo-literals (`nan`, `+inf`, `-inf`), overflow to `impossible`. Uses `std::stringstream` for type-safe parsing rather than `atoi`/`atof`.

### RPN Evaluator — cpp9/ex01

Stack-based evaluator using `std::stack<int>`. Input validation rejects non-digit, non-operator characters and malformed sign sequences at construction time. The `solve()` method processes the expression left-to-right: digits are pushed, operators pop two operands, compute, and push the result. Division-by-zero and operand-count errors are caught before any operation is attempted.

### Bitcoin Exchange — cpp9/ex00

Loads a historical BTC/USD rate CSV into a `std::map<string, string>` at construction. For each input date, uses `lower_bound` to find the closest earlier date when an exact match doesn't exist — correct handling of sparse time-series data. Full date validation includes calendar rules (leap years, month lengths), Bitcoin's launch date (2009-01-03), and future-date detection via `std::localtime`.

### Ford-Johnson Sort — cpp9/ex02

`PmergeMe` implements the merge-insertion sort algorithm (Ford-Johnson) — one of the theoretically optimal comparison-sort algorithms for small inputs — templated to run on both `std::vector<int>` and `std::deque<int>` from a single implementation. Uses `gettimeofday` to measure and compare per-container sort time. The algorithm divides the input into adjacent power-of-2 groups, pairs elements to establish a sorted large-element sequence, then inserts small elements using binary search with Jacobsthal-number-ordered insertion to minimise comparisons.

### Exception Hierarchy — cpp5

`Bureaucrat` holds a `const` grade in range [1, 150]. `GradeTooHighException` and `GradeTooLowException` are nested classes inheriting `std::exception`, thrown from the constructor and grade-mutation methods. `AForm` (abstract) defines a signing/execution grade contract; concrete forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) inherit it and implement `execute()`. The `Bureaucrat::signForm` / `executeForm` methods catch and re-report form-level exceptions.

### Span — cpp8

Capacity-bounded integer container backed by `std::vector<int>`. `shortestSpan` sorts a copy and finds the minimum adjacent difference; `longestSpan` returns `max - min`. `addManyNums` accepts an iterator range, enabling bulk insertion from any compatible container. Throws on capacity overflow and on calling span functions with fewer than two elements.

---

## Key C++ Concepts Practised

| Concept | Where |
|---|---|
| Orthodox Canonical Form (constructor, copy constructor, copy assignment, destructor) | Every class from cpp2 onwards |
| Operator overloading (`+`, `-`, `*`, `/`, `<<`, `>>`, `<`, `>`, `==`, `!=`, `++`, `--`) | `Fixed` (cpp2) |
| Pure virtual functions / abstract classes | `Animal`, `AForm` (cpp4, cpp5) |
| Nested exception classes | `Bureaucrat`, `Form` (cpp5) |
| C++ casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`) | cpp6 |
| Function templates and specialisation | cpp7 |
| Class templates with STL container traits | `PmergeMe` (cpp9) |
| Iterator protocol and range insertion | `Span` (cpp8) |
| `std::map::lower_bound` for nearest-key lookup | `BitcoinExchange` (cpp9) |
| Stack-based expression evaluation | `RPN` (cpp9) |

---

## Getting Started

### Requirements

- `g++` with `-std=c++98` support
- GNU Make

### Build & Run

Each exercise has its own `Makefile`:

```sh
cd cpp9/ex02
make
./PmergeMe 3 5 9 7 4 2 6 1 8
```

```sh
cd cpp9/ex00
make
./btc input.txt
```

```sh
cd cpp9/ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

Standard Makefile targets across all exercises:

```sh
make        # build
make clean  # remove object files
make fclean # remove object files and binary
make re     # fclean + rebuild
```

---

## Scale

- **10 modules**, **30+ exercises**
- **156 source files** (`.cpp` + `.hpp`)
- **~5,700 lines of C++**
- **128 commits**

---

## Engineering Notes

**Orthodox Canonical Form is enforced as a discipline, not a formality.**
Every class defines all four canonical members explicitly. This forces consistent thinking about object ownership and copy semantics — particularly relevant for classes that manage heap allocations or hold `const` members (where the copy assignment operator requires careful design).

**No STL until cpp8 is a meaningful constraint.**
Writing `Fixed`, `Span`, and the exception hierarchies without STL utilities makes the cost of each abstraction visible. By the time `std::map` and `std::stack` appear in cpp9, their internal behaviour is already understood rather than assumed.

**Template design requires separating interface from implementation.**
`PmergeMe` exposes all its logic as `static` template methods in a `.tpp` file included by the header, since template definitions must be visible at instantiation. The class itself is non-instantiable — a deliberate choice to keep it as a pure algorithm namespace.

**`lower_bound` on a sorted `std::map` is the correct tool for sparse time-series lookup.**
Using `find` would miss dates not in the dataset. `lower_bound` returns the first key ≥ the query; decrementing the iterator gives the closest earlier date. This is the idiomatic pattern for range-based lookups in ordered associative containers.

---

## License

This project is licensed under the MIT License.

---

[↑ Back to top](#c-modules--42)
