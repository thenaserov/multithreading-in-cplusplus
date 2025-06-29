# multithreading-in-cplusplus

All codes were written in C++14
I am using MSVC
New exercises should be added

makefile usage: (by contributer)
```
make #just to compile
make clean # clean the files no need after linking
make fclean # clean everything just before running make
make re # fclean and all 
```
# 🧵 C++ Multithreading Examples

This repository contains concise examples showcasing core concepts and patterns in C++ multithreading. The code is organized in small, focused files for easy understanding and experimentation. Below is an explanation of what each file demonstrates:

---

## 🧠 Basics of Thread Management

- **000_join_and_multithreading.cpp**  
  Demonstrates how to create a thread and use `.join()` to wait for its completion.

- **000_join_vs_detach.cpp**  
  Explains the difference between `join()` (blocking) and `detach()` (non-blocking).

- **000_joinable.cpp**  
  Shows how to check if a thread is joinable using `.joinable()` before calling `join()` or `detach()`.

---

## 🔄 Data Sharing and Synchronization

- **001_shared_data_and_std_atomic.cpp**  
  Introduces safe data sharing using `std::atomic` to prevent race conditions.

- **002_shared_data_and_mutexes.cpp**  
  Shows how to protect shared data using `std::mutex`.

- **003_passing_arguments.cpp**  
  Covers how to pass arguments to threads, including by value and by reference.

- **004_lock_guard.cpp**  
  Demonstrates `std::lock_guard` for automatic mutex locking and unlocking using RAII.

---

## 🧰 Thread Functions & Objects

- **005_start_a_thread_with_a_function_in_a_class.cpp**  
  Starts a thread using a member function of a class.

- **005_threads_with_callable_objects.cpp**  
  Uses functor (callable objects) to launch threads.

---

## 🧮 Practical Exercises

- **006_calculating_PI_exercise.cpp**  
  A multithreaded example of calculating π using numerical integration.

---

## 🔮 Promises, Futures & Async

- **007_promises_and_futures_function_args.cpp**  
  Introduces `std::promise` and `std::future` for thread communication via function arguments.

- **008_promises_and_futures_lambda_expr_for_promise.cpp**  
  Uses lambda functions with promises and futures.

- **009_promises_and_futures_with_exception.cpp**  
  Demonstrates exception handling with `std::promise` and `std::future`.

- **010_packaged_tasks.cpp**  
  Uses `std::packaged_task` to wrap callable objects and retrieve results asynchronously.

- **015_parallelism_using_async.cpp**  
  Shows how to use `std::async` for parallel function execution with automatic future handling.

---

## 🕰️ Thread Coordination

- **011_waiting_for_threads_with_a_bool.cpp**  
  Uses a boolean flag to signal a thread to stop or wait.

- **012_condition_variables.cpp**  
  Demonstrates `std::condition_variable` for thread synchronization.

- **012_two_threads_one_condition_variable.cpp**  
  A more practical example of two threads waiting on a shared `condition_variable`.

---

## 🧱 Thread Utilities

- **013_blocking_queue.cpp**  
  Implements a thread-safe blocking queue using mutexes and condition variables.

- **014_thread_pool.cpp**  
  A simple thread pool implementation for managing a fixed number of worker threads.

- **016_yield_vs_unyield.cpp**  
  Compares thread yielding (`std::this_thread::yield`) vs. busy-waiting.

---

## 🏁 Miscellaneous

- **999_all_the_ways_to_start_threads.cpp**  
  A summary showcasing various ways to start a thread (function pointer, lambda, functor, etc).

- **999_bonus_chunksum_async.cpp**  
  A bonus example showing how to split a large task (like summing elements) into chunks and process them asynchronously.

---

## 📌 Requirements

- C++11 or later
- A C++ compiler like GCC, Clang, or MSVC

## 📦 Building

```bash
g++ -std=c++17 -pthread <filename.cpp> -o <output_name>

After learning launching threads and shared data mangement, you can simply follow this project
to understand more of threading usages:
https://github.com/thenaserov/cpp_multithreaded_file_organizer

Also check out log_mediator_cpp:
https://github.com/thenaserov/log_mediator_cpp
