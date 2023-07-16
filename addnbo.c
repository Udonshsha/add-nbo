#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <stdlib.h>


void check_func(int num) {
	if (num < 3){
		fprintf(stderr,"error plz check input type\n");
		exit(1);
	}
}


uint32_t file_read(char *argv, uint32_t re_str){
	
	uint32_t re_value;

	FILE *pFILE = fopen(argv,"rb");
	
	if(pFILE == NULL) {
		fprintf(stderr, "file open err\n");
	}

	fread(&re_value, sizeof(uint32_t),1, pFILE);

	fclose(pFILE);
	
	return re_value;

}


void sum_bin(uint32_t str1, uint32_t str2){
	
	uint32_t str3 = htonl(str1)+htonl(str2);

	printf("0x%x + ",str1);
	printf("0x%x = ",str2);
	printf("0x%x\n",str3);

}


int main(int argc, char *argv[]) {
	
	uint32_t str1;
	uint32_t str2;
	uint32_t str3;

	check_func(argc);
	str1 = file_read(argv[1],str1);
	str2 = file_read(argv[2],str2);

	sum_bin(str1, str2);
}
