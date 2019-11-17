#include <getopt.h>
#include <iostream>

using namespace std;

const char *all_options = "dm:gsr::";
const struct option long_options[] = {
	{"drink-beer", no_argument, 0, 'd'},
	{"make-lab", required_argument, 0, 'm'},
	{"go-walk", no_argument, 0, 'g'},
	{"sleep", no_argument, 0, 's'},
	{"runserver", optional_argument, 0, 'r'},
};

int main(int argc, char *argv[])
{
	char p;
	int d = 0, m = 0, g = 0, s = 0, r = 0;

	int option_index = 0;

	while (true)
	{
		p = getopt_long(argc, argv, all_options,
						long_options, &option_index);

		if (p == -1)
			break;

		switch (p)
		{
		case 'd':
			if (d == 0)
			{
				printf("Okay, nice idea, man! 		(-d | --drink-beer)\n");
				d = 1;
			}
			break;

		case 'm':
			if (m == 0)
			{
				printf("Okay, let's do lab.		(-m | --make-lab : arg = %s)\n", optarg);
				m = 1;
			}
			break;

		case 'g':
			if (s == 0)
			{
				printf("Not today, sorry. 		(-g | --go-walk)\n");
				s = 1;
			}
			break;

		case 's':
			if (s == 0)
			{
				printf("Well, nice idea. 		(-s | --sleep)\n");
				s = 1;
			}
			break;

		case 'r':
			if (r == 0)
			{
				if (optarg != NULL)
					printf("Running server...		(-r | --runserver : without arg)\n");
				else
					printf("Running server...		(-r | --runserver : arg = %s)\n", optarg);
				r = 1;
			}
			break;

		case '?':
			printf("Unknown parameter\n");
			break;

		default:
			break;
		}
	}

	return 0;
}