#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>
#include <chrono>

int main() {
    int minutes{ 0 }, seconds{0};
    std::cout << "Enter the number of minutes and seconds to set the timer(MM SS): ";
    std::cin >> minutes >> seconds;

    int totalSeconds = minutes * 60 + seconds;
    std::time_t startTime = std::time(nullptr);

    int remainingSeconds{ 0 };
    do {
        std::time_t currentTime = std::time(nullptr);
        int elapsedSeconds = (currentTime - startTime);
        remainingSeconds = totalSeconds - elapsedSeconds;

        if (remainingSeconds < 1) {
            std::cout << "DING! DING! DING!" << std::endl;
            break;
        }

        std::cout << std::setw(2) << std::setfill('0') << remainingSeconds / 60 << ":" 
                  << std::setw(2) << std::setfill('0') << remainingSeconds % 60 << "\r";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    } while (remainingSeconds > 0);

    return 0;
}
