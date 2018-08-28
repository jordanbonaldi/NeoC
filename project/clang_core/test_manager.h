/*
** EPITECH PROJECT, 2018
** lol
** File description:
** lol
*/

# ifndef TEST_JORDYTERION_HH
	# define TEST_JORDYTERION_HH

# include "clang.h"

OBJECT_CREATOR
(
	Tests,

	String name;

	bool (*action)(MAIN_STRUCT *);

	struct s_Tests *next;
)

# define setTests(n, cb) (Tests) {\
					.name = n,\
					.action = cb\
				}

# define CREATE_TEST(name) private function(bool, name)

# define INIT_TEST public function(void, init_test)

# define __ACTIVATED__(n, f) {\
				call(addTest, setTests(n, GET_FUNCTION(f)));\
			}

public function(int, sizeTests)
{
	int $i = 0;
	FOREACH_LIST(Tests *, this->tests, {
		__SETUNUSED__(IT);
		$i++;
	})
	return $i;
}

public function(void, launchTests)
{
	int $failed = 0;
	int $succeed = 0;
	int $test = 0;
	int $size = call(sizeTests);

	FOREACH_LIST
	(
		Tests *,
		this->tests,
		{
			$test++;
			printf("\nTesting T:%d -> %s\n\n", $test, IT->name);
			if (IT->action(this)) {
				printf("\n=========== RESULTS ===========\n");
				printf("\n\tTest : %d -> succeed\n", $test);
				$succeed ++;
			} else {
				printf("\n=========== RESULTS ===========\n");
				printf("\n\tTest : %d -> failed\n", $test);
				$failed ++;
			}
		}
	)

	printf("\n\n======== GLOBAL RESULTS ========\n\n");

	printf("\t%d test(s) succeed on %d test(s)\n", $succeed, $size);

	printf("\t%d test(s) failed on %d test(s)\n", $failed, $size);

	printf("\n\tSuccess : %.1f%%\n", (double)($succeed * 100) / $size);
	if ($failed)
		printf("\tFail : %.1f%%\n", (double)($failed * 100) / $size);
}

public function(void, addTest, Tests test)
{
	Tests *__test;
	Tests *tmp;
	__MALLOC__(__test, sizeof(Tests));

	__test->name = test.name;
	__test->action = test.action;
	__test->next = NULL;
	if (!this->tests)
		this->tests = __test;
	else {
		tmp = this->tests;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = __test;
	}
}

public function(void, destroyTests)
{
	Tests *tmp = this->tests;
	Tests *tmp2;

	while (tmp) {
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}


# endif
