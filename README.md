# easybenchk

easybenchk — это утилита, которая поможет сравнить несколько процессоров друг с другом.

# Компиляция

Для компиляции нужен `gcc/g++`. На Windows для этого необходим [`MinGW`](https://github.com/The220th/SharedLib/tree/main/cpp/Windows/MinGW).

`mingw gcc` необходим версии 9 и выше.

Склонируйте репозиторий и скомпилируйте, выполнив команды:

``` bash
> git clone https://github.com/The220th/easybenchk

> cd easybenchk

> make
```

После этого запустить:

``` bash
> ./easybenchk # UNIX-like and UNIX
# или
> easybenchk.exe # windows
```

Во время работы программы система не должна быть нагружена. Необходимо выключить все лишние программы.

# Запуск

Если скомпилировать возможности нет, то можете скачать уже скомпилированный файл под вашу систему [здесь](https://github.com/The220th/easybenchk/releases): https://github.com/The220th/easybenchk/releases.

Запустите командой:

``` bash
> ./easybenchk # UNIX-like and UNIX
# или
> easybenchk.exe # windows
```

Во время работы программы система не должна быть нагружена. Необходимо выключить все лишние программы.

# Некоторые результаты

В таблице ниже приведены результаты на некоторых системах. В столбцах закодировано следующее:

 - `CPU` — название процессора: `название`, `кол-во физических ядер`/`кол-во логических ядер`, `архитектура`;

 - `RAM` — информация о памяти: `тип памяти`/`частота`/`кол-во каналов`;

 - `pi + e` — время за которое посчиталось 100 000 знаков после запятой числа pi и 10 000 знаков после запятой у числа Эйлера. В результате: `время работы на процессоре`/`времени реально прошло`;

 - `1 core` — вычисление числа пи, интеграла формулой Симпсона и суммы ряда на одном ядре;

 - `2 cores` — вычисление числа пи, интеграла формулой Симпсона и суммы ряда на двух ядрах;

 - `4 cores` — вычисление числа пи, интеграла формулой Симпсона и суммы ряда на четырёх ядрах;

 - `6 cores` — вычисление числа пи, интеграла формулой Симпсона и суммы ряда на шести ядрах;

 - `8 cores` — вычисление числа пи, интеграла формулой Симпсона и суммы ряда на восьми ядрах;

 - `12 cores` — вычисление числа пи, интеграла формулой Симпсона и суммы ряда на двенадцати ядрах;

 - `16 cores` — вычисление числа пи, интеграла формулой Симпсона и суммы ряда на шестнадцати ядрах;

 - `mem` — сортировка, где очень много обращений к памяти;

 - `Примечания` — доп. информация о тесте.

Везде время указано в **миллисекундах**. Чем значение ниже, тем лучше.

В зависимости от системы время тестирования может очень сильно различаться.

Если нужно узнать информация о памяти, выполните команду:

``` bash
> sudo dmidecode --type 17 | grep Speed # GNU/Linux
# или
> wmic memorychip get Speed # Windows
```

<table border='1'>

<tr>
    <td><b>CPU</b></td>
    <td><b>RAM</b></td>
    <td><b>pi + e</b></td>
    <td><b>1 core</b></td>
    <td><b>2 cores</b></td>
    <td><b>4 cores</b></td>
    <td><b>6 cores</b></td>
    <td><b>8 cores</b></td>
    <td><b>12 cores</b></td>
    <td><b>16 cores</b></td>
    <td><b>mem</b></td>
    <td><b>Примечания</b></td>
</tr>

<tr>
    <td>AMD Ryzen 5 3600, 6/12, amd64</td>
    <td>DDR4/2133/2</td>
    <td>14356/14372</td>
    <td>17003</td>
    <td>8883</td>
    <td>7556</td>
    <td>6103</td>
    <td>6369</td>
    <td>6147</td>
    <td>7426</td>
    <td>57938</td>
    <td>GNU/Linux</td>
</tr>

<tr>
    <td>Intel Core i5-9400F, 6/6, amd64</td>
    <td>DDR4/2666/1</td>
    <td>17372/17372</td>
    <td>13665</td>
    <td>8047</td>
    <td>5112</td>
    <td>4603</td>
    <td>4980</td>
    <td>4973</td>
    <td>5316</td>
    <td>70398</td>
    <td>GNU/Linux</td>
</tr>

<tr>
    <td>Intel Core i7-1165G7, 4/8, amd64</td>
    <td>DDR4/4267/>=2</td>
    <td>13952/13957</td>
    <td>12393</td>
    <td>8732</td>
    <td>6975</td>
    <td>6755</td>
    <td>7397</td>
    <td>7873</td>
    <td>7818</td>
    <td>30523</td>
    <td>Windows</td>
</tr>

<tr>
    <td>Intel Core i5-9300H, 4/8, amd64</td>
    <td>DDR4/2667/1</td>
    <td>15921/15921</td>
    <td>14227</td>
    <td>9024</td>
    <td>6430</td>
    <td>7005</td>
    <td>7354</td>
    <td>8198</td>
    <td>8532</td>
    <td>62029</td>
    <td>Windows</td>
</tr>

<tr>
    <td>Intel Core i5-9400F, 6/6, amd64</td>
    <td>DDR4/2133/2</td>
    <td>17680/17680</td>
    <td>14098</td>
    <td>9390</td>
    <td>6630</td>
    <td>5715</td>
    <td>5857</td>
    <td>5806</td>
    <td>5926</td>
    <td>63317</td>
    <td>Windows</td>
</tr>

<tr>
    <td>Intel Core i7-8750H, 6/12, amd64</td>
    <td>DDR4/2667/?</td>
    <td>17015/17021</td>
    <td>13656</td>
    <td>8936</td>
    <td>6275</td>
    <td>5702</td>
    <td>6181</td>
    <td>8171</td>
    <td>8009</td>
    <td>63863</td>
    <td>GNU/Linux</td>
</tr>

<tr>
    <td>AMD Ryzen 5 4600H, 6/12, amd64</td>
    <td>DDR4/3200/?</td>
    <td>15649/15652</td>
    <td>17632</td>
    <td>9925</td>
    <td>6745</td>
    <td>5404</td>
    <td>5669</td>
    <td>5897</td>
    <td>5996</td>
    <td>50662</td>
    <td>Windows</td>
</tr>

<tr>
    <td>IIntel Core i7-5650U, 2/4, amd64</td>
    <td>DDR3/1600/2</td>
    <td>20642/20661</td>
    <td>19371</td>
    <td>14497</td>
    <td>15192</td>
    <td>16287</td>
    <td>15895</td>
    <td>15921</td>
    <td>16406</td>
    <td>76070</td>
    <td>Mac OS</td>
</tr>

<tr>
    <td>Intel Pentium Gold 5405U, 2/4, amd64</td>
    <td>DDR4/2133/?</td>
    <td>30275/30284</td>
    <td>24176</td>
    <td>14252</td>
    <td>15429</td>
    <td>16025</td>
    <td>15944</td>
    <td>16605</td>
    <td>16706</td>
    <td>88755</td>
    <td>Windows</td>
</tr>

<tr>
    <td>Intel Core i5-3570, 4/4, amd64</td>
    <td>DDR3/1600/2</td>
    <td>18531/18541</td>
    <td>51265</td>
    <td>27708</td>
    <td>16561</td>
    <td>16465</td>
    <td>16132</td>
    <td>16288</td>
    <td>15876</td>
    <td>62931</td>
    <td>Windows</td>
</tr>

<tr>
    <td>Intel Core i3-6006U, 2/4, amd64</td>
    <td>DDR4/2133/2</td>
    <td>31853/31855</td>
    <td>28092</td>
    <td>17982</td>
    <td>17031</td>
    <td>17323</td>
    <td>17126</td>
    <td>17871</td>
    <td>17420</td>
    <td>121306</td>
    <td>Windows</td>
</tr>

<tr>
    <td>Intel Core i5-4300U, 2/4, amd64</td>
    <td>DDR3/1600/1</td>
    <td>34850/34853</td>
    <td>102077</td>
    <td>51956</td>
    <td>52752</td>
    <td>53175</td>
    <td>53306</td>
    <td>53508</td>
    <td>53733</td>
    <td>218018</td>
    <td>GNU/Linux</td>
</tr>

<tr>
    <td>Intel Core i5-4300U, 2/4, amd64</td>
    <td>DDR3/1600/1</td>
    <td>34028/34033</td>
    <td>102150</td>
    <td>54638</td>
    <td>54838</td>
    <td>54726</td>
    <td>55167</td>
    <td>55203</td>
    <td>54977</td>
    <td>117580</td>
    <td>Windows</td>
</tr>

<tr>
    <td>Intel Atom N570, 2/4, amd64</td>
    <td>DDR2/667/1</td>
    <td>196887/196887</td>
    <td>563348</td>
    <td>298724</td>
    <td>243844</td>
    <td>248087</td>
    <td>243298</td>
    <td>242720</td>
    <td>242986</td>
    <td>812199</td>
    <td>Windows</td>
</tr>

<tr>
    <td>Qualcomm Snapdragon 435, 8, arm64</td>
    <td>LPDDR3/800/?</td>
    <td>88850/88891</td>
    <td>4194293</td>
    <td>2117734</td>
    <td>1048831</td>
    <td>797518</td>
    <td>638089</td>
    <td>722360</td>
    <td>685100</td>
    <td>430052</td>
    <td>Android</td>
</tr>

</table>
