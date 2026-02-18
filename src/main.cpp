#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generate_key(const std::string& name) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::string key = "RAR registration data\n";
    key += name + "\n";
    key += "UID=" + std::to_string(std::rand() % 1000000) + "\n";
    key += "Key=" + std::to_string(std::rand() % 1000000) + "\n";
    key += "Hash=" + std::to_string(std::rand() % 1000000) + "\n";
    return key;
}

int main(int argc, char* argv[]) {
    std::cout << "WinRAR 7.20 Keygen (Educational purpose only)\n";
    std::cout << "==============================================\n";
    
    std::string userName;
    if (argc > 1) {
        userName = argv[1];
    } else {
        std::cout << "Enter your name: ";
        std::getline(std::cin, userName);
        if (userName.empty()) userName = "User";
    }
    
    std::string key = generate_key(userName);
    
    std::ofstream out("rarreg.key");
    if (out) {
        out << key;
        out.close();
        std::cout << "\n[+] rarreg.key generated successfully!\n";
        std::cout << "Copy this file to %APPDATA%\\WinRAR or double-click any .rar file.\n";
    } else {
        std::cerr << "[-] Error writing rarreg.key\n";
        return 1;
    }
    
    return 0;
}