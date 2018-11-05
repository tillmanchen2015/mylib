#include <ctime>

std::time_t t1 = std::time(nullptr);
std::this_thread::sleep_for(std::chrono::seconds(3));
std::time_t t2 = std::time(nullptr);
double s = std::difftime(t2, t1);
printf("s is %f", s);

pay attention to if plus or minus