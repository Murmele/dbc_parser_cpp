
#ifndef __SIGNAL_HPP__
#define __SIGNAL_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

namespace libdbc {
struct Signal {
	struct SignalValueDescriptions {
		uint32_t value;
		std::string description;
	};

	std::string name;
	bool is_multiplexed;
	uint32_t start_bit;
	uint32_t size;
	bool is_bigendian;
	bool is_signed;
	double factor;
	double offset;
	double min;
	double max;
	std::string unit;
	std::vector<std::string> receivers;
	std::vector<SignalValueDescriptions> svDescriptions;

	Signal() = delete;
	explicit Signal(std::string name,
					bool is_multiplexed,
					uint32_t start_bit,
					uint32_t size,
					bool is_bigendian,
					bool is_signed,
					double factor,
					double offset,
					double min,
					double max,
					std::string unit,
					std::vector<std::string> recievers);

	virtual bool operator==(const Signal& rhs) const;
	bool operator<(const Signal& rhs) const;
};

std::ostream& operator<<(std::ostream& out, const Signal& sig);

}

#endif // __SIGNAL_HPP__
