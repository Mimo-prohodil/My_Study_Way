#include <clocale>
#include <iostream>
const int CHAR_ARR_SIZE = 1000;
char alpha_eng[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                           'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                           'w', 'x', 'y', 'z' };

void encript_caesar(char* arr, char* alpha_eng, int key) {
    key = key % 26;
    for (size_t i = 0; arr[i] != '\0'; i++) {
        for (size_t j = 0; j < 26; j++) {
            if (arr[i] == alpha_eng[j]) {
                int idx = int(j + key);
                if (idx < 0) { 
                    arr[i] = alpha_eng[26 + idx];
                    break;
                }
                arr[i] = alpha_eng[idx % 26];
                break;
            }
        }
    }
}

void decript_caesar(char* arr, char* alpha_eng, int key) {
    key = -(key % 26);    
    for (size_t i = 0; arr[i] != '\0'; i++) {
        for (size_t j = 0; j < 26; j++) {
            if (arr[i] == alpha_eng[j]) {
                int idx = int(j + key);
                if (idx < 0) {
                    arr[i] = alpha_eng[26 + idx];
                    break;
                }
                arr[i] = alpha_eng[idx % 26];
                break;
            }
        }
    }
}

void print_arr(char* arr) {
    for (size_t i = 0; i < CHAR_ARR_SIZE; i++)
    {
        if (arr[i] == '\0') break;
        std::cout << arr[i]<< " ";
    }
    std::cout << std::endl;
}

char* swap_encript(char* message, int key) {
    int arr_len = 0;
    for (size_t i = 0; message[i] != '\0'; i++) {
        arr_len++;
    }
    char* encripted_message = new char[arr_len + 1];
    int idx = 0;
    for (size_t i = 0; i < key; i++) {
        for (size_t j = i; j < arr_len; j += key) {
        encripted_message[idx++] = message[j];
        }
    }  
    encripted_message[arr_len] = '\0';
    delete[] message;
    return encripted_message;
}

char* swap_decript(char* message, char *alpha_eng, int key) {
    int arr_len = 0;
    for (size_t i = 0; message[i] != '\0'; i++) {
        arr_len++;
    }
    char* decripted_message = new char[arr_len + 1];
    int idx = 0;
    for (size_t i = 0; i < arr_len/key; i++) {
        for (size_t j = i; j < arr_len; j += arr_len/key) {
            decripted_message[idx++] = message[j];
        }
    }
    for (size_t i = 0; i < arr_len; i++) {        
        if (decripted_message[i] == '1') {               
            decripted_message[i] = '\0';
            break;
        }
        else {
            decripted_message[arr_len] = '\0';
        }
    }    
    return decripted_message;
}

char* swap_check(char* message, int arr_len, int key) {
    
    int arr_size = arr_len;
    if (arr_len % key != 0) {
        arr_size += key - (arr_len % key);
    }    
    char* message_for_encrypt = new char[arr_size + 1];
    for (size_t i = 0; i < arr_size; i++) {
        if (i < arr_len) {
            message_for_encrypt[i] = message[i];
        }
        else {
            message_for_encrypt[i] = '1';
        }
    }
    message_for_encrypt[arr_size] = '\0';

    return message_for_encrypt;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    {
        //std::cout << "№1. Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом." << std::endl;
        //char message[CHAR_ARR_SIZE] = "thisisasecretmessage";
        ///*std::cout << "Введите строку для шифровки: ";    
        //std::cin.getline(message, CHAR_ARR_SIZE);*/
        //int key;
        //std::cout << "Введите ключ: "; 
        //std::cin >> key;
        //encript_caesar(message, alpha_eng, key);
        //std::cout << "Шифрованное сообщение: ";
        //print_arr(message);
        //decript_caesar(message, alpha_eng, key);
        //std::cout << "Расифрованное сообщение: ";
        //print_arr(message);
    }

    {
        std::cout << "№2. Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и количеством столбцов." << std::endl;
        char message_1[CHAR_ARR_SIZE] = "thisisasecretmessage";
        /*std::cout << "Введите строку для шифровки: ";
        std::cin.getline(message_1, CHAR_ARR_SIZE)*/;
        int key;
        std::cout << "Введите ключ: ";
        std::cin >> key;
        int arr_len = 0;
        for (size_t i = 0; message_1[i] != '\0'; i++) {
            arr_len++;
        }              
        std::cout << "Шифрованное сообщение: ";
        char* encrypted_message = swap_encript(swap_check(message_1, arr_len, key), key);
        print_arr(encrypted_message);
        std::cout << "Расифрованное сообщение: ";
        char* decrypted_message = swap_decript(encrypted_message, alpha_eng, key);
        print_arr(decrypted_message);
        delete[] decrypted_message;
        delete[] encrypted_message;
    }
    return 0;
}