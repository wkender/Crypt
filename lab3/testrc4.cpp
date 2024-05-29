#include <fstream>
#include <ctime>
#include "rc4.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEYSIZE 30

using namespace std;

void rc4_setup( struct rc4_state *s, std::string key,  int length )
{
    int i, j, k, *m, a;

    s->x = 0;
    s->y = 0;
    m = s->m;

    for( i = 0; i < 256; i++ )
    {
        m[i] = i;
     }

    j = k = 0;

    for( i = 0; i < 256; i++ )
    {
        a = m[i];
        j = (unsigned char) ( j + a + key[k] );
        m[i] = m[j]; m[j] = a;
        if( ++k >= length ) k = 0;
    }
} 

std::string RandomKey(std::string key){
	for (int i = 0; i < KEYSIZE; i++){
		key += rand()%256;
	}
	return key;
}

std::string rc4_crypt( struct rc4_state *s, std::string data, int length )
{ 
    int i, x, y, *m, a, b;

    x = s->x;
    y = s->y;
    m = s->m;

    for( i = 0; i < length; i++ )
     {
        x = (unsigned char) ( x + 1 ); a = m[x];
        y = (unsigned char) ( y + a );
        m[x] = b = m[y];
        m[y] = a;
        data[i] ^= m[(unsigned char) ( a + b )];
    }

    s->x = x;
    s->y = y;
    return data;
}

int main(){
	struct rc4_state *s;
	s=(struct rc4_state *) malloc (sizeof(struct rc4_state));
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
	rc4_setup(s, key, key.length());
	std::cout << "Key file is :\n" << key << std::endl;
	keyfile.close();
	keyfile.open("encoded.txt", std::ios::ate | std::ios::trunc);
	encode = rc4_crypt(s, text, text.length());
	keyfile << encode;
	std::cout << "Encoded file is \n" << encode << std::endl;
	keyfile.close();
	keyfile.open("decoded.txt", std::ios::trunc);
	rc4_setup(s, key, key.length());
	text = rc4_crypt(s, encode, encode.length());
	keyfile << text;
	std::cout << "Decoded file is \n" << text << std::endl;	
}

