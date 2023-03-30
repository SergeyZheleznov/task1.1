

#include <iostream>
#include <fstream>

    int main()
    {
        setlocale(LC_ALL, "Russian");

        int size1 = 0;
        int size2 = 0;

        std::ifstream fin("in.txt");

        if (fin.is_open()) {
            std::cout << "Файл открыт" << std::endl;
        }
        else {
            std::cout << "Не получилось открыть файл" << std::endl;
        }
        fin >> size1;
        int* int_ptr1 = new int[size1]();
        for (int i = 0; i < size1; i++) {
            fin >> int_ptr1[i];
        }
        fin >> size2;
        int* int_ptr2 = new int[size2]();
        for (int i = 0; i < size2; i++) {
            fin >> int_ptr2[i];
        }

        fin.close();

        int x = 0;
        int y = int_ptr1[0];
        for (int i = 0; i < size1 - 1; i++) {
            int_ptr1[i] = int_ptr1[i + 1];
        }
        int_ptr1[size1 - 1] = y;

        x = 0;
        y = int_ptr2[size2 - 1];
        for (int i = size2 - 1; i > 0; i--) {
            int_ptr2[i] = int_ptr2[i - 1];
        }
        int_ptr2[0] = y;


        std::ofstream fout("out.txt");
        if (fout.is_open()) {
            std::cout << "Файл открыт" << std::endl;
        }
        else {
            std::cout << "Не получилось открыть файл" << std::endl;
        }

        fout << size2 << std::endl;

        for (int i = 0; i < size2; i++) {
            fout << int_ptr2[i] << " ";
        }
        fout << std::endl;

        fout << size1 << std::endl;

        for (int i = 0; i < size1; i++) {
            fout << int_ptr1[i] << " ";
        }
        fout << std::endl;

        fout.close();

        x = 0;
        y = 0;
        delete[] int_ptr1;
        delete[] int_ptr2;
        return 0;
    }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
