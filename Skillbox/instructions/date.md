### `#include <ctime>` - время
### `#include <iomanip>` - Манипулирование ввода-вывода

* `std::time(nullptr)` - Выводит количество секунд с 1 января 1970г. в utc
* `std::time_t t = std::time(nullptr)` - тип времени
* `std::tm* local = std::localtime(&t)` - присваивает локальное время
* `std::asctime(local)` - вывод полной даты -время
```c++
  std::time_t t = std::time(nullptr);
  std::tm* local = std::localtime(&t);
  std::cout << std::asctime(local) << std::endl;
```
* `std::put_time(local,"%Y")` - где `local`- переменная, а `"%Y"` - формат для вывода года 
* `"%Y/%m/%d"` - вывод даты в формате ГГГГ/ММ/ДД
* `"%y"` - Для вывода года в формате ГГ - две последние цифры
* `"%H:%M:%S"` - вывод времени в формате ЧЧ:ММ:СС
---
## Ввод

```c++
std::time_t t = std::time(nullptr);
std::tm* local = std::localtime(&t);
std::cin >> std::get_time(&local,"%H:%M");
std::cout << std::asctime(&local) << std::endl;
```
Изменение часов и минут

--- 
## Разница во времени
```c++
std::time_t a = std::time(nullptr);
int foo;
std::cin >> foo;
std::time_t b = std::time(nullptr);

double d = std::difftime(a,b);
std::time_t f = b + (std::time_t)d;

std::tm* local_future = std::localtime(&f);
std::cout <<asctime(local_future) << std::endl;
```
Прыжок в будущее






