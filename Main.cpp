#include <iostream>
#include "Calcul.h"
#include "FileW.h"
#include "MessageW.h"

int main()
{
    std::vector <std::vector <char>> sMessage;
    std::vector <std::vector <char>> dMessage;
    std::string message {""};
    int numberOfLines{ 0 };
    try {
        if (!read_from_file(sMessage, message, numberOfLines)) {
            throw 1;
        }
        std::cout << "Mesaj initial:" << std::endl;
        extra_column_and_line(sMessage);
        clacul_XoR(sMessage);
        print_with_lines(sMessage);
        std::cout << "==============================\n";
        std::cout << "Mesaj corupt:" << std::endl;
        corrup_message(message);
        from_message_to_matrix(message, dMessage, numberOfLines);
        extra_column_and_line(dMessage);
        clacul_XoR(dMessage);
        print_with_lines(dMessage);
        identify_error(sMessage, dMessage);
        std::cout << "==============================\n";
        std::cout << "Eroare identificata:" << std::endl;
        print_with_lines(dMessage);
    }
    catch (...) {
        std::cout << "Program STOP. Check for errors.\n";
        return -1;
    }
    return 0;
}
