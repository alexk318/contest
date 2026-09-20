/*
1023. Camelcase Matching (Medium)
*/

class Solution {
public:

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        // Разделить строку на три строки, начинающихся с заглавной буквы.

        std::vector<bool> result = {};

        std::vector<std::vector<std::string>> queries_parts = {};
        for (std::string query : queries) {
            queries_parts.push_back(split_string_by_uppercase(query));
        }

        std::vector<std::string> pattern_parts = split_string_by_uppercase(pattern);

        // Если шаблон подходящий, то размеры query_parts и pattern_parts одинаковые

        bool is_correct = true;
        for (size_t q = 0; q < queries_parts.size(); ++q) {
            if (queries_parts[q].size() != pattern_parts.size()) {
                result.push_back(false);
            }

            else {
                is_correct = true;

                for (size_t i = 0; i < pattern_parts.size(); ++i) {
                    if (!is_correct) { break; }

                    // Необязательно чтобы в слове буквы шли друг за другом
                    for (size_t letter_index = 0; letter_index < pattern_parts[i].size(); ++letter_index) {

                        if (queries_parts[q][i].find(pattern_parts[i][letter_index]) == std::string::npos) {
                            result.push_back(false);
                            is_correct = false;
                            break;
                        }
                        else {
                            queries_parts[q][i].erase(queries_parts[q][i].find(pattern_parts[i][letter_index]), 1);
                        }
                    }

                    
                }

                if (result.size() == q) { result.push_back(true); } // Если совпало с шаблоном

            }

        }

        return result;
    }

    std::vector<std::string> split_string_by_uppercase(std::string query) {

        std::vector<std::string> result = {};

        size_t first_capital_index = 0;
        for (size_t i = 0; i < query.size(); ++i) {
            if (std::isupper(static_cast<unsigned char>(query[i]))) {
                first_capital_index = i;
                break;
            }
        }

        std::string current_part = { query[first_capital_index] };

        for (size_t i = first_capital_index + 1; i < query.size(); ++i) {

            if (std::isupper(static_cast<unsigned char>(query[i]))) {
                // Если мы наткнулись на заглавную букву, то это означает что можно подвести итог

                result.push_back(current_part);
                current_part = query[i];
            }

            else {
                current_part.push_back(query[i]);
            }

            if (i == query.size() - 1) { result.push_back(current_part); }
        }

        return result;
    }
    
};
