# Documentation

Описанные функции:
```
fork                    stat
wait                    lstat
waitpid                 fstat
wait3                   execve
wait4                   dup
signal                  dup2
kill                    pipe
exit                    opendir
getcwd                  readdir
chdir                   closedir
errno                   strerror
```
## Name function: `fork()`


## Synopsis function

```
#include <sys/types.h>
#include <unistd.h>

pid_t	fork(void);
```
## Description function
Процесс после системного вызова fork, раздваивается, у исходного процесса создаётся идентичный потомок-двойник в идентичном состоянии. Создавшийся процесс будет занят выполнением того же кода ровно с той же точки, что и исходный процесс.
## Return value
При успешном завершении родителю возвращается PID (идентификатор процесса) процесса-потомка, а процессу-потомку возвращается 0. При неудаче родительскому процессу возвращается -1, процесс-потомок не создается, а значение errno устанавливается должным образом.
## Examples
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main	(void)
{
	pid_t	pid;

	pid = fork();
	pid = fork();
	printf("Fork-Test\n");
	return (0);
}
Вывод:
	Fork-Test
	Fork-Test
	Fork-Test
	Fork-Test
```
```
     P               # перед первым pid = fork();

  [fork 1]

     P               # перед вторым pid = fork();
      \
       P(1)          # перед вторым pid = fork();

  [fork 2]

     P               # перед printf("Fork-Test\n");
    / \
P(2)   P(1)          # перед printf("Fork-Test\n");   # перед printf("Fork-Test\n");
           \
            P(1)(2)  # перед printf("Fork-Test\n");
```
---
## Name function: `wait()`, `wait3()`, `wait4()`, `waitpid()`
## Synopsis function
```
#include <sys/wait.h>
#include <sys/types.h>

pid_t	wait(int *stat_loc);

pid_t	wait3(int *stat_loc, int options, struct rusage *rusage);

pid_t	wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage);

pid_t	waitpid(pid_t pid, int *stat_loc, int options); 
```
## Description function
Функция wait приостанавливает выполнение текущего процесса до тех пор, пока дочерний процесс не завершится, или до появления сигнала, который либо завершает текущий процесс, либо требует вызвать функцию-обработчик. Если дочерний процесс к моменту вызова функции уже завершился (так называемый "зомби" ("zombie")), то функция немедленно возвращается. Системные ресурсы, связанные с дочерним процессом, освобождаются.\

Функция waitpid приостанавливает выполнение текущего процесса до тех пор, пока дочерний процесс, указанный в параметре pid, не завершит выполнение, или пока не появится сигнал, который либо завершает текущий процесс либо требует вызвать функцию-обработчик. Если указанный дочерний процесс к моменту вызова функции уже завершился (так называемый "зомби"), то функция немедленно возвращается. Системные ресурсы, связанные с дочерним процессом, освобождаются.\

Для wait3 wait4:\
Если rusage не NULL, то структура struct rusage  которая  описывается  в `<sys/resource.h>`будет заполнена учётной информацией.\
```
struct rusage {
    struct timeval ru_utime; /* время ЦП, исполь. в режиме пользователя */
    struct timeval ru_stime; /* время ЦП, исполь. в режиме системы */
    long   ru_maxrss;        /* максимальный rss */
    long   ru_ixrss;         /* полный объём общей памяти */
    long   ru_idrss;         /* полный объём собственной памяти */
    long   ru_isrss;         /* полный объём собственного стека */
    long   ru_minflt;        /* количество восстановленных страниц
                                (мягких отказов) */
    long   ru_majflt;        /* количество отказавших страниц
                                (жёстких отказов) */
    long   ru_nswap;         /* количество обращений при подкачке */
    long   ru_inblock;       /* количество операций блокового ввода */
    long   ru_oublock;       /* количество операций блокового вывода */
    long   ru_msgsnd;        /* количество посланных сообщений IPC */
    long   ru_msgrcv;        /* количество принятых сообщений IPC */
    long   ru_nsignals;      /* количество принятых сигналов */
    long   ru_nvcsw;         /* количество переключений контекста */
    long   ru_nivcsw;        /* кол-во принудительных переключений контекста */
};
```

Функция   wait3  приостанавливает  выполнение  текущего  процесса,  пока  его  потомок  не
завершится или пока не будет получен сигнал для завершения текущего  процесса  или  вызова
функции-обработчика  этого  сигнала.  Если  потомок  уже  завершился к моменту вызова этой
функции (так называемый "zombie"  (зомби)  процесс),  то  возврат  из  функции  происходит
мнгновенно. Все системные ресурсы, которые использовал потомок - освобождаются.\

Функция  wait4  приостанавливает  выполнение текущего процесса, пока его потомок, заданный
аргументом pid не завершится или пока пока не будет получен сигнал для завершения текущего
процесса  или вызова функции-обработчика этого сигнала.  Если потомок, заданный аргументом
pid уже завершился  к  моменту  вызова  этой  функции  (так  называемый  "zombie"  (зомби)
процесс),  то  возврат  из  функции  происходит мнгновенно. Все системные ресурсы, которые
использовал потомок - освобождаются.\
## Return value
Возвращает идентификатор дочернего процесса, который завершил выполнение, или ноль, если использовался WNOHANG и ни один дочерний процесс пока еще недоступен, или -1 в случае ошибки (в этом случае переменной errno присваивается соответствующее значение).
## Examples
```
int status;
if (wait(&status) >= 0)
{
    if (WEXITED(status))
    {
        /* Child process exited normally, through `return` or `exit` */
        printf("Child process exited with %d status\n", WEXITSTATUS(status));
    }
}
```

---

## Name function: `signal()`
## Synopsis function
```
#include <signal.h>

