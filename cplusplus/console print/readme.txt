tinyformat.h

1. printf with string
    std::string weekday = "Wednesday";
    const char* month = "July";
    size_t day = 27;
    long hour = 14;
    int min = 44;

    tfm::printf("%s, %s %d, %.2d:%.2d\n", weekday, month, day, hour, min);

2. std::stirng format
    std::string date = tfm::format("%s, %s %d, %.2d:%.2d\n",
                               weekday, month, day, hour, min);

3. printf with new line : tfm::printfln()

4. use %s as common specifier to print. It's safe. 

5. %s can output boo variable

6. wrapping fmt in function

    template<typename... Args>
    void error(int code, const char* fmt, const Args&... args)
    {
        std::cerr << "error (code " << code << ")";
        tfm::format(std::cerr, fmt, args...);
    }                                    
