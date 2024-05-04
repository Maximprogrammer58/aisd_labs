#include "include/HashTable.h"
#include "include/Random.h"
#include "include/Hash.h"
#include "include/Compare_hash.h"
#include "../include/Equal.h"

int main() {
    // �������� ������ ���-������� (��� int)
    HashTable<int, int, IntHash> table(10);
    table.insert(1, 1);
    table.insert(3, -1);
    table.insert(4, 4);
    table.print();
    table.insert(2, 2);
    std::cout << table.contains(-1) << std::endl;
    table.insert_or_assign(3, 3);
    table.insert(0, 0);
    table.erase(4);
    table.print();

    // �������� ������ ���-������� (�� ������� ��� std::string)
    HashTable<std::string, std::string, PearsonHash, StringEqual, StringEqual> string_table(10);
    string_table.insert("ab", "z");
    string_table.insert_or_assign("bc", "b");
    string_table.insert("cd", "c");
    string_table.print();
    string_table["ab"] = "a";
    std::cout << string_table.contains("b") << std::endl;
    string_table.print();
   
    // �������� ���-������� ������� ��� �����
    setlocale(LC_ALL, "Rus");
    PearsonHash pearson_hash;

    std::string message, filename;
    std::cout << "������� ������: ";
    std::getline(std::cin, message);
    std::cout << "������� ��� ����� ��� ���������� ����: ";
    std::cin >> filename;

    std::cout << "��� ������ " << message << " : " << pearson_hash(message) << std::endl;
    save_hash_to_file(message, filename);

    std::string other_message = generate_random_string(5);
    std::cout << "��� ������ " << other_message << " : " << pearson_hash(other_message) << std::endl;

    if (compare_hash(other_message, filename)) 
        std::cout << "���� ���������" << std::endl;
    else 
        std::cout << "���� �� ���������" << std::endl;
 
    return 0;
}