#二级指针
二级指针即是指向指针的指针

``` c
int movestr(char **s, int n) {
	*s = *s + n;
	return 0;
}
```
