#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

/**
 * print_addr - prints an address
 * @ptr: pointer
 * Return: void
 */
void print_addr(char *ptr)
{
	int i, start;
	char temp;

	printf("  Entry point address:               0x");

	temp = ptr[4] + '0';
	if (temp == '1')
	{
		start = 26;
		printf("80");
		for (i = start; i >= 22; i--)
		{
			if (ptr[i] > 0)
				printf("%x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%x", 256 + ptr[i]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (temp == '2')
	{
		start = 26;
		for (i = start; i > 23; i--)
		{
			if (ptr[i] >= 0)
				printf("%02x", ptr[i]);

			else if (ptr[i] < 0)
				printf("%02x", 256 + ptr[i]);

		}
	}
	printf("\n");
}

/**
 * print_type - prints the type
 * @ptr: pointer
 * Return: void
 */
void print_type(char *ptr)
{
	char type = ptr[16];

	if (ptr[5] == 1)
		type = ptr[16];
	else
		type = ptr[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * print_os_abi - prints OS/ABI
 * @ptr: pointer
 * Return: void
 */
void print_os_abi(char *ptr)
{
	char os_abi = ptr[7];

	printf("  OS/ABI:                            ");
	if (os_abi == 0)
		printf("UNIX - System V\n");
	else if (os_abi == 2)
		printf("UNIX - NetBSD\n");
	else if (os_abi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", os_abi);

	printf("  ABI Version:                       %d\n", ptr[8]);
}


/**
 * print_ver - prints version
 * @ptr: pointer
 * Return: void
 */
void print_ver(char *ptr)
{
	int ver = ptr[6];

	printf("  Version:                           %d", ver);

	if (ver == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}

/**
 * print_data - prints data
 * @ptr: pointer
 * Return: void
 */
void print_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}

/**
 * print_magic - prints magic information
 * @ptr: pointer
 * Return: void
 */
void print_magic(char *ptr)
{
	int nbytes;

	printf("  Magic:  ");

	for (nbytes = 0; nbytes < 16; nbytes++)
		printf(" %02x", ptr[nbytes]);

	printf("\n");

}

/**
 * sys_check - checks the version system
 * @ptr: pointer
 * Return: void
 */
void sys_check(char *ptr)
{
	char sys = ptr[4] + '0';

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	print_magic(ptr);

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");

	print_data(ptr);
	print_ver(ptr);
	print_os_abi(ptr);
	print_type(ptr);
	print_addr(ptr);
}

/**
 * elf_check - checks if it is an elf file
 * @ptr: pointer
 * Return: 1 if true, 0 if false
 */
int elf_check(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - check the code
 * @argc: number of arguments
 * @argv: arguments array
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int fo, frd;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fo = open(argv[1], O_RDONLY);

	if (fo < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(fo, 0, SEEK_SET);
	frd = read(fo, ptr, 27);

	if (frd == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!elf_check(ptr))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	sys_check(ptr);
	close(fo);

	return (0);
}
