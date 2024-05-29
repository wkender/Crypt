#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#define KEYSIZE 30

std::string RandomKey(std::string key){
	for (int i = 0; i < KEYSIZE; i++){
		key += rand()%26+'A';
	}
	return key;
}

std::string Encode(std::string text, std::string key){
	std::string encode = "";
	for (int i = 0; i < text.length(); i++){
		encode += text[i]^key[i];
	}
	return encode;
}


int main(){
	std::string text = "Hello world!";
	std::string encode = "";
	std::string decode = "";
	std::string key = "";
	std::ofstream keyfile;
	keyfile.open("key.txt", std::ios::ate | std::ios::trunc);
	if (!keyfile.is_open()){
		std::cout << "File not open!" << std::endl;
	       return -1;	
	}
	srand(time(NULL));
	key = RandomKey(key);
        keyfile << key;
	std::cout << "Key file is :\n" << key << std::endl;
	encode = Encode(text, key);
	keyfile.close();
	keyfile.open("encoded.txt", std::ios::ate | std::ios::trunc);
	keyfile << encode;
	std::cout << "Encoded file is \n" << encode << std::endl;
	keyfile.close();
	keyfile.open("decoded.txt", std::ios::trunc);
	decode = Encode(encode, key);
	keyfile << decode;
	std::cout << "Decoded file is \n" << text << std::endl;	
}
