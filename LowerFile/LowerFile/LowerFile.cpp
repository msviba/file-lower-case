#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <filesystem>


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "No file name provided." << std::endl;
        return 1;
    }
    std::ifstream input(argv[1]);
    std::string output_name = "lower\\";
    std::filesystem::create_directory(output_name);

    output_name += argv[1];

    std::ofstream output(output_name, std::ios::out);   


    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Failed to open the file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(input, line)) {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        output << line << std::endl;
    }

    input.close();
    output.close();
    return 0;
}