void (*signal(int sig, void (*func)(int)))(int);
```
## Description function
Сигналы позволяют управлять процессом извне, а также позволяют процессу манипулировать собой или своими копиями (дочерними элементами). Есть два основных типа сигналов: те, которые вызывают завершение процесса, и те, которые этого не делают. Сигналы, которые вызывают завершение работы программы, могут быть результатом неисправимой ошибки или могут быть результатом ввода пользователем на терминале символа «прерывание». Сигналы используются, когда процесс остановлен, потому что он хочет получить доступ к своему контрольному терминалу в фоновом режиме (см. Tty (4)). Сигналы необязательно генерируются, когда процесс возобновляется после остановки, когда изменяется состояние дочерних процессов или когда ввод готов на терминале управления. Большинство сигналов приводят к завершению процесса их получения, если не предпринимается никаких действий; вместо этого некоторые сигналы вызывают остановку принимающего их процесса или просто отбрасываются, если процесс не запросил иное. За исключением сигналов SIGKILL и SIGSTOP, функция signal () позволяет перехватывать сигнал, игнорировать его или генерировать прерывание.
## Return value
В случае успеха функция signal() возвращает адрес функции, которая была ранее определена для обработки заданного сигнала. В случае ошибки возвращается SIG_ERR, а переменная errno устанавливается в EINV
## Examples
Следующая строка обусловливает вызов функции myint() при нажатии клавиш CTRL-C:
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_sigint(int sig)
{
    printf("Caught signal %d\n", sig);
}

int		main(void)
{
	signal(SIGINT, handle_sigint);
	while (1)
    {
        printf("hello world\n");
        sleep(1);
    }
	return (0);
}
```
Вывод c нажатием ctrl+C:
```
hello world
hello world
hello world
hello world
^CCaught signal 2
hello world
hello world
hello world
hello world
```
---
## Name function: `getcwd()`
## Synopsis function
```
#include <unistd.h>

char	*getcwd(char *buf, size_t size);
```
## Description function
Функция getcwd() копирует полный путь (максимум len символов) текущего рабочего каталога диска в строку, на которую указывает параметр dir. Если полный путь длиннее, чем len символов, то возникает ошибка. Функция getcwd() возвращает указатель на dir.
## Return value
При ошибке функция getcwd() возвращает значение NULL, а переменная errno устанавливается равной ENODEV (устройство не существует), ENOMEM (недостаточно памяти) или ERANGE (ошибка области).
## Examples
Следующая программа выводит полный путь текущего рабочего каталога:
```
#include <stdio.h>
#include <dir.h>

int		main(void)
{
	char	dir[MAXDIR];

	getcwd(dir, MAXDIR);
	printf("Current directory is %s", dir);
	return (0);
}
```
---

