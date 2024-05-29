#include <iostream>
#include "AES.cpp"

int main(){
    AES aes(AESKeyLength::AES_128);
    unsigned char text[] = {0xab, 0xac, 0xad, 0xae, 0xaf, 0x00, 0x13, 0x35, 0x88, 0x22, 0x45, 0x88, 0xbe, 0xcc, 0xfe, 0x15};
    std::cout << "Init text is ";
    for(int i = 0; i < 16; i++){
        printf("%02x", text[i]);
    }
    std::cout << std::endl;
    unsigned char key[] = {0x05, 0x55, 0x21, 0x32, 0x66, 0x0a, 0x3e, 0xaa, 0xfe, 0x15, 0x05, 0x13, 0x45, 0x12, 0x15, 0x18};
    unsigned char* encrypted;
    encrypted = aes.EncryptECB(text,16,key);
    std::cout << "Encrypted text is ";
    for (int i = 0; i < 16; i++){
        printf("%02x", encrypted[i]);
    }
    unsigned char* decrypted;
    decrypted = aes.DecryptECB(encrypted, 16, key);
    std::cout << std::endl << "Decrypted text is ";
    for (int i = 0; i < 16; i++){
        printf("%02x", decrypted[i]);
    }
}
