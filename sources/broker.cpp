// Copyright 2021 Your Name <your_email>

#include <stdexcept>

#include <broker.hpp>

Broker::Broker(std::string& name, std::string& numb, std::string& date)
    : _name(name),
      _number(numb),
      _last_date(date)
{
}

void Broker::update(const std::string& date){
  if (_last_date < date) _last_date = date;
}

void Broker::operator++() {
  ++_count;
}

void Broker::print(){
  std::cout << "broker: " << _name << " number of accounts: "
            << _number << " number of files: " << _count <<
      " last date: " << _last_date << "\n";
}

void print_data(std::map<std::string, std::map<std::string, Broker>> database) {
  for (auto& pair : database) {
    for (auto& broker : pair.second) broker.second.print();
  }
}