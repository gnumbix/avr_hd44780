# avr_hd44780

Данная библиотека написана для работы с LCD экранами, построенными на чипе HD44780 (или совместимого с ним). 

Она позволяет работать как в 4bit режиме, так и в 8bit. Помимо этого есть возможность не соблюдать порядок
подключения контактов. Это будет полезно, если не хочется заново разводить плату, а на порту
есть свободные контакты.


```
На данный момент в библиотеке есть проблеммы с 4bit режимом. 
```



## Getting Started

Настройки находятся в файле hd44780.h вверху. Настройте их под себя.

Библиотека состоит из двух файлов hd44780.h и hd44780.с

Написана так чтобы не занимать много памяти. И если какая-то возможность отключается в настройках.
То код полностью убирается из памяти.

Пример работы с библиотекой находится в файле:  example.c

Перед началом работы надо вызвать функцию hd44780_init(); она инициализирует LCD.

Доступные команды после инициализации:

HD44780_SEND_CHAR('a');    // Выводит символ на экран
HD44780_SEND_CURSOR_POS(позиция x, позиция y);  // Устанавливает курсор в указанную позицию.
HD44780_SEND_CMD_CLEAR;	// Очистка экрана
HD44780_SEND_CMD_HOME;   // Устанавливает курсор в начальную позицию.
HD44780_SEND_CURSOR_LEFT;    // Сдвигает курсор влево
HD44780_SEND_CURSOR_RIGHT;   // Сдвигает курсор вправо
HD44780_SEND_DISPLAY_LEFT;    // Двигает экран влево
HD44780_SEND_DISPLAY_RIGHT;     // Двигает экран вправо
HD44780_SEND_DDRAM_ADDRESS(тут адрес);  // Устанавливает DDRAM адрес (кто не знает что это, тому не нужно)
HD44780_SEND_CGRAM_ADDRESS(тут адрес);  // Устанавливает CGRAM адрес (кто не знает что это, тому не нужно)


// Управление экраном:
// active – включен экран или нет (1 да / 0 нет)
// cursor – показывать курсор или нет (1 да / 0 нет)
// blink – мигать курсором или нет (1 да / 0 нет)
HD44780_SEND_LCD_CTRL(active, cursor, blink);

// Позволяет отправить произвольную команду 
// cmd это команда которую вы отправляете
// b указывает куда посылается команда.  (1 - На вывод /  2 - системная )
HD44780_CMD_SEND_OPT(cmd, b);


В файле example.c есть пример, как вывести свой собственный символ.

```
#include <stdlib.h>
#include "hd44780.h"


// Вывод строки
void lcd_puts(const char *s)
{
    register char c;

    while ( (c = *s++) ) {
        HD44780_SEND_CHAR(c);
    }

}


int main(void)
{  

	// Инициализируем экран
	hd44780_init();

	// Устанавливаем с какой позиции будем печатать
	HD44780_SEND_CURSOR_POS(0, 0);

	// Выводим всю фразу
	lcd_puts("Counter");

	// Если нужно вывести только 1 символ то можно так:
	// HD44780_SEND_CHAR('C');

	
	// ------------------------------------------------
	// Пример как вывести произвольный символ	
	// ------------------------------------------------

	// Выбираем в CGRAM адрес 0x08
	HD44780_SEND_CGRAM_ADDRESS(0x08);

	// Далее передаем наш символ
	HD44780_CMD_SEND_OPT(0b00000001, 1); 
	HD44780_CMD_SEND_OPT(0b00000010, 1); 
	HD44780_CMD_SEND_OPT(0b00000100, 1); 
	HD44780_CMD_SEND_OPT(0b00001000, 1); 
	HD44780_CMD_SEND_OPT(0b00011111, 1); 
	HD44780_CMD_SEND_OPT(0b00000010, 1); 
	HD44780_CMD_SEND_OPT(0b00000100, 1); 
	HD44780_CMD_SEND_OPT(0b00001000, 1); 
	HD44780_CMD_SEND_OPT(0b00010000, 1); 

	// Указываем позицию в которую выводить символ
	HD44780_SEND_DDRAM_ADDRESS(7);

	// Выводим на экран символ что мы ввели
	HD44780_CMD_SEND_OPT(0b00000001, 1); 

	// ------------------------------------------------
	
	

	// Выводит счетчик
	
	unsigned int i=0;
	char buf[20];

	for( ; ; ) {

		// Устанавливаем курсор на позицию с какой печатать будем
		HD44780_SEND_CURSOR_POS(1, 0); // Вторая строчка и 0 позиция

		// Число в строку превращаем
		itoa(i, buf, 10);
	
		// Выводим строчку
		lcd_puts(buf);

		i++;
	}
	

	return 0;
}

```

## Built With

* [Atmel Studio](http://www.atmel.com/tools/atmelstudio.aspx) - AVR IDE

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Kirill Pershin** - *Initial work* - [PurpleBooth](https://github.com/GnumBix)

See also the list of [contributors](https://github.com/gnumbix/avr_hd44780/contributors) who participated in this project.

## License

This project is licensed under the Apache License, Version 2.0 - see the LICENSE file for details
