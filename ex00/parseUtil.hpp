#pragma once

#include <iostream>
#include <map>

std::map<time_t, double> parseCsv( const std::string &filename );

std::pair<time_t, double> parseLine(const std::string &line, char delimiter, bool max1000);
