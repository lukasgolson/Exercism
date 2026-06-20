#include <string>


int get_level_start(std::string line){

    std::string search_string{"["};

    auto start_guard_start = line.find_first_of(search_string);
    
    return start_guard_start;
}


int get_level_end(std::string line){
    std::string search_string{"]: "};
    auto search_string_length = search_string.length();
    auto end_guard_start = line.find_first_of(search_string);

    return end_guard_start + search_string_length;
}


namespace log_line {
std::string message(std::string line) {

    int end_pos = get_level_end(line);

    std::string cleaned = line.erase(0, end_pos);

    return cleaned;
}

std::string log_level(std::string line) {
    int start_pos = get_level_start(line) + 1;
    int end_pos = get_level_end(line) - 3;

    std::string substr = line.substr(start_pos, end_pos - start_pos);


    return substr;
}

std::string reformat(std::string line) {
    std::string message_text = message(line);
    std::string log_level_text = log_level(line);

    std::string final_text = message_text + " (" + log_level_text + ")";

    return final_text;
}
    
}  // namespace log_line

