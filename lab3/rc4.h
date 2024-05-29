#ifndef _RC4_H
#define _RC4_H

struct rc4_state
{
    int x, y, m[256];
};

void rc4_setup( struct rc4_state* s, std::string key,  int length );
std::string rc4_crypt( struct rc4_state *s, std::string data, int length );

#endif
