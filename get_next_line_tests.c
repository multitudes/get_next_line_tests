#include "get_next_line_tests.h"


/*
Reading a line from a fd is way too tedious.  
This project is about programming a function that returns a line
 read from a file descriptor.
*/


char *test_invalid_fd(void)
{
	int	fd;
	fd = 1000;
	debug("======= test_invalid_fd ==========\n");
	debug("** fd = %d - buffer size %d\n",fd ,BUFFER_SIZE);

	char *s = get_next_line(fd);
	debug("next line is |%s|\n", s);
	close(fd);
	
	fd = -1;
	debug("** fd = %d - buffer size %d\n",fd ,BUFFER_SIZE);
	s = get_next_line(fd);
	debug("next line is |%s|\n", s);
	close(fd);
	
	fd = open("f/file.txt", O_RDONLY);
	close(fd);
	debug("** fd = %d - buffer size %d\n",fd ,BUFFER_SIZE);
	s = get_next_line(fd);
	debug("next line is |%s|\n", s);
	close(fd);
	
	return (NULL);
}

char *test_one_newline(void)
{
	
	debug("=======  test_one_newline ==========\n");
	debug("buffer size %d\n", BUFFER_SIZE);

	int	fd;
	char	*s;

	fd = open("t/nl", O_RDONLY);
	debug("** fd = %d - buffer size %d\n",fd ,BUFFER_SIZE);
	s = get_next_line(fd);
	debug("next line is |%s|\n", s);
	close(fd);
	
	
	//
	//	fd = open("file.txt", O_RDONLY);
	//
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	close(fd);
	//
	//	fd = open("nl", O_RDONLY);
	//
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	close(fd);
	//
	//	fd = open("multiple_nlx5", O_RDONLY);
	//
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	close(fd);
	//
	//	fd = open("multiple_line_with_nl", O_RDONLY);
	//
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	close(fd);
	//
	//	fd = open("empty", O_RDONLY);
	//
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	close(fd);
	//
	//	fd = open("big_line_with_nl", O_RDONLY);
	//
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	close(fd);
	//
	//	fd = open("big_line_no_nl", O_RDONLY);
	//
	//	s = get_next_line(fd);
	//	printf("+++++++++++++++++++++++\n");
	//	printf("next line is |%s|\n", s);
	//	printf("+++++++++++++++++++++++\n");
	//	close(fd);
	//
	fd = open("alternate_line_nl_with_nl", O_RDONLY);
	
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	
	close(fd);
	
	
	fd = open("alternate_line_nl_no_nl", O_RDONLY);
	
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	
	close(fd);
	
	//		fd = open("big_line_with_nl", O_RDONLY);
	// from the input line
	//		s = get_next_line(0);
	//		printf("+++++++++++++++++++++++\n");
	//		printf("next line is |%s|\n", s);
	//		printf("+++++++++++++++++++++++\n");
	//		close(fd);
	//
	
	fd = open("43_with_nl", O_RDONLY);
	
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	
	close(fd);
	
	fd = open("42_with_nl", O_RDONLY);
	
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	
	close(fd);
	
	fd = open("42_no_nl", O_RDONLY);
	
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	
	close(fd);
	
	fd = open("41_with_nl", O_RDONLY);
	
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	
	close(fd);
	
	
	fd = open("41_no_nl", O_RDONLY);
	
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	
	close(fd);
	
	
	fd = open("empty", O_RDONLY);
	
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	
	close(fd);
	
	fd = open("1char.txt", O_RDONLY);
	
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	s = get_next_line(fd);
	printf("+++++++++++++++++++++++\n");
	printf("next line is |%s|\n", s);
	printf("+++++++++++++++++++++++\n");
	
	close(fd);
	
	
	
	
	return NULL;
}

char *all_tests(void)
{
	mu_suite_start();

	mu_run_test(test_invalid_fd);
	mu_run_test(test_one_newline);
	
	return NULL;
}

RUN_TESTS(all_tests);

