 # 🔰 Battle city 🔰

Добро пожаловать в Battle City! Эта игра была разработана с использованием C ++ и SFML, с графикой и игровой механикой, вдохновленной классической игрой "Танк" (Battle City) 1980-х годов.

## 📖 Краткое описание
Игрок, управляя танком, должен уничтожать вражеские танки на каждом уровне, которые появляются на игровом поле в верхней части экрана. Вражеские танки пытаются уничтожить базу игрока (представленную на карте в виде птицы, орла или Феникса), а также сам человеческий танк. Уровень завершается, когда игрок уничтожает все количество вражеских танков, которые будут показаны в правой части окна просмотра, но игра заканчивается, если база игрока разрушена или игрок теряет все доступные жизни. Обратите внимание, что оружие танка игрока также может разрушить базу, поэтому игрок все равно может проиграть даже после того, как все вражеские танки будут уничтожены.

Battle City состоит из 5 различных этапов. Каждая карта содержит различные типы местности и препятствий.

Танк: символ, дающий дополнительную жизнь. Игрок также получает одну дополнительную жизнь, выиграв уровень.;

## ✔️Требования
* :link: https://www.sfml-dev.org/download.php SFML
* Visual Studio 2022

## 📁Список файлов:
- main.cpp - запускают функцию main
- Engine.h + Engine.cpp - основные файлы, выводящие окно игры
- Bullet.h + Bullet.cpp - класс производный от Entity, хранит все данные и функции, относящиеся к объекту bullet
- Enemy.h + Enemy.cpp - класс производный от Tank, хранит все данные и функции, относящиеся к объекту enemy
- GameMenu.h + GameMenu.cpp - класс отвечающий за отображения главного меню программы
- Maps.h - хранит карты уровней в игры
- Tank.h + Tank.cpp - класс производный от Entity, хранит все данные и функции, относящиеся к объекту tank

## 🎮 Запуск игры 
### Visual Studio 2022
1) Клонирование репозитория
2) Скачивае SFML ( :link: https://www.sfml-dev.org/download.php)
3) В свойствах проекта:
    - C/C++ -> Общие -> Дополнительные каталоги включаемых файлов -> (добавить путь до папки) Ваш_Диск:\SFML-2.6.1-windows-vc17-64-bit\SFML-2.6.1\include
    - Компоновщик -> Общие -> Дополнительныекаталоги библиотек -> (добавить путь до папки) Ваш_Диск:\D:\SFML-2.6.1-windows-vc17-64-bit\SFML-2.6.1\lib
    - Компоновщик -> Ввод -> Дополнительные зависимости -> доавить следующие файлы: sfml-graphics-d.lib;sfml-window-d.lib;sfml-audio-d.lib;sfml-system-d.lib;
4) Скомпилировать (Ctrl + Shift + B)
5) Запуск (Ctrl + F5)

## 🎹 Управление
- Для управления в меню используются клавиши:
    - Arrow UP - перемещение вверх
    - Arrow Down - для перемещения вниз
    - Enter - выбор
- Управление Танком в одиночной игре:
    - W - перемещение вверх по карте
    - A - перемещение влево по карте 
    - S - перемещение вниз по карте 
    - D - перемещение вправо по карте 
    - Space - выстрел
- Управление Танком в мультиплеере игре:
    * Для игрока 1:
      - W - перемещение вверх по карте
      - A - перемещение влево по карте 
      - S - перемещение вниз по карте 
      - D - перемещение вправо по карте 
      - Space - выстрел
    * Для игрока 2:
      - Arrow UP - перемещение вверх
      - Arrow Down - для перемещения вниз
      - Arrow Left - перемещение влево
      - Arrow Right - перемещение вправо
      - P - выстрел
## 🖼️ Скриншоты
  #### Главное меню
  ![Главное меню](https://github.com/Holy-Fame/Battle-city/blob/master/screenshots/MainMenu.PNG)
  #### Первый уровень 
  ![Первый уровень](https://github.com/Holy-Fame/Battle-city/blob/master/screenshots/FirstLevel.PNG)
  #### Второй уровень
   ![Второй уровень](https://github.com/Holy-Fame/Battle-city/blob/master/screenshots/SecondLevel.png)
  #### Четвертый уровень
  ![Четвертый уровень](https://github.com/Holy-Fame/Battle-city/blob/master/screenshots/FourthLevel.png)
  #### Пятый уровень
   ![Пятый уровень](https://github.com/Holy-Fame/Battle-city/blob/master/screenshots/FifthLevel.png)
