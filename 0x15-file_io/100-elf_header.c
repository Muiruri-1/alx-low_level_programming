#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_elf_header_info - displays information from ELF header
 * @header: pointer to ELF header
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n",
			(header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
			(header->e_ident[EI_DATA] == ELFDATA2LSB) ?
			"2's complement, little endian" :
			"2's complement, big endian");
	printf("  Version:                           %d (current)\n",
			header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			(header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" :
			(header->e_ident[EI_OSABI] == ELFOSABI_HPUX) ? "UNIX - HP-UX" :
			(header->e_ident[EI_OSABI] == ELFOSABI_NETBSD) ? "UNIX - NetBSD" :
			(header->e_ident[EI_OSABI] == ELFOSABI_LINUX) ? "UNIX - Linux" :
			(header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS) ? "UNIX - Solaris" :
			(header->e_ident[EI_OSABI] == ELFOSABI_AIX) ? "UNIX - AIX" :
			(header->e_ident[EI_OSABI] == ELFOSABI_IRIX) ? "UNIX - IRIX" :
			(header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD) ? "UNIX - FreeBSD" :
			(header->e_ident[EI_OSABI] == ELFOSABI_TRU64) ? "UNIX - TRU64" :
			(header->e_ident[EI_OSABI] == ELFOSABI_MODESTO) ? "Novell - Modesto" :
			(header->e_ident[EI_OSABI] == ELFOSABI_OPENBSD) ? "UNIX - OpenBSD" :
			(header->e_ident[EI_OSABI] == ELFOSABI_ARM_AEABI) ? "ARM EABI" :
			(header->e_ident[EI_OSABI] == ELFOSABI_ARM) ? "ARM" :
			(header->e_ident[EI_OSABI] == ELFOSABI_STANDALONE) ?
			"Standalone App" : "Unknown");
	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			(header->e_type == ET_NONE) ? "NONE (No file type)" :
			(header->e_type == ET_REL) ? "REL (Relocatable file)" :
			(header->e_type == ET_EXEC) ? "EXEC (Executable file)" :
			(header->e_type == ET_DYN) ? "DYN (Shared object file)" :
			(header->e_type == ET_CORE) ? "CORE (Core file)" : "Unknown");
	printf("  Entry point address:               %lx\n",
			(unsigned long)header->e_entry);
}
/**
 * main - for arguments argc and argv
 * @argc: argument
 * @argv: argument
 * Return: always
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(2, "Error: Can't read file header\n");
		close(fd);
		return (98);
	}
	if (header.e_ident[0] != 0x7f || header.e_ident[1] != 'E' ||
			header.e_ident[2] != 'L' || header.e_ident[3] != 'F')
	{
		dprintf(2, "Error: Not an ELF file\n");
		close(fd);
		return (98);
	}
	lseek(fd, 0, SEEK_SET);
	print_elf_header_info(&header);
	close(fd);
	return (0);
}

