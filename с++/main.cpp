
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <curl/curl.h>

// Коллбэк функция для записи данных в строку
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    std::vector<std::string> urls;
    std::ifstream infile("urls.txt");

    if (!infile.is_open()) {
        std::cerr << "Не удалось открыть файл urls.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        if (!line.empty()) {
            urls.push_back(line);
        }
    }
    infile.close();

    // Добавляем пример сайта
    std::string example_url = "https://tsutmb.ru/news/derzhavinskaya-regata-v-sedmoy-raz-sobrala-lyubiteley-vodnykh-vidov-sporta-tambovshchiny/";
    urls.push_back(example_url);

    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);

    int count = 1;
    for (const auto& url : urls) {
        curl = curl_easy_init();
        if(curl) {
            std::string readBuffer;
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                std::cerr << "Ошибка при скачивании " << url << ": " << curl_easy_strerror(res) << std::endl;
            } else {
                std::string filename = "page_" + std::to_string(count) + ".html";
                std::ofstream outfile(filename);
                if (outfile.is_open()) {
                    outfile << readBuffer;
                    outfile.close();
                    std::cout << "Сохранена страница: " << url << " в файл " << filename << std::endl;
                } else {
                    std::cerr << "Не удалось записать файл " << filename << std::endl;
                }
            }
            curl_easy_cleanup(curl);
        }
        ++count;
    }

    curl_global_cleanup();
    return 0;
}