## Name function: `chdir()`
## Synopsis function
```
#include <unistd.h>

int		chdir(const char *path);
```
## Description function
Функция chdir() устанавливает в качестве текущего каталог, на который указывает параметр path. Путь может включать в себя и спецификацию диска. Каталог должен существовать.
## Return value
В случае успеха функция chdir() возвращает 0.
При неудаче возвращается значение —1, а переменная errno устанавливается в ENOENT (недей­ствительный путь).
## Examples
Следующий фрагмент кода назначает каталог ../../../ в качестве текущего рабоче­го каталога:
```
...
chdir("../../../");
...
```
---
## Name function: `stat()`,`lstat()`,`fstat()`
## Synopsis function
```
#include <sys/stat.h>

int		fstat(int fildes, struct stat *buf);

int		lstat(const char *restrict path, struct stat *restrict buf);

int		stat(const char *restrict path, struct stat *restrict buf);
```
## Description function
Эти функции возвращают информацию об указанном файле. Для этого не требуется иметь права доступа к файлу, хотя потребуются права поиска во всех каталогах, указанных в полном имени файла.\
stat возвращает информацию о файле file_name и заполняет буфер buf. lstat идентична stat, но в случае символьных сылок она возвращает информацию о самой ссылке, а не о файле, на который она указывает. fstat идентична stat, только возвращается информация об открытом файле, на который указывает filedes (возвращаемый open(2)), а не о file_name.\\
Все эти функции заполняют структуру stat, которая содержит следующие поля:
```
struct stat {
    dev_t         st_dev;      /* устройство */
    ino_t         st_ino;      /* inode */
    mode_t        st_mode;     /* режим доступа */
    nlink_t       st_nlink;    /* количество жестких ссылок */
    uid_t         st_uid;      /* идентификатор пользователя-владельца */
    gid_t         st_gid;      /* идентификатор группы-владельца */
    dev_t         st_rdev;     /* тип устройства */
                               /* (если это устройство) */
    off_t         st_size;     /* общий размер в байтах */
    blksize_t     st_blksize;  /* размер блока ввода-вывода */
                               /* в файловой системе */
    blkcnt_t      st_blocks;   /* количество выделенных блоков */
    time_t        st_atime;    /* время последнего доступа */
    time_t        st_mtime;    /* время последней модификации */
    time_t        st_ctime;    /* время последнего изменения */
};
```
## Return value
В случае успеха возвращается ноль. При ошибке возвращается -1, а переменной errno присваивается номер ошибки.
## Examples
```
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
 
int main(int argc, char **argv)
{
    if(argc != 2)    
        return 1;
 
    struct stat fileStat;
    if(stat(argv[1],&fileStat) < 0)    
        return 1;
 
    printf("Information for %s\n",argv[1]);
    printf("---------------------------\n");
    printf("File Size: \t\t%d bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("File inode: \t\t%d\n",fileStat.st_ino);
 
    printf("File Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
 
    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
 
    return 0;
}
```
Вывод:
```
$ ./testProgram testfile.sh

Information for testfile.sh
---------------------------
File Size:              36 bytes
Number of Links:        1
File inode:             180055
File Permissions:       -rwxr-xr-x

The file is not a symbolic link
```
---

## Name function: `execve()`

