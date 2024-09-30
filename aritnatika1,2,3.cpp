#include <iostream>
#include <limits>
#include <vector>

void findTwoSmallest() {
    int n;
    std::cout << "Masukkan jumlah bilangan yang ingin Anda input: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Anda harus memasukkan setidaknya 2 bilangan.\n";
        return;
    }

    std::vector<int> numbers(n);
    std::cout << "Masukkan " << n << " bilangan:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    int smallest = std::numeric_limits<int>::max();
    int second_smallest = std::numeric_limits<int>::max();

    for (int num : numbers) {
        if (num < smallest) {
            second_smallest = smallest;
            smallest = num;
        } else if (num < second_smallest && num != smallest) {
            second_smallest = num;
        }
    }

    if (second_smallest == std::numeric_limits<int>::max()) {
        std::cout << "Semua bilangan yang dimasukkan sama.\n";
    } else {
        std::cout << "Dua bilangan terkecil adalah: " << smallest << " dan " << second_smallest << "\n";
    }
}

void findTwoLargest() {
    int n;
    std::cout << "Masukkan jumlah bilangan yang ingin Anda input: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Anda harus memasukkan setidaknya 2 bilangan.\n";
        return;
    }

    int first_max = std::numeric_limits<int>::min();
    int second_max = std::numeric_limits<int>::min();
    int number;

    std::cout << "Masukkan " << n << " bilangan:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> number;

        if (number > first_max) {
            second_max = first_max;
            first_max = number;
        } else if (number > second_max && number != first_max) {
            second_max = number;
        }
    }

    if (second_max == std::numeric_limits<int>::min()) {
        std::cout << "Semua bilangan yang dimasukkan sama.\n";
    } else {
        std::cout << "Dua bilangan terbesar adalah: " << first_max << " dan " << second_max << "\n";
    }
}

void checkOddOrEven() {
    int number;
    std::cout << "Masukkan sebuah bilangan: ";
    std::cin >> number;

    if (number % 2 == 0) {
        std::cout << number << " adalah bilangan genap.\n";
    } else {
        std::cout << number << " adalah bilangan ganjil.\n";
    }
}

int main() {
    char choice;
    do {
        std::cout << "Pilih program:\n";
        std::cout << "1. Menghitung dua bilangan terkecil\n";
        std::cout << "2. Menghitung dua bilangan terbesar\n";
        std::cout << "3. Menentukan apakah bilangan ini ganjil atau genap\n";
        std::cout << "Masukkan pilihan (1/2/3): ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                findTwoSmallest();
                break;
            case '2':
                findTwoLargest();
                break;
            case '3':
                checkOddOrEven();
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
        }

        std::cout << "Apakah Anda ingin mengulangi program? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}