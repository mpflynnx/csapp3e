## Practice Problem 2.10 pdf page 83

```c
void inplace_swap(int *x, int *y){
    *y = *x ^ *y; // Step1, alternative *y ^= *x;
    *x = *x ^ *y; // Step2, alternative *x ^= *y;
    *y = *x ^ *y; // Step3, alternative *y ^= *x;
}
```

||Operation|Result|
|---|---|---|
||a|[01001110] = 78
||b|[11100001] = 225

||a ^ b|[10101111] = 175


|Step|*x|*y
|---|---|---|
|0|78|225
|1|78|175
|2|225|175
|3|225|78

### after step 1

x = 78, y = 175
|y = x ^ y|
|--|
01001110
11100001
10101111 = 175

### after step 2

x = 225, y = 175
|x = x ^ y|
|--|
01001110
10101111
11100001 = 225

### after step 2

x = 225, y = 175
|y = x ^ y|
|--|
11100001
10101111
01001110 = 78


### book solution text

|Step|*x|*y
|---|---|---|
|0|a|b
|1|a|a^b
|2|a^(a^b)=(a^a)^b=b|a^b
|3|b|b^(a^b)=(b^b)^a=a
