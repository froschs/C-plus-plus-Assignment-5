#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Config {
    string first_name;
    string last_name;
    string email;
    string cypher;
    string timezone;
};

namespace config_generator {
    Config* read_config(string config_file_path);
    bool write_config(string config_file_path, struct Config);
}
