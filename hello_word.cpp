#include <iostream>
#include <string>
//удалено using name std
constexpr std::string_view kMessagePrefix = "Hello world from ";

std::string GetUserName() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    return name;
}

int main() {
    const auto user_name = GetUserName();
    std::cout << kMessagePrefix << user_name << "!\n";
    return EXIT_SUCCESS;

}