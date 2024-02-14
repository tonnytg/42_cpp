#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string replaceAll(std::string str, const std::string &from, const std::string &to) {
    size_t start_pos = 0;
    std::string result;

    while (start_pos < str.length()) {
        size_t pos = str.find(from, start_pos);
        if (pos == std::string::npos) {
            result += str.substr(start_pos);
            break;
        }

        result += str.substr(start_pos, pos - start_pos) + to;
        start_pos = pos + from.length();
    }

    return result;
}

std::string newFileName(std::string filename) {

	size_t lastDotPos = filename.find_last_of(".");
	std::string newFilename = filename.substr(0, lastDotPos);

	return newFilename;
}

int	replaceFile(std::string filename, std::string s1, std::string s2) {

    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string content = buffer.str();
    inFile.close();

    std::string modifiedContent = replaceAll(content, s1, s2);

    std::ofstream outFile((newFileName(filename) + ".replace").c_str());
    if (!outFile) {
        std::cerr << "Cannot create output file." << std::endl;
        return 1;
    }

    outFile << modifiedContent;
    outFile.close();

	return 0;
}

int main(int argc, char **argv) {

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

	if (replaceFile(filename, s1, s2)) {
		std::cout << "ERROR to replace file" << std::endl;
		return 1;
	}

    return 0;
}
