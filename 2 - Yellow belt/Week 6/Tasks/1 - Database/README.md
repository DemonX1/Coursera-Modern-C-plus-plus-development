#### Задание по программированию: Курсовой проект ####

##### Введение #####

В курсе «Белый пояс по С++» [финальным заданием](https://www.coursera.org/learn/c-plus-plus-white/programming/sO7Vq/final-naia-zadacha-kursa) была разработка базы данных, которая работала с парами (дата, событие). В этой задаче вам нужно развить эту базу данных, научив её выбирать и удалять события, удовлетворяющие заданному условию, а также разделив её код на несколько файлов.

Более подробно, ваша программа должна уметь обрабатывать набор команд:

-   **Add  _date_  _event_**  — добавить в базу данных пару (_**date**_,  _**event**_);
-   **Print**  — вывести всё содержимое базы данных;
-   **Find  _condition_**  — вывести все записи, содержащиеся в базе данных, которые удовлетворяют условию  _**condition**_;
-   **Del  _condition_**  — удалить из базы все записи, которые удовлетворяют условию  _**condition**_;
-   **Last  _date_**  — вывести запись с последним событием, случившимся не позже данной даты.
Условия в командах  **Find**  и  **Del**  накладывают определённые ограничения на даты и события, например:

-   **Find date < 2017-11-06**  — найти все события, которые случились раньше 6 ноября 2017 года;
-   **Del event != "holiday"**  — удалить из базы все события, кроме «**holiday**»;
-   **Find date >= 2017-01-01 AND date < 2017-07-01 AND event == "sport event"**  — найти всё события «**sport event**», случившиеся в первой половине 2017 года;
-   **Del date < 2017-01-01 AND (event == "holiday" OR event == "sport event")**  — удалить из базы все события «**holiday**» и «**sport event**», случившиеся до 2017 года.

В командах обоих типов условия могут быть пустыми: под такое условие попадают все события.

##### Структура программы #####

Ниже вам даны заготовки для файлов

-   condition_parser.h/cpp — в видеолекции «Задача разбора арифметического выражения. Описание решения» мы продемонстрировали построение абстрактного синтаксического дерева для арифметических выражений. Реализация этого алгоритма для разбора условий в командах  **Find**  и  **Del** содержится в функции ParseCondition, объявленной и полностью реализованной в файлах condition_parser.h/cpp;

-   token.h/cpp — содержат готовый токенизатор, который используется в функции ParseCondition;
-   main.cpp — содержит готовую функцию main.

Вам нужно проанализировать выданный код и разработать недостающие классы и функции:

-   класс Database, который представляет собой базу данных, — вы должны сами создать его публичный интерфейс, основываясь на том, как он используется в функции main;
-   классы Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode — сформировать их иерархию и публичный интерфейс вам поможет анализ функций main и ParseCondition;
-   класс Date, а также функцию ParseDate и оператор вывода в поток для класса Date.

На проверку вы должны прислать архив, состоящий из файлов:

-   date.h/cpp — эти файлы должны содержать объявления и определения класса Date, функции ParseDate и оператора вывода в поток для класса Date;
-   database.h/cpp — эти файлы должны содержать объявление и определение класса Database;
-   node.h/cpp — эти файлы должны содержать объявления и определения класса Node, а также всех его потомков (см. выше), которые представляют собой узлы абстрактного синтаксического дерева, формируемого функцией ParseCondition;
-   condition_parser.h/cpp;
-   token.h/cpp;
-   main.cpp;
-   другие .h- и .cpp-файлы, которые вы посчитаете нужным создать в своём решении.

##### Как будет тестироваться ваше решение #####

Тестирование вашего решения будет выполняться в два этапа. На первом этапе автоматическая тестирующая система распакует присланный вами архив и соберёт извлечённые файлы в исполняемый файл. Затем этот исполняемый файл будет запущен на наборе тестов. Тестирование выполняется так же, как и для большинства задач на нашем курсе — тест подаётся в stdin, замеряется время выполнения программы, а затем анализируется stdout.

На втором этапе будет выполняться тестирование отдельных файлов вашего проекта. Проверяется, что файл date.h действительно содержит объявление класса Date, что Database::FindIf корректно выполняет поиск по переданному предикату и т.д. Мы ожидаем от ваших классов интерфейс, который зафиксирован в функции main. Поэтому в классах Database и Node делайте у методов именно те сигнатуры, которые используются в функции main.

##### Формат ввода и вывода #####

В стандартном вводе содержатся команды для работы с базой данных, по одной команде в строке. Ваша программа должна считать их и вывести результаты обработки в стандартный вывод. Правила обработки команд приведены ниже.

##### Команда Add #####

Встретив команду  **Add  _date_  _event_**, ваша программа должна добавить пару (_**date**_,  _**event**_) в базу данных и затем показывать её при поиске (команда  **Find**) или печати (команда  **Print**). Одинаковые события, произошедшие в один и тот же день, сохранять не нужно: добавление в базу уже существующей пары (_**date**_,  _**event**_) должно игнорироваться. В одну и ту же дату может произойти много разных событий, БД должна суметь их все сохранить.

Гарантируется, что поле  _**date**_  в команде  **Add**  имеет формат «_Год_-_Месяц_-_День_», где  _Год_  — это целое число от 0 до 9999,  _Месяц_  — это номер месяца от 1 до 12 включительно,  _День_  — это номер дня от 1 до 31 включительно. После даты обязательно следует пробел, отделяющий её от события. Примеры корректных дат:  **2017-11-07**,  **0-2-31**.

Вся остальная часть строки в команде  **Add**  задаёт событие. Оно может содержать пробелы, поэтому для его считывания удобно воспользоваться функцией getline. При этом гарантируется, что название события не может содержать символ кавычки (**"**). Таким образом, этот символ может встретиться лишь в условии в командах  **Find**  и  **Del**, являясь ограничителем названия события.

Пример

Для команды  **Add 2017-11-07 big sport event**  программа должна добавить в базу данных пару (**2017-11-07**,  **big sport event**).

##### Команда Del #####

Встретив команду  **Del  _condition_**, ваша программа должна удалить из базы данных все события, удовлетворяющие условию  _**condition**_, и вывести в стандартный вывод количество удалённых записей  _**N**_  в формате «**Removed  _N_ entries**». Если условие пусто, результатом выполнения команды должна стать очистка всей базы данных.

Пример

Ввод: 
```objectivec
Add 2017-06-01 1st of June
Add 2017-07-08 8th of July
Add 2017-07-08 Someone's birthday
Del date == 2017-07-08
```
Вывод:
```objectivec
Removed 2 entries
```

##### Команда Print #####

Встретив команду  **Print**, ваша программа должна вывести все пары (_дата_,  _событие_), которые в данный момент содержатся в базе данных. Пары надо выводить по одной в строке. Они должны быть отсортированы по дате по возрастанию. События в рамках одной даты необходимо выводить в порядке добавления (за исключением уже удалённых и попыток добавления повторов).

Даты надо выводить в формате  **ГГГГ-ММ-ДД**, где Г, М, Д — это цифры чисел года, месяца и дня соответственно. Если какое-то число имеет меньше разрядов, чем нужно, его надо дополнить нулями, например:  **0001-01-01**  — первое января первого года.

Пример

Ввод: 
```objectivec
Add 2017-01-01 Holiday
Add 2017-03-08 Holiday
Add 2017-1-1 New Year
Add 2017-1-1 New Year
Print
```
Вывод:
```objectivec
2017-01-01 Holiday
2017-01-01 New Year
2017-03-08 Holiday
```

_Обратите внимание, что событие "New Year" выведено только один раз, несмотря на то, что оно добавлено дважды. Как сказано в описании команды Add, одинаковые события, произошедшие в один и тот же день, сохранять не нужно._

##### Команда Find #####

Встретив команду  **Find  _condition_**, ваша программа должна вывести все пары (_дата_,  _событие_), которые в данный момент содержатся в базе данных и удовлетворяют условию  _**condition**_. Формат вывода аналогичен команде  **Print**. Поиск с пустым условием эквивалентен команде  **Print**. В конце команда должна вывести строку  **Found  _N_  entries**, где  _**N**_— количество найденных пар.

Пример


Ввод: 
```objectivec
Add 2017-01-01 Holiday
Add 2017-03-08 Holiday
Add 2017-01-01 New Year
Find event != "working day"
Add 2017-05-09 Holiday
```
Вывод:
```objectivec
2017-01-01 Holiday
2017-01-01 New Year
2017-03-08 Holiday
Found 3 entries
```

### Команда Last

По команде  **Last  _date_**  нужно вывести последнее из событий, случившихся к дате  _**date**_. Более формально:

-   среди всех имеющихся дат событий нужно найти наибольшую, не превосходящую  _**date**_;
-   из всех событий с такой датой нужно выбрать  **последнее добавленное**  и вывести в формате, аналогичном формату команды  **Print**;
-   если  _**date**_  меньше всех имеющихся дат, необходимо вывести «**No entries**».

Пример

Ввод: 
```objectivec
Add 2017-01-01 New Year
Add 2017-03-08 Holiday
Add 2017-01-01 Holiday
Last 2016-12-31
Last 2017-01-01
Last 2017-06-01
Add 2017-05-09 Holiday
```
Вывод:
```objectivec
No entries
2017-01-01 Holiday
2017-03-08 Holiday
```

#### Пример ####

Ввод: 
```objectivec
Add 2017-11-21 Tuesday
Add 2017-11-20 Monday
Add 2017-11-21 Weekly meeting
Print
Find event != "Weekly meeting"
Last 2017-11-30
Del date > 2017-11-20
Last 2017-11-30
Last 2017-11-01
```
Вывод:
```objectivec
2017-11-20 Monday
2017-11-21 Tuesday
2017-11-21 Weekly meeting
2017-11-20 Monday
2017-11-21 Tuesday
Found 2 entries
2017-11-21 Weekly meeting
Removed 2 entries
2017-11-20 Monday
No entries
```

##### Заготовки файлов #####

[token.h](https://d3c33hcgiwev3.cloudfront.net/_1640ad9030c0d03640026eccd83d190f_token.h?Expires=1569456000&Signature=TUmAwx22mZCnDdAvPLJXM3dvr3K4kWeAqtQ1vtuttHR2gkOA2uFhPOsuMAKxgvfmkQ692azUfCGz-tHkgSZgwXixgU0qFimftNW5oHpteYyPyMrE9dNWV246dqgrMe3WX-dz5211y~K2quKVEVMVCJ3XtoW~BLh1M4LOyreio3M_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

[token.cpp](https://d3c33hcgiwev3.cloudfront.net/_1640ad9030c0d03640026eccd83d190f_token.cpp?Expires=1569456000&Signature=EMdr0nZWf3A7LVfAqtyElXM9304COG3aRHRxvQfTnK4567GDrbvCUI823yvOaRFXJ1Xw9BeMk8sT~AHGBqWd1d9JPFImNJqqFsVntsEutK46fPcc4o8RIv4xGjWEfI57i3LuJDLcL-Ptr4Ffu0qmHVCKVwJK1PZtjqi53hAFTRA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

[condition_parser.h](https://d3c33hcgiwev3.cloudfront.net/_1640ad9030c0d03640026eccd83d190f_condition_parser.h?Expires=1569456000&Signature=eF0opBCsJsvDyFzIrGyd3iVi9PiZJ~qGzmMn0fNvBhTnMmz4BX9GIfC3Jk1D1z8LNbvEiVhjq8qKIEfUu9Go-XCQjmYSVZ6NTEIUKoz4YX63-iisIoyYPO8mP6VZvXGHPSWeqYyGg5O3gscu6-1Ws4Nc-TTOOmFFb~baNq8yEf8_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

[condition_parser.cpp](https://d3c33hcgiwev3.cloudfront.net/_1640ad9030c0d03640026eccd83d190f_condition_parser.cpp?Expires=1569456000&Signature=WyyBVACDjoQxKpPs2hRxbTioFPAhmXGWcQGJF4sIylcQ-edXqbl9~kOgsWLI1~dnazZDNaAWuZCXJV1h4rBAjjV~-K-jNAJopt0lsgsKWsM~2j17B4oLff1Mn31~Y1Oe~MA8HC5Q8g1AJlQsmQZQx2un7H-8FVyLpDdGowSx5U4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

[condition_parser_test.cpp](https://d3c33hcgiwev3.cloudfront.net/_8238a90130e316da9eabec79c0325d5d_condition_parser_test.cpp?Expires=1569456000&Signature=BGQXRV1u593Kk4CkctSB5mfdWlZJTqJhkftqG2k4RGDGsi1kk~i6O6HZy59C0oH6huewztokpO0a-y6VwVljVk0j7mbyHATr~Dxm2wOakGKqiBGRSShUcaXOUcS-528Asvex9nazsqSyQtzsfq2s31RTzTgdZredzEwYvVPPxuw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

[main.cpp](https://d3c33hcgiwev3.cloudfront.net/jObtWT8UEeiVZA69vv3iOA_8d4623803f1411e8b699e1a3b32ed99e_main.cpp?Expires=1569456000&Signature=enuwyfLnhExpo1ILOLo00m2TntnF~OHWAE8PL4r4QUGIEHqPVRkS1laWcW1mgPeEZ6GOXSpcLWKXlVccE3sBQIwthVyswRaMybtXpzWWJGLvL86iLf4-oXqo~fK3~6Ia3Ft85n0UpsypHhYq~BJFo3J647zV4d-hbYJuoPMLpnk_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

Обратите внимание, что в файле main.cpp мы используем наш фреймворк юнит-тестов, для тестирования функций ParseCondition и ParseEvent. В процессе работы над проектом вы можете разрабатывать свои тесты и добавлять их в функцию TestAll.

##### Подсказки #####

Для этой задачи есть набор подсказок, которые должны помочь вам с решением. Если вам не удаётся решить задачу и вы чувствуете, что у вас кончились идеи, вы можете ими воспользоваться. Но сначала обязательно попробуйте решить задачу без подсказок.

[Подсказка 1](https://d3c33hcgiwev3.cloudfront.net/gOtr-MMSEeiHqw7NuTbPEA_81690050c31211e886d35bf31cd9316a__________-1.pdf?Expires=1569456000&Signature=frbPUyH9r3aHvM4MKhfG~5yRXgLZRkkGz~YhWJwtzVt7~YifEJQqx2E0INGPDSia2LkTqWI3I7GHMIIVXtX9fDALFo-J914xtU42ksyWwr4zKiV5HPS1DR~61TwUiND2tfMgc8T6YkgrYwq8wajAsM30QKKKjEosncgsWyYkHYc_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

[Подсказка 2](https://d3c33hcgiwev3.cloudfront.net/YhZmDsMTEeiZjg4gmeu3pg_62748b00c31311e88260477c31b38644__________-2.pdf?Expires=1569456000&Signature=Sotrv6-pmWR5cFUQiDj766CPwKonTHGkhofLacF2iwj2OpatI7Tqy3YseyC39vjmaQKcSrh3aTkbOikXEsxFzNzvUJzY6HJA1-VwiJBw203FqdZByjsdaDAf-6sh2pDQHwddMipV9h4cvroLBr2ApREd1VmXF0dByhdd5E3t0f4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

[Подсказка 3](https://d3c33hcgiwev3.cloudfront.net/YhcpcMMTEeiTIRLEW541JA_62774a20c31311e8ad3f8bdce68cc9f2__________-3.pdf?Expires=1569456000&Signature=AN0yzgeXJ~oGNz-02gtTZ1ALaxM9RqopDjsYFzVMPSkEl7APYO8ZrmERL8BcBjgilSLaE7DnHFw5WV0Gn2pwn1TqZgQpPZnBYFlvL8h3NB43cXJnDjJkRUU35UBBdpVtQaTeoWaJc8ZVgBLK6xSCdVd3BGKMkeBxnIA8YdHsu5g_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

[Подсказка 4](https://d3c33hcgiwev3.cloudfront.net/YhcB8MMTEeiQ4QpwNIMilg_62774a20c31311e8ba890b8f62b9d7b0__________-4.pdf?Expires=1569456000&Signature=TRMY-eZ8ABeWOVmKmc2qwhNZ1nUNDZlBLHULeyBIJGakJZf8~G9KGCdlcNeRgULueXJC8QZNAl8OdNt~QIxGq0MYn1vTeW7aPftDLc8ZCVD8fcs7w2WWn9aP8TCIgXYX9sW5KC~UdCGDB77EY5t-pgigTzbCIS96l8SAbAfUKz8_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)