// 한국이 그리울 땐 서버에 접속하지

#include <bits/stdc++.h>

std::vector<std::string> split(std::string input_s, std::string delimiter) {
    std::vector<std::string> result_v;
    long long pos = 0;
    std::string token = "";

    while ((pos = input_s.find(delimiter)) != std::string::npos) {
        token = input_s.substr(0, pos);
        result_v.push_back(token);
        input_s.erase(0, pos + delimiter.length());
    }

    result_v.push_back(input_s);
    return result_v;
}

int matches(std::string file_name, std::vector<std::string> split_pattern) {
    std::string before_asterisk_pattern = split_pattern[0];
    std::string after_asterisk_pattern = split_pattern[1];

    if (file_name.size() <
        (before_asterisk_pattern.length() + after_asterisk_pattern.length())) {
        return 0;
    }

    std::string before_asterisk_substr =
        file_name.substr(0, before_asterisk_pattern.length());
    std::string after_asterisk_substr =
        file_name.substr(file_name.length() - after_asterisk_pattern.length());

    int before_asterisk_match =
        before_asterisk_pattern == before_asterisk_substr;
    int after_asterisk_match = after_asterisk_pattern == after_asterisk_substr;

    if (!before_asterisk_match || !after_asterisk_match) {
        return 0;
    }
    return 1;
}

int main() {
    int N = 0;
    std::string pattern;
    std::cin >> N;
    std::cin >> pattern;
    std::string delimiter = "*";
    std::vector<std::string> split_pattern = split(pattern, delimiter);
    std::vector<std::string> file_names;
    for (int i = 0; i < N; i++) {
        std::string temp;
        std::cin >> temp;
        file_names.push_back(temp);
    }
    for (int i = 0; i < file_names.size(); i++) {
        if (matches(file_names[i], split_pattern)) {
            std::cout << "DA" << std::endl;
        } else {
            std::cout << "NE" << std::endl;
        }
    }

    return 0;
}