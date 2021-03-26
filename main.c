#include "types.h"
#include "base32.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
const u8* cstr_to_u8(const char* cstr){
	return (const u8*)( &cstr[0] );
//	return reinterpret_cast<const u8*>(&cstr[0])
}

int main(){
	const char* test0 = "test";
	const char* test1 = "\x50\xF5\x71\x99\x4B\x80\xBE\x23\xDD\xCF\xC7\xBB\x45\x76\xEE\x86\x2E\x68\xFD\xD2";//20


	const u8* test0_u8 = cstr_to_u8(test0);
	const u8* test1_u8 = cstr_to_u8(test1);

	int test0_len = strlen(test0);
	int test1_len = strlen(test1);

	int test0_outlen = BASE32_TO_LEN(test0_len);
	int test1_outlen = BASE32_TO_LEN(test1_len);

	char* test0_out = (char*) malloc(test0_outlen);
	base32_to(test0_out, test0_u8, test0_len);

	printf("test: inlen=%d input=%s\r\n",test0_len,test0);
	printf("result: outlen=%d output=%s\r\n",test0_outlen,test0_out);


        char* test1_out = (char*) malloc(test1_outlen);
        base32_to(test1_out, test1_u8, test1_len);

        printf("test: inlen=%d input=%s\r\n",test1_len,test1);
        printf("result: outlen=%d output=%s\r\n",test1_outlen,test1_out);


	return 0;
}
