#pragma once
#include <string>
#include <vector>
#include <utility>
#define DASH '-'

std::pair<unsigned long long, unsigned long long> convertID(const std::string& range);

unsigned long long validate(unsigned long long first, unsigned long long last);