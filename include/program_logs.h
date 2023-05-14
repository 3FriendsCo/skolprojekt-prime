#ifndef PROGRAM_LOGS_H
#define PROGRAM_LOGS_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <memory>

class ProgramLog
{
private:
    static std::string log_file_path;
    static std::shared_ptr<ProgramLog> instance;
    std::ofstream log_file;

    ProgramLog()
    {
        if (log_file_path.empty())
        {
            auto timestamp = create_timestamp_for_filename();
            std::stringstream path;
            path << "./build/logs/Log-" << timestamp << ".log";
            log_file_path = path.str();
        }

        log_file.open(log_file_path, std::ios::app);
        if (!log_file)
        {
            std::cerr << "Error while opening log file for writing\n";
            throw std::runtime_error("File open error");
        }
    }

    std::string create_timestamp()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::chrono::duration<double> elapsed_seconds = now - std::chrono::system_clock::from_time_t(in_time_t);
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds).count() % 1000;

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y.%m.%d-%H.%M.%S") << "." << std::setfill('0') << std::setw(3) << milliseconds;
        return ss.str();
    }

    std::string create_timestamp_for_filename()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y.%m.%d-%H.%M");
        return ss.str();
    }

public:
    static std::shared_ptr<ProgramLog> get_instance()
    {
        if (!instance)
        {
            instance = std::shared_ptr<ProgramLog>(new ProgramLog());
        }
        return instance;
    }

    ~ProgramLog()
    {
        if (log_file.is_open())
        {
            log_file.close();
        }
    }

    void log_start_message()
    {
        if (log_file.tellp() == 0)
        {
            auto timestamp = create_timestamp();
            log_file << std::endl
                     << std::endl
                     << "------" << std::endl
                     << timestamp << " Log started\n";
        }
    }

    void log_message(const std::string &message)
    {
        if (!log_file)
        {
            std::cerr << "Log file not open for writing\n";
            throw std::runtime_error("File write error");
        }

        auto timestamp = create_timestamp();
        log_file << timestamp << " " << message << "\n";
        if (log_file.fail())
        {
            std::cerr << "Error while writing to log file\n";
            throw std::runtime_error("File write error");
        }
    }
};

// Initialize static members outside the class definition
std::string ProgramLog::log_file_path = "";
std::shared_ptr<ProgramLog> ProgramLog::instance = nullptr;

#endif /* PROGRAM_LOGS_H */
