```bash
$ gcc -c -fPIC test1.c
$ gcc -c -fPIC test2.c
$ gcc -shared -fPIC -o libtest.so test1.o test2.o

$ nm -s libtest.so

$ gcc app.c -ldl
$ ./a.out
6
0.750000
```

