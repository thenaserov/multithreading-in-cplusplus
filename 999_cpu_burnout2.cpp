#include <thread>
#include <vector>
#include <iostream>
#include <cmath>
#include <random>
#include <immintrin.h>

int main() {
    unsigned int cores = std::thread::hardware_concurrency();
    if (cores == 0) cores = 4;
    
    std::cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n";
    std::cout << "█  MAXIMUM CPU STRESS TEST ACTIVATED  █\n";
    std::cout << "█  Running on " << cores << " CPU cores";
    if (cores < 10) std::cout << " ";
    std::cout << "        █\n";
    std::cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n";
    
    std::cout << "⚠️  WARNING: This will generate EXTREME heat!\n";
    std::cout << "⚠️  Ensure proper cooling or risk hardware damage!\n";
    std::cout << "⚠️  Only terminate with: kill -9 PID or hard reboot\n\n";
    
    std::vector<std::thread> workers;
    workers.reserve(cores);
    
    for (unsigned int i = 0; i < cores; ++i) {
        workers.emplace_back([i]() {
            // Multiple volatile variables to prevent optimization
            volatile double a = 1.000001 * (i + 1);
            volatile double b = 2.000002;
            volatile double c = 3.000003;
            volatile double d = 4.000004;
            volatile double e = 5.000005;
            
            // Large arrays for cache/memory stress
            volatile double arr1[1024];
            volatile double arr2[1024];
            volatile double arr3[1024];
            
            // Initialize arrays
            for (int idx = 0; idx < 1024; ++idx) {
                arr1[idx] = std::sin(idx);
                arr2[idx] = std::cos(idx);
                arr3[idx] = std::tan(idx * 0.1);
            }
            
            // INFINITE LOOP - NO ESCAPE
            while (true) {
                // HEAVY nested loops
                for (int mega = 0; mega < 1000; ++mega) {
                    for (int super = 0; super < 1000; ++super) {
                        for (int ultra = 0; ultra < 1000; ++ultra) {
                            // Extreme floating-point computations
                            a = std::sin(a) * std::cos(b) * std::tan(c) * std::asin(d) * std::acos(e);
                            b = std::sqrt(std::abs(a * b + c * d + e)) + std::pow(std::abs(a), 1.00001);
                            c = std::log(std::abs(a + b + c + d + e + 1.0)) * std::exp(a * 0.0001);
                            d = std::sinh(a) * std::cosh(b) * std::tanh(c);
                            e = std::atan2(a, b) * std::atan2(c, d);
                            
                            // Memory access patterns (cache thrashing)
                            for (int mem = 0; mem < 512; ++mem) {
                                arr1[mem] = arr1[mem] * arr2[mem] + arr3[mem];
                                arr2[mem] = arr2[mem] * arr3[mem] - arr1[mem];
                                arr3[mem] = arr3[mem] * arr1[mem] / (arr2[mem] + 0.000001);
                                
                                // Additional operations
                                arr1[mem] = std::sin(arr1[mem]);
                                arr2[mem] = std::cos(arr2[mem]);
                                arr3[mem] = std::sqrt(std::abs(arr3[mem]));
                            }
                            
                            // Integer stress operations
                            volatile long long int1 = 123456789;
                            volatile long long int2 = 987654321;
                            for (int int_ops = 0; int_ops < 1000; ++int_ops) {
                                int1 = (int1 * 6364136223846793005ULL + 1442695040888963407ULL);
                                int2 = (int2 * 1103515245 + 12345) & 0x7fffffff;
                                
                                // Bit manipulation stress
                                int1 = (int1 << 13) | (int1 >> 51);
                                int2 = (int2 ^ (int2 >> 17)) * 0x45d9f3b;
                                int2 = (int2 ^ (int2 >> 17)) * 0x45d9f3b;
                                int2 = int2 ^ (int2 >> 17);
                            }
                            
                            // More mathematical chaos
                            a = a + std::pow(b, 1.0001) - std::pow(c, 0.9999);
                            b = b * std::exp(d) / std::log(std::abs(e) + 2.0);
                            c = c + std::atan(a) * std::atan2(b, c);
                            d = std::fmod(d * 1.0000001, 1000.0);
                            e = std::remainder(e * 1.0000001, 1000.0);
                            
                            // Force all variables to be used
                            volatile double chaos = a + b + c + d + e + arr1[0] + arr2[0] + arr3[0] + int1 + int2;
                            chaos = chaos * 0.999999; // Prevent optimization
                        }
                    }
                }
            }
        });
    }
    
    std::cout << "🔥 CPU MELTDOWN INITIATED 🔥\n";
    std::cout << "Process ID: " << getpid() << "\n";
    std::cout << "To stop: sudo kill -9 " << getpid() << "\n";
    std::cout << "Or: hard reboot required\n\n";
    
    // Nuclear option: Also stress main thread
    std::thread main_stressor([]() {
        volatile double nuclear = 999999.999;
        while (true) {
            for (int apocalypse = 0; apocalypse < 1000000000; ++apocalypse) {
                nuclear = std::sin(nuclear) * std::cos(nuclear) * std::tan(nuclear);
                nuclear = std::sqrt(std::abs(nuclear)) + std::pow(std::abs(nuclear), 1.0000001);
                nuclear = std::log(std::abs(nuclear) + 1.0) * std::exp(nuclear * 0.000001);
            }
        }
    });
    
    // Join all threads (this will never return)
    for (auto &t : workers) {
        t.join();
    }
    main_stressor.join();
    
    return 0; // Never reached
}
