#include "main.h"

int _puts(const char *s)
{
    int len_str = _strlen(s);


    write(1, s, len_str);
    write(1, "\n", 1);



    return (len_str);
}

int main()
{
    


    our_prompt();


    return (0);

}