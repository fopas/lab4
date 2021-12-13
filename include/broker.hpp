// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_BROKER_HPP_
#define INCLUDE_BROKER_HPP_
#include <iostream>
#include <boost/regex.hpp>
#include <string>
#include "boost/filesystem.hpp"
#include <map>

class Broker{
 private:
  std::string _name;
  std::string _number;
  std::string _last_date;
  unsigned _count = 1;

 public:
  Broker(std::string& name, std::string& numb, std::string& date);
  void update(const std::string& date);
  void operator++();
  void print();
};
void print_data(std::map<std::string, std::map<std::string, Broker>> database);

#endif // INCLUDE_BROKER_HPP_