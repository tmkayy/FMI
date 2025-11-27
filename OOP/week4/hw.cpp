#include <iostream>

namespace consts {
	constexpr int SECS_IN_MINUTE = 60;
	constexpr int SECS_IN_HOUR = 60 * SECS_IN_MINUTE;
	constexpr int SECS_IN_DAY = 24 * SECS_IN_HOUR;
}


class Time {
private:
	int seconds;
	int minutes;
	int hours;

public:

	Time() : seconds(0), minutes(0), hours(0) {};

	Time(int seconds, int minutes, int hours) {
		SetSeconds(seconds);
		SetMinutes(minutes);
		SetHours(hours);
	}

	void SetSeconds(int seconds) {
		if (seconds >= 0 && seconds < 60)
			this->seconds = seconds;
		else
			this->seconds = 0;
	}

	void SetMinutes(int minutes) {
		if (minutes >= 0 && minutes < 60)
			this->minutes = minutes;
		else
			this->minutes = 0;
	}

	void SetHours(int hours) {
		if (hours >= 0 && hours < 24)
			this->hours = hours;
		else
			this->hours = 0;
	}

	int GetSeconds() const {
		return seconds;
	}

	int GetMinutes() const {
		return minutes;
	}

	int GetHours() const {
		return hours;
	}

	int ThisTimeIntoSeconds() const {
		return this->GetSeconds() + this->GetMinutes() * consts::SECS_IN_MINUTE + this->GetHours() * consts::SECS_IN_HOUR;
	}

	Time SecondsIntoTime(int secs) {
		secs %= consts::SECS_IN_DAY;
		int hrs = secs / consts::SECS_IN_HOUR;
		secs %= consts::SECS_IN_HOUR;
		int mins = secs / consts::SECS_IN_MINUTE;
		secs %= consts::SECS_IN_MINUTE;
		Time t(secs, mins, hrs);
		return t;
	}

	Time TimeUntilMidnight() {
		int secs = consts::SECS_IN_DAY - ThisTimeIntoSeconds();
		return SecondsIntoTime(secs);
	}

	Time IncreaseBy1Second() {
		int secs = ThisTimeIntoSeconds() + 1;
		Time t = SecondsIntoTime(secs);
		this->SetHours(t.hours);
		this->SetMinutes(t.minutes);
		this->SetSeconds(t.seconds);
	}

	bool DinnerTime() const {
		Time t(0, 30, 20);
		Time t2(0, 0, 22);
		int secs = ThisTimeIntoSeconds();
		return secs >= t.ThisTimeIntoSeconds() && secs <= t2.ThisTimeIntoSeconds();
	}

	bool PartyTime() const {
		return this->GetHours() >= 23
			|| this->GetHours() <= 5 ||
			(this->GetHours() == 6 && this->GetMinutes() == 0 && this->GetSeconds() == 0);
	}

	Time TimeDifference(Time& t) {
		int diff = abs(this->ThisTimeIntoSeconds() - t.ThisTimeIntoSeconds());
		return SecondsIntoTime(diff);
	}

	bool isLater(Time& t) const {
		return this->ThisTimeIntoSeconds() > t.ThisTimeIntoSeconds();
	}

	void PrintTime() const {
		if (this->GetHours() < 10)
			std::cout << '0';
		std::cout << this->GetHours() << ':';
		if (this->GetMinutes() < 10)
			std::cout << '0';
		std::cout << this->GetMinutes() << ':';
		if (this->GetSeconds() < 10)
			std::cout << '0';
		std::cout << this->GetSeconds() << std::endl;
	}
};

int main() {
	const int size = 10;
	Time times[size]{};
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (times[j].isLater(times[j + 1]))
			{
				std::swap(times[j], times[j + 1]);
			}
		}
	}
	return 0;
}