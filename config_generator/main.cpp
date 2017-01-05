#include "./generator.h"

void init();
void edit(string edit_field);

int main(int argc, char *argv[]) {

    cout << "Please enter 'init' to initialize config file or 'edit' plus the field you wish to change:" << endl;

    if (static_cast<string>(argv[1]) == "init") {
        cout << "Preparing config file initialization." << endl;
        init();
    }
    else if (static_cast<string>(argv[1]) == "edit") {
        cout << "Preparing to edit config file." << endl;
        edit(static_cast<string>(argv[2]));
    }

    return 0;
}

void init(){
    // Receiving config file data from user, repeating request while blank
    string first_name = "";
    do {
        cout << "Enter your first name" << endl;
        getline (cin, first_name);
    } while (first_name == "");

    string last_name = "";
    do {
        cout << "Enter your last name" << endl;
        getline (cin, last_name);
    } while (last_name == "");

    string email = "";
    do {
        cout << "Enter your email address" << endl;
        getline (cin, email);
    } while (email == "");

    string cypher = "";
    do {
        cout << "Enter a unique cypher" << endl;
        getline (cin, cypher);
    } while (cypher == "");

    string timezone = "";
    do {
        cout << "Enter your timezone offset" << endl;
        getline (cin, timezone);
    } while (timezone == "");

    string file_path = "";
    cout << "Enter path to knownrecipients file" << endl;
    getline (cin, file_path);
    if (file_path == "") {
        file_path = "knownrecipients.txt";
    }

    // Inserting data into a Config structure
    Config data;
    data.first_name = first_name;
    data.last_name = last_name;
    data.email = email;
    data.cypher = cypher;
    data.timezone = timezone;

    // Sending structure to write_config function to create config file
    bool file_found = config_generator::write_config(file_path, data);

    if (file_found == true) {
        cout << "Config file successfully initialized" << endl;
    } else {
        cout << "Could not initialize config file" << endl;
    }
}

void edit(string edit_field) {
    string file_path_edit;
    cout << "Enter path to knownrecipients file:" << endl;
    cin >> file_path_edit;

    // Receiving structure Config pointer from read_config function
    Config *config_ptr = nullptr;
    config_ptr = config_generator::read_config(file_path_edit);

    // Initializing fields with data from Config structure
    string first_name_edit = config_ptr->first_name;
    string last_name_edit = config_ptr->last_name;
    string email_edit = config_ptr->email;
    string cypher_edit = config_ptr->cypher;
    string timezone_edit = config_ptr->timezone;

    // Receiving edit field information from second argument
    if (edit_field == "name") {
        cout << "The current name is: " << first_name_edit << " " << last_name_edit << endl;
        cout << "Enter new first name" << endl;
        cin >> first_name_edit;
        cout << "Enter new last name" << endl;
        cin >> last_name_edit;
    } else if (edit_field == "email") {
        cout << "The current email is: " << email_edit << endl;
        cout << "Enter new email" << endl;
        cin >> email_edit;
    } else if (edit_field == "cypher") {
        cout << "The current cypher is: " << cypher_edit << endl;
        cout << "Enter new cypher" << endl;
        cin >> cypher_edit;
    } else if (edit_field == "timezone") {
        cout << "The current timezone offset is: " << timezone_edit << endl;
        cout << "Enter new timezone offset" << endl;
        cin >> timezone_edit;
    }

    // Putting previous data plus edited data back in to a Config struct
    Config data;
    data.first_name = first_name_edit;
    data.last_name = last_name_edit;
    data.email = email_edit;
    data.cypher = cypher_edit;
    data.timezone = timezone_edit;

    // Sending structure to write_config function to update file
    bool file_found = config_generator::write_config(file_path_edit, data);

    if (file_found == true) {
        cout << "Config file successfully edited" << endl;
    } else {
        cout << "Could not edit config file" << endl;
    }
}