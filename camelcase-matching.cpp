/*
1023. Camelcase Matching (Medium)

Идея заключается в том, чтобы разделить слова и шаблон на несколько частей, начинающихся с заглавной буквы. Все это будем хранить в векторе.
Для этого заведем функцию split_string_by_uppercase(std::string query). Т. к. в тест-кейсах имеются случаи когда слова начинаются с маленьких букв,
в этой функции сначала ищется индекс первой заглавной буквы first_capital_index.

Далее смотрим, имеется ли в i-ой части слова все буквы из i-ой частьи шаблона. Если шаблон верный, то этих частей должно быть поровну.
После обнаружения того, что слово не соответствует шаблону, цикл перебирающий части шаблона будет зря отрабатывать. Чтобы этого избежать используется is_correct

*/

class Solution {
public:

    vector<bool> camelMatch(vector<string>& queries, string pattern) {

        std::vector<bool> result = {};

        std::vector<std::vector<std::string>> queries_parts = {};
        for (std::string query : queries) {
            queries_parts.push_back(split_string_by_uppercase(query));
        }

        std::vector<std::string> pattern_parts = split_string_by_uppercase(pattern);

        // Если шаблон подходящий, то размеры query_parts и pattern_parts одинаковые

        // После обнаружения того, что слово не соответствует шаблону, цикл перебирающий части шаблона будет зря отрабатывать. Чтобы этого избежать используется is_correct
        bool is_correct = true;     
        for (size_t q = 0; q < queries_parts.size(); ++q) {
            if (queries_parts[q].size() != pattern_parts.size()) {  // Если кол-во частей слова и шаблона разные, то оно точно не подходит
                result.push_back(false);
            }

            else {
                is_correct = true;

                for (size_t i = 0; i < pattern_parts.size(); ++i) {
                    if (!is_correct) { break; }  

                    for (size_t letter_index = 0; letter_index < pattern_parts[i].size(); ++letter_index) {   // Перебираем буквы части шаблона

                        if (queries_parts[q][i].find(pattern_parts[i][letter_index]) == std::string::npos) {   // Если не нашли букву
                            result.push_back(false);
                            is_correct = false;
                            break;
                        }
                        else {
                            // Если нашли букву, то ее стираем, т. к. может быть несколько одинаковых букв
                            queries_parts[q][i].erase(queries_parts[q][i].find(pattern_parts[i][letter_index]), 1);   
                        }
                    }
                }

                // Если совпало с шаблоном, то в ответ не будет добавлен false, тем самым размер result не будет соответствовать числу рассмотренных слов -
                // Чем и воспользуемся для определения условия, когда нужно добавлять true.
                if (result.size() == q) { result.push_back(true); } 
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
                // Если мы наткнулись на заглавную букву, то это означает что составление части завершено

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
