# OTP Verification System

A simple C++ program that simulates an OTP (One-Time Password) verification system.

## Features

- Generates random 4-digit OTP
- 30-second expiry timer
- 5 attempts limit
- Auto-generates new OTP on expiry
- Account lockout after max attempts

## How to Run
```bash
g++ main.cpp -o otp
./otp
```

## Technologies Used

- C++
- Standard Library (`<iostream>`, `<ctime>`, `<cstdlib>`, `<iomanip>`)

## Sample Output
```
=== OTP Verification ===

Your OTP: 1234
Attempts left: 5/5
Enter OTP: 1234

Login successful!
```

## Learning Outcomes

- Random number generation
- Time-based logic
- Loop control structures
- Input validation
