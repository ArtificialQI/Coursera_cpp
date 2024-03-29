
Add date event — добавить в базу данных пару (date, event);
Print — вывести всё содержимое базы данных;
Find condition — вывести все записи, содержащиеся в базе данных, которые удовлетворяют условию condition;
Del condition — удалить из базы все записи, которые удовлетворяют условию condition;
Last date — вывести запись с последним событием, случившимся не позже данной даты.
Условия в командах Find и Del накладывают определённые ограничения на даты и события, например:

Find date < 2017-11-06 — найти все события, которые случились раньше 6 ноября 2017 года;
Del event != "holiday" — удалить из базы все события, кроме «holiday»;
Find date >= 2017-01-01 AND date < 2017-07-01 AND event == "sport event" — найти всё события «sport event», случившиеся в первой половине 2017 года;
Del date < 2017-01-01 AND (event == "holiday" OR event == "sport event") — удалить из базы все события «holiday» и «sport event», случившиеся до 2017 года.
В командах обоих типов условия могут быть пустыми: под такое условие попадают все события.

Структура программы
Ниже вам даны заготовки для файлов

condition_parser.h/cpp — в видеолекции «Задача разбора арифметического выражения. Описание решения» мы продемонстрировали построение абстрактного синтаксического дерева для арифметических выражений. Реализация этого алгоритма для разбора условий в командах Find и Del содержится в функции ParseCondition, объявленной и полностью реализованной в файлах condition_parser.h/cpp;
token.h/cpp — содержат готовый токенизатор, который используется в функции ParseCondition;
main.cpp — содержит готовую функцию main.
Вам нужно проанализировать выданный код и разработать недостающие классы и функции:

класс Database, который представляет собой базу данных, — вы должны сами создать его публичный интерфейс, основываясь на том, как он используется в функции main;
классы Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode — сформировать их иерархию и публичный интерфейс вам поможет анализ функций main и ParseCondition;
класс Date, а также функцию ParseDate и оператор вывода в поток для класса Date.
На проверку вы должны прислать архив, состоящий из файлов:

date.h/cpp — эти файлы должны содержать объявления и определения класса Date, функции ParseDate и оператора вывода в поток для класса Date;
database.h/cpp — эти файлы должны содержать объявление и определение класса Database;
node.h/cpp — эти файлы должны содержать объявления и определения класса Node, а также всех его потомков (см. выше), которые представляют собой узлы абстрактного синтаксического дерева, формируемого функцией ParseCondition;
condition_parser.h/cpp;
token.h/cpp;
main.cpp; 
другие .h- и .cpp-файлы, которые вы посчитаете нужным создать в своём решении.