## Synopsis function
```
#include <unistd.h>

int		execve(const char *path, char *const argv[], char *const envp[]);
```
## Description function
execve() выполняет программу, задаваемую аргументом filename. В filename должно быть указано имя двоичного исполняемого файла или сценарий, начинающийся со строки вида:\
\
`#! интерпретатор [необязательные параметры]`\
\
argv — это массив строковых параметров, передаваемых новой программе. По соглашению, в первой строке должно содержаться имя файла, относящееся к запускаемой программе. envp — это массив строк в формате ключ=значение, которые передаются новой программе в качестве окружения (environment). Оба массива argv и envp завершаются указателем null.\
При успешном выполнении execve() управление не возвращается, а код, данные, bss и стек вызвавшего процесса перезаписываются загруженной программой.\
Если текущая программа выполнялась под управлением ptrace, то после успешного вызова execve() ей посылается сигнал SIGTRAP
## Return value
При успешном выполнении execve() не возвращает управление. В случае ошибки возвращается -1, а errno устанавливается в соответствующее значение.

## Examples

<http://ru.manpages.org/execve/2>

---

## Name function: `dup()`, `dup2()`

## Synopsis function

```
#include <unistd.h>

int		dup(int fildes);

int		dup2(int fildes, int fildes2);
```

## Description function
Функция dup() возвращает новый дескриптор файла, который полностью описывает (т.е. дуб­лирует) состояние файла, связанного с handle. (Проще говоря теперь имееи два fd на один файл)\
\
Функция dup2() дублирует old_handle как new_handle. Если имеется файл, который был связан с new_handle до вызова dup2(), то он будет закрыт. (Также имеем два fd, но второму fd сами можем назначить определенное значение. Например можем поместить в fd 1 и весь вывод с терминала будет перенаправлен в файл.)
## Return value
В случае успеха возвращается 0, а в случае ошибки —1. При ошибке errno устанавливается в одно из следующих значений
## Examples
Этот фрагмент кода присваивает fp2 новый дескриптор файла
```
FILE *fp, *fp2;
...
fp2 = dup(fp);
```

Этот фрагмент кода присваивает fp2 новый дескриптор файла равный 1
```
FILE *fp, *fp2;
...
fp2 = dup2(fp, 1);
```

---

## Name function: `pipe()`

## Synopsis function
```
#include <unistd.h>

int		pipe(int fildes[2]);
```

## Description function
pipe() создаёт однонаправленный канал данных, который можно использовать для взаимодействия между процессами.\
Массив pipefd используется для возврата двух файловых описателей, указывающих на концы канала. pipefd[0] указывает на конец канала для чтения. pipefd[1] указывает на конец канала для записи. Данные, записанные в конец канала, буферизируются ядром до тех пор, пока не будут прочитаны из конца канала для чтения.
## Return value
При успешном выполнении возвращается 0. В случае ошибки возвращается -1, а errno устанавливается в соответствующее значение.
## Examples
Следующая программа создаёт канал, и затем выполняет fork(2) для создания потомка; потомок наследует скопированный набор файловых дескрипторов, которые указывают на тот же канал. После fork(2) каждый процесс закрывает файловые дескрипторы, которые ненужны каналу (см. pipe(7)). Затем родитель записывает строку, переданную в качестве аргумента командной строки, в канал, а потомок читает эту строку из канала по байту за раз, и выводит её на стандартный вывод.
```
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int
main(int argc, char *argv[])
{
    int pipefd[2];
    pid_t cpid;
    char buf;
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (cpid == 0) {    /* Потомок читает из канала */
        close(pipefd[1]);          /* Закрывает неиспользуемый конец для записи */
        while (read(pipefd[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);
    } else {            /* Родитель пишет значение argv[1] в канал */
        close(pipefd[0]);          /* Закрывает неиспользуемый конец для чтения */
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);          /* Читатель видит EOF */
        wait(NULL);                /* Ожидание потомка */
        exit(EXIT_SUCCESS);
```

---

