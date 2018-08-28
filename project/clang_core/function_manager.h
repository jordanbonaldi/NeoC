/*
** EPITECH PROJECT, 2018
** IT
** File description:
** IT
*/

# ifndef FUNCTION_HANDLER_HH
	# define FUNCTION_HANDLER_HH

# define PARAM_NAMED this

# define public

# define import

# define private static

# define VA_ARGS(...) , ##__VA_ARGS__

# define __UNUSED__ (void)this;

# define __SETUNUSED__(param) (void)param;

# define PRE_FUNC_NAME MAIN_PREFIX

# define CREATE_ARGS MAIN_STRUCT *PARAM_NAMED

# define function(type, name, ...) type PRE_FUNC_NAME##name(\
				__attribute__((unused))CREATE_ARGS VA_ARGS(__VA_ARGS__))

# define default(type) type launcher(\
					__attribute__((unused))CREATE_ARGS,\
					__attribute__((unused))const int argc,\
					__attribute__((unused))char **argv)

# define call(name, ...) PRE_FUNC_NAME##name(PARAM_NAMED VA_ARGS(__VA_ARGS__))

# define get(name) PRE_FUNC_NAME##name

# define with_caller(caller, args) caller(PARAM_NAMED, args)

# define FUNC(c_) ({ c_ a;})

# define EXEC_FUNC(ret, func)\
		({ ret __fn__ func __fn__; })

# define main(type, oj) type main(__attribute__((unused)) const int argc,\
				__attribute__((unused)) char **argv\
			) {\
					new(MAIN_STRUCT, this, sizeof(MAIN_STRUCT))\
					Object *obj = call(oj);\
					setDefault(obj)\
					type t = launcher(this, argc, argc);\
					free(obj);\
					free(this);\
					return t;\
				}

#endif
