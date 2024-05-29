#include <iostream>

using namespace std;

string CaesarEncode(string text, int shift){
	string encode = "";
	for (int i = 0; i<text.length(); i++){
		if (text[i] == ' ') encode += text[i];
		if (text[i] >= 'a' && text[i] <= 'z'){
			encode += int(text[i]+shift-int('a'))%26+int('a');
		}
		else if (text[i] >= 'A' && text[i] <= 'Z'){
			encode += int(text[i]+shift-int('A'))%26+int('A');
		}
	}
	return encode;
}

string CaesarDecode(string text, int shift){
	string decode = "";
	int a;
	for (int i = 0; i<text.length(); i++){
		if (text[i] == ' ') decode += text[i];
		if (text[i] >= 'a' && text[i] <= 'z'){
			a = int(text[i]-shift-int('a'))%26;
			decode += int(26+text[i]-shift-int('a'))%26+int('a');
		}
		else if (text[i] >= 'A' && text[i] <= 'Z'){
			decode += int(26+text[i]-shift-int('A'))%26+int('A');
		}
	}
	return decode;
}

void CaesarEncodeText(string encoded, string original){
	string decode = "";
	int key;
	for (int i = 1; i <= 26; i++){
		decode = CaesarDecode(encoded, i);
		if (original == decode){
			cout << "key is " << i << endl;
			return;
		}
	}
	cout << "Key not found!" << endl;
}

void CaesarRandomEncode(string encoded){
	string decoded = "";
	for (int i = 1; i<=25; i++){
		decoded = CaesarDecode(encoded, i);
		cout << "Text with shift = " << i << " is: " << decoded << endl; 
	}
}

int main(){
	string text = "My new text";
 	unsigned short shift;
	cout << "Enter shift: ";
	cin >> shift;
	string encode = CaesarEncode(text,shift);
	cout << "Text: " << text << " Shift = " << shift << " Encoded text: " << encode << endl;
	CaesarRandomEncode(encode);
	CaesarEncodeText(encode, text);
	return 0;

}
