#pragma once

//#include <stdio.h>

enum LogPriority
{
	TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
};

class Logger
{
private:
	static LogPriority priority;
	static const HANDLE hConsole;

public:
	static void set_priority(LogPriority new_priority) {
		priority = new_priority;
	}

	template<typename... Args>
	static void Trace(const char* message) {
		if (priority <= TracePriority) {
			SetConsoleTextAttribute(hConsole, 8);
			std::cout << "[.]  |  " << message << std::endl;
		}
	}

	template<typename... Args>
	static void Debug(const char* message) {
		if (priority <= DebugPriority) {
			SetConsoleTextAttribute(hConsole, 9);
			std::cout << "[#]  |  " << message << std::endl;
		}
	}

	template<typename... Args>
	static void Info(const char* message) {
		if (priority <= InfoPriority) {
			SetConsoleTextAttribute(hConsole, 7);
			std::cout << "[i]  |  " << message << std::endl;
		}
	}

	template<typename... Args>
	static void Warn(const char* message) {
		if (priority <= WarnPriority) {
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "[*]  |  " << message << std::endl;
		}
	}

	template<typename... Args>
	static void Error(const char* message) {
		if (priority <= ErrorPriority) {
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "[!]  |  " << message << std::endl;
		}
	}

	template<typename... Args>
	static void Critical(const char* message) {
		if (priority <= CriticalPriority) {
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "[!!]  |  " << message << std::endl;
		}
	}


};

LogPriority Logger::priority = InfoPriority;
const HANDLE Logger::hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 