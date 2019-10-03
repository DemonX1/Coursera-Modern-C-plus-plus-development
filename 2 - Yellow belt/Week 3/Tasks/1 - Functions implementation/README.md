#### Задание по программированию: Реализовать функции, объявленные в заголовочном файле ####


Вам дан заголовочный файл *sum_reverse_sort.h*, содержащий объявления трёх функций

[sum_reverse_sort.h](https://d3c33hcgiwev3.cloudfront.net/_3c8d2ebb6fe1005588f14d1408481a9b_sum_reverse_sort.h?Expires=1559606400&Signature=ElIUvzs7jKSz5tu6jrFnD4tp3bZBKJzO8XfgIh8x5fIVoEzEORZL8z50XTnjbLlgEw5qUKdK1-6tEZrAkv97t7d2ZRmBpaOfpx2bQwT8d1bO~sc3ZILEVjjxnuEEWydui-1tOwW9GMC0-lu2Z9MKtK~M6p20AqkNUhqu3esgZPw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

```objectivec
#pragma once
#include <string>
#include <vector>

using namespace std;

int Sum(int x, int y);
string Reverse(string s);
void Sort(vector<int>& nums);

```
Вам надо прислать *cpp*-файл, содержащий определения этих функций.

##### Как будет тестироваться ваш код #####
Автоматическая тестирующая система добавит ваш *cpp*-файл в проект, содержащий другой *cpp*-файл с юнит-тестами для всех трёх функций, а также файл *sum_reverse_sort.h*. Затем она соберёт этот проект и, если компиляция будет выполнена успешно, запустит получившийся исполняемый файл. Если он завершится успешно (т. е. юнит-тесты не найдут ошибок в вашей реализации), то ваша посылка будет засчитана.