## Name function: `kill()`
## Synopsis function
```
#include <signal.h>

int		kill(pid_t pid, int sig);
```
## Description function
Системный вызов kill может быть использован для посылки какого-либо сигнала какому-либо процессу или группе процесса.
Первое - номер процесса (берется в программе, как ей надобно, в соответствии с задачей, или вводится ручками как переменная спец.типа pid_t), второе - посылаемый ему сигнал.
## Return value
В случае успеха, возвращается ноль. При ошибке, возвращается -1 и значение errno устанавливается соответствующим образом. 
## Examples
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void){

    pid_t retVal;

    retVal = fork();

    if(retVal > 0){
        int i = 0;
        while(i++ < 5){
            printf("in the parent process.\n");
            sleep(1);
        }
        //kill the child process
        kill(retVal, SIGKILL);

    } else if (retVal == 0){
        int i = 0;
        //will not ever get to 15, because
        //the parent process will kill it
        while(i++ < 15){
            printf("In the child process.\n");
            sleep(1);
        }
    } else {
        //something bad happened.
        printf("Something bad happened.");
        exit(EXIT_FAILURE);
    }
    return 0;
}
```
---

## Name function: `opendir()` ,`readdir()`, `closedir()`


## Synopsis function
```
#include <dirent.h>

DIR				*opendir(const char *filename);
struct dirent	*readdir(DIR *dirp);
int				closedir(DIR *dirp);
```
## Description function
Функция opendir() открывает поток каталога и возвращает указатель на структуру типа DIR, которая содержит информацию о каталоге. Не следует модифицировать содержимое данной струк­туры.\
\
Функция closedir() закрывает поток каталога, на который указывает ptr.\
\
Функция readdir() возвращает название следующего файла в каталоге. Иными словами, функ­ция readdir() читает оглавление каталога по одному файлу за раз. Параметр ptr должен указы­вать на поток каталога, открытый с помощью opendir(). \
```
struct DIR {
    struct dirent ent;
    struct _WDIR *wdirp;
};

struct dirent {
    /* Always zero */
    long d_ino;

    /* File position within stream */
    long d_off;

    /* Structure size */
    unsigned short d_reclen;

    /* Length of name without \0 */
    size_t d_namlen;

    /* File type */
    int d_type;

    /* File name */
    char d_name[PATH_MAX+1];
};
```
## Return value
Функция closedir() в случае успеха возвращает 0 и —1 в противном случае. При неудаче переменная errno устанавливается равной EBADF (недействительный каталог). Функция opendir() возвращает NULL в том случае, если каталог не может быть открыт. При этом переменная errno устанавливается равной либо ENOENT (каталог не найден), либо ENOMEM (недостаточно памя­ти). Функция readdir() возвращает NULL, когда достигается конец каталога.
## Examples
Пример кода, который ищет в каталоге запись ''name'':
```
dirp = opendir(".");
if (dirp == NULL)
		return (ERROR);
len = strlen(name);
while ((dp = readdir(dirp)) != NULL) {
		if (dp->d_namlen == len && strcmp(dp->d_name, name) == 0) {
				(void)closedir(dirp);
				return (FOUND);
		}
}
(void)closedir(dirp);
return (NOT_FOUND);
```

---

## Name function: `strerror()`, `errno`
## Synopsis function
```
#include <stdio.h>
extern int	errno
char		 *strerror(int errnum);
```
## Description function
В заголовочном файле <errno.h> определяется целочисленная переменная errno, которая используется системными вызовами и некоторыми библиотечными функциями при ошибках для указания того, что именно произошло. Её значение имеет смысл только тогда, когда вызов возвратил ошибку.\
Функция strerror формирует описание ошибки по коду ошибки указанному в аргументе errcode и возвращает указатель на строку, содержащую сформированное описание ошибки.\
errcode – код ошибки
## Return value
Указатель на строку, содержащую описание ошибки, код которой указан в аргументе errcode.
## Examples
В примере расшифровывается код ошибки 99 и результат выводиться на консоль.

```
#include <stdio.h>  // Для printf
#include <string.h> // Для strerror

int		main(void)
{    
	//Вывод описания ошибки №99
	errno = 99
	printf (“Ошибка %d: %s\n“, errno, strerror (99) );

	return (0);
}
```
