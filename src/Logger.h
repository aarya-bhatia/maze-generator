#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>

struct Logger
{
    static std::string getCurrentDateTime(const std::string &s)
    {
        auto t = std::time(nullptr);
        auto tm = *localtime(&t);

        std::ostringstream oss;
        if (s == "now")
            oss << std::put_time(&tm, "%d-%m-%Y %X");
        else if (s == "date")
            oss << std::put_time(&tm, "%d-%m-%Y");
        return oss.str();
    }

    static void log(const char *message)
    {
        std::string filePath = "logs/" + getCurrentDateTime("date") + ".txt";
        std::string now = getCurrentDateTime("now");
        std::ofstream ofs(filePath.c_str());
        if (ofs)
        {
            ofs << now << ":\t" << message << '\n';
        }
        ofs.close();
    }
};