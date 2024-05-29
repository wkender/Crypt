#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <cmath>
#define alphabet 256

float ShannonEntropy(std::map <char, int> fr, std::string text, unsigned short size){
	float freqforchar = 0.0;
	float entropy = 0.0;
	for (char c : text) {
		fr[c]++;
	}
	for (std::pair <char, int> a : fr){
		freqforchar = static_cast<float>(a.second)/size;
		entropy -= freqforchar*std::log2f(freqforchar);
		std::cout << "Frequency of char '" << a.first << "' is " << freqforchar << std::endl;
	}
	return entropy;
}

int main(){
	std::ifstream f("text.txt", std::ios::in | std::ios::binary);
	std::map <char, int> freq;
	std::string text;
	std::string line;
	float v = 0;
	unsigned short size = f.tellg();
	if (!f.is_open()){
		std::cout << "File not open!" << std::endl;
		return -1;
	}
	f.seekg(0, std::ios_base::end);
	size = f.tellg();
	f.seekg(0, std::ios_base::beg);
	std::getline(f, text, '\0');
	text.pop_back();
	std::cout << "Text is: " << text << std::endl  << "Size is: " << --size << std::endl;
	v = ShannonEntropy(freq, text, size);
	std::cout << "Entropy is: " << v << std::endl;
	return 0;
}
