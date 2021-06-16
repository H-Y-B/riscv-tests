#include <stdio.h>

typedef unsigned int u32;
typedef unsigned long long u64;

#define csr_misa 0x301
#define csr_start 0x345
#define csr_size 0x346

/*
#define read_csr(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define write_csr(reg, val) ({ \
  asm volatile ("csrw " #reg ", %0" :: "rK"(val)); })
*/


inline u64 read_csr(u32 csr_num){
    u64 result;
    asm("csrr %0, %1" : "=r"(result) : "I"(csr_num));
    return result; 
}
inline void write_csr(u32 csr_num,u64 data){
    asm("csrw %0, %1" :: "I"(csr_num),"rK"(data));
}





int main (int argc, char** argv)

	write_csr(csr_size,0x80000);
	u64 size=read_csr(csr_size);
	printf("huangyubiao : %llx\n",size);

	write_csr(csr_start,0x1234567812345678);
	u64 start=read_csr(csr_start);
	printf("huangyubiao : %llx\n",start);
	return 0;
}
