/* DISKFETCH VERSION 1.6
   COMMAND MADE BY ADRIJP */

#include <stdio.h>
#include <stdint.h>
#include <sys/statvfs.h>
#include <string.h>

int main(int args, char **arcs) {

	if (args == 1) {

		printf("\n");
		printf("\033[1;36m            _.........._\n");
		printf("\033[1;36m           | |        | |\n");
		printf("\033[1;36m           | | DISK   | |\n");
		printf("\033[1;36m           | | FETCH  | |\n");
		printf("\033[1;36m           | |________| |\n");
		printf("\033[1;36m           |   ______   |\n");
		printf("\033[1;36m           |  |    | |  |\n");
		printf("\033[1;36m           |__|____|_|__|\n");
		printf("\033[0m\n");

		struct statvfs diskinfo;
		char *path = "/";

		statvfs(path, &diskinfo);

		int32_t disktotal = (diskinfo.f_blocks * diskinfo.f_frsize) / 1000000;
		int32_t diskfree = (diskinfo.f_bavail * diskinfo.f_frsize) / 1000000;
		int32_t diskused = ((diskinfo.f_blocks * diskinfo.f_frsize) - (diskinfo.f_bavail * diskinfo.f_frsize)) / 1000000;

		printf("\033[1;36m        Disk usage of path: %s\n", path);
		printf("\033[1;36m        Total: %dMB\n", disktotal);
		printf("\033[1;36m        Free:  %dMB\n", diskfree);
		printf("\033[1;36m        Used:  %dMB\n", diskused);
		printf("\033[0m\n");

		return 0;

	} else {

		if (strcmp(arcs[1], "--version") == 0) {
			printf("Diskfetch version 1.6\n");
			printf("Docs and source code on github\n");
			return 0;
		} else if (strcmp(arcs[1], "--help") == 0) {
			printf("Diskfetch is a command made to show information about disk usage of the system\n");
			printf("The documentation is available on github\n");
			return 0;
		} else {
			printf("unknown option: %s\n", arcs[1]);
		    return 1;
		}

	}

}
