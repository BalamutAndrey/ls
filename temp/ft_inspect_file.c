/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:29:00 by eboris            #+#    #+#             */
/*   Updated: 2020/02/01 16:16:15 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <grp.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/xattr.h>

void	ft_print_file_stat(struct stat buff)
{
	struct group	*group;
	struct passwd	*pass;
	
	group = getgrgid(buff.st_gid);
	pass = getpwuid(buff.st_uid);

	printf("\n-= START stat informations =-\n");
	printf("ID of device containing file:\t%d\tst_dev\n", buff.st_dev);
	printf("Mode of file (see below):\t%hu\t\tst_mode\n", buff.st_mode);
	printf("Number of hard links:\t\t%hu\t\tst_nlink\n", buff.st_nlink);
	printf("File serial number:\t\t%llu\t\tst_ino\n", buff.st_ino);
	printf("User ID of the file:\t\t%u\t\tst_uid\t\tname: %s, pass: %s, id: %i, groupid: %i, gecos: %s, gir: %s, shell: %s\n", buff.st_uid, pass->pw_name, pass->pw_passwd, pass->pw_uid, pass->pw_gid, pass->pw_gecos, pass->pw_dir, pass->pw_shell);
	printf("Group ID of the file:\t\t%u\t\tst_gid\t\tname: %s, pass: %s, id: %i\n", buff.st_gid, group->gr_name, group->gr_passwd, group->gr_gid);
	printf("Device ID:\t\t\t%u\t\tst_rdev\n", buff.st_rdev);
	printf("file size, in bytes:\t\t%lld\t\tst_size\n", buff.st_size);
	printf("blocks allocated for file:\t%lld\t\tst_blocks\n", buff.st_blocks);
	printf("optimal blocksize for I/O:\t%u\t\tst_blksize\n", buff.st_blksize);
	printf("user defined flags for file:\t%u\t\tst_flags\n", buff.st_flags);
	printf("file generation number:\t\t%u\t\tst_gen\n", buff.st_gen);
	printf("-= EXT stat informations =-\n");
	printf("Time of last access:\t\t%ld\tst_atime\t%s", buff.st_atime, ctime(&buff.st_atime));
	printf("Last data modification time:\t%ld\tst_mtime\t%s", buff.st_mtime, ctime(&buff.st_mtime));
	printf("Time of last status change:\t%ld\tst_ctime\t%s\n", buff.st_ctime, ctime(&buff.st_ctime));
	printf("-= END stat informations =-\n");
	if (S_ISDIR(buff.st_mode))
		printf("\nThis is a directory!");
	if (S_ISBLK(buff.st_mode))
		printf("\nThis is a block special!");
	if (S_ISCHR(buff.st_mode))
		printf("\nThis is a char special!");
	if (S_ISFIFO(buff.st_mode))
		printf("\nThis is a fifo or socket!");
	if (S_ISREG(buff.st_mode))
		printf("\nThis is a regular file!");
	if (S_ISLNK(buff.st_mode))
		printf("\nThis is a symbolic link!");
	if (S_ISSOCK(buff.st_mode))
		printf("\nThis is a socket!");
	printf("\n");

	if (S_ISDIR(buff.st_mode))
		printf("d");
	else
		printf("-");


}

int		main(int argc, char **argv)
{
	FILE		*fp;
	struct stat buff;
	char		*fn;

	if (argc == 2)
	{
		fn = strdup(argv[1]);
	}
	else
	{
		printf("bad parameters");
		return (0);
	}
	if ((fp = fopen(fn, "rb")) == NULL)
	{
		printf("Cannot open file.\n");
		return (0);
	}
	lstat(fn, &buff);
	printf("\nfilename is:\t\t\t%s\n", fn);
	ft_print_file_stat(buff);

	fclose(fp);
	return (0);
}
