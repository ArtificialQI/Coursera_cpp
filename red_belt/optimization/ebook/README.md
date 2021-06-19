Вам даны задача и её решение — верное, но не удовлетворяющее заданным ограничениям на время работы. Переработайте это решение и сдайте в систему.

Условие
Разработайте систему стимулирования чтения электронных книг. Для простоты будем считать, что книга всего одна, но её одновременно читают много людей. Необходимо следить за прогрессом чтения у всех пользователей и выводить мотивирующие уведомления. А именно, ваша программа должна обрабатывать следующие события:

READ user page — сохранить факт того, что пользователь под номером user дочитал книгу до страницы page. Если ранее такой пользователь не встречался, необходимо его добавить. Гарантируется, что в рамках одного пользователя номера страниц в соответствующих ему событиях возрастают.
CHEER user — сообщить пользователю user, какая доля существующих пользователей (не считая его самого) прочитала меньшую часть книги, чем он. Если этот пользователь на данный момент единственный, доля считается равной 1. Если для данного пользователя пока не было ни одного события READ, доля считается равной 0, а сам пользователь не учитывается при вычислении долей для других пользователей до тех пор, пока для него не случится событие READ.
Формат входных данных
В первой строке вводится количество запросов Q — натуральное число, не превосходящее 10^6. В следующих Q строках в соответствии с описанным выше форматом вводятся запросы. Гарантируется, что все вводимые числа целые и положительные, при этом номера пользователей не превосходят 10^5, а номера страниц не превосходят 1000.

Формат выходных данных
Для каждого запроса CHEER user выведите единственное вещественное число от 0 до 1 — долю пользователей, прочитавших меньше страниц, чем user. Формат вывода этого числа должен быть в точности таким же, как в опубликованном ниже медленном решении.

ввод
12
CHEER 5
READ 1 10
CHEER 1
READ 2 5
READ 3 7
CHEER 2
CHEER 3
READ 3 10
CHEER 3
READ 3 11
CHEER 3
CHEER 1
вывод
0
1
0
0.5
0.5
1
0.5