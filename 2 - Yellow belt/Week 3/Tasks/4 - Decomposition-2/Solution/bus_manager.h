#ifndef BUS_MANAGER_H_INCLUDED
#define BUS_MANAGER_H_INCLUDED

#include <string>
#include <vector>
#include <utility>
#include <map>

#include "query.h"
#include "responses.h"

class BusManager {
public:
    BusManager();

	void AddBus(const std::string &bus, const std::vector < std::string > &stops);

	BusesForStopResponse GetBusesForStop(const std::string &stop) const;
	StopsForBusResponse GetStopsForBus(const std::string &bus) const;

	AllBusesResponse GetAllBuses() const;

private:
	std::map < std::string , std::vector < std::string > > buses_to_stops;
	std::map < std::string , std::vector < std::string > > stops_to_buses;
};


#endif // BUS_MANAGER_H_INCLUDED
