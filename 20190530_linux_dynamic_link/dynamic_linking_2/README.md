dynamic linking 和 implicit linking相比，优点如下：

1. 写app.c代码时，只需要一个so文件，不需要头文件。
2. 运行程序时，没有libtest.so也可以正常运行。只是在代码中加载so的时候会提示错误。



缺点是：我们在app.c文件中是不知道libtest.so文件导出的各个函数的具体名称、函数的参数类型、函数的参数个数和函数的返回值的。我们在写app.c程序的时候，必须要找到写libtest.so的作者，询问他这些信息。这样真是太麻烦了。所以，还是需要一个头文件的。

但是只有头文件还是不方便的，如果libtest.so文件中导出了10个函数，那我们在app.c中需要调用10次dlsym函数。



解决方法是：在libtest.so中导出一个struct，在app.c中只要调用1次dlsym函数获取struct的指针，后面就不需要再调用dlsym了。





```bash
$ gcc -c -fPIC test1.c
$ gcc -c -fPIC test2.c
$ gcc -shared -fPIC -o libtest.so test1.o test2.o

$ nm -s libtest.so

$ gcc app.c -ldl
$ ./a.out
pz_add(3,4) is 7.
pz_sub(3.0f,4.0f) is -1.000000.
```

