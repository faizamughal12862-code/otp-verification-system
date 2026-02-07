#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>  

using namespace std;

int otpGenerator();

int main()
{
    int otp = otpGenerator();
    time_t generatedTime = time(0);
    int attempts = 5;
    
    cout << "\n=== OTP Verification ===" << endl;
    
    while (attempts > 0)
    {
        cout << "\nYour OTP: " << setfill('0') << setw(4) << otp << endl;
        cout << "Attempts left: " << attempts << "/5" << endl;
        cout << "Enter OTP: ";
        
        int input;
        cin >> input;

        time_t currentTime = time(0);
        int late = currentTime - generatedTime;

        if (late > 30)
        {
            cout << "\nOTP expired (" << late << " seconds passed)" << endl;
            cout << "Generating new OTP...\n" << endl;
            
            otp = otpGenerator();
            generatedTime = time(0);
            attempts--;
            continue;
        }
        else if (input == otp && late <= 30) 
        {
            cout << "\nLogin successful!" << endl;
            return 0;
        } 
        else 
        {
            cout << "\nWrong OTP. Try again." << endl;
            otp = otpGenerator();
            attempts--;
        }
    }

    cout << "\nAccount locked. Too many failed attempts." << endl;

    return 0;
}

int otpGenerator()
{
    srand(time(0));
    int otp = 0;

    for (int i = 0; i < 4; i++)
    {
        int num = rand();
        int digit = num % 10;
        otp = (otp * 10) + digit;
    }

    return otp;
}