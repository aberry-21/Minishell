# check wildcard
echo /./../../*/./*				>  test0
./minishell "/./../../*/./*"	>> test0
leaks minishell					>> log

echo *					>  test1
./minishell "*"			>> test1
leaks minishell					>> log

echo */*				>  test2
./minishell "*/*"		>> test2
leaks minishell					>> log
echo src/*.* 		>  test3
./minishell "src/*.*"	>> test3
leaks minishell					>> log
echo t*s/				>  test4
./minishell "t*s/"		>> test4
leaks minishell					>> log
echo ./././*/./* 			>  test5
./minishell "./././*/./*"	>> test5
leaks minishell					>> log

# check prompt
make && ./minishell "c" && leaks minishell >> log