#include <iostream>
#include <iomanip>
#include <unordered_map>
#include "md5.cpp"
#include <string>
#include <ctime>
#define SIZE_TABLE 10000

std::string GenerateRandomText(){
	std::string str;
	for (int i = 0; i < 10; i++){
		str += rand()%256;
	}
	return str;
}

void GenerateHashTable(std::string* str1, std::string* str2){
	for (int i = 0; i < SIZE_TABLE; i++){
		str1[i] = GenerateRandomText();
		str2[i] = md5(str1[i]);
	}
}

void FindCollisions(std::string* str1, std::string* str2){
	int colission_vals = 0;
	for (int i = 0; i < SIZE_TABLE; i++){
		for (int j = 0; j < SIZE_TABLE; j++){
			colission_vals = 0;
			if (i == j) continue;
			for (int k = 0; k < str2[0].length(); k++){
				if (str2[i][k] == str2[j][k]) colission_vals++;
			}
			if (colission_vals>12){
				std::cout << "Found partial collision! " << str1[i] << "  " << str1[j] << " in hash " << str2[i] << " and " << str2[j] << " With " << colission_vals << " bytes" <<  std::endl;
			}
		}
	}
}

int main(){
	std::string str1[SIZE_TABLE];
	std::string str2[SIZE_TABLE];
	srand(time(NULL));
	GenerateHashTable(str1, str2);
	FindCollisions(str1, str2);
}
