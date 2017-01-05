#include "./library.h"

namespace config_generator {

    Config* read_config(string config_file_path) {
        string lines[5];
        Config config_data;
        Config *config_ptr = nullptr;
        config_ptr = new Config;
        ifstream inputFile;

        // Method will return file at the path passed to it
        inputFile.open(config_file_path);

        // For loop to store each line from the file to an array in lines
        for (int i = 0; i < 5; i++) {
            inputFile >> lines[i];
        }

        // Each line from lines array will be placed in config struct
        config_data.first_name = lines[0];
        config_data.last_name = lines[1];
        config_data.email = lines[2];
        config_data.cypher = lines[3];
        config_data.timezone = lines[4];

        // Pointer to struct address
        config_ptr = &config_data;

        inputFile.close();

        return config_ptr;
    }

    bool write_config(string config_file_path, Config data) {
        ofstream outputFile;
        bool file_found = false;

        // Method will return file at the path passed to it
        outputFile.open(config_file_path);

        // If the file path is correct, data from config struct will be written to it
        if (outputFile) {
            outputFile << data.first_name << endl;
            outputFile << data.last_name << endl;
            outputFile << data.email << endl;
            outputFile << data.cypher << endl;
            outputFile << data.timezone << endl;

            outputFile.close();
            file_found = true;
        }
        return file_found;
    }
}