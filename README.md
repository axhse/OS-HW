
ДЗ семинаров 3, 4, 5 и 13  

ФИО: **Битюгов Алексей Сергеевич**, **БПИ217**  

Артефакты дз лежат в соответствующих папках **HW<НОМЕР_ДЗ>**  


### Семинар 3

[Исходный код](https://github.com/axhse/OS-HW/blob/main/HW3/solution.c) программы  
Число от 0 до 20 указывается параметром при запуске  

Компиляция и запуск  
```
gcc HW3/solution.c -o HW3/solution.out
HW3/solution.out 17

```


### Семинар 4

[Исходный код](https://github.com/axhse/OS-HW/blob/main/HW4/solution.c) программы  
Путь источника указывается первым параметром, путь назначения — вторым  
При копировании режимы чтения/исполнения сохраняются, режим записи =2 нет  

Компиляция и запуски  
```
gcc HW4/solution.c -o HW4/solution.out
mkdir -p HW4/output
HW4/solution.out HW4/input/all.txt HW4/output/all.txt
HW4/solution.out HW4/input/empty.txt HW4/output/empty.txt
HW4/solution.out HW4/input/heavy.txt HW4/output/heavy.txt
HW4/solution.out HW4/input/light.txt HW4/output/light.txt
HW4/solution.out HW4/input/regular.txt HW4/output/regular.txt

```

Проверка содержимого  
```
diff HW4/input/all.txt HW4/output/all.txt
diff HW4/input/empty.txt HW4/output/empty.txt
diff HW4/input/heavy.txt HW4/output/heavy.txt
diff HW4/input/light.txt HW4/output/light.txt
diff HW4/input/regular.txt HW4/output/regular.txt

```

Проверка статусов  
```
chmod 755 HW4/input/mode_test.txt
HW4/solution.out HW4/input/mode_test.txt HW4/output/mode_test.txt
stat -c '%a' HW4/input/mode_test.txt && stat -c '%a' HW4/output/mode_test.txt

chmod 644 HW4/input/mode_test.txt
HW4/solution.out HW4/input/mode_test.txt HW4/output/mode_test.txt
stat -c '%a' HW4/input/mode_test.txt && stat -c '%a' HW4/output/mode_test.txt

chmod 555 HW4/input/mode_test.txt
HW4/solution.out HW4/input/mode_test.txt HW4/output/mode_test.txt
stat -c '%a' HW4/input/mode_test.txt && stat -c '%a' HW4/output/mode_test.txt

chmod 411 HW4/input/mode_test.txt
HW4/solution.out HW4/input/mode_test.txt HW4/output/mode_test.txt
stat -c '%a' HW4/input/mode_test.txt && stat -c '%a' HW4/output/mode_test.txt

chmod 400 HW4/input/mode_test.txt
HW4/solution.out HW4/input/mode_test.txt HW4/output/mode_test.txt
stat -c '%a' HW4/input/mode_test.txt && stat -c '%a' HW4/output/mode_test.txt

```


### Семинар 5

[Исходный код](https://github.com/axhse/OS-HW/blob/main/HW5/process.c) программы  

Программа читает stdin и дублирует данные по выходному именованному каналу,  
а также читает входной именованной канал и выводит его данные в stdin  

Программа запускается в нескольких экземплярах  
Файл входного канала указывается первым параметром, файл выходного — вторым  

Компиляция и создание каналов  
```
gcc HW5/process.c -o HW5/process.out
rm -f /tmp/firstpipe && rm -f /tmp/secondpipe
mkfifo /tmp/firstpipe && mkfifo /tmp/secondpipe

```

Запуски (в разных окнах терминала)
```
HW5/process.out /tmp/firstpipe /tmp/secondpipe

```
```
HW5/process.out /tmp/secondpipe /tmp/firstpipe

```

### Семинар 13

[Исходный код](https://github.com/axhse/OS-HW/blob/main/HW13/solution.c) программы  
Файлы и ссылки создаются в `/tmp/linktest/`  

Использование программы  
```
gcc HW13/solution.c -o HW13/solution.out
rm -rf /tmp/linktest/
HW13/solution.out

```
Получилось 41
