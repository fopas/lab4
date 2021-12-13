#include <broker.hpp>
namespace f = boost::filesystem;

int main(int argc, char* argv[]) {
  f::path path;
  if (argc < 2) {
    path = f::current_path();
  } else {
    path = argv[1];
  }

  const boost::regex temp{"balance_[0-9]{8}_[0-9]{8}\\.txt"};
  std::map<std::string, std::map<std::string, Broker>> database;

  for (const auto& p : f::recursive_directory_iterator(path)) {
    auto f_name = p.path().filename().string();
    auto b_name = p.path().parent_path().filename().string();

    if (f::is_regular_file(p) &&
        boost::regex_match(f_name, temp)) {
      std::cout << f_name << std::endl;
      std::string numb = f_name.substr(8, 8);
      std::string date = f_name.substr(17, 8);

      if (database.count(b_name) == 0) {
        std::map<std::string, Broker> m;
        m.insert({numb, Broker(b_name, numb, date)});
        database.insert({b_name, m}); //кладем его в словарь
      } else if (database[b_name].count(numb) == 0){
        database[b_name].insert({numb, Broker(b_name, numb, date)});
      } else{
        database.at(b_name).at(numb).update(date);
        ++(database.at(b_name).at(numb));
      }
    }
  }
  print_data(database);
  return 0;